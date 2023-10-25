#pragma once
#include "node.h"
#include "core/string_view.h"
#include "value.h"
#include "pointer.h"
#include "allocator.h"
#include "string.h"

namespace ara
{
    namespace rest
    {
        namespace ogm
        {
            class Field : public Node
            {
            private:
            public:
                using SelfType = Field;
                using ParentType = Node;
                Node *GetParent() noexcept;
                const Node *GetParent() const noexcept;
                bool HasParent() const noexcept;
                const core::StringView &GetName() const noexcept;
                const Value &GetValue() const noexcept;
                Value &GetValue() noexcept;
                void SetValue(Pointer<Value> &&v) noexcept;
                Pointer<Value> ReplaceValue(Pointer<Value> &&v) noexcept;

                template <typename... Ts>
                static Pointer<SelfType> Make(Ts &&...ts);

                template <typename... Ts>
                static Pointer<SelfType> Make(Allocator *alloc, Ts &&...ts);

                Field(const String &name, Pointer<Value> &&value);
                Field(Allocator *alloc, const String &key, Pointer<Value> &&val);
            };
        }
    }
}