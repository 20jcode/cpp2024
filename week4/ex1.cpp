//
// Created by leeyoungjun on 3/28/24.
//
#include <iostream>

using namespace std;

class Point{
private:
    float x;
    float y;
public:
    Point();
    Point(const Point &);
    Point operator+(Point B);
    Point operator+(float op);
    friend ostream& operator<<(ostream&, const Point&);
    friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream& os, const Point& p){
    os<<p.x<<" "<<p.y<<"\n";
    return os;
}

istream& operator>>(istream& is,Point& p){
    is>>p.x>>p.y;
    return is;
}

Point::Point(const Point & rhs){
    this->x = rhs.x;
    this->y = rhs.y;

}

Point::Point(){
    this->x = 0;
    this->y = 0;
}

Point Point::operator+(Point op){
    Point temp;
    temp.x = x+op.x;
    temp.y = y +op.y;

    return temp;
}

Point Point::operator+(float op){
    Point temp;
    temp.x = x + op;
    temp.y = y + op;

    return temp;
}

int main(){
    Point A,B,C;
    float D;
    cin>>A;
    cin>>B;
    C=A+B;
    cout<<C;
    cin>>D;
    C=C+D;
    cout<<C;
}
