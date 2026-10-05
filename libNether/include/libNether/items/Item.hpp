#pragma once

#include <libNether/Namespace.hpp>
#include <libNether/Texture.hpp>

struct Item {
    static Item New(Namespace namespace_, std::string displayName);

    Namespace namespace_;
    std::string displayName;
    Texture texture;
};
