#include "tsp_solver/tsp_path.h"

namespace daa {

TspPath::TspPath(const std::string& first_node, const std::string& second_node)
    : first_node_{first_node}, second_node_{second_node} {}

}  // namespace daa
