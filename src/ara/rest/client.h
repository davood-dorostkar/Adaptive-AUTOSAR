#pragma once
#include "ogm/object.h"
#include "endpoint.h"
#include "allocator.h"
#include "task.h"
#include "pointer.h"
#include "uri.h"
#include "types.h"
#include "function.h"

namespace ara
{
    namespace rest
    {
        class Event
        {
        private:
        public:
            Event();
            ~Event();
        };

        Event::Event() {}
        Event::~Event() {}

        class Reply
        {
        private:
        public:
            Reply();
            ~Reply();
        };

        Reply::Reply() {}
        Reply::~Reply() {}

        class Request
        {
        private:
        public:
            Request();
            ~Request();
        };

        Request::Request() {}
        Request::~Request() {}

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
            ~Client();
        };

        Client::~Client() {}
    }
}