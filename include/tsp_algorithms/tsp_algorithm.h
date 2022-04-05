#ifndef P6TSP_TSP_ALGORITHMS_TSP_ALGORITHM_H_
#define P6TSP_TSP_ALGORITHMS_TSP_ALGORITHM_H_

#include <chrono>
#include <map>
#include <set>
#include <string>

#include "tsp_solver/tsp_path.h"
#include "tsp_solver/tsp_solution.h"

namespace daa {

const auto kAlgotithmMaxExecutionTime =
    std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::minutes{5});

class TspAlgorithm {
 public:
  virtual TspSolution Execute(
      const std::set<std::string>& nodes_list,
      const std::map<TspPath, std::size_t>& path_costs) = 0;

  virtual std::string GetName() const = 0;
};

}  // namespace daa

#endif  // P6TSP_TSP_ALGORITHMS_TSP_ALGORITHM_H_