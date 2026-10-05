#include <libNether/Nether.hpp>
#include <libNether/MinecraftBlocks.hpp>

namespace Nether {
    bool Init() {
        RegisterMinecraftBlocks();

        return true;
    }
}