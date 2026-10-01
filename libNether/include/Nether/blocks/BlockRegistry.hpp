#pragma once

#include <Nether/blocks/Block.hpp>

#include <unordered_map>
#include <string>

class BlockRegistry {
    public:
        static void Register(const Block& block);

        static const Block* Get(const Namespace namespace_);
    
    private:
        static std::unordered_map<Namespace, Block> blocks;
};