#include <stdio.h>
#include <stdlib.h>

int sum(int n){
    if(n>0){
        return n+sum(n-1);
    } else {
        return 0;
    }

}

int main()
{
    int n = 10;

    printf("Sum= %d\n", sum(n));
    return 0;
}
