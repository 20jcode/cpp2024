//
// Created by leeyoungjun on 3/27/24.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int k;

    FILE *fp2 = fopen("test.bin","wb");

    scanf("%d",&n);
    scanf("%d",&k);

    fwrite(&n,sizeof(int),1,fp2);
    fwrite(&k,sizeof(int),1,fp2);

    int id[n];
    float weight[n];
    int height[n];
    float score[n];

    for(int i=0;i<n;i++){
        scanf("%d",&id[i]);
        scanf("%f",&weight[i]);
        scanf("%d",&height[i]);
        scanf("%f",&score[i]);


        fwrite(&id[i],sizeof(int),1,fp2);
        fwrite(&weight[i],sizeof(float),1,fp2);
        fwrite(&height[i],sizeof(int),1,fp2);
        fwrite(&score[i],sizeof(float),1,fp2);
    }

    fclose(fp2);

    FILE* ansfp = fopen("test.bin","rb");

    fseek(ansfp,sizeof(int)*2+k,SEEK_SET);

    int kid;
    float kweight;
    int kheight;
    float kscore;


    fread(&kid,sizeof(int),1,ansfp);
    fread(&kweight,sizeof(float),1,ansfp);
    fread(&kheight,sizeof(int),1,ansfp);
    fread(&kscore,sizeof(float),1,ansfp);


    printf("%.1f %d %0.1f %d",kscore,kid,kweight,kheight);

    fclose(ansfp);

    return 0;
}