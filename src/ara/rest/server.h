#pragma once
#include "task.h"
#include "pointer.h"
#include "ogm/object.h"
#include "uri.h"
#include "core/string_view.h"
#include "header.h"
#include "core/string.h"

namespace ara
{
    namespace rest
    {
        class ServerEvent
        {
        private:
        public:
            ServerEvent(const ServerEvent &) = delete;
            ServerEvent &operator=(const ServerEvent &) = delete;
            Task<void> Notify(const Pointer<ogm::Object> &data);
            Task<void> Notify();
            void SetSubscriptionState(const SubscriptionState);
            SubscriptionState GetSubscriptionState() const noexcept;
            const Uri &GetUri() const noexcept;
            void SendError(const unsigned int errorCode, const core::StringView &errorMessage) noexcept;
            friend bool operator==(const ServerEvent &a, const ServerEvent &b) noexcept;
            friend bool operator!=(const ServerEvent &a, const ServerEvent &b) noexcept;
            friend bool operator<(const ServerEvent &a, const ServerEvent &b) noexcept;
        };

        class ServerReply
        {
        private:
        public:
            ServerReply(const ServerReply &) = delete;
            ServerReply &operator=(const ServerReply &) = delete;
            ReplyHeader &GetHeader();
            Task<void> Send(const Pointer<ogm::Object> &data = {});
            Task<void> Send(const Pointer<ogm::Object> &&data);
            Task<void> Send(const core::StringView &data);
            Task<void> Redirect(const Uri &uri);
        };

        class ServerRequest
        {
        private:
        public:
            ServerRequest(const ServerRequest &) = delete;
            ServerRequest &operator=(const ServerRequest &) = delete;
            RequestHeader const &GetHeader() const;
            Task<ogm::Object const &> GetObject() const;
            Task<Pointer<ogm::Object>> ReleaseObject();
            Task<Pointer<core::String>> ReleaseBinary();
        };

        class Server
        {
        private:
        public:
            using RequestHandlerType = void(const ServerRequest &, ServerReply &);
            using SubscriptionHandlerType = void(ServerEvent);
            using SubscriptionStateHandlerType = void(ServerEvent &, SubscriptionState);
            Server(const Server &) = delete;
            Server &operator=(const Server &) = delete;
            Server(const InstanceIdentifier &inst_id, const Function<RequestHandlerType> &hnd, Allocator *alloc = GetDefaultAllocator());
            Task<void> Start(StartupPolicy policy = StartupPolicy::kDetached);
            Task<void> Stop(ShutdownPolicy policy = ShutdownPolicy::kGraceful);
            void ObserveSubscriptions(const Function<SubscriptionHandlerType> &shnd, const Function<SubscriptionStateHandlerType> &sshnd);
            core::ErrorCode GetError() const noexcept;
            void ObserveError(const Function<void(core::ErrorCode)> &hnd);
        };
    }

}