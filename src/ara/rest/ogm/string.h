#pragma once
#include "value.h"
#include "allocator.h"
#include "core/string_view.h"

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
                using ValueType = core::StringView;
                String(Allocator *alloc, ValueType value = ValueType{});
                String(ValueType value = ValueType{});
            };
        }
    }
}