//
// Created by leeyoungjun on 4/18/24.
//
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int main(){
    int n;
    int k;
    string s;
    ofstream binlog("ans.bin",ios::binary);
    cin>>n>>k;
    cin.ignore();
    string inputdata;
    for(int i=0;i<n*4;i++){
        cin>>inputdata;
        binlog<<inputdata<<endl;
    }

    ifstream myfile("ans.bin",ios::binary);
    myfile.seekg(k);

    string ans;
    string s1,s2,s3,s4;
    getline(myfile,s1);
    getline(myfile,s2);
    getline(myfile,s3);
    getline(myfile,s4);


    cout<<s4<<" "<<s1<<" "<<s2<<" "<<s3<<endl;

    return 0;
}