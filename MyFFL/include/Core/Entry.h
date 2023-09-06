#include "Core/Base.h"
#include "Core/Application.h"

int main(int argc, char** argv) {
    MyFFL::Log::Init();
    
    MyFFL_PROFILE_BEGIN_SESSION("Startup", "MyFFLProfile-Startup.json");
    auto app = MyFFL::CreateApplication();
    MyFFL_PROFILE_END_SESSION();

    MyFFL_PROFILE_BEGIN_SESSION("Runtime", "MyFFLProfile-Runtime.json");
    app->Run();
    MyFFL_PROFILE_END_SESSION();

    MyFFL_PROFILE_BEGIN_SESSION("Shutdown", "MyFFLProfile-Shutdown.json");
    delete app;
    MyFFL_PROFILE_END_SESSION();

    return 0;
}