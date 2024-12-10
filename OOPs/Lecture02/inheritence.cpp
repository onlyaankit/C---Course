#include <iostream>
using namespace std;

class Human {
    private:
    int height;

    public:
    int weight;

    private:
    int age;

    public:
    int getAge(){
        return this -> age;
    }
    int setWeight(int w){
        this -> weight = w;
    }
};

class male : private Human {
    public:
    string color;

    void sleep(){
        cout << "Male is Sleeping..." << endl;
    }

    void getHeight(){
        return this -> height;
    }

};

int main(){
    male m1;

    cout << m1.height << endl;

    male object1;
    
    cout << object1.age <<endl;
    cout << object1.height <<endl;
    cout << object1.weight <<endl;
    cout << object1.color <<endl;

    object1.setWeight(80);
    cout << object1.weight << endl;
    object1.sleep();

    return 0;
}