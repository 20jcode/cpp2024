#include "iostream"

using namespace std;

int goto_ij(int* p,int k,int i,int j){
    return *(p+i*(k)+j);
}
int main(){
    int n,m;
    cin>>n>>m;

    int max = 0;
    int max_i = 0;
    int max_j = 0;
    int* parr;


    parr = (int *)malloc(sizeof(int)*n*m);


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>*(parr+i*(m)+j);
        }
    }
    // -1,-1 / -1,0 / 0,-1 / 1,0 / 0,1 / 1,1 / -1,1 / 1,-1 /
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int buf = 0;

            if(i>0){
                buf += goto_ij(parr,m,i-1,j);
            }
            if(j>0){
                buf += goto_ij(parr,m,i,j-1);
            }
            if(i<n-1){
                buf += goto_ij(parr,m,i+1,j);
            }
            if(j<m-1){
                buf += goto_ij(parr,m,i,j+1);
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