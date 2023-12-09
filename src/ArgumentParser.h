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
    int carMaxVelocity = 135;      // 135 km/h
    int roadLength = 1000;         // 1 km
    int acceleration = 11;         // 11 km/h^2
    int levelOfAggressiveness = 0; // 0%
    double chanceToSlowDown = 15;  // 15%
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
