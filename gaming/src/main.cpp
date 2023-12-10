// #include "ArgumentParser.h"

#include "Simulation.h"

int main(int argc, char *argv[]) {
  // auto args = ArgumentParser::parse(argc, argv);

  Simulation::SimulationParams params;
  // params.iterationCount = args.iterationCount;
  // params.carCount = args.carCount;
  // params.carMaxVelocity = args.carMaxVelocity;
  // params.roadLength = args.roadLength;
  // params.acceleration = args.acceleration;
  // params.levelOfAggressiveness = args.levelOfAggressiveness;
  // params.chanceToSlowDown = args.chanceToSlowDown;
  // params.debug = args.debug;
  params.iterationCount = 1000;
  params.carCount = 5;
  params.carMaxVelocity = 5;
  params.roadLength = 1000;
  params.acceleration = 1;
  params.levelOfAggressiveness = 0;
  params.chanceToSlowDown = 0.3;
  params.debug = true;

  Simulation simulation(params);
  simulation.run();

  return 0;
}
