#include "main.h"

int main(int argc, char* argv[]) {
  std::string path{argv[1]};
  CheckGeneration(path);
  daa::TspSolver solver{};
  std::map<std::size_t, std::vector<FileSolutions>> solutions{};
  for (const auto& entry :
       std::filesystem::directory_iterator{std::filesystem::path{path}}) {
    std::string file_path{entry.path().string()};
    solver.LoadFile(file_path);
    FileSolutions file_solutions{file_path, solver.Solve()};
    std::cout << file_solutions.file_name << "\n";
    for (const auto& named_solution : file_solutions.named_solutions) {
      std::cout << named_solution.name << "\n";
      std::cout << "Path -> " << named_solution.solution.GetPath() << "\n";
      std::int64_t time = named_solution.solution.GetTime().count();
      std::cout << "Time -> " << time << " ms\n";
    }
    std::cout << "\n";
    solutions[solver.GetSize()].push_back(file_solutions);
  }
  ShowTable(solutions);
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
  std::cout << "Generation Finished\n";
}

void ShowTable(const std::map<std::size_t, std::vector<FileSolutions>>&
                   ordered_files_solutions) {
  std::cout << "Instancia\tValor Fuerza Bruta\tTiempo (ms)\tValor "
               "Voraz\tTiempo (ms)\n";
  for (const auto& ordered_solutions : ordered_files_solutions) {
    std::vector<std::size_t> cost_mean(2, 0);
    std::vector<std::chrono::milliseconds> time_mean(
        2, std::chrono::milliseconds{});
    for (std::size_t j = 0; j < ordered_solutions.second.size(); ++j) {
      auto files_solution = ordered_solutions.second[j];
      std::cout << files_solution.file_name << "(" << ordered_solutions.first
                << ")\t";
      std::size_t size = files_solution.named_solutions.size();
      for (std::size_t i = 0; i < size; ++i) {
        cost_mean[i] +=
            files_solution.named_solutions[i].solution.GetCost() / size;
        time_mean[i] +=
            files_solution.named_solutions[i].solution.GetTime() / size;
      }
      if (j != ordered_solutions.second.size() - 1) std::cout << "\n";
    }
    for (std::size_t i = 0; i < cost_mean.size(); ++i) {
      std::cout << cost_mean[i] << "\t";
      std::int64_t time =
          (time_mean[i] < daa::kAlgorithmMaxExecutionTime ? time_mean[i].count()
                                                          : -1);
      if (time == -1)
        std::cout << "10 min\t";
      else
        std::cout << time << " ms\t";
    }
    std::cout << "\n";
  }
}