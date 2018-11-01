#include <climits>
#include <iostream>
#include <stdio.h>

using namespace std;
int main(int argc, char ** argv) {
	cout << "INT_MAX : " << INT_MAX << endl;
	cout << "INT_MIN : " << INT_MIN << endl;
	static const int MAX_INT = (int)((unsigned)~0 >> 1);
	static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
		
	printf("MAX_INT : %d -- %x 	MIN_INT : %d -- %x\n", MAX_INT, MAX_INT, MIN_INT, MIN_INT);
	return 0;
}
