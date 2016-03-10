#pragma once

#include "util/variant.h"

#include "glm/glm.hpp"

#include <string>
#include <vector>

namespace Tangram {

class ShaderProgram;

using UniformArray = std::vector<float>;

/* Style Block Uniform types */
using UniformValue = variant<none_type, bool, std::string, float, int, glm::vec2, glm::vec3,
      glm::vec4, glm::mat2, glm::mat3, glm::mat4, UniformArray>;


class UniformLocation {

public:
    UniformLocation(const std::string& _name) : name(_name) {}

private:
    const std::string name;

    mutable int location = -1;
    mutable int generation = -1;

    friend class ShaderProgram;
};

}
