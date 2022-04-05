#ifndef P6TSP_INSTANCE_GENERATOR_INSTANCE_GENERATOR_H_
#define P6TSP_INSTANCE_GENERATOR_INSTANCE_GENERATOR_H_

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

namespace daa {

class InstanceGenerator {
 public:
  void GenerateInstaces(std::size_t nodes_amount, std::size_t files_amount,
                        const std::string& folder_path) const;

 private:
  std::string GetNodeIndentifier(std::size_t index) const;
  std::size_t GenerateRandomCost() const;
};

}  // namespace daa

#endif  // P6TSP_INSTANCE_GENERATOR_INSTANCE_GENERATOR_H_