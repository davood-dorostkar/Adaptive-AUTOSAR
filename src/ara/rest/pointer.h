#pragma once
namespace ara
{
    namespace rest
    {
        template <typename T>
        using Pointer = std::unique_ptr<T>;
    }
}