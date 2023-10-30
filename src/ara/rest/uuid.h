#pragma once
#include "core/string.h"
#include "core/string_view.h"
#include <cstdint>

namespace ara
{
    namespace rest
    {
        class Uuid
        {
        private:
        public:
            static Uuid MakeV1();
            static Uuid MakeV3(const core::String &ns);
            static Uuid MakeV4();
            static Uuid MakeV5(const core::String &ns);
            Uuid() noexcept = default;
            Uuid(core::StringView id);
            Uuid(std::uint32_t timeLow,
                 std::uint16_t timeMid,
                 std::uint16_t timeHighAndVersion,
                 std::uint16_t clockSeq,
                 std::uint64_t node) noexcept;
            std::uint32_t GetTimeLow() const noexcept;
            std::uint16_t GetTimeMid() const noexcept;
            std::uint16_t GetTimeHighAndVersion() const noexcept;
            std::uint16_t GetClockSeq() const noexcept;
            std::uint64_t GetNode() const noexcept;
            friend bool operator==(const Uuid &a, const Uuid &b) noexcept;
            friend bool operator!=(const Uuid &a, const Uuid &b) noexcept;
            friend bool operator<(const Uuid &a, const Uuid &b) noexcept;
        };

    }

}
