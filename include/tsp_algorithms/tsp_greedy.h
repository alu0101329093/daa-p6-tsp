#ifndef P6TSP_TSP_ALGORITHMS_TSP_GREEDY_H_
#define P6TSP_TSP_ALGORITHMS_TSP_GREEDY_H_

#include <algorithm>
#include <chrono>
#include <climits>
#include <set>

#include "tsp_algorithms/tsp_algorithm.h"

namespace daa {

class TspGreedy : public TspAlgorithm {
 public:
  virtual TspSolution Execute(
      const std::set<std::string>& nodes_list,
      const std::map<TspPath, std::size_t>& path_costs) override;

  virtual std::string GetName() const override;
};

}  // namespace daa

#endif  // P6TSP_TSP_ALGORITHMS_TSP_GREEDY_H_