#pragma once

#include <string>
#include <functional>

struct Namespace
{
    std::string namespace_;
    std::string name;

    bool operator==(const Namespace& other) const
    {
        return namespace_ == other.namespace_ &&
               name == other.name;
    }
};

template<>
struct std::hash<Namespace>
{
    std::size_t operator()(const Namespace& ns) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(ns.namespace_);
        std::size_t h2 = std::hash<std::string>{}(ns.name);

        return h1 ^ (h2 << 1);
    }
};
