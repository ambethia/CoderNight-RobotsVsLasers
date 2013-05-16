#include "decommissionator.h"

using namespace std;

enum
{
  EAST,
  WEST
};

Decommissionator::Decommissionator(bitset<MAX_LASERS> northLasers, bitset<MAX_LASERS> southLasers, int positionOfEntry)
{
  this->northLasers = northLasers;
  this->southLasers = southLasers;
  this->positionOfEntry = positionOfEntry;
}

Decommissionator::~Decommissionator()
{
  // Nothing to do here? All resources are on the stack.
}

string Decommissionator::annihilate()
{
  bitset<MAX_LASERS> northWesternLasers = northLasers << MAX_LASERS - positionOfEntry - 1;
  bitset<MAX_LASERS> southWesternLasers = southLasers << MAX_LASERS - positionOfEntry - 1;
  bitset<MAX_LASERS> northEasternLasers = northLasers >> positionOfEntry;
  bitset<MAX_LASERS> southEasternLasers = southLasers >> positionOfEntry;

  string maskOneString;
  for (int i = 0; i < MAX_LASERS / 2; i++) {
    maskOneString += "01";
  }
  bitset<MAX_LASERS> maskOne (maskOneString);

  string maskTwoString;
  for (int i = 0; i < MAX_LASERS / 2; i++) {
    maskTwoString += "10";
  }
  bitset<MAX_LASERS> maskTwo (maskTwoString);

  northWesternLasers &= maskTwo;
  southWesternLasers &= maskOne;

  northEasternLasers &= maskOne;
  southEasternLasers &= maskTwo;

  int northWesternHits = northWesternLasers.count();
  int southWesternHits = southWesternLasers.count();
  int northEasternHits = northEasternLasers.count();
  int southEasternHits = southEasternLasers.count();

  // printf("nw%d sw:%d ne%d se:%d\n", northWesternHits, southWesternHits, northEasternHits, southEasternHits);

  // printf("nwl %s\n", northWesternLasers.to_string().c_str());
  // printf("swl %s\n", southWesternLasers.to_string().c_str());
  // printf("nel %s\n", northEasternLasers.to_string().c_str());
  // printf("sel %s\n", southEasternLasers.to_string().c_str());

  // printf("nl  %s\n", northLasers.to_string().c_str());
  // printf("sl  %s\n", southLasers.to_string().c_str());

  // printf("%d\n", simulateLasers(1));

  if (northEasternHits + southEasternHits < northWesternHits + southWesternHits)
  {
    return "GO EAST";
  } else {
    return "GO WEST";
  }
  // return "GO ? " + northLasers.to_string(); // + '\n' + northWesternLasers.to_string();
}

int Decommissionator::simulateLasers(int direction)
{
  return direction ? 7 : 8;
}
