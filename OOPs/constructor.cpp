#include <iostream>
using namespace std;

class Hero{
    public:
    int health;

    Hero(){
        cout<< "constructor called Successfully" << endl;
    }
};

int main(){
    cout<< "hello world"<< endl;
    Hero h1;
    cout << "lol"<< endl;
    return 0;
}