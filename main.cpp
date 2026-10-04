#include <iostream>
#include "mytime.h"


int main() {
	
	MyTime t1, t2(1,10,25), t3(1,5,10);
	t1.info();
	t2.info();
	t3.info();
	t1 = t2.add(10);
	t1.info();
	t2.info();
	t1 = t2.add(t3);
	t1.info();
	t2.info();
	return 0;
}
