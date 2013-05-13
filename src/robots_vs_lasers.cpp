#include "robots_vs_lasers.h"

RobotsVsLasers::RobotsVsLasers(std::string northLasers, std::string conveyorBelt, std::string southLasers)
{
  this->northLasers = northLasers;
  this->conveyorBelt = conveyorBelt;
  this->southLasers = southLasers;
}

RobotsVsLasers::~RobotsVsLasers()
{
  // Nothing to do here?
}

std::string RobotsVsLasers::go()
{
  return "GO!";
}
