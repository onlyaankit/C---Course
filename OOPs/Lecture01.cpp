#include <iostream> 
using namespace std;


// cleation of class variables
class Hero {
    private:
    int health;
    // string level;

    //getter/ setter methods
    void getHealth(){
        return health;
    }

};

int main(){
    //creation of object 
    Hero h1;
    h1.setHealth(100);
    // h1.level = "Paul";

   // access the variables
    cout << h1.getHealth() << endl;
    // cout << h1.level << endl;
return 0;
}