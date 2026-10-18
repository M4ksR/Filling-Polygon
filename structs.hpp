#include <cstdint>

struct RGB {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    
    RGB(uint8_t b = 255, uint8_t g = 255, uint8_t r = 255) :
                                blue(b), green(g), red(r) {} 

    bool operator==(RGB p) {
        return blue == p.blue && green == p.green && red == p.red;
    }
};

struct Point {
    int x;
    int y;
    Point(int cordX = 0, int cordY = 0) : x(cordX), y(cordY) {}
};
