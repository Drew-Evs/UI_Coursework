// COMP2811 Coursework 1: quaketool application
#include <vector>
#include <stdexcept>
#include "dataset.cpp"
#include "quake.cpp"

using namespace std;

int main(int argc, char* argv[])
{
  if (argc == 2) {
    string input = argv[1];
    //outputs all the different commands that can be used
    if (!input.compare("help")) {
      cout << "Enter with filesize to get data e.g # of files" << endl;
      cout << "Enter with table to output all of the quake info in a table" << endl;
      cout << "Enter with a magnitude to get only details above a certain magnitude" << endl;
    } else {
      QuakeDataset data = QuakeDataset(argv[1]);
      cout << "Number files read: " << data.size() << endl;
      Quake x = data.strongest();
      cout << "For strongest: Time: " << x.getTime() << " Lat: " << x.getLatitude() << " Long: " << 
      x.getLongitude() << " Depth: " << x.getDepth() << " Mag: " << x.getMagnitude() << endl;
      Quake y = data.shallowest();
      cout << "For shallowest: Time: " << y.getTime() << " Lat: " << y.getLatitude() << " Long: " << 
      y.getLongitude() << " Depth: " << y.getDepth() << " Mag: " << y.getMagnitude() << endl;
      cout << "Mean depth: " << data.meanDepth() << endl;
      cout << "Mean magnitude: " << data.meanMagnitude() << endl;
    }
  }
  return 0;
}
