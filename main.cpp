#include <iostream>
void swap(int& _num1, int& _num2)
{
	int temp;
	temp = _num1;
	_num1 = _num2;
	_num2 = temp;
}
bool check(int& a, int& b, int& c)
{
	if (a % 2 == 0 && b % 2 == 0 && c % 2 != 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int steps(const int& bigger_quantity, const int& smaller_quantity, const int& search, int bigger_change, int smaller_change, int counter_steps)
{
	// base of recursion
	if (bigger_change == search || smaller_change == search)
	{
		return counter_steps;
	}
	if ((bigger_quantity == smaller_quantity && bigger_quantity != search) || (bigger_quantity < search))
	{
		return -1;
	}
	if (bigger_quantity == search || smaller_quantity == search)
	{
		return 1;
	}
	if (bigger_change == smaller_change && bigger_change != search && counter_steps != 0)
	{
		return -1;
	}
	if (bigger_change <= bigger_quantity && bigger_change > 0 && bigger_change > smaller_quantity && smaller_change < smaller_quantity)
	{
		bigger_change -= (smaller_quantity - smaller_change);
		smaller_change = smaller_quantity;
		return steps(bigger_quantity, smaller_quantity, search, bigger_change, smaller_change, ++counter_steps);
	}
	if (bigger_change > 0 && smaller_change == smaller_quantity)
	{
		smaller_change = 0;
		return steps(bigger_quantity, smaller_quantity, search, bigger_change, smaller_change, ++counter_steps);
	}
	if (bigger_change == 0)
	{
		bigger_change = bigger_quantity;
		return steps(bigger_quantity, smaller_quantity, search, bigger_change, smaller_change, ++counter_steps);
	}
	if (bigger_change > 0 && smaller_change == 0 && bigger_change < smaller_quantity)
	{
		smaller_change = bigger_change;
		bigger_change = 0;
		return steps(bigger_quantity, smaller_quantity, search, bigger_change, smaller_change, ++counter_steps);
	}
}
int main()
{
	int counter_steps = 0;
	int bigger = 0;
	int smaller = 0;
	int search = 0;
	int bigger_change = 0;
	int smaller_change = 0;
	std::cin >> bigger;
	std::cin >> smaller;
	std::cin >> search;
	if (bigger < smaller)
	{
		swap(bigger, smaller);
	}
	if (check(bigger, smaller, search) == 0)
	{
		std::cout << "-1";
		return 0;
	}
	std::cout << steps(bigger, smaller, search, bigger_change, smaller_change, counter_steps) << std::endl;
	return 0;
}
