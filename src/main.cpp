#include "simulation.h"

using namespace std;

int main () {
  Simulation sim("data/data");
  for (long t=0; t<=1; ++t) sim.step();
  return 0;
}