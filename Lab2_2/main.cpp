
#include <iostream>
#include "compCont.h"

using namespace std;

int main()
{
	CompCont cmp;
	cmp.inputEmployee();
	cmp.findBestPaid();
	cmp.printBestPaid();

	cmp.removeEmployee();
	cmp.removeEmployee();
	cmp.removeEmployee();
	cmp.findBestPaid();
	cmp.printBestPaid();
}