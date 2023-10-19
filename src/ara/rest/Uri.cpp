#pragma once
#include "Uri.h"

namespace ara
{
    namespace rest
    {
        std::string Uri::percentEncode(const std::string &input) noexcept
        {
            std::ostringstream encoded;
            encoded.fill('0');
            encoded << std::hex;

            for (char c : input)
            {
                if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
                {
                    encoded << c;
                }
                else
                {
                    encoded << std::uppercase;
                    encoded << '%' << std::setw(2) << int(static_cast<unsigned char>(c));
                    encoded << std::nouppercase;
                }
            }

            return encoded.str();
        }
        std::string Uri::percentDecode(const std::string &input) noexcept
        {
            std::stringstream decoded;

            for (std::size_t i = 0; i < input.size(); ++i)
            {
                if (input[i] == '%')
                {
                    if (i + 2 < input.size())
                    {
                        try
                        {
                            int value = std::stoi(input.substr(i + 1, 2), nullptr, 16);
                            decoded << static_cast<char>(value);
                            i += 2;
                        }
                        catch (const std::invalid_argument &)
                        {
                            // Invalid percent-encoded sequence, ignore it.
                            decoded << input[i];
                        }
                    }
                    else
                    {
                        // Incomplete percent-encoded sequence, ignore it.
                        decoded << input[i];
                    }
                }
                else
                {
                    decoded << input[i];
                }
            }

            return decoded.str();
        }

        Uri::Builder &Uri::Builder::setPath(const std::string &path)
        {
            this->path = path;
            return *this;
        };
        Uri Uri::Builder::build() const
        {
            return Uri(path);
        }
    }
}