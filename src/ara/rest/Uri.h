#pragma once
#include <stddef.h>

namespace ara
{
    namespace rest
    {
        class Uri
        {
        private:
        public:
            class Path
            {
            private:
            public:
                class Segment
                {
                private:
                public:
                    core::StringView Get() noexcept(std::is_nothrow_constructible<core::StringView>::value);

                    template <typename T>
                    T GetAs(T &&def = {}) const;

                    friend bool operator==(const Segment &a, const Segment &b) noexcept;
                    friend bool operator!=(const Segment &a, const Segment &b) noexcept;
                    friend bool operator<(const Segment &a, const Segment &b) noexcept;
                };
                using IteratorRange = IteratorRange<unspecified_iterator_type>;
                std::size_t NumSegments() const noexcept;
                IteratorRange GetSegments() const noexcept;
                friend bool operator==(const Path &a, const Path &b) noexcept;
                friend bool operator!=(const Path &a, const Path &b) noexcept;
                friend bool operator<(const Path &a, const Path &b) noexcept;
            };

            class Query
            {
            private:
            public:
                class Parameter
                {
                private:
                public:
                    core::StringView GetKey() const noexcept(std::is_nothrow_constructible<core::StringView>::value);

                    template <typename T>
                    T GetKeyAs(T &&def = {}) const;

                    bool HasValue() const noexcept;
                    core::StringView GetValue() const noexcept(std::is_nothrow_constructible<core::StringView>::value);

                    template <typename T>
                    T GetValueAs(T &&def = {}) const;
                };
                using IteratorRange = IteratorRange<unspecified_iterator_type>;
                std::size_t NumParameters() const noexcept;
                IteratorRange GetParameters() const noexcept;
                const Parameter &GetParameter(std::size_t i) const noexcept;
                IteratorRange::Iterator Find(core::StringView key) const noexcept;
                bool HasKey(core::StringView key) noexcept;
            };

            class Builder
            {
            private:
            public:
                Builder(Allocator *alloc = GetDefaultAllocator());
                Builder(core::StringView uri, Allocator *alloc = GetDefaultAllocator());
                Builder(const Uri &uri, Allocator *alloc = GetDefaultAllocator());
                Builder(Uri &&uri, Allocator *alloc = GetDefaultAllocator());

                template <typename T>
                Builder &Scheme(T &&value);

                template <typename T>
                Builder &UserInfo(T &&value);

                template <typename T>
                Builder &Host(T &&value);

                template <typename T>
                Builder &Port(T &&value);

                Builder &Path(core::StringView value);
                Builder &Path(const Uri::Path &value);

                template <typename T>
                Builder &PathSegment(T &&seg);

                template <typename... Ts>
                Builder &PathSegments(Ts &&...values);

                template <typename... Ts>
                Builder &PathSegmentsFrom(std::size_t pos, Ts &&...values);

                template <typename T, typename U>
                Builder &PathSegmentAt(T &&oldseg, U &&newseg);

                template <typename T>
                Builder &PathSegmentAt(T &&seg);

                Builder &Query(const Uri::Query &q);

                template <typename T>
                Builder &QueryParameter(T &&key);

                template <typename T, typename U>
                Builder &QueryParameter(T &&key, U &&value);

                template <typename T, typename U>
                Builder &QueryParameterAt(T &&oldkey, U &&newkey);

                template <typename T>
                Builder &QueryParameterAt(T &&key);

                template <typename T, typename U, typename V>
                Builder &QueryParameterAt(T &&oldkey, U &&newkey, V &&newvalue);

                template <typename T>
                Builder &Fragment(T &&value);

                Builder &Fragment();
                Uri ToUri() const;
                Uri::Path ToPath() const;
                Uri::Query ToQuery() const;
            };

            enum class Part : std::uint32_t
            {
                kScheme = 1 << 1,
                kUserInfo = 1 << 2,
                kHost = 1 << 3,
                kPort = 1 << 4,
                kPath = 1 << 5,
                kQuery = 1 << 6,
                kFragment = 1 << 7,
                kPathAndQuery = Part::kPath | Part::kQuery,
                kPathEtc = Part::kPath | Part::kQuery | Part::kFragment,
                kAll = ~std::underlying_type<Part>::type{0}
            };
            static constexpr std::size_t LENGTH_MAX = 2048;
        };
    }
}
