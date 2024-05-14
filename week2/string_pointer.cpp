//
// Created by leeyoungjun on 3/12/24.
//
#include <iostream>

using namespace std;

/*
void strcpy(char s[],char t[]){

    int i = 0;
    while(s[i] != '\n'){
        t[i] = s[i];
        i++;
    }
    s[i] = '\n';
}

*/

void strcpy(char* s,char* t){
    while(*s!='\n'){
        *t = *s;
        t++,s++;
    }
}

// 왜 '\n'으로 하면 안될까? '0'도 된다. 그냥 0도 된다.
int main(){
    char input[100];
    char ans[100];
    cin>>input;
    strcpy(input,ans);
    cout<<ans;

}