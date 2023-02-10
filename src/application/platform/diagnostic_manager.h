#ifndef DIAGNOSTIC_MANAGER_H
#define DIAGNOSTIC_MANAGER_H

#include "../../ara/exec/helper/modelled_process.h"
#include "../../ara/com/someip/sd/someip_sd_client.h"
#include "../../ara/diag/monitor.h"
#include "../helper/network_configuration.h"

namespace application
{
    namespace platform
    {
        /// @brief Diagnostic Manager (DM) functional cluster
        class DiagnosticManager : public ara::exec::helper::ModelledProcess
        {
        private:
            static const std::string cAppId;

            ara::com::helper::NetworkLayer<ara::com::someip::sd::SomeIpSdMessage> *mNetworkLayer;
            ara::com::someip::sd::SomeIpSdClient *mSdClient;
            const ara::core::InstanceSpecifier *mEventSpecifier;
            ara::diag::Event *mEvent;
            const ara::core::InstanceSpecifier *mMonitorSpecifier;
            ara::diag::Monitor *mMonitor;

            void configureNetworkLayer(const arxml::ArxmlReader &reader);

            void configureSdClient(const arxml::ArxmlReader &reader);

            void configureEvent(const arxml::ArxmlReader &reader);

            void onInitMonitor(ara::diag::InitMonitorReason reason);

            void configureMonitor(const arxml::ArxmlReader &reader);

        protected:
            int Main(
                const std::atomic_bool *cancellationToken,
                const std::map<std::string, std::string> &arguments) override;

        public:
            /// @brief Constructor
            /// @param poller Global poller for network communication
            DiagnosticManager(AsyncBsdSocketLib::Poller *poller);

            ~DiagnosticManager() override;
        };
    }
}

#endif