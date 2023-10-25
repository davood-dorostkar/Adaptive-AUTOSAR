#pragma once
#include "iterator.h"
#include <cstddef>
#include "core/string_view.h"
#include <type_traits>

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
            using MatchRange = IteratorRange<unspecified_iterator_type>;
            std::size_t Count() const noexcept;
            const Match &Get(std::size_t i) const noexcept;
            MatchRange Get() const noexcept;
        };
    }
}
