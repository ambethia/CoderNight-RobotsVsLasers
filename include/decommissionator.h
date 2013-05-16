#include <bitset>

#define MAX_LASERS 256

using namespace std;

class Decommissionator
{
  public:
    Decommissionator(bitset<MAX_LASERS> northLasers, bitset<MAX_LASERS> southLasers, int positionOfEntry);
    ~Decommissionator();
    string annihilate();
  private:
    bitset<MAX_LASERS> northLasers;
    bitset<MAX_LASERS> southLasers;
    int positionOfEntry;
    int simulateLasers(int direction);
};
