//
// Created by leeyoungjun on 4/11/24.
//
#include <iostream>
using namespace std;

class Point{
private:
    float X; float Y;
public:
  void printPoint() { cout << "("<<X<<", "<<Y<<")\n"; }
  void inputPoint(float a, float b) {X=a;Y=b;}
};
class Location{
private:
    Point loc;
public:
    Point getLoc(){
        return loc;
    }
    void printLocation(){
        loc.printPoint();
    }
};


int main(){
    Location myLocation;
    (myLocation.getLoc()).inputPoint(1.0,2.0);
    myLocation.printLocation();
    return 0;}