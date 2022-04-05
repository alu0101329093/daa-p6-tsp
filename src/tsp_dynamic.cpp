// #include "tsp_algorithms/tsp_dynamic.h"

// namespace daa {

// TspSolution TspDynamic::Execute(
//     const std::set<std::string>& nodes_list,
//     const std::map<TspPath, std::size_t>& path_costs) {
//   const auto start_time = std::chrono::steady_clock::now();
//   std::vector<std::string> nodes(nodes_list.begin(), nodes_list.end());

//   std::priority_queue<OrderedNode, std::vector<OrderedNode>, CompareCostedPath>
//       ordered_nodes{};
//   ordered_nodes.push({0, nodes[0], {}, {}});

//   while (!ordered_nodes.empty()) {
//     OrderedNode current = ordered_nodes.top();
//     ordered_nodes.pop();
//     if (current.visited_nodes.size() == nodes_list.size()) break;
//   }

//   // std::set<std::string> visited_nodes{nodes[0]};
//   // std::string actual_node{nodes[0]};
//   // std::size_t actual_cost{0};
//   // std::vector<std::string> actual_path{actual_node};
//   // do {
//   //   auto actual_time = std::chrono::steady_clock::now();
//   //   auto execution_time =
//   //   std::chrono::duration_cast<std::chrono::milliseconds>(
//   //       actual_time - start_time);
//   //   if (execution_time >= kAlgotithmMaxExecutionTime)
//   //     return TspSolution{actual_path, execution_time, actual_cost};
//   //   std::string min_node{""};
//   //   std::size_t min_cost{SIZE_MAX};
//   //   for (const auto& node : search_nodes) {
//   //     std::size_t cost = path_costs.at(TspPath{actual_node, node});
//   //     if (cost < min_cost) {
//   //       min_cost = cost;
//   //       min_node = node;
//   //     }
//   //   }
//   //   actual_cost += min_cost;
//   //   actual_path.push_back(min_node);
//   //   search_nodes.erase(min_node);
//   //   actual_node = min_node;
//   // } while (!search_nodes.empty());
//   // actual_cost += path_costs.at(TspPath{actual_node, nodes[0]});
//   // actual_path.push_back(nodes[0]);
//   auto actual_time = std::chrono::steady_clock::now();
//   auto execution_time = std::chrono::duration_cast<std::chrono::milliseconds>(
//       actual_time - start_time);
//   return TspSolution{actual_path, execution_time, actual_cost};
// }

// std::string TspDynamic::GetName() const { return "Dynamic"; }

// }  // namespace daa
