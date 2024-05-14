//
// Created by leeyoungjun on 4/11/24.
//
#include <iostream>
using namespace std;

class Point{
private:
    float X; float Y;

public:
    Point();
    Point(float a): X(a),Y(a) {};
    Point(float a, float b):X(a),Y(b) {};
    Point(const Point& a);
    void printValues(){
      cout << "("<<X<<","<<Y<<")\n";
    }
    friend Point operator+(Point&,Point&);

//  Point operator+(Point& b){
//      X = X+b.X;
//      Y = Y+b.Y;
//  };
};
//ㅇㅚ부로 빼내기?

Point operator+(Point& a,Point& b){
   Point temp;
   temp.X = a.X+b.X;
   temp.Y = a.Y+b.Y;
   return temp;
}

int main(){
    Point myPoint(1.0);
    Point yourPoint(2.0);
    (myPoint+yourPoint).printValues();
    return 0;
}