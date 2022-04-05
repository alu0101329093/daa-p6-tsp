// #ifndef P6TSP_TSP_ALGORITHMS_TSP_DYNAMIC_H_
// #define P6TSP_TSP_ALGORITHMS_TSP_DYNAMIC_H_

// #include <algorithm>
// #include <chrono>
// #include <climits>
// #include <queue>
// #include <set>

// #include "tsp_algorithms/tsp_algorithm.h"

// namespace daa {

// class TspDynamic : public TspAlgorithm {
//  public:
//   virtual TspSolution Execute(
//       const std::set<std::string>& nodes_list,
//       const std::map<TspPath, std::size_t>& path_costs) override;

//   virtual std::string GetName() const override;

//  private:
//   struct OrderedNode {
//     std::size_t cost;
//     std::string node;
//     std::set<std::string> visited_nodes;
//     std::vector<TspPath> current_path;
//   };

//   struct CompareCostedPath {
//     bool operator()(const OrderedNode& lhs, const OrderedNode& rhs) const {
//       return lhs.first > rhs.first;
//     }
//   };
// };

// }  // namespace daa

// #endif  // P6TSP_TSP_ALGORITHMS_TSP_DYNAMIC_H_