#pragma once
#include "uri.h"

namespace ara
{
    namespace rest
    {
        class Normalize
        {
        private:
            std::string remove_dot_segments(const std::string &uri) const {}

        public:
            Normalize();
            ~Normalize();
            Uri &caseNormalize(Uri &uri)
            {
                std::cout << "case normalization not implemented yet" << std::endl;
                return uri;
            }
            Uri &percentNormalize(Uri &uri)
            {
                std::cout << "percent encoding normalization not implemented yet" << std::endl;
                return uri;
            }
            Uri &pathSegmentNormalize(Uri &uri)
            {
                std::string path = remove_dot_segments(uri.path);
                std::cout << "path segment normalization not implemented yet" << std::endl;
                return uri;
            }
            virtual Uri &schemeNormalize(Uri &uri) = 0;
            Uri &protocolNormalize(Uri &uri)
            {
                std::cout << "protocol normalization not implemented yet" << std::endl;
                return uri;
            }
        };

        Normalize::Normalize() {}
        Normalize::~Normalize() {}
    }
}

class HTTPNormalize : public ara::rest::Normalize
{
public:
    ara::rest::Uri &schemeNormalize(ara::rest::Uri &uri)
    {
        std::cout << "http scehme normalization not implemented yet" << std::endl;
        return uri;
    }
};

class HTTPSNormalize : public ara::rest::Normalize
{
public:
    ara::rest::Uri &schemeNormalize(ara::rest::Uri &uri)
    {
        std::cout << "https scehme normalization not implemented yet" << std::endl;
        return uri;
    }
};