// COMP2811 Coursework 1: QuakeDataset class
#include <vector>
#include <stdexcept>
#include "dataset.hpp"
#include "csv.hpp"

QuakeDataset::QuakeDataset() {}

void QuakeDataset::loadData(const std::string& file) {
    csv::CSVReader reader(file);

    for (auto& row: reader) {
        std::string time = row["time"].get<std::string>(); 
        double lat = row["latitude"].get<double>();
        double lon = row["longitude"].get<double>();
        double depth = row["depth"].get<double>();
        double mag = row["mag"].get<double>();

        Quake temp(time, lat, lon, depth, mag);
        data.push_back(temp);
    }
}

Quake QuakeDataset::strongest() {
    if (data.size() != 0) {
        Quake strong_quake = data[0];
        double strongest = 0;
        for (int i=0; i<data.size(); i++) {
            if (strongest < data[i].getMagnitude()) {
                strongest = data[i].getMagnitude();
                strong_quake = data[i];
            }
        }
        return strong_quake;
    } else {
        throw std::invalid_argument("Empty dataset");
    }
}

Quake QuakeDataset::shallowest() {
   if (data.size() != 0) {
        Quake shallow_quake = data[0];
        double shallow = data[0].getDepth();
        for (int i=0; i<data.size(); i++) {
            if (shallow > data[i].getDepth()) {
                shallow = data[i].getDepth();
                shallow_quake = data[i];
            }
        }
        return shallow_quake;
    } else {
        throw std::invalid_argument("Empty dataset");
    }
}

double QuakeDataset::meanDepth() {
    if (data.size() != 0) {
        double mean = 0;
        for (int i=0; i<data.size(); i++) {
            mean = mean + data[i].getDepth();
        }
        mean = mean/data.size();
        return mean;
    } else {
        throw std::invalid_argument("Empty dataset");
    }
}


double QuakeDataset::meanMagnitude() {
    if (data.size() != 0) {
        double mean = 0;
        for (int i=0; i<data.size(); i++) {
            mean = mean + data[i].getMagnitude();
        }
        mean = mean/data.size();
        return mean;
    } else {
        throw std::invalid_argument("Empty dataset");
    }
}

