#include "pch.h"
#include "Window/RootLayer.h"

#include <imgui/imgui.h>
#include <tinyfiledialogs/tinyfiledialogs.h>

namespace MyFFL
{
    RootLayer::RootLayer()
        : Layer("RootLayer") {}

    void RootLayer::OnAttach()
    {
        MyFFL_INFO("Root Layer Attached");
    }
    void RootLayer::OnDetach()
    {
        MyFFL_INFO("Root Layer Detached");
    }
    void RootLayer::OnUpdate(Timestep ts)
    {
    }
    void RootLayer::OnImGuiRender()
    {
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
        ImGui::ShowDemoWindow();
        ImGui::BeginMainMenuBar();
            if(ImGui::BeginMenu("File"))
            {
                if(ImGui::MenuItem("New", "Ctrl+N"))
                {
                    MyFFL_INFO("New Clicked");
                }
                if(ImGui::MenuItem("Open", "Ctrl+O"))
                {
                    char const *lFilterPatterns[4] = {"*.MyFFL", "*.ffl", "*.yaml", "*.gun"};
                    char *out = tinyfd_openFileDialog("Open Project", "", 2, lFilterPatterns, "Project Files", 0);
                    MyFFL_INFO("File Selected To Open: {0}", out);
                }
                ImGui::EndMenu();
            }
        ImGui::EndMainMenuBar();
        ImGui::Begin("Test Window");

        ImGui::End();
    }
    void RootLayer::OnEvent(Event &e)
    {

    }

} // namespace MyFFL