#pragma once
#include "uri.h"
#include "core/string_view.h"
#include "iterator.h"

namespace ara
{
    namespace rest
    {
        class ReplyHeader
        {
        private:
        public:
            int GetStatus() const noexcept;
            void SetStatus(int code) const noexcept;
            const Uri &GetUri() const noexcept;
            void SetUri(const Uri &uri);
            bool HasField(const core::StringView &key) const;
            bool InsertField(const core::StringView &key, const core::StringView &value);
            bool EraseField(const core::StringView &key) noexcept;
            core::StringView GetField(const core::StringView &key);
            void SetField(const core::StringView &key, const core::StringView &value) noexcept;
            std::size_t NumFields() const noexcept;
            void ClearFields() noexcept;
            using FieldIteratorRange = IteratorRange<unspecified_iterator_type>;
            using ConstFieldIteratorRange = IteratorRange<unspecified_iterator_type>;
            FieldIteratorRange::Iterator FindField(core::StringView key) noexcept;
            ConstFieldIteratorRange::Iterator FindField(core::StringView key) const noexcept;
            FieldIteratorRange::Iterator GetFields() noexcept;
            ConstFieldIteratorRange::Iterator GetFields() const noexcept;
        };

        class RequestHeader
        {
        private:
        public:
            RequestMethod GetMethod() const noexcept;
            void SetMethod(RequestMethod met);
            const Uri &GetUri() const noexcept;
            void SetUri(const Uri &uri);
            bool HasField(const core::StringView &key) const;
            bool InsertField(const core::StringView &key, const core::StringView &value);
            bool EraseField(const core::StringView &key) noexcept;
            core::StringView GetField(const core::StringView &key);
            void SetField(const core::StringView &key, const core::StringView &value) noexcept;
            std::size_t NumFields() const noexcept;
            void ClearFields() noexcept;
            using FieldIteratorRange = IteratorRange<unspecified_iterator_type>;
            using ConstFieldIteratorRange = IteratorRange<unspecified_iterator_type>;
            FieldIteratorRange::Iterator FindField(const core::StringView &key) noexcept;
            ConstFieldIteratorRange::Iterator FindField(const core::StringView &key) const noexcept;
            FieldIteratorRange::Iterator GetFields() noexcept;
            ConstFieldIteratorRange::Iterator GetFields() const noexcept;
            int GetStatus();
            void SetStatus(int code) const noexcept;
        };
    }
}
