#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <stdexcept>
#include <ctime>

using namespace std;

template <typename T>
class DynamicArray {
private:
	int* array;
	int size;
	int capacity;

public:
	DynamicArray(int cap) : size(0), capacity(cap) {
		array = new int[capacity];
	}

	~DynamicArray() {
		delete[] array;
	}

	void addToTheEnd(int element) {
		if (size == capacity) {
			int* temp = new int[2 * capacity];
			for (int i = 0; i < size; i++) {
				temp[i] = array[i];
			}
			delete[] array;
			array = temp;
			capacity *= 2;
		}
		array[size++] = element;
	}

	void displayForward() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << endl;
		}
		cout << "Size: " << size << endl << "Capacity: " << capacity << endl;
	}

	void initializer(int amountOfElements) {
		for (int i = 0; i < amountOfElements; i++) {
			int randomInt = rand() % 10000;
			addToTheEnd(randomInt);
		}
	}

	void elementsAdder(int amountOfElements) {
		for (int i = 0; i < amountOfElements; i++) {
			int randomInt = rand() % 10000;
			//clock_t start = clock();
			addToTheEnd(randomInt);
			//clock_t end = clock();
			//double elapsedTimeAddingElements = (double)(end - start) / CLOCKS_PER_SEC * 1000;


		}
	}

	string toString(int range) {
		
		string res = "Size: " + to_string(size) + "\n";
		res = res + "Capacity" + to_string(capacity) + "\n";
		res = res + "Elements: " + "\n";
		int count = 0;

		for (int i = 0; i < range && i < size; i++) {
			res += to_string(array[i]) + "\n";
		}

		for (int i = 0; i < 94; i++) {
			cout << "-";
		}
		cout << endl;
		cout << "Memory address: " << array << endl;

		return res;
	}

	void getById(int id) {
		try {
			if (id < 0 || id >= size) {
				throw invalid_argument("id out of bounds");
			}
			cout << "Here it is: " << array[id] << endl;
		}
		catch (const invalid_argument& e) {
			cout << "something went wrong :( " << e.what() << endl;
		}
	}

	void updateById(int id, T field) {
		try {
			if (id < 0 || id >= size) {
				throw invalid_argument("id out of bounds");
			}
			array[id] = field;
		}
		catch (const invalid_argument& e) {
			cout << "something went wrong :( " << e.what() << endl;
		}
	}

	void deleteAll() {
		delete[] array;
		size = 0;
		capacity = 1;
		array = new T[capacity];
	}

	void bubbleSort(bool ascending = true) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if ((ascending && array[j] > array[j + 1]) ||
					(!ascending && array[j] < array[j + 1])) {
					T temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
	}


	void start(int maxPower, DynamicArray& sampleArray) {
		double maxTimePerElement = 0.0; 
		cout << "najgorszy czas: " << maxTimePerElement << endl;
		for (int i = 1; i <= maxPower; i++) {
			int k = pow(10, i);
			cout << "Indeks: " << i << endl;
			//clock_t start = clock(); 

			sampleArray.initializer(14);  
			clock_t startElements = clock(); 
			sampleArray.elementsAdder(k);
			clock_t endElements = clock(); 
			double addingTime = (double)(endElements - startElements) / CLOCKS_PER_SEC * 1000;
			cout << sampleArray.toString(10);

			//clock_t end = clock();
			//double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC * 1000;

			cout << "Czas pojedynczej operacji dodawania: " << addingTime << " ms" << endl;
			if (addingTime > maxTimePerElement) {
				maxTimePerElement = addingTime;
				cout << "Nowy najgorszy czas: " << maxTimePerElement << " ms " << "przy indeksie: " << i << endl;
			}
		}
	}

};

int main() {
	DynamicArray<int> coolArray(1);
	coolArray.start(7, coolArray);
}
