#include <vector>
#include "PrimeClock.hpp"

namespace SynthDevKit {
  PrimeClock::PrimeClock (uint16_t count, float threshold) : Clock(count, threshold){

    // generate the prime numbers for up to CLOCK_LIMIT
    generatePrimes(count);
  }

  bool *PrimeClock::update (float input) {
    cv->update(input);

    // only become ready after the first trigger has occurred.  this allows for
    // an interval to be set up
    if (!ready) {
      if (cv->newTrigger()) {
        ready = true;
      }

      return states;
    }

    current++;

    if (cv->newTrigger()) {
      step++;
      current = 0;

      for (uint16_t i = 0; i < triggerCount; i++) {
        states[i] = (step == primes[i]) ? true : false;
      }
    } else if (current >= cv->triggerInterval() / 2) {
      for (uint16_t i = 0; i < triggerCount; i++) {
        states[i] = false;
      }
    }

    if (step >= primes[triggerCount - 1]) {
      step = 0;
    }

    return states;
  }

  void PrimeClock::generatePrimes (uint16_t count) {
    primes.push_back(2);
    primes.push_back(3);
    for (uint16_t i = 3; i < CLOCK_LIMIT && primes.size() < count; i++) {
      bool prime = true;

      for (uint16_t j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++) {
        if (i % primes[j] == 0) {
          prime = false;
          break;
        }

        if (prime) {
          primes.push_back(i);
        }
      }
    }
  }
}
