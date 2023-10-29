#pragma once
#include <functional>

namespace ara
{
    namespace rest
    {
        template <typename T>
        using Function = std::function<T>;
    }
}