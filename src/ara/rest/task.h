#pragma once
#include "core/future.h"

namespace ara
{
    namespace rest
    {
        template <typename T>
        using Task = core::Future<T>;
    }
}