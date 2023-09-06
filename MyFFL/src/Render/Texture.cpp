#include "pch.h"
#include "Render/Texture.h"

#include "OpenGL/include/OpenGLTexture.h"

namespace MyFFL
{
    Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
    {
        return CreateRef<OpenGLTexture2D>(width, height);
    }

    Ref<Texture2D> Texture2D::Create(const std::string &path)
    {
        return CreateRef<OpenGLTexture2D>(path);
    }
} // namespace MyFFL
