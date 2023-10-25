#pragma once

namespace ara
{
    namespace rest
    {
        template <typename IterT>
        class IteratorRange
        {
        private:
        public:
            using Iterator = IterT;
            IteratorRange(Iterator first, Iterator last);
            Iterator begin() const;
            Iterator end() const;
            friend Iterator begin(const IteratorRange &r);
            friend Iterator end(const IteratorRange &r);
        };

        template <typename IterT>
        class MoveIteratorRange
        {
            using MoveIterator = IterT;
            MoveIteratorRange(MoveIterator first, MoveIterator last);
            MoveIterator begin() const;
            MoveIterator end() const;
            friend MoveIterator begin(const MoveIteratorRange &r);
            friend MoveIterator end(const MoveIteratorRange &r);
        };
    }
}
