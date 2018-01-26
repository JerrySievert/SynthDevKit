#pragma once

#include <stdint.h>
#include <vector>

#include "Clock.hpp"

namespace SynthDevKit {
  class PrimeClock : Clock {
    public:
      PrimeClock (uint16_t, float);
      bool *update (float);
      std::vector<uint16_t> primes;
    private:
      void generatePrimes (uint16_t);
  };
}
