#pragma once
#include "value.h"
#include "iterator.h"

namespace ara
{
    namespace rest
    {
        namespace ogm
        {
            class Object : public Value
            {
            private:
            public:
                using SelfType = Object;
                using ParentType = Value;
                using Iterator = unspecified_iterator_type;
                using ConstIterator = unspecified_iterator_type;
                using FieldRange = IteratorRange<Iterator>;
                using ConstFieldRange = IteratorRange<ConstIterator>;
                using MoveFieldRange = IteratorRange<MoveIterator>;
                Node *GetParent() noexcept;
                const Node *GetParent() const noexcept;
                bool Object::HasParent() const noexcept;
                std::size_t GetSize() const noexcept;
                bool IsEmpty() const noexcept;
                FieldRange GetFields();
            };
        }
    }
}
