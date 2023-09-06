#pragma once

#include "Core/Layer.h"

namespace MyFFL
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;
        virtual void OnEvent(Event &e) override;

        inline void BlockEvents(bool block) { m_BlockEvents = block; }
        void Begin();
        void End();

    private:
        bool m_BlockEvents = true;
        float m_Time = 0.0f;
    };
} // namespace MyFFL
