#include "ArgumentParser.h"

ArgumentParser::CommandLineArguments ArgumentParser::parse(int argc,
                                                           char *argv[]) {
  static struct option longOptions[] = {
      {"iteration-count", optional_argument, 0, 'i'},
      {"car-count", optional_argument, 0, 'c'},
      {"car-max-velocity", optional_argument, 0, 'v'},
      {"road-length", optional_argument, 0, 'r'},
      {"acceleration", optional_argument, 0, 'a'},
      {"level-of-aggressiveness", optional_argument, 0, 'l'},
      {"chance-to-slow-down", optional_argument, 0, 's'},
      {"debug", optional_argument, 0, 'd'},
      {"help", no_argument, 0, 'h'},
      {0, 0, 0, 0}};

  // initialize with default values
  CommandLineArguments args;

  int option;
  int optionIndex = 0;

  while ((option = getopt_long(argc, argv, "i:c:v:r:a:l:s:d:h", longOptions,
                               &optionIndex)) != -1) {
    switch (option) {
    case 'i':
      args.iterationCount =
          convertAndValidate<int>(optarg, "--iteration-count");
      break;
    case 'c':
      args.carCount = convertAndValidate<int>(optarg, "--car-count");
      break;
    case 'v':
      args.carMaxVelocity =
          convertAndValidate<int>(optarg, "--car-max-velocity");
      break;
    case 'r':
      args.roadLength = convertAndValidate<int>(optarg, "--road-length");
      break;
    case 'a':
      args.acceleration = convertAndValidate<int>(optarg, "--acceleration");
      break;
    case 'l':
      args.levelOfAggressiveness =
          convertAndValidate<int>(optarg, "--level-of-aggressiveness");
      break;
    case 's':
      args.chanceToSlowDown =
          convertAndValidate<int>(optarg, "--chance-to-slow-down");
      break;
    case 'd':
      args.debug = convertAndValidate<int>(optarg, "--debug") != 0;
      break;
    case 'h':
      printHelpAndExit(argv[0]);
      break;
    default:
      printHelpAndExit(argv[0]);
    }
  }

  return args;
}

void ArgumentParser::printHelpAndExit(const char *programName) {
  ArgumentParser::CommandLineArguments args;
  std::cerr
      << "Usage: " << programName << " [options]" << std::endl
      << "Options:" << std::endl
      << "  -i, --iteration-count      Number of iterations (default: "
      << args.iterationCount << ")" << std::endl
      << "  -c, --car-count            Number of cars (default: "
      << args.carCount << ")" << std::endl
      << "  -v, --car-max-velocity     Maximum velocity of cars (default: "
      << args.carMaxVelocity << ")" << std::endl
      << "  -r, --road-length          Length of the road (default: "
      << args.roadLength << ")" << std::endl
      << "  -a, --acceleration         Acceleration of cars (default: "
      << args.acceleration << ")" << std::endl
      << "  -l, --level-of-aggressiveness   Aggressiveness level (default: "
      << args.levelOfAggressiveness << ")" << std::endl
      << "  -s, --chance-to-slow-down  Chance for cars to slow down (default: "
      << args.chanceToSlowDown << ")" << std::endl
      << "  -d, --debug                Enable debugging (default: "
      << (args.debug ? "true" : "false") << ")" << std::endl
      << std::endl
      << "  -h, --help                 Display this help message" << std::endl;
  exit(EXIT_FAILURE);
}

template <typename T>
T ArgumentParser::convertAndValidate(const char *optarg,
                                     const char *optionName) {
  try {
    return std::stoi(optarg);
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: Invalid argument for " << optionName
              << ". Must be an integer." << std::endl;
    printHelpAndExit(optarg);
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: Out of range value for " << optionName << "."
              << std::endl;
    printHelpAndExit(optarg);
  }
  return 0; // unreachable
}
