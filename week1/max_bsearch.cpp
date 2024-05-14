//
// Created by leeyoungjun on 3/7/24.
/*
 imax = max(a[i],arec(a,i-1);

*/
//
#include <iostream>

using namespace std;

int max_r(int start,int end,int* arr){
    int num1;
    int num2;
    if(start>=end){
        return *(arr+(start+end)/2+1);
    } else {
        num1=max_r(start,(start+end)/2,arr);
        num2=max_r((start+end)/2+1,end,arr);
        if(num1>=num2){
            return num1;
        } else {
            return num2;
        }
    }
}

int max_find(int n,int* arr){
    int start = 0;
    int end = n;
    return max_r(start,end,arr);
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<max_find(n,arr);
}