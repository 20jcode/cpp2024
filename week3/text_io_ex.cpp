//
// Created by leeyoungjun on 3/19/24.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char msg[100];

    fp=fopen("abc.txt","w");

    if(fp==nullptr) { //null is not open, "NULL"
        printf("File open error\n");
        exit(1);
    }

    fprintf(fp, "%s", "text testasdfasdfasdf");
    //printf("%s", msg);
    fclose(fp);
    return 0;
}
