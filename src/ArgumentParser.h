#pragma once

#include <cstdlib>
#include <getopt.h>
#include <iostream>
#include <stdexcept>

class ArgumentParser {
public:
  struct CommandLineArguments {
    // TODO
    int iterationCount = 1000;
    int carCount = 20;
    int carMaxVelocity = 135;      // 135 km/h
    int roadLength = 1000;         // 1 km
    int acceleration = 11;         // 11 km/h^2
    int levelOfAggressiveness = 0; // 0%
    double chanceToSlowDown = 15;  // 15%
    bool debug = false;
  };

  static CommandLineArguments parse(int argc, char *argv[]);

private:
  static void printHelpAndExit(const char *programName);

  template <typename T>
  static T convertAndValidate(const char *optarg, const char *optionName);
};
