#include <stdio.h>
#include <stdlib.h>

int maxValue(int length,int* arr){
    int max = 0;
    length--;
    if(max<*arr){
        max = *arr;
    }
    if(length !=0){
        max = maxValue(length,++arr);
    }
    return max;
}


int main()
{
    int intValues[]={10, 20, 21, 25, 54, 58, 60, 66, 87, 99};
    int v;
    int N=10;

    v=maxValue(10, intValues);
    printf("Max Value= %d\n",v);
    exit(0);
}
