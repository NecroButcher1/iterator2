#include "list.h"
#include <iostream> 
using namespace std;

int main() {
	list<int> curr;
	for (size_t i = 0; i < 5; i++) {
		curr.push(i+1);
	}
	list<int>::iterator beg;
	for (beg = curr.begin(); !beg.end(); ++beg) {
		cout << *beg << " ";
	}
	return 0;
}