
#include <iostream>
using namespace std;

void main(void) {
	int Num;
	int* data; //pointer called data that stores mem address of integer.

	cout << "How many numbers?";
	cin >> Num;

	//THERE IS NOT VARIABLE NAME FOR ARRAY, just the pointer
	data = new int[Num]; //allocate an array of ints of "num" length to heap
						// AND store the first adress to pointer data

	if (data == NULL) { cout << "Error";return; }

	//Fill vector
	for (int i = 0; i < Num;i++) {
		cout << "give data[" << i << "]:?";
		cin >> data[i]; //data[i] == *(data + 1) ORIGINAL
	}

	//SORT DATA from small to big
	for (int i = 0; i < Num-1; i++) {
		for (int j = i+1; j < Num;j++) {
			if (data[j] < data[i]) {
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}

	for (int i = 0; i < Num;i++) {
		cout << i << ":" << data[i] << endl;
	}

	delete[] data; //MUST DELETE SO WE DONT HAVE MEMORY LEAK



}