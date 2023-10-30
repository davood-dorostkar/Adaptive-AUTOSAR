#pragma once
#include "pointer.h"

namespace ara
{
    namespace rest

    {
        namespace ogm
        {
            template <typename NodeT, typename... Visitors>
            void Visit(const NodeT &u, Visitors &&...vis) noexcept;

            template <typename NodeT, typename... Visitors>
            void Visit(const Pointer<NodeT> &u, Visitors &&...vis) noexcept;

            template <typename NodeT, typename... Visitors>
            void Visit(NodeT &u, Visitors &&...vis);

            template <typename NodeT, typename... Visitors>
            void Visit(Pointer<NodeT> &u, Visitors &&...vis);

            template <typename NodeT, typename... Visitors>
            void VisitAll(const NodeT &u, Visitors &&...vis) noexcept;

            template <typename NodeT, typename... Visitors>
            void VisitAll(const Pointer<NodeT> &u, Visitors &&...vis) noexcept;

            template <typename NodeT, typename... Visitors>
            void VisitAll(NodeT &u, Visitors &&...vis);

            template <typename NodeT, typename... Visitors>
            void VisitAll(Pointer<NodeT> &u, Visitors &&...vis);
        }

    }

}
