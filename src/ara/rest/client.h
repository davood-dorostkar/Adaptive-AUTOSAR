#pragma once
#include "ogm/object.h"
#include "endpoint.h"
#include "allocator.h"
#include "task.h"
#include "pointer.h"
#include "uri.h"
#include "types.h"
#include "function.h"
#include "header.h"
#include "string.h"

namespace ara
{
    namespace rest
    {
        class Event
        {
        private:
        public:
            Event(const Event &) = delete;
            Event &operator=(const Event &) = delete;
            Task<bool> Unsubscribe();
            Task<bool> Resubscribe();
            const Uri &GetUri() const noexcept;
            SubscriptionState GetSubscriptionState() const noexcept;
            friend bool operator==(const Event &a, const Event &b) noexcept;
            friend bool operator!=(const Event &a, const Event &b) noexcept;
            friend bool operator<(const Event &a, const Event &b) noexcept;
        };

        class Reply
        {
        private:
        public:
            Reply(const Reply &) = delete;
            Reply &operator=(const Reply &) = delete;
            ReplyHeader const &GetHeader() const;
            Task<ogm::Object const &> GetObject() const;
            Task<Pointer<ogm::Object>> ReleaseObject();
            Task<Pointer<ogm::String>> ReleaseBinary(); // autosar document seems wrong; changed
        };

        class Request
        {
        private:
        public:
        };

        class Client
        {
        private:
        public:
            using NotificationHandlerType = void(const ogm::Object &);
            using SubscriptionStateHandlerType = void(const Event &, SubscriptionState);
            Client(const ara::rest::InstanceIdentifier &inst_id, Allocator *alloc = GetDefaultAllocator());
            Client(const Client &) = delete;
            Client &operator=(const Client &) = delete;
            Task<void> Stop(ShutdownPolicy policy = ShutdownPolicy::kGraceful);
            Task<Pointer<Reply>> Send(const Request &req);
            Task<Event> Subscribe(const Uri &uri,
                                  EventPolicy policy,
                                  duration_t time,
                                  const Function<NotificationHandlerType> &notify,
                                  const Function<SubscriptionStateHandlerType> &state = {});
            ara::core::ErrorCode GetError() const;
            void ObserveError(const Function<void(ara::core::ErrorCode)> &hnd);
        };
    }
}