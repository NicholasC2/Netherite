#include <Nether/blocks/Block.hpp>

Block Block::New(Namespace namespace_) {
    Block block;

    block.namespace_ = namespace_;

    return block;
}
