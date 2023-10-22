#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

namespace ara
{
    namespace rest
    {
        class Uri
        {
        public:
            std::string path;
            Uri(const std::string &path) noexcept : path(path) {}

            class Builder
            {
            private:
                std::string path;

            public:
                Builder() = default;
                Builder &setPath(const std::string &path);
                Uri build() const;
            };

        private:
            std::string percentEncode(const std::string &input) noexcept; // must be changed regarding SWS_REST_01103
            std::string percentDecode(const std::string &input) noexcept;
        };

    }

}
