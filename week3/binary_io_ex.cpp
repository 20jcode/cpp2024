//
// Created by leeyoungjun on 3/19/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//text데이터를 읽어서 binary로 write 하는 것이다.

int main()
{
    FILE *fp;
    int a[10];
    int nbytes;
    int fd;

    fp=fopen("data.txt","r");
    if(fp==NULL) {
        printf("data.txt File Open Error\n");
        exit(1);
    }

    fd=open("data.bin",O_WRONLY|O_CREAT); //없으면 새로 만들어라라는 것. 비트 or 연산
    if(fd==-1) {
        printf("data.bin File Open Error\n");
        exit(1);
    }

    while(fscanf(fp,"%d %d %d %d %d %d %d %d %d %d",
           &a[0],&a[1],&a[2],&a[3],&a[4],
           &a[5],&a[6],&a[7],&a[8],&a[9])!=EOF) {

        for(int i=0;i<10;i++) {
            printf("%d ",a[i]);
            nbytes=write(fd,&a[i],sizeof(int));
            if(nbytes<sizeof(int)) {
                printf("Binary write error\n");
                exit(1);
            }
        }
        printf("\n");
    }

    fclose(fp);
    close(fd);
    return 0;
}
