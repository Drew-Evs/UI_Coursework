// COMP2811 Coursework 1: QuakeDataset class
#include <vector>
#include "dataset.hpp"
#include "csv.hpp"

QuakeDataset::QuakeDataset() {}

void QuakeDataset::loadData(std::string filename) {
    csv::CSVReader reader(filename);

    for (auto& row: reader) {
        std::string time = row["A"].get<>();
        double lat = row["B"].get<double>();
        double lon = row["C"].get<double>();
        double depth = row["D"].get<double>();
        double mag = row["E"].get<double>();
        Quake temp(time,lat,lon,depth,mag);
        data.push_back(temp);
    }
}

Quake QuakeDataset::strongest() {
    return Quake("Test",1,1,1,1);
}

Quake QuakeDataset::shallowest() {
    return Quake("Test",1,1,1,1);
}

double QuakeDataset::meanDepth() {
    return 0;
}

double QuakeDataset::meanMagnitude() {
    return 0;
}
