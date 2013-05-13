#include <string>

enum
{
  NORTH_LASERS,
  CONVEYOR_BELT,
  SOUTH_LASERS
};

class RobotsVsLasers
{
  public:
    RobotsVsLasers(std::string northLasers, std::string conveyorBelt, std::string southLasers);
    ~RobotsVsLasers();
    std::string go();
  private:
    std::string northLasers;
    std::string conveyorBelt;
    std::string southLasers;
};
