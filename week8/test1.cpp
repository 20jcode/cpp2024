//
// Created by leeyoungjun on 5/2/24.
//
#include <iostream>
using namespace std;

class Fish {
public :
    int mari;
};

class Tuna : public Fish {
public :
    int chaci;
};

int myfunc(Fish *f){
    Tuna *t = static_cast<Tuna *>(f);
    return t->chaci;
}

int main(){
    Tuna t;
    t.chaci = 2;
    Fish* f = &t;
    cout<<myfunc(f);
}