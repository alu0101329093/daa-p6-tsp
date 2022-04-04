#include "utils.h"

namespace daa {

std::size_t NumberSummatory(std::size_t starting_number) {
  std::size_t sum{};
  for (std::size_t i = starting_number; i > 0; --i) sum += i;
  return sum;
}

}  // namespace daa
