// COMP2811 Coursework 1: QuakeDataset class

#pragma once

#include <vector>
#include "quake.hpp"

class QuakeDataset
{
  public:
    // Specify prototypes or inlined methods here
    // (see UML diagram for what is required)
    QuakeDataset();
    QuakeDataset(const std::string& file) : filename(file) {}
    void loadData(std::string);
    int size() { return data.size(); }
    Quake operator[](int index) { return data.at(index) ; }
    Quake strongest();
    Quake shallowest();
    double meanDepth();
    double meanMagnitude();

  private:
    std::vector<Quake> data;
    std::string filename;
};
