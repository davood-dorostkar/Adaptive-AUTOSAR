#pragma once
#include "allocator.h"
#include "pointer.h"

namespace ara
{
    namespace rest

    {
        namespace ogm
        {
            template <typename T>
            Pointer<T> Copy(const T &g, Allocator *alloc = GetDefaultAllocator());

            template <typename T>
            Pointer<T> Copy(const Pointer<T> &g, Allocator *alloc = GetDefaultAllocator());
        }

    }

}
