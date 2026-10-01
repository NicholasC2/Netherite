#include <Nether/Nether.hpp>
#include <Nether/MinecraftBlocks.hpp>

namespace Nether {
    bool Init() {
        RegisterMinecraftBlocks();

        return true;
    }
}