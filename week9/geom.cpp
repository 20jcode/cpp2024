#include <iostream>
#define PI  3.14

using namespace std;

class Geom {
protected:
    int type;
public:
    enum {RECT, CIRCLE, SQUARE, POINT};
    Geom(int t): type(t) {}
    Geom() {}
    virtual float area()=0;
};

class Point: public Geom {
    float   a, b;
public:
    Point(float x, float y): Geom(POINT), a(x), b(y) {}
    Point() {}
    float   area() { return 0.0; }
    float geta(){return a;}
    float getb(){return b;}
};

class Circle: public Geom {
    Point   center;
    float   radius;
public:
    Circle(float x, float y, float r):
        Geom(CIRCLE), center(x,y), radius(r) {}
    Circle() {}
    float area() { return PI*radius*radius; }
};

class Rectangle: public Geom {
    Point   p1; // bottom left corner point
    Point   p2; // top right corner point
public:
    Rectangle(float, float, float, float );// implement it
    Rectangle() {}
    float area() {return (p2.geta()-p1.geta())*(p2.getb()-p1.getb());};
};

Rectangle::Rectangle(float x1, float y1, float x2, float y2) :
    Geom(RECT), p1(x1,y1),p2(x2,y2){}


class Square: public Geom {
    Point   p;    // bottom left corner point
    float   side; // side length
public:
    Square();
    Square(float x,float y,float s) : Geom(SQUARE),p(x,y),side(s){}
    float area() {
        return side*side;
    }
    // implement here
};


int main()
{
    int     numGeom;
    cin>> numGeom;
    Geom    *geom;
    string s;
    float n1;
    float n2;
    float n3;
    float n4;

    for(int i=0;i<numGeom;i++) {

        // complete here
        cin>>s;
        if(s == "R"){
            cin>>n1>>n2>>n3>>n4;
            geom = new Rectangle(n1,n2,n3,n4);
        }
        if(s == "S"){
            cin>>n1>>n2>>n3;
            geom = new Square(n1,n2,n3);
        }
        if(s == "P"){
            cin>>n1>>n2;
            geom = new Point(n1,n2);
        }
        if(s== "C"){
            cin>>n1>>n2>>n3;
            geom = new Circle(n1,n2,n3);
        }

        cout<<geom->area()<<endl;
        delete geom;

    }

    return 0;
}
