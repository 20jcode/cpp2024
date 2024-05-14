//
// Created by leeyoungjun on 4/4/24.
//
#include <iostream>
using namespace std;

class ThreeDPoint {
     int x,y,z;
public:
    ThreeDPoint(){
        cout<<"No param"<<endl;
    }
    ThreeDPoint(int a, int b, int c){
        x=a;
        y=b;
        z=c;
        cout<<"yes params"<<endl;
    }
    ThreeDPoint(const ThreeDPoint& dp){
        ThreeDPoint(dp.x,dp.y,dp.z);
    }

// 1. class
    void setX(int a);
    void setY(int b);
    void setZ(int c);

// 2. function overloading
  void setValues() {cout<<"0\n"; x=y=z=0;}
  // void setValues(int a=0, int b=0, int c=0) { cout<<"1\n"; x=a; y=b; z=c;}
  void setValues(int& m) {x=y=z=m++;}
//  void setValues(int a) {x=y=z=a;}
  void setValues(float a) {x=y=z=(int)a;}
  void printout() { cout << "(" << x << ", " << y << ", " << z << ")\n"; }
  int volume();
};

void ThreeDPoint::setX(int a) { x = a; }
void ThreeDPoint::setY(int b) { y = b; }
void ThreeDPoint::setZ(int c) { z = c; }

int ThreeDPoint::volume() {
	int result = x * y * z;
	return result;
}

int functionA(ThreeDPoint dp){
    dp.printout();
}

int main() {
	ThreeDPoint	myDimension;
	int	vol;
    //ThreeDPoint yourDimension(1);

// 1. class
	myDimension.setX(7);
	myDimension.setY(16);
	myDimension.setZ(21);

// 2. function overloading
	float v=18.5;
	myDimension.setValues(v);
	vol = myDimension.volume();

	myDimension.printout();


    functionA(myDimension);

	return 0;
}
