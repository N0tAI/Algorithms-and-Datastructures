#include<iostream>

using namespace std; 

typedef struct {
	int length;
	int width;
} Rectangle;

void structure_practice() {
	Rectangle r1 = { 2, 1 };
	cout << "size = " << sizeof(r1)
		 << "\nlength = " << r1.length
		 << "\nwidth = " << r1.width << endl;
}