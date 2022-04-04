#include "tsp_solver/tsp_solver.h"

namespace daa {

TspSolver::TspSolver(const std::string& file_name)
    : nodes_list_{}, path_costs_{} {
  std::ifstream input_file{file_name};
  std::size_t nodes_amount{};
  input_file >> nodes_amount;

  std::size_t paths_amount{NumberSummatory(nodes_amount)};
  std::string first_node{}, second_node{};
  for (std::size_t i = 0; i < paths_amount; ++i) {
    std::size_t distance;
    input_file >> first_node >> second_node >> distance;
    nodes_list_.insert(first_node);
    nodes_list_.insert(second_node);
    path_costs_.insert({TspPath{first_node, second_node}, distance});
  }
}

}  // namespace daa
