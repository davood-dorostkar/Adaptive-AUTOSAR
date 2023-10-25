#pragma once
#include "value.h"
#include "iterator.h"
#include "core/string_view.h"
#include "pointer.h"
#include "field.h"
#include <utility>

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
                ConstFieldRange GetFields() const noexcept;
                bool HasField(core::StringView name) const noexcept;
                Iterator Find(core::StringView name) noexcept;
                ConstIterator Find(core::StringView name) const noexcept;
                bool Insert(Pointer<Field> &&f);
                Iterator Remove(Iterator iter);
                std::pair<Iterator, Pointer<Field>> Release(Iterator iter);
                Pointer<Field> Replace(Iterator iter, Pointer<Field> &&field);
                void Clear();

                template <typename... Ts>
                static Pointer<SelfType> Make(Ts &&...ts);

                template <typename... Ts>
                static Pointer<SelfType> Make(Allocator *alloc, Ts &&...ts);

                template <typename... Ts>
                Object(Pointer<Ts> &&...fields);

                template <typename... Ts>
                Object(Allocator *alloc, Pointer<Ts> &&...fields);
            };
        }
    }
}
