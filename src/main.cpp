/*
* Project: IMS 2023/2024 CA in traffic
* Authors: Jiří Štípek (xstipe02) and Štefan Pekník (xpekni01)
*/

#include "ArgumentParser.h"
#include "Simulation.h"

int main(int argc, char *argv[]) {
  auto args = ArgumentParser::parse(argc, argv);

  Simulation::SimulationParams params;
  params.iterationCount = args.iterationCount;
  params.carCount = args.carCount;
  params.carMaxVelocity = args.carMaxVelocity;
  params.roadLength = args.roadLength;
  params.acceleration = args.acceleration;
  params.levelOfAggressiveness = args.levelOfAggressiveness;
  params.chanceToSlowDown = args.chanceToSlowDown;
  params.debug = args.debug;

  Simulation simulation(params);
  simulation.run();

  return 0;
}
