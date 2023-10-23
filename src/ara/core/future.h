#pragma once
#include "error_code.h"

namespace ara
{
    namespace core
    {
        template <typename T, typename E = ErrorCode>
        class Future final
        {
        public:
            Future<T, E>::Future() noexcept = default;
            Future<T, E>::Future(const Future &) = delete;
            Future<T, E>::Future(Future &&other) noexcept;
            Future<T, E>::~Future() noexcept;
            Future &Future<T, E>::operator=(const Future &) = delete;
            Future &Future<T, E>::operator=(Future &&other) noexcept;
            T Future<T, E>::get();
            Result<T, E> Future<T, E>::GetResult() noexcept;
            bool Future<T, E>::valid() const noexcept;
            void Future<T, E>::wait() const;

            template <typename Rep, typename Period>
            future_status Future<T, E>::wait_for(const std::chrono::duration<Rep, Period> &timeoutDuration) const;

            template <typename Clock, typename Duration>
            future_status Future<T, E>::wait_until(const std::chrono::time_point<Clock, Duration> &deadline) const;

            // template <typename F>
            // auto Future<T, E>::then(F &&func) -> Future << see below>>;

            // template <typename F, typename ExecutorT>
            // auto Future<T, E>::then(F &&func, ExecutorT &&executor)-> Future<< see below>>;

            bool Future<T, E>::is_ready() const;
        };
    }
}