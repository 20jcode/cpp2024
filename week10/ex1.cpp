//
// Created by leeyoungjun on 5/14/24.
//
#include <iostream>
using namespace std;

template<class T>
class MyCl{
private:
    T x;
    T y;
public:
    MyCl(T a,T b){
        x = a;
        y = b;
    }
    friend ostream& operator<<(ostream& os, MyCl<T>& t)

    {
        os<<"love"<<t.x<<t.y<<endl;
        return os;
    }

};
//link error

template<typename T>
ostream& operator<<(ostream& os, MyCl<T>& t){
    os<<"love"<<t.x<<t.y<<endl;
    return os;
}

/*
ostream & operator<<(ostream& os,MyCl<int>& t){
    os<<"love"<<t.x<<t.y<<endl;
    return os;
}
*/

int main()
{
    MyCl<int> mm = MyCl<int>(2,3);
    cout<<mm;
    return 0;
}