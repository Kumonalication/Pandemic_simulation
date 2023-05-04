//±©Ò»³À 202130270029

#include <cstdlib>
#include <ctime>

bool hit(double rate) {
	int a = rand();
	if (rand() <= RAND_MAX * rate)
		return true;
	return false;
}