#pragma once
#include "value.h"
#include "iterator.h"
#include <cstddef>
#include "pointer.h"
#include <utility>
#include "allocator.h"

namespace ara
{
    namespace rest
    {
        namespace ogm
        {
            class Array : public Value
            {
            private:
            public:
                using SelfType = Array;
                using ParentType = Value;
                using Iterator = IteratorType;
                using ConstIterator = IteratorType;
                using ValueRange = IteratorRange<Iterator>;
                using ConstValueRange = IteratorRange<ConstIterator>;
                using MoveRange = IteratorRange<MoveIterator>;
                Node *GetParent() noexcept;
                const Node *GetParent() const noexcept;
                bool HasParent() const noexcept;
                std::size_t GetSize() const noexcept;
                bool IsEmpty() const noexcept;
                Value &GetValue(std::size_t index);
                const Value &GetValue(std::size_t index) const;
                ValueRange GetValues() noexcept;
                ConstValueRange GetValues() const noexcept;
                void Append(Pointer<Value> &&v);
                void Insert(Iterator iter, Pointer<Value> &&v);
                Iterator Remove(Iterator iter);
                std::pair<Iterator, Pointer<Value>> Release(Iterator iter);
                Pointer<Value> Replace(Iterator iter, Pointer<Value> &&v);
                void Clear();

                template <typename... Ts>
                static Pointer<SelfType> Make(Ts &&...ts);

                template <typename... Ts>
                static Pointer<SelfType> Make(Allocator *alloc, Ts &&...ts);

                template <typename... Ts>
                Array(Pointer<Ts> &&...ts);

                template <typename... Ts>
                Array(Allocator *alloc, Pointer<Ts> &&...ts);
            };
        }

    }
}