# IMS

A project to simulate how drivers who have higher acceleration and deceleration are more likely to contribute to the ongoing traffic jam instead of the traffic jam being slowly dismissed.

## Usage

```./simulation [options]```

Options:

  - `-i`, `--iteration-count` - Number of iterations (default: 1000)
  - `-c`, `--car-count` - Number of cars (default: 20)
  - `-v`, `--car-max-velocity` - Maximum velocity of cars (default: 135)
  - `-r`, `--road-length` - Length of the road (default: 1000)
  - `-a`, `--acceleration` - Acceleration of cars (default: 11)
  - `-l`, `--level-of-aggressiveness` - Aggressiveness level (default: 0)
  - `-s`, `--chance-to-slow-down` - Chance for cars to slow down (default: 15)
  - `-d`, `--debug` - Enable debugging (default: false)
  - `-h`, `--help` - Display this help message