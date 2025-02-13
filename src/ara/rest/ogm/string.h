#pragma once
#include "value.h"
#include "allocator.h"
#include "core/string_view.h"
#include "pointer.h"

namespace ara
{
    namespace rest
    {
        namespace ogm
        {
            class String : public Value
            {
            private:
            public:
                using SelfType = String;
                using ParentType = Value;
                using ValueType = core::StringView;
                Node *GetParent() noexcept;
                const Node *GetParent() const noexcept;
                bool HasParent() const noexcept;
                ValueType GetValue() const;
                void SetValue(const ValueType &v);

                template <typename... Ts>
                static Pointer<SelfType> Make(Ts &&...ts);

                template <typename... Ts>
                static Pointer<SelfType> Make(Allocator *alloc, Ts &&...ts);

                String(ValueType value = ValueType{});
                String(Allocator *alloc, ValueType value = ValueType{});
            };
        }
    }
}