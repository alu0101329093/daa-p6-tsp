#ifndef P6TSP_MAIN_H_
#define P6TSP_MAIN_H_

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "instance_generator/instance_generator.h"
#include "tsp_solver/tsp_solver.h"

struct FileSolutions {
  std::string file_name;
  std::vector<daa::NamedTspSolution> named_solutions;
};

void CheckGeneration(const std::string& path);

int main(int argc, char* argv[]);

#endif  // P6TSP_MAIN_H_