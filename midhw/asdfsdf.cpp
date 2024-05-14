#include <string>
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<string,int> a,pair<string,int> b);

int main(){

    map<string,int> wordset = map<string,int>();

    list<string> wordlist;

    list<string> noswordlist;

    string bufferword = "";

    while(!cin.eof()) {

        getline(cin, bufferword, ' ');


        if(bufferword.length()>2){
            char c = bufferword[bufferword.length()-1];
            if (c == '\n'){
                bufferword = bufferword.substr(0,bufferword.length()-1);
            }
            c = bufferword[bufferword.length()-1];
            if( c == ',' || c=='.'){
                bufferword = bufferword.substr(0,bufferword.length()-1);
            }
            c = bufferword[bufferword.length()-1];
            if ( c == 's'){
                bufferword = bufferword.substr(0,bufferword.length()-1);
            }

            wordlist.push_back(bufferword);
        }
        if(wordlist.size()>500){
            break;
        }
    }

    for(list<string>::iterator iter= wordlist.begin();iter!= wordlist.end();iter++){
        char firstWord = *iter->begin();
        if(isupper(firstWord)){
            char c = tolower(firstWord);
            string reword = iter->substr(1);
            reword = c + reword;

            map<string,int>::iterator p = wordset.find(reword);

            if(p!=wordset.end()){
                p->second = p->second+1;
            } else {
                wordset.insert(pair<string,int>(reword,1));
            }
        } else {
            map<string,int>::iterator p = wordset.find(*iter);
            if(p!=wordset.end()){
                p->second = p->second+1;
            } else {
                wordset.insert(pair<string,int>(*iter,1));
            }
        }

    }

    vector<pair<string,int> > vec(wordset.begin(),wordset.end());
    sort(vec.begin(),vec.end(),comp);


    vector<pair<string,int> >::iterator iter = vec.begin();
    int flag;

    for(int i=0;i<3;i++){
        flag = 1;


        for(list<string>::iterator lter = wordlist.begin();lter != wordlist.end(); lter++){
            if (iter->first == *lter){
                cout<<iter->first<<" "<<iter->second<<endl;
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            char toc = toupper(iter->first[0]);
            cout<<toc;
            cout<<iter->first.substr(1)<<" "<<iter->second<<endl;
        }
        iter++;

    }

    return 0;
}

bool comp(pair<string,int> a,pair<string,int> b){
    if (a.second == b.second){
        return a.first<b.first;
    } else {
        return a.second>b.second;
    }
}
