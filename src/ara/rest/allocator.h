#pragma once
#include <cstddef>

namespace ara
{
    namespace rest
    {

        class Allocator
        {
        private:
        public:
            Allocator() = default;
            virtual ~Allocator();
            void *allocate(std::size_t bytes, std::size_t alignment = alignof(std::max_align_t)){};
            void deallocate(void *p, std::size_t bytes, std::size_t alignment = alignof(std::max_align_t)){};
            bool is_equal(const Allocator &alloc) const {};
        };

        template <typename T>
        class StdAllocator
        {
        private:
        public:
            using StdAllocator<T>::value_type = T;
            StdAllocator<T>::StdAllocator() noexcept;
            StdAllocator<T>::StdAllocator(Allocator *a) noexcept;

            template <typename U>
            StdAllocator<T>::StdAllocator(StdAllocator<U> const &do_not_use) noexcept;

            value_type *StdAllocator<T>::allocate(std::size_t n);
            void StdAllocator<T>::deallocate(value_type *p, std::size_t s) noexcept;
            StdAllocator StdAllocator<T>::select_on_container_copy_construction() const;
            Allocator *StdAllocator<T>::resource() const noexcept;
        };

        bool operator==(const Allocator &a, const Allocator &b);
        bool operator!=(const Allocator &a, const Allocator &b);
        Allocator *NewDeleteAllocator() noexcept;
        Allocator *GetDefaultAllocator() noexcept;
        Allocator *SetDefaultAllocator(Allocator *a) noexcept;

        template <typename T, typename U>
        bool operator==(const StdAllocator<T> &a, const StdAllocator<U> &b) noexcept;

        template <typename T, typename U>
        bool operator!=(StdAllocator<T> const &x, StdAllocator<U> const &y) noexcept;

    }
}
