#pragma once
#include "value.h"

namespace ara
{
    namespace rest
    {
        namespace ogm
        {
            class Object : public Value
            {
            private:
            public:
                Object();
                ~Object();
            };

            Object::Object() {}
            Object::~Object() {}

        }

    }
}
