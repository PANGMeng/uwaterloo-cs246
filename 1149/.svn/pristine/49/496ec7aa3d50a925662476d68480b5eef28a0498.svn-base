#include <iostream>

using namespace std;

struct Array {
	int capacity;
	int * array;

	// Doubles the length of the array and stores each number multiplied by a number
	void multiply(){
		int * temp = new int[capacity*2];
		cout << "What shall each number be multiplied by? ";
		int multiplier;
		cin >> multiplier;
		for (int i = 0; i < capacity; ++i){
			temp[2*i] = array[i];
			temp[2*i+1] = array[i] * multiplier;
		}
		delete[] array;
		array = temp;
		capacity = capacity*2;
	}

	void add(){
		int * temp = new int[capacity*2];		
		cout << "What shall be added to each number? ";
		int num;
		cin >> num;
		for (int i = 0; i < capacity; ++i){
			temp[2*i] = array[i];
			temp[2*i+1] = array[i] + num;
		}
		delete[] array;
		array = temp;
		capacity = capacity*2;
	}
};

Array * createArray(){
	Array * arr = new Array;
	cout << "How many numbers are read in? ";
	cin >> arr->capacity;
	arr->array = new int[arr->capacity];
	for (int i = 0; i < arr->capacity; ++i){
		int j = 0;
		cin >> j;
		arr->array[i] = j;
	}
	return arr;
}

ostream& operator<<(ostream & out, const Array * arr){
	for ( int i = 0; i < arr->capacity ; ++i){
		out << arr->array[i] << " ";
	}
	return out;
}


int main(){
	Array * output = createArray();
	char oper;
	bool flag = true;
	while( flag ) {
		cout << "Command?" << endl;
		cin >> oper;
		switch(oper){
			case '*':
				output->multiply();
				break;
			case '+':
				output->add();
				break;
			case 'n':
				delete[] output->array;
				delete output;
				output = createArray();
				break;
			case 'p':
				cout << output << endl;
				break;
			case 'q':
				flag = false;
		} //switch

	} //while
	delete[] output->array;
	delete output;
}
