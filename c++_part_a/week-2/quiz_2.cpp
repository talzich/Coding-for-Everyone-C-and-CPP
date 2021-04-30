#include <iostream>
#include <vector>

using namespace std;

template <class Summable>
Summable sub(const vector<Summable> v, int size, Summable s = 0){

    for(int i = 0; i < size ; i++){
        s -= v.at(i);
    }
    return s;
}

template <class Summable>
void elements(const vector<Summable> v, int size){

    for(int i = 0; i < size ; i++){
        cout << v.at(i) << '\t';
    }
    cout << endl;
}

int main(){
    cout << "template for sub()" << endl;
}