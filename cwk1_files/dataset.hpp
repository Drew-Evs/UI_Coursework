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
    QuakeDataset(const std::string& file) { loadData(file); }
    void loadData(const std::string&);
    int size() const { return data.size(); }
    Quake operator[](int index) { return data.at(index) ; }
    Quake strongest();
    Quake shallowest();
    double meanDepth();
    double meanMagnitude();

  private:
    std::vector<Quake> data;
};
