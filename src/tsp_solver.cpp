#include "tsp_solver/tsp_solver.h"

namespace daa {

TspSolver::TspSolver() : nodes_list_{}, path_costs_{}, algorithm_{}, size_{} {}

TspSolver::TspSolver(const std::string& file_name)
    : nodes_list_{}, path_costs_{}, algorithm_{}, size_{} {
  ChangeProblem(file_name);
}

void TspSolver::SetAlgorithm(TspAlgorithms algorithm) {
  switch (algorithm) {
    case TspAlgorithms::kBruteForce:
      algorithm_.reset(new TspBruteForce{});
      break;
    case TspAlgorithms::kGreedy:
      algorithm_.reset(new TspGreedy{});
      break;
    case TspAlgorithms::kDynamic:
      break;
    default:
      throw UnknownTspAlgorithmException{};
  }
}

void TspSolver::LoadFile(const std::string& file_name) {
  nodes_list_.clear();
  path_costs_.clear();
  ChangeProblem(file_name);
}

std::vector<NamedTspSolution> TspSolver::Solve() {
  std::vector<NamedTspSolution> results{};
  for (std::size_t i = 0; i < kTspAlgorithmsAmount; ++i) {
    SetAlgorithm(static_cast<TspAlgorithms>(i));
    TspSolution solution{algorithm_->Execute(nodes_list_, path_costs_)};
    std::string algorithm_name{algorithm_->GetName()};
    results.push_back({algorithm_name, solution});
  }
  return results;
}

void TspSolver::ChangeProblem(const std::string& file_name) {
  std::ifstream input_file{file_name};
  std::size_t nodes_amount{};
  input_file >> nodes_amount;
  size_ = nodes_amount;

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
