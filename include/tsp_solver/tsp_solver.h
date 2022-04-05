#ifndef P6TSP_TSP_SOLVER_TSP_SOLVER_H_
#define P6TSP_TSP_SOLVER_TSP_SOLVER_H_

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "tsp_algorithms/tsp_algorithm.h"
#include "tsp_algorithms/tsp_brute_force.h"
#include "tsp_algorithms/tsp_greedy.h"
#include "tsp_algorithms/unknown_tsp_algorithm_exception.h"
#include "tsp_solver/tsp_path.h"
#include "utils.h"

namespace daa {

struct NamedTspSolution {
  std::string name;
  TspSolution solution;
};

enum class TspAlgorithms { kBruteForce = 0, kGreedy, kDynamic };

const std::size_t kTspAlgorithmsAmount = 2;

class TspSolver {
 public:
  TspSolver();
  TspSolver(const std::string& file_name);

  void SetAlgorithm(TspAlgorithms algorithm);

  void LoadFile(const std::string& file_name);
  std::vector<NamedTspSolution> Solve();

  inline std::size_t GetSize() {return size_;}

 private:
  void ChangeProblem(const std::string& file_name);

  std::set<std::string> nodes_list_;
  std::map<TspPath, std::size_t> path_costs_;
  std::unique_ptr<TspAlgorithm> algorithm_;
  std::size_t size_;
};

}  // namespace daa

#endif  // P6TSP_TSP_SOLVER_TSP_SOLVER_H_