#pragma once
#include "allocator.h"

namespace ara
{
    namespace rest
    {
        namespace ogm
        {
            class Node
            {
            private:
                Node();

            public:
                using SelfType = Node;
                using ParentType = void;
                ParentType *GetParent() noexcept;
                const ParentType *GetParent() const noexcept;
                bool HasParent() const noexcept;
                virtual ~Node();
                Node(const Node &) = delete;
                Node &operator=(const Node &) = delete;
                Allocator *GetAllocator() noexcept;
                const Allocator *GetAllocator() const noexcept;
            };
        }
    }
}
