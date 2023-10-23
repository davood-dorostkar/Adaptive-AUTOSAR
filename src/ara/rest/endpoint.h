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
        using InstanceIdentifier = ara::core::StringView;
    }
}