#pragma once

namespace ara
{
    namespace rest
    {
        template <typename T>
        using Function = std::function<T>;
    }
}