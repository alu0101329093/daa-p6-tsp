#include "tsp_algorithms/tsp_brute_force.h"

namespace daa {

TspSolution TspBruteForce::Execute(
    const std::set<std::string>& nodes_list,
    const std::map<TspPath, std::size_t>& path_costs) {
  const auto start_time = std::chrono::steady_clock::now();
  std::size_t min_cost{SIZE_MAX};
  std::vector<std::string> min_path{};
  std::vector<std::string> nodes(nodes_list.begin(), nodes_list.end());
  std::vector<std::string> search_nodes(nodes.begin() + 1, nodes.end());
  do {
    std::string actual_node{nodes[0]};
    std::size_t actual_cost{0};
    std::vector<std::string> actual_path{actual_node};
    for (const auto& node : search_nodes) {
      auto actual_time = std::chrono::steady_clock::now();
      auto execution_time =
          std::chrono::duration_cast<std::chrono::milliseconds>(actual_time -
                                                                start_time);
      if (execution_time >= kAlgorithmMaxExecutionTime)
        return TspSolution{min_path, execution_time, min_cost};
      actual_cost += path_costs.at(TspPath{actual_node, node});
      actual_node = node;
      actual_path.push_back(node);
    }
    actual_cost += path_costs.at(TspPath{actual_node, nodes[0]});
    actual_path.push_back(nodes[0]);
    if (actual_cost < min_cost) {
      min_cost = actual_cost;
      min_path = actual_path;
    }
  } while (std::next_permutation(search_nodes.begin(), search_nodes.end()));
  auto actual_time = std::chrono::steady_clock::now();
  auto execution_time = std::chrono::duration_cast<std::chrono::milliseconds>(
      actual_time - start_time);
  return TspSolution{min_path, execution_time, min_cost};
}

std::string TspBruteForce::GetName() const { return "Brute Force"; }

}  // namespace daa
