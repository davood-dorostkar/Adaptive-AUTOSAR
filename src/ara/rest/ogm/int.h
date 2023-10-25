#pragma once
#include "value.h"
#include <cstdint>
#include "pointer.h"
#include "allocator.h"

namespace ara
{
    namespace rest
    {
        namespace ogm
        {
            class Int
            {
            private:
            public:
                using SelfType = Int;
                using ParentType = Value;
                using ValueType = std::int64_t;
                Node *GetParent() noexcept;
                const Node *GetParent() const noexcept;
                bool HasParent() const noexcept;
                ValueType GetValue() const noexcept;
                void SetValue(ValueType v);

                template <typename... Ts>
                static Pointer<SelfType> Make(Ts &&...ts);

                template <typename... Ts>
                static Pointer<SelfType> Make(Allocator *alloc, Ts &&...ts);
                Int(ValueType value = ValueType{});
            };
        }
    }
}