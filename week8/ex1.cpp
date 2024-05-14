//
// Created by leeyoungjun on 4/30/24.
//

#include <iostream>

using namespace std;

class IntegerSet {
private:
    int     numElements,maxNumElements;
    int     *elements;
public:
    IntegerSet(int max) {
        numElements=0;
        maxNumElements=max;
        elements=new int[max];
    }

    IntegerSet(): numElements(0), maxNumElements(100) {}
    ~IntegerSet(); // to implement

    int     operator+(int);  // add an integer element, duplication is allowed
    int     operator-(int);  // remove an integer element
    int     operator[](int);  // search a value, return the number of elements matched with key
    friend ostream& operator<<(ostream&, IntegerSet&); // given as below
};

IntegerSet::~IntegerSet() {
    // to implement
    delete [] elements;
}

int IntegerSet::operator+(int a){
    // to implement
    elements[numElements] = a;
    numElements++;
    return numElements;
}

int IntegerSet::operator-(int a){
    for(int i=0;i<numElements;i++){
        if(elements[i] == a){
            for(int j=i;j<numElements-1;j++){
                elements[j] = elements[j+1];
            }
            numElements--;
            break;
        }
    }
    return numElements;
}

int IntegerSet::operator[](int a){
    // search a in the IntegerSet, return the number of elements matched with a
    // to implement
    int num=0;
    for(int i=0;i<numElements;i++){
        if(elements[i] == a){
            num++;
        }
    }

    return num; // modify it properly
}

ostream& operator<<(ostream& os, IntegerSet& set) {

  for(int i=0;i<set.numElements;i++) cout<<set.elements[i]<<endl;
  return os;

}

int main()
{
    IntegerSet  mySet(100);
    int         numLines;
    char        op;
    int n;

    cin>>numLines;
    for(int i=0;i<numLines;i++) {
        cin>>op;
        switch(op) {
            case '+':
                cin>>n;
                cout<<mySet + n<<endl;
                break;
            case '-':
                cin>>n;
                cout<<mySet - n<<endl;
                break;

            case '=':
                cout<<mySet;
                break;

            default:
                cin>>n;
                cout<<mySet[n]<<endl;
                break;
        }

    }

    return 0;
}
