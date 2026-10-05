#include <libNether/blocks/Block.hpp>

Block Block::New(Namespace namespace_, std::array<Texture, 6> textures, Item* item) {
    Block block;

    block.namespace_ = namespace_;
    block.textures = textures;
    block.item = item;

    return block;
}
