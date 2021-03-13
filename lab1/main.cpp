#include <iostream>
#include <vector>

#include "interfaces/Shape.h"
#include "classes/Trapezoid.h"
#include "classes/RegularPolygon.h"
#include "classes/Polygon.h"
#include "classes/Triangle.h"

using namespace geometry;
using namespace std;

vector<Shape*> create_shapes();

int main() {
    vector<Shape*> shapes = create_shapes();
    for (auto shape: shapes) {
        cout << "Area: " << shape->getArea() << endl;
        cout << "Perimeter: " << shape->getPerimeter() << endl;
    }
    return 0;
}

vector<Shape*> create_shapes() {
    vector<Shape*> shapes;
    shapes.push_back(new Trapezoid(2, 5, 2, 3));
    shapes.push_back(new RegularPolygon(10, 5));
    shapes.push_back(new Polygon(
            {new Point(0, 0), new Point(0, 3),
                   new Point(3, 3), new Point(3, 0)}
                    ));
    shapes.push_back(new Triangle(12, 5, 13));
    return shapes;
}