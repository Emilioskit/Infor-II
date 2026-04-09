
#include <iostream>
using namespace std;

namespace food {

    class product { 
        char name[20]; //PRIVATE by default

    public:
        //constructor with parameters
        product(char* n) {     
            strcpy_s(name, n); 
        }

        //product object(char* n);
    };

}

int main() {
    char name[] = "milk";
    food::product p1(name, 1);
}
    

