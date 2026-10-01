#pragma once

#include <Nether/Namespace.hpp>

class Block {
    public:
        static Block New(Namespace namespace_);

        Namespace namespace_;
};
