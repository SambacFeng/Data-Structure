
#include "listTemp.h"
#include "company.h"
#include <iostream>
using namespace std;

int main()
{
	Company cmp;
	cmp.inputEmployee();
	cmp.findBestPaid();
	cmp.printBestPaid();

	cmp.findBestPaidReverse();
	cmp.printBestPaid();
	return 0;
}