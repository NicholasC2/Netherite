#pragma once

#include <libNether/Namespace.hpp>
#include <libNether/Texture.hpp>
#include <libNether/items/Item.hpp>

struct Block {
    static Block New(Namespace namespace_, std::array<Texture, 6> textures, Item* item);

    Namespace namespace_;
    std::array<Texture, 6> textures;
    Item* item;
};
