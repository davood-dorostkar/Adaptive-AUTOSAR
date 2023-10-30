#pragma once
#include <cstdint>
#include "core/string_view.h"

namespace ara
{
    namespace rest
    {
        enum class SubscriptionState
        {
            kSubscribed,
            kCanceled,
            kResubscribe,
            kInvalid
        };
        enum class ShutdownPolicy : std::uint32_t
        {
            kForced,
            kGraceful
        };
        enum class EventPolicy : std::uint32_t
        {
            kTriggered = 1u << 0,
            kPeriodic = 1u << 1
        };
        enum class RequestMethod : std::uint32_t
        {
            kGet = 1 << 0,
            kPost = 1 << 1,
            kPut = 1 << 2,
            kDelete = 1 << 3,
            kOptions = 1 << 4,
            kHead = 1 << 5
        };
        enum class StartupPolicy : std::uint32_t
        {
            kDetached,
            kAttached
        };
        constexpr RequestMethod operator|(RequestMethod a, RequestMethod b) noexcept;
        constexpr EventPolicy operator|(EventPolicy a, EventPolicy b) noexcept;
        using InstanceIdentifier = core::StringView;
    }
}