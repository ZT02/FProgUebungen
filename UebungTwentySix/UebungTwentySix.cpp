#include <iostream>
#define SWAP(x, y) { int temp = x; x = y; y = temp; }
using namespace std;



int main(void) {
	int array[5];
	int size = (sizeof(array) / 4);
	for (int i = 0; i < size; i++) {
		cout << i << ". Zahl: ";
		cin >> array[i];
	}
	for (int i = 0; i < size; i++) {
		for (int y = 0; y < size; y++) {
			if (array[i] < array[y])
				SWAP(array[i], array[y]);
		}

	}
	cout << array[2] << endl;
	return 0;
}