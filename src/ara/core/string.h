#pragma once

namespace ara
{
    namespace core
    {
        template <typename Allocator = char> // TODO: actual doc is: Allocator = <implementation-defined>
        class BasicString final
        {
            using BasicString<Allocator>::size_type = std::size_t;
        };
        using String = BasicString<>;
    }

}
