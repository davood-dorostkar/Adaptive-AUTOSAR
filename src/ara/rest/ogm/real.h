#pragma once
#include "value.h"
#include "pointer.h"

namespace ara
{
    namespace rest
    {
        namespace ogm
        {
            class Real : public Value
            {
            private:
            public:
                using SelfType = Real;
                using ParentType = Value;
                using ValueType = long double;
                Node *GetParent() noexcept;
                const Node *GetParent() const noexcept;
                bool HasParent() const noexcept;
                ValueType GetValue() const noexcept;
                void SetValue(ValueType v) noexcept;

                template <typename... Ts>
                static Pointer<SelfType> Make(Ts &&...ts);

                template <typename... Ts>
                static Pointer<SelfType> Make(Allocator *alloc, Ts &&...ts);

                Real(ValueType value = ValueType{});
            };
        }
    }
}