#pragma once

#include <cstdlib>
#include <getopt.h>
#include <iostream>
#include <stdexcept>

/**
 * Parses command line arguments.
 */
class ArgumentParser {
public:
  /**
   * Parsed command line arguments.
   */
  struct CommandLineArguments {
    // TODO
    int iterationCount = 1000;
    int carCount = 20;
    int carMaxVelocity = 38; // 38 m/s ~= 136.8 km/h
    int roadLength = 500;    // 500 m = 0.5 km
    int acceleration = 3;    // 3 m/s^2 ~= 10.8 km/h^2
    int levelOfAggressiveness = 0;
    double chanceToSlowDown = 15; // 15%
    bool debug = false;
  };

  /**
   * Parses command line arguments.
   *
   * @param argc number of command line arguments
   * @param argv command line arguments
   * @return parsed command line arguments
   */
  static CommandLineArguments parse(int argc, char *argv[]);

private:
  /**
   * Prints help message and exits.
   *
   * @param programName name of the program
   */
  static void printHelpAndExit(const char *programName);

  /**
   * Converts command line argument to specified type and validates it.
   *
   * @tparam T type to convert to
   * @param optarg command line argument
   * @param optionName name of the option
   * @return converted and validated value
   */
  template <typename T>
  static T convertAndValidate(const char *optarg, const char *optionName);
};
