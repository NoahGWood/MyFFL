#pragma once

#include "Core/Log.h"
#include "Core/Window.h"
#include "Core/Layer.h"
#include "Core/LayerStack.h"
#include "Core/Input.h"
#include "Core/Timestep.h"
#include "Window/ImGuiLayer.h"

namespace MyFFL
{
    class Application
    {
        public:
            Application();
            virtual ~Application();

            void Run();

            void OnEvent(Event& e);

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* layer);

            inline static Application& Get() { return *s_Instance; }
            inline Window& GetWindow() { return *m_Window; }

            ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }
            
        private:
            bool OnWindowClose(WindowCloseEvent& e);
            bool OnWindowResize(WindowResizeEvent& e);
        private:
            static Application *s_Instance;
            //Layers
            LayerStack m_LayerStack;
            ImGuiLayer* m_ImGuiLayer;
            // Windows
            Scope<Window> m_Window;
            // Stats
            Timestep m_LastFrameTime = 0.0f;
            bool m_Running = true;
            bool m_Minimized = false;
            
    };

    // Defined in client
    Application* CreateApplication();

} // namespace MyFFL
