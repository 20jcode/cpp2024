#include <stdio.h>
#include "cstdlib"

using namespace std;
//연산자를 앞에 쓰냐 뒤에 쓰냐에 주의해서 하자!

int funcBsearch(int* arr,int n){
    int ans = 0;
    if(*arr==n){
        return 0;
    } else {
        ans += funcBsearch(++arr,n);
        return ans+1;
    }
}

int main()
{
    int intValues[]={10, 20, 21, 25, 54, 58, 60, 66, 87, 99};
    int i,key;
    int N=10;
    /*
    printf("Input Key Values: ");
    scanf("%d", &key);
    for(i=0;i<N;i++)
        if(key==intValues[i]) {
            printf("Found: index is %d\n",i);
            exit(0);
        }
    */

    printf("%d",funcBsearch(intValues,66));
    exit(0);

}
