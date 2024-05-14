//
// Created by leeyoungjun on 3/21/24.
//

#include "iostream"

using namespace std;

int main(){
    int n;
    int k;

    //FILE *fp = fopen("01.inp","r");
    FILE *fp2 = fopen("test.bin","wb");

    //fscanf(fp,"%d",&n);
    //fscanf(fp,"%d",&k);
    scanf("%d",&n);
    scanf("%d",&k);

    fwrite(&n,sizeof(int),1,fp2);
    fwrite(&k,sizeof(int),1,fp2);

    int id[n];
    float weight[n];
    int height[n];
    float score[n];

    for(int i=0;i<n;i++){
        //fscanf(fp,"%d",&id[i]);
        //fscanf(fp,"%f",&weight[i]);
        //fscanf(fp,"%d",&height[i]);
        //fscanf(fp,"%f",&score[i]);
        scanf("%d",&id[i]);
        scanf("%f",&weight[i]);
        scanf("%d",&height[i]);
        scanf("%f",&score[i]);

        fwrite(&id[i],sizeof(int),1,fp2);
        fwrite(&weight[i],sizeof(float),1,fp2);
        fwrite(&height[i],sizeof(float),1,fp2);
        fwrite(&score[i],sizeof(int),1,fp2);
    }
    //fclose(fp);
    fclose(fp2);

    FILE* ansfp = fopen("test.bin","rb");

    fseek(ansfp,k,SEEK_SET);

    int ans;

    fread(&ans,sizeof(int),1,ansfp);

    printf("%d",ans);

    fclose(ansfp);


}