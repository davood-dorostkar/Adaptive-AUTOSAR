#pragma once
#include "core/string_view.h"

namespace ara
{
    namespace rest
    {
        class Pattern
        {
        private:
        public:
            Pattern(core::StringView pat);
            friend bool operator==(const Pattern &a, const Pattern &b) noexcept;
            friend bool operator!=(const Pattern &a, const Pattern &b) noexcept;
            friend bool operator<(const Pattern &a, const Pattern &b) noexcept;
        };
    }
}