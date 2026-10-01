#include <Nether/blocks/BlockRegistry.hpp>

std::unordered_map<Namespace, Block> BlockRegistry::blocks;

void BlockRegistry::Register(const Block& block) {
    blocks.emplace(block.namespace_, block);
}

const Block* BlockRegistry::Get(const Namespace namespace_) {
    auto it = blocks.find(namespace_);

    if (it == blocks.end())
        return nullptr;

    return &it->second;
}
