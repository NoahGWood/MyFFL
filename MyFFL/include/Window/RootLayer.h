#pragma once
#include "MyFFL.h"

namespace MyFFL
{
    class RootLayer : public Layer
    {
        public:
            RootLayer();
            ~RootLayer() = default;

            virtual void OnAttach() override;
            virtual void OnDetach() override;
            virtual void OnEvent(Event &e) override;
            virtual void OnUpdate(Timestep ts) override;
            virtual void OnImGuiRender() override;
    };
} // namespace MyFFL