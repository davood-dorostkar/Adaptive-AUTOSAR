#pragma once
#include "iterator.h"
#include <cstddef>
#include "core/string_view.h"
#include <type_traits>
#include "server.h"
#include "allocator.h"
#include <initializer_list>
#include "endpoint.h"
#include "pattern.h"
#include "function.h"

namespace ara
{
    namespace rest
    {
        class Match
        {
        private:
        public:
            core::StringView Get() const noexcept(std::is_nothrow_constructible<core::StringView>::value);

            template <typename T>
            T GetAs(T &&def = {});
        };

        class Matches
        {
        private:
        public:
            using MatchRange = IteratorRange<IteratorType>;
            std::size_t Count() const noexcept;
            const Match &Get(std::size_t i) const noexcept;
            MatchRange Get() const noexcept;
        };

        class Router
        {
        private:
        public:
            using RouteHandlerType = Route::Upshot(const ServerRequest &, ServerReply &, const Matches &);
            using RouteRange = IteratorRange<IteratorType>;
            using ConstRouteRange = IteratorRange<IteratorType>;
            Router(Allocator *alloc = GetDefaultAllocator());
            Router(std::initializer_list<Route> routes, Allocator *alloc = GetDefaultAllocator());
            void operator()(const ServerRequest &req, ServerReply &rep) const;
            Router &InsertRoute(const Route &route);
            Router &EmplaceRoute(RequestMethod met, Pattern pat, const Function<RouteHandlerType> &hnd);
            Router &SetDefaultHandler(const Function<Server::RequestHandlerType> &hnd);
            std::size_t RouteCount();
            RouteRange Routes();
            ConstRouteRange Routes() const;
            void RemoveRoute(RouteRange::Iterator iter);
            RouteRange::Iterator FindRoute(const Route &route);
            void Clear();
        };

        class Route
        {
        private:
        public:
            enum class Upshot
            {
                kAccept,
                kYield,
                kDefault
            };
            using RouteHandlerType = Upshot(const ServerRequest &, ServerReply &, const Matches &);
            Route(RequestMethod met, const Pattern &pat, const Function<RouteHandlerType> &hnd);
            Upshot operator()(const ServerRequest &req, ServerReply &rep) const noexcept;
            RequestMethod GetRequestMethod() const noexcept;
            const Pattern &GetPattern() const noexcept;
            friend bool operator==(const Route &a, const Route &b) noexcept;
            friend bool operator!=(const Route &a, const Route &b) noexcept;
            friend bool operator<(const Route &a, const Route &b) noexcept;
        };

    }
}
