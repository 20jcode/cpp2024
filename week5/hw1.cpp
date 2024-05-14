//
// Created by leeyoungjun on 4/4/24.
//
#include <iostream>

using namespace std;

class Complex {
    int real;
    int im;
public:
    Complex(int r,int i){
        cout<<"Constructor "<<r<<" "<<i<<endl;
        real = r;
        im = i;
    };
    Complex(const Complex& tmp){
        real = tmp.real;
        im = tmp.im;
        cout<<"Copy"<<endl;
    };
    friend Complex operator+(const Complex& a,const Complex& b){
        Complex ans(a);
        ans.real += b.real;
        ans.im += b.im;
        cout<<"+ "<<ans.real<<" "<<ans.im<<endl;
        return ans;
    };
};

int main(){
    int x1;
    int y1;
    int x2;
    int y2;

    cin>>x1>>y1;
    cin>>x2>>y2;

    Complex C1(x1,y1);
    Complex C2(x2,y2);
    Complex Ans = C1+C2;
}