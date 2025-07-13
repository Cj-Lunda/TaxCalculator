#include "tax_calculator.h"

#include <SDL.h>
#include <glad/gl.h>  // GLAD 2.x

#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_opengl3.h"

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

int main(int, char**) {
    // SDL + OpenGL setup
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_Window* window = SDL_CreateWindow("NZ Tax Calculator",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1000, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    // GLAD 2.x loader
    if (!gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool show_window = true;
    double income = 0.0;
    double roundedIncome = 0.0;
    std::string resultStr;

    while (show_window) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                show_window = false;
        }


        

        ImGui_ImplSDL2_NewFrame();          // <-- Call without argument here
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();
        ImGui::SetNextWindowPos(ImVec2(40, 80), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(900, 900), ImGuiCond_FirstUseEver);
        ImGui::Begin("NZ Tax Calculator");
        ImGui::Text("Enter your income (whole dollars, no cents): [Tax rates 01 April 2025 - 31 March 2026]");

        static char incomeBuffer[64] = "";
        ImGui::InputText("Income", incomeBuffer, IM_ARRAYSIZE(incomeBuffer), ImGuiInputTextFlags_CharsDecimal);

        if (ImGui::Button("Calculate Tax")) {
            try {
                income = std::stod(incomeBuffer);
                roundedIncome = (income - floor(income) <= 0.5) ? floor(income) : floor(income) + 1;

                std::ostringstream oss;
                oss << "Income: " << moneyFormat(roundedIncome) << "\n";

                std::streambuf* oldCoutBuf = std::cout.rdbuf();
                std::ostringstream tempStream;
                std::cout.rdbuf(tempStream.rdbuf());

                taxCalculator(roundedIncome);

                std::cout.rdbuf(oldCoutBuf);
                oss << tempStream.str();

                resultStr = oss.str();
            } catch (...) {
                resultStr = "Invalid input!";
            }
        }

        if (!resultStr.empty()) {
            ImGui::TextWrapped("%s", resultStr.c_str());
        }

        ImGui::End();

        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
