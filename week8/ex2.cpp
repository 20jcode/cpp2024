//
// Created by leeyoungjun on 5/2/24.
//
#include <iostream> 
#include <cstring> 
using namespace std; 
 
class Shape {
private:
    int mytest;

public:
  double width;
  double height;

  void display() {
    cout << "Width and height are " << width << " and " << height << "\n";
  }
};

// Triangle is derived from Shape.
class Triangle : private Shape {
public:
  char style[20];

  double area() {
    return width * height / 2;
  }

  void showStyle() {
    cout << "Triangle is " << style << "\n";
  }
};

int main() {
  Triangle t1;
  Triangle t2;

  t1.width = 4.0;
  t1.height = 4.0;
  strcpy(t1.style, "isosceles");

  t2.width = 8.0;
  t2.height = 12.0;
  strcpy(t2.style, "right");

  t1.showStyle();
  t1.display();
  cout << "Area is " << t1.area() << "\n";

  t2.showStyle();
  t2.display();
  cout << "Area is " << t2.area() << "\n";

  return 0;
}