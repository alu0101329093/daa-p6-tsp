#include "instance_generator/instance_generator.h"

namespace daa {

void InstanceGenerator::GenerateInstaces(std::size_t nodes_amount,
                                         std::size_t files_amount,
                                         const std::string& folder_path) const {
  for (std::size_t i = 0; i < files_amount; ++i) {
    std::ofstream generated_file{folder_path + "generated-" +
                                 std::to_string(i) + ".txt"};
    generated_file << nodes_amount << "\n";
    for (std::size_t node = 0; node < nodes_amount - 1; ++node) {
      std::string node_identifier{GetNodeIndentifier(node)};
      for (std::size_t j = node + 1; j < nodes_amount; ++j) {
        generated_file << node_identifier << GetNodeIndentifier(j)
                       << GenerateRandomCost() << "\n";
      }
    }
  }
}

std::string InstanceGenerator::GetNodeIndentifier(std::size_t index) const {
  std::size_t current_index = index + 65;
  return std::string{static_cast<char>(current_index)};
}

std::size_t InstanceGenerator::GenerateRandomCost() const {
  std::srand(std::time(nullptr));
  return std::rand() % 100 + 1;
}

}  // namespace daa
