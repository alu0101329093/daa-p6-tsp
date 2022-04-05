#ifndef P6TSP_TSP_SOLVER_TSP_SOLUTION_H_
#define P6TSP_TSP_SOLVER_TSP_SOLUTION_H_

#include <chrono>
#include <sstream>
#include <string>
#include <vector>

namespace daa {

class TspSolution {
 public:
  TspSolution(const std::vector<std::string>& path,
              const std::chrono::milliseconds& time, std::size_t cost);

  inline const std::string& GetPath() const { return path_; }
  inline void SetPath(const std::string& path) { path_ = path; }
  void SetPath(const std::vector<std::string>& path);
  inline const std::chrono::milliseconds& GetTime() const { return time_; }
  inline void SetTime(const std::chrono::milliseconds& time) { time_ = time; }
  inline std::size_t GetCost() const { return cost_; }
  inline void SetCost(std::size_t cost) { cost_ = cost; }

 private:
  std::string ConvertVectorPathToString(
      const std::vector<std::string>& path) const;

  std::string path_;
  std::chrono::milliseconds time_;
  std::size_t cost_;
};

}  // namespace daa

#endif  // P6TSP_TSP_SOLVER_TSP_SOLUTION_H_