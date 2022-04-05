#include "main.h"

int main(int argc, char* argv[]) {
  std::string path{argv[1]};
  CheckGeneration(path);
  daa::TspSolver solver{};
  std::vector<FileSolutions> solutions{};
  for (const auto& entry :
       std::filesystem::directory_iterator{std::filesystem::path{path}}) {
    std::string file_path{entry.path().string()};
    solver.LoadFile(file_path);
    solutions.push_back(FileSolutions{file_path, solver.Solve()});
  }
  return EXIT_SUCCESS;
}

void CheckGeneration(const std::string& path) {
  std::size_t files_amount{};
  std::cout << "File amount to generate: ";
  std::cin >> files_amount;
  if (files_amount > 0) {
    std::size_t nodes_amount{};
    std::cout << "Nodes amount: ";
    std::cin >> nodes_amount;
    daa::InstanceGenerator generator{};
    generator.GenerateInstaces(nodes_amount, files_amount, path);
  }
}