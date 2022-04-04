#ifndef P6TSP_TSP_ALGORITHMS_UNKNOWN_TSP_ALGOPITHM_EXCEPTION_H_
#define P6TSP_TSP_ALGORITHMS_UNKNOWN_TSP_ALGOPITHM_EXCEPTION_H_

#include <exception>

namespace daa {

class UnknownTspAlgorithmException : public std::exception {
 public:
  const char* what() const noexcept override;
};

}  // namespace daa

#endif  // P6TSP_TSP_ALGORITHMS_UNKNOWN_TSP_ALGOPITHM_EXCEPTION_H_