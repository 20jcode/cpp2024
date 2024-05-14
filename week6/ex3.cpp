//
// Created by leeyoungjun on 4/11/24.
//
#include <iostream>

using namespace std;

class Point{
private:
    float X,Y;
public:
    friend istream& operator>>(istream&, Point&);
    friend ostream& operator<<(ostream&, const Point&);
};

istream& operator>>(istream& is,Point& p){
    cout<<"input x = ";
    is>>p.X;
    cout<<"input y = ";
    is>>p.Y;
    return is;
}
ostream& operator<<(ostream& os,const Point& p){
    os<<"X= "<<p.X<<" , "<<"Y= "<<p.Y<<endl;
    return os;
}

int main(){
    Point p,q;
    cin>>p>>q;
    cout<<p<<q;
    return 0;
}