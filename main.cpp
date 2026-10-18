#include <iostream>
#include "functs.hpp"

int main() {
    int WIDTH;
    int HEIGHT;
    
    // Задаем размер изображения
    std::cout << "Enter image size: WIDTH HEIGHT" << std::endl;
    std::cin >> WIDTH >> HEIGHT;

    // Создаем вектор размера HEIGHT x WIDTH для пикселей
    std::vector<std::vector<RGB>> Image(HEIGHT, std::vector<RGB>(WIDTH));

    // Задаем количество вершин
    int VertexCount;
    std::cout << "Enter vertex count: VertexCount" << std::endl;
    std::cin >> VertexCount;

    std::vector<Point> points;
    points.reserve(VertexCount);

    // Задаем все вершины
    for (int i = 1; i <= VertexCount; ++i) {
        int x, y;
        std::cout << "Enter vertex number " << i << ": x y" << std::endl;
        std::cin >> x >> y;
        points.emplace_back(x,y);
    }

    // Отрисовываем многоугольник с помощью алгоритма Брезенхема
    drawPolygon(Image, points, {0,0,0});

    // Задаем затравочную вершину
    Point SeedVertex;
    {
        int x, y;
        std::cout << "Enter seed vertex: x y" << std::endl;
        std::cin >> x >> y;
        SeedVertex = Point{x,y};        
    }

    // Задаем цвет заполнения
    RGB fillColor;
    {
        int r, g, b;
        std::cout << "Enter fill color: red green blue" << std::endl;
        std::cin >> r >> g >> b;
        fillColor = RGB(static_cast<uint8_t>(b), 
                        static_cast<uint8_t>(g),
                        static_cast<uint8_t>(r));
    }

    // Производим закраску многоугольника и записываем результат в файл
    waveFill(Image, SeedVertex, fillColor);
    saveBMP(Image, "result.bmp");
    
    return 0;
}
