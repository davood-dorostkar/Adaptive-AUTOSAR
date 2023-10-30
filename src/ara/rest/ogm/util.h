#pragma once
#include "pointer.h"
#include "core/string_view.h"
#include "ogm/array.h"
#include "ogm/object.h"

namespace ara
{
    namespace rest

    {
        namespace ogm
        {
            template <typename ValueNodeT, typename NodeT>
            ValueNodeT &Get(const NodeT &u, const core::StringView &n);

            template <typename ValueNodeT, typename NodeT>
            ValueNodeT &Get(const Pointer<NodeT> &u, const core::StringView &n);

            template <typename ValueNodeT, typename NodeT>
            typename ValueNodeT::ValueType GetValue(const NodeT &u, const core::StringView &n);

            template <typename ValueNodeT, typename NodeT>
            typename ValueNodeT::ValueType GetValue(const Pointer<NodeT> &u, const core::StringView &n);

            template <typename ValueNodeT, typename ValueT>
            bool Set(ValueNodeT &u, ValueT &v);

            bool Set(Array &u, Array::MoveRange &v);
            bool Set(Object &u, Object::MoveFieldRange &v);

            template <typename ValueNodeT, typename NodeT, typename ValueT>
            bool SetValue(const ValueNodeT &u, const core::StringView &n, ValueT &v);

            template <typename ValueNodeT, typename NodeT, typename ValueT>
            bool SetValue(const Pointer<ValueNodeT> &u, const core::StringView &n, ValueT &v);

            template <typename NodeT>
            Pointer<NodeT> Cast(Pointer<Node> n);
        }
    }
}