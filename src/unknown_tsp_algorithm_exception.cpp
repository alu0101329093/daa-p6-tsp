#include "tsp_algorithms/unknown_tsp_algorithm_exception.h"

namespace daa {

const char* UnknownTspAlgorithmException::what() const noexcept {
  return "Unknown Tsp algorithm found";
}

}  // namespace daa
