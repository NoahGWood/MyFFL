#include "pch.h"
#include "Core/Application.h"

#include <GLFW/glfw3.h>

namespace MyFFL
{
    Application *Application::s_Instance = nullptr;

    Application::Application() 
    {
        MyFFL_CORE_ASSERT(!s_Instance, "Application already started.");
        s_Instance = this;
        MyFFL_PROFILE_FUNCTION();
        m_Window = Scope<Window>(Window::Create());
        m_Window->SetEventCallback(MyFFL_BIND_EVENT_FN(OnEvent));

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
    }

    Application::~Application()
    {
        MyFFL_PROFILE_FUNCTION();
    }

    void Application::PushLayer(Layer* layer)
    {
        MyFFL_PROFILE_FUNCTION();
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }
    void Application::PushOverlay(Layer *overlay)
    {
        MyFFL_PROFILE_FUNCTION();

        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }
    void Application::Run()
    {
        MyFFL_PROFILE_FUNCTION();
        while(m_Running)
        {
            float time = (float)glfwGetTime()*1000.0f; // Platform::GetTime();
            Timestep timestep = time - m_LastFrameTime;
            m_LastFrameTime = time;
            MyFFL_PROFILE_SCOPE("Application::Run");
            if(!m_Minimized)
            {
                for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
                {
                    (*it)->OnUpdate(timestep);
                }
            }
            m_ImGuiLayer->Begin();
            for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
            {
                (*it)->OnImGuiRender();
            }
            m_ImGuiLayer->End();
            m_Window->OnUpdate();
        }
    }
    void Application::OnEvent(Event& e)
    {
        MyFFL_PROFILE_FUNCTION();
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(MyFFL_BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(MyFFL_BIND_EVENT_FN(Application::OnWindowResize));
        for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
        {
            if (e.m_Handled)
            {
                break;
            }
            (*it)->OnEvent(e);
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent &e)
    {
        MyFFL_PROFILE_FUNCTION();       
        if(e.GetWidth() ==0 | e.GetHeight() == 0)
        {
            m_Minimized = true;
            return false;
        }
        m_Minimized = false;
        return true;
    }

} // namespace MyFFL