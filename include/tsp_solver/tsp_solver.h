#ifndef P6TSP_TSP_SOLVER_TSP_SOLVER_H_
#define P6TSP_TSP_SOLVER_TSP_SOLVER_H_

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>

#include "tsp_algorithms/tsp_algorithm.h"
#include "tsp_solver/tsp_path.h"
#include "utils.h"

namespace daa {

class TspSolver {
 public:
  TspSolver(const std::string& file_name);

 private:
  std::set<std::string> nodes_list_;
  std::map<TspPath, std::size_t> path_costs_;
  std::unique_ptr<TspAlgorithm> tsp_algorithm_;
};

}  // namespace daa

#endif  // P6TSP_TSP_SOLVER_TSP_SOLVER_H_