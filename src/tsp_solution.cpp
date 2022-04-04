#include "tsp_solver/tsp_solution.h"

namespace daa {

TspSolution::TspSolution(const std::vector<std::string>& path,
                         const std::chrono::milliseconds& time)
    : path_{ConvertVectorPathToString(path)}, time_{time} {}

void TspSolution::SetPath(const std::vector<std::string>& path) {
  path_ = ConvertVectorPathToString(path);
}

std::string TspSolution::ConvertVectorPathToString(
    const std::vector<std::string>& path) const {
  if (path.size() == 0) return "";
  std::stringstream path_stream{};
  path_stream << path[0];
  for (std::size_t i = 1; i < path.size(); ++i) {
    path_stream << "-" << path[i];
  }
  return path_stream.str();
}

}  // namespace daa
