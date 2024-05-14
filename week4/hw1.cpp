//
// Created by leeyoungjun on 4/2/24.
//
#include "iostream"
using namespace std;

class Complex {
private:
    float real;
    float im;
public:
    Complex();
    Complex(const Complex &);
    Complex operator+(Complex B);
    Complex operator+(float op);
    Complex operator*(Complex B);
    Complex operator*(float op);
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, Complex&);


};
ostream& operator<<(ostream& os, const Complex& p){
    os<<p.real<<' '<<p.im<<endl;
    return os;
}

istream& operator>>(istream& is,Complex& p){
    is>>p.real>>p.im;
    return is;
}
Complex::Complex(const Complex & rhs){
    this->real = rhs.real;
    this->im = rhs.im;

}

Complex::Complex(){
    this->real = 0;
    this->im = 0;
}

Complex Complex::operator+(Complex op){
    Complex temp;
    temp.real = real+op.real;
    temp.im = im +op.im;

    return temp;
}

Complex Complex::operator+(float op){
    Complex temp;
    temp.real = real + op;
    temp.im = im;
    return temp;
}

Complex Complex::operator*(Complex B) {
    Complex temp;
    temp.real = real*B.real;
    temp.im = im*B.im;
    return temp;
}

Complex Complex::operator*(float op) {
    Complex temp;
    temp.real = real*op;
    temp.im = im*op;
    return temp;
}

int main(){
    Complex A,B,C;
    float D;
    cin>>A;
    cin>>B;
    cin>>D;

    C = A+B;
    cout<<C;
    C=A*B;
    cout<<C;
    C=C*D;
    cout<<C;
}