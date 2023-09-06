#include "pch.h"
#include "MyFFL.h"
#include "Core/Entry.h"
#include "Window/RootLayer.h"
namespace MyFFL
{
    class Main : public Application
    {
        public:
            Main()
            {
                PushLayer(new RootLayer());
            }
            ~Main() {}
    };
} // namespace MyFFL

MyFFL::Application *MyFFL::CreateApplication()
{
    return new Main();
}