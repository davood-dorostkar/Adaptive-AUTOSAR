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
            public:
                Value();
                ~Value();
            };

            Value::Value() {}
            Value::~Value() {}

        }

    }
}
