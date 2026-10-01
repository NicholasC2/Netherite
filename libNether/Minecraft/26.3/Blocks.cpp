#include <Nether/MinecraftBlocks.hpp>
#include <Nether/blocks/BlockRegistry.hpp>

void RegisterMinecraftBlocks()
{
    BlockRegistry::Register(
        Block::New({"minecraft", "stone"})
    );

    BlockRegistry::Register(
        Block::New({"minecraft", "dirt"})
    );

    BlockRegistry::Register(
        Block::New({"minecraft", "grass_block"})
    );
}
