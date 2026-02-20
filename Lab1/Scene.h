#pragma once
#include <vector>
#include <memory>

class Scene {
public:
    static int ID;
    std::vector<std::unique_ptr<Object>> objects;

    Object& CreateObject(Mesh* mesh, Texture* texture);
};
