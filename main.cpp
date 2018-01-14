#include <iostream>
void swap(int& _num1, int& _num2)
{
	int temp;
	temp = _num1;
	_num1 = _num2;
	_num2 = temp;
}
int steps(int bigger, int smaller, int search, int bigger_change, int smaller_change, int counter_steps)
{
	if (bigger_change == search || smaller_change == search)
	{
		return counter_steps;
	}
	if ((bigger == smaller && bigger != search) || (bigger < search))
	{
		return -1;
	}
	if (bigger == search || smaller == search)
	{
		return 1;
	}
	if (bigger_change == smaller_change && bigger_change != search && counter_steps != 0)
	{
		return -1;
	}
	if (bigger_change <= bigger && bigger_change > 0 && bigger_change > smaller && smaller_change < smaller)
	{
		bigger_change = bigger_change - (smaller - smaller_change);
		smaller_change = smaller;
		return steps(bigger, smaller, search, bigger_change, smaller_change, ++counter_steps);
	}
	if (bigger_change > 0 && smaller_change == smaller)
	{
		smaller_change = 0;
		return steps(bigger, smaller, search, bigger_change, smaller_change, ++counter_steps);
	}
	if (bigger_change == 0)
	{
		bigger_change = bigger;
		return steps(bigger, smaller, search, bigger_change, smaller_change, ++counter_steps);
	}
	if (bigger_change > 0 && smaller_change == 0 && bigger_change < smaller)
	{
		smaller_change = bigger_change;
		bigger_change = 0;
		return steps(bigger, smaller, search, bigger_change, smaller_change, ++counter_steps);
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
	/*if (bigger > 20 || smaller < 1)
	{
		std::cout << "-1" << std::endl;
		return 0;
	}*/
	std::cout << steps(bigger, smaller, search, bigger_change, smaller_change, counter_steps) << std::endl;
	return 0;
}
//int steps(int bigger, int smaller, int search, int bigger_change, int smaller_change, int counter_steps)
//{
//	if (bigger_change == search || smaller_change == search)
//	{
//		return counter_steps;
//	}
//	if ((bigger == smaller && bigger != search) || (bigger < search))
//	{
//		return -1;
//	}
//	if (bigger == search || smaller == search)
//	{
//		return 1;
//	}
//	if (counter_steps == 0)
//	{
//		bigger_change = bigger;
//		return steps(bigger, smaller, search, bigger_change, smaller_change, ++counter_steps);
//	}
//	if (bigger_change == bigger && smaller_change < smaller && smaller_change != 0)
//	{
//		bigger_change = bigger_change - (smaller - smaller_change);
//		smaller_change = smaller;
//		return steps(bigger, smaller, search, bigger_change, smaller_change, ++counter_steps);
//	}
//	if (bigger_change == bigger && smaller_change == 0) // 20 0
//	{
//		bigger_change -= smaller;
//		smaller_change = smaller;
//		return steps(bigger, smaller, search, bigger_change, smaller_change, ++counter_steps);
//	}
//	if (bigger_change > 0 && smaller_change == smaller)
//	{
//		smaller_change = 0;
//		return steps(bigger, smaller, search, bigger_change, smaller_change, ++counter_steps);
//	}
//	if (bigger_change == 0 && steps != 0)
//	{
//		bigger_change = bigger;
//		return steps(bigger, smaller, search, bigger_change, smaller_change, ++counter_steps);
//	}
//	if (bigger_change > 0 && smaller_change == 0 && bigger_change > smaller && bigger_change != bigger)
//	{
//		bigger_change -= smaller;
//		smaller_change = smaller;
//		return steps(bigger, smaller, search, bigger_change, smaller_change, ++counter_steps);
//	}
//	if (bigger_change > 0 && smaller_change == 0 && bigger_change < smaller)
//	{
//		smaller_change = bigger_change;
//		bigger_change = 0;
//		return steps(bigger, smaller, search, bigger_change, smaller_change, ++counter_steps);
//	}
//}
