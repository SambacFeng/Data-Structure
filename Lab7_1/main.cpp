
#include "car.h"
#include "washCmp.h"
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	WashCmp cmp;
	cmp.simulation();
	cmp.printCmpStatistic();

	return 0;
}