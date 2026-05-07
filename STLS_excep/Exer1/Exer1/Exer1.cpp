#include <iostream>
using namespace std;

//first namespace

namespace first_space {
	void func() {
		cout << "inside first space" << endl;
	}
}

namespace second_space {
	void func() {
		cout << "inside second space" << endl;
	}
}

using namespace first_space;
using namespace second_space;

int main(){

	first_space::func();
	second_space::func();

	return 0;
}