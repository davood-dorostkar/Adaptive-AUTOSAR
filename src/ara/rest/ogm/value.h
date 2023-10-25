#pragma once
#include "node.h"

namespace ara
{
    namespace rest
    {
        namespace ogm
        {
            class Value : public Node
            {
            private:
                Value();

            public:
                using SelfType = Value;
                using ParentType = Node;
                Node *GetParent() noexcept;
                const Node *GetParent() const noexcept;
                bool HasParent() const noexcept;
            };
        }
    }
}
