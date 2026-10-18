#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

#include "structs.hpp"

void setPixel(std::vector<std::vector<RGB>>&, int, int, RGB);

void drawLine(std::vector<std::vector<RGB>>&, Point, Point, RGB);

void drawPolygon(std::vector<std::vector<RGB>>&,
                std::vector<Point>&, 
                RGB);

void waveFill(std::vector<std::vector<RGB>>&, Point, RGB);

void writeLittleEndian(std::ofstream&, uint32_t, int);

void saveBMP(const std::vector<std::vector<RGB>>&, const std::string&);
