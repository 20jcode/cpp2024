#include "iostream"

using namespace std;

class Student {
private :
    static int sCount;
public :
    unsigned ID;
    string name;
    Student(){
        ID = 0;
        name = "";
        sCount++;
        cout<<sCount<<endl;
    }
    Student(const Student& s){
        ID = s.ID;
        name = s.name;
    };
    ~Student(){
        sCount--;
        cout<<sCount<<endl;
    };
};

class Lecture {

public :
    string prof;
    Student *students;
    int number;
    Lecture(int n){
        students = new Student[n];
        number += n;
    }
    Lecture(const Lecture& l){
        prof = l.prof;
        number = l.number;
        students = new Student[l.number];
        for(int i=0;i<number;i++){
            students[i].ID = l.students[i].ID;
            students[i].name = l.students[i].name;
        }
    }

    ~Lecture(){
        delete[] students; //이렇게 해야지 하나씩 없어진다.
    }

    int operator[](string name) const{
        for(int i=0;i<number;i++){
            if(students[i].name == name){
                return students[i].ID;
            }
        }
        return 0;
    }


};

int Student::sCount = 0;

int main(){
    int n;
    cin>>n;
    Lecture lecture(n);

    for(int i=0;i<n;i++){
        cin>>lecture.students[i].ID>>lecture.students[i].name;

    }

    string key_name;
    cin>>key_name;
    cout<<lecture[key_name]<<endl;
}