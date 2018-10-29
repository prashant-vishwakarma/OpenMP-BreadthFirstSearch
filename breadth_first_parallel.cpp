#include<iostream>
#include<cstdlib>

using namespace std;

class Tree {
	static const int SIZE = 2047;
	int data[SIZE];
public:
	Tree() {
		for (int i = 0; i < SIZE; i++) {
			data[i] = 0;
		}
	}
	void insert(int n) {
		if (data[0] == 0) {
			data[0] = n;
		}
		else {
			int current = 0;
			while (data[current] != 0) {
				if (n < data[current]) {
					current += current + 1;
				}
				else {
					current += current + 2;
				}
			}
			data[current] = n;
		}
	}

	int breadthFirstSearch(int n) {
		int index = -1;
		for (int i = 0; i < SIZE; i++) {
			if (data[i] == n) {
				index = i;
			}
		}
		return index;
	}

	void printBreadthFirst() {
		for (int i = 0; i < SIZE; i++) {
			if(data[i] != 0)
			cout << data[i] << endl;
		}
	}
};

int main() {
	Tree t;
	
	for(int i = 0; i < 10; i++)
	t.insert(rand()%10);

	t.printBreadthFirst();

	cout << "4 Found at index = " << t.breadthFirstSearch(5) << endl;

	return 0;

}
