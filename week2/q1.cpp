//
// Created by leeyoungjun on 3/14/24.
// using pointer

#include "iostream"

using namespace std;

int goto_ij(int* p,int k,int i,int j){

    return *(p+i*k+j);
}
int main(){
    int k;
    cin>>k;
    int max = 0;
    int max_i = 0;
    int max_j = 0;
    int* parr;


    parr = (int *)malloc(sizeof(int) * k*k);


    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cin>>*(parr+i*k+j);
        }
    }
    // -1,-1 / -1,0 / 0,-1 / 1,0 / 0,1 / 1,1 / -1,1 / 1,-1 /
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            int buf = 0;
            if(i>0 and j>0){
                buf += goto_ij(parr,k,i-1,j-1);
            }
            if(i>0){
                buf += goto_ij(parr,k,i-1,j);
            }
            if(j>0){
                buf += goto_ij(parr,k,i,j-1);
            }
            if(i<k){
                buf += goto_ij(parr,k,i+1,j);
            }
            if(j<k){
                buf += goto_ij(parr,k,i,j+1);
            }
            if(i<k and j<k){
                buf += goto_ij(parr,k,i+1,j+1);
            }
            if(i>0 and j<k){
                buf += goto_ij(parr,k,i-1,j+1);
            }
            if(i<k and j>0){
                buf += goto_ij(parr,k,i+1,j-1);
            }

            if(max<buf){
                max = buf;
                max_i = i;
                max_j = j;
            }
        }
    }

    cout<<max_i+1<<" "<<max_j+1<<endl;

    free(parr);
}