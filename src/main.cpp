#include <iostream>
#include <string>
#include "robots_vs_lasers.h"

int main()
{
  int lineCount = 0;
  std::string line;
  std::string northLasers;
  std::string conveyorBelt;
  std::string southLasers;

  while (getline(std::cin, line)) {
    if (line.empty()) {
      RobotsVsLasers rvl (northLasers, conveyorBelt, southLasers);
      std::cout << rvl.go() + "\n";
      lineCount = 0;
    } else {
      switch (lineCount) {
        case NORTH_LASERS:
          northLasers = line;
        break;
        case CONVEYOR_BELT:
          conveyorBelt = line;
        break;
        case SOUTH_LASERS:
          southLasers = line;
        break;
      }
      lineCount++;
    }
  }
  return 0;
}
