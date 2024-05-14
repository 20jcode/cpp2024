
#include <iostream>
using namespace std;

float myFunc(int n){

    if(n==0){
        return 1;
    } else {
        n = n-1;

        return 1+1/myFunc(n);
    }

}

int main(){
    int n;
    cin>>n;
    cout<<fixed;
    cout.precision(5);

    cout<<myFunc(n);
}