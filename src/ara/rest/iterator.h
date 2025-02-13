#pragma once
#include <iterator>

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

        template <typename IterT>
        IteratorRange<IterT> MakeIteratorRange(IterT a, IterT b);

        template <typename IterT>
        MoveIteratorRange<IterT> MakeMoveIteratorRange(IterT a, IterT b);
        using IteratorType = std::iterator<std::input_iterator_tag, long, long, const long *, long>; // TODO: this iterator defined randomly, define it per as your need
        using MoveIterator = std::iterator<std::input_iterator_tag, long, long, const long *, long>; // TODO: this iterator defined randomly, define it per as your need
    }

}
