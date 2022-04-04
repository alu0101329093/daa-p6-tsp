#ifndef P6TSP_TSP_SOLVER_TSP_PATH_H_
#define P6TSP_TSP_SOLVER_TSP_PATH_H_

#include <string>

namespace daa {

class TspPath {
 public:
  TspPath(const std::string& first_node, const std::string& second_node);

  inline void SetFirstNode(const std::string& node) { first_node_ = node; }
  inline const std::string& GetFirstNode() { return first_node_; }
  inline void SetSecondNode(const std::string& node) { second_node_ = node; }
  inline const std::string& GetSecondNode() { return second_node_; }

  friend bool operator<(const TspPath& first_path, const TspPath& second_path) {
    return first_path.first_node_ < second_path.first_node_ ||
           (first_path.first_node_ == second_path.first_node_ &&
            first_path.second_node_ < second_path.second_node_);
  }

 private:
  std::string first_node_;
  std::string second_node_;
};

}  // namespace daa

#endif  // P6TSP_TSP_SOLVER_TSP_PATH_H_