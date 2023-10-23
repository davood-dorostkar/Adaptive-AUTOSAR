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
            ~Allocator();
            void *allocate(std::size_t bytes, std::size_t alignment = alignof(std::max_align_t)){};
            void deallocate(void *p, std::size_t bytes, std::size_t alignment = alignof(std::max_align_t)){};
            bool is_equal(const Allocator &alloc) const {};
        };

        Allocator::Allocator() {}
        Allocator::~Allocator() {}
        Allocator *GetDefaultAllocator(){};
    }
}
