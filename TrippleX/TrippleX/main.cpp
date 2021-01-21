#include <iostream>

using std::cout;

int main()
{
	//Print welcom message to the terminal
	cout << "You're a secret agent breaking into a secure server room...\n";
	cout << "You need to enter the correct code to continue...\n";

	//declare 3 number code
	const int a = 4;
	const int b = 8;
	const int c = 2;

	const int sum = a + b + c;		//14
	const int product = a * b * c;	//64

	//print sum and product to the terminal
	cout << "The sum of the all the numbers is equal to " << sum << ".\n";
	cout << "The product of the all the numbers is " << product << ".\n";

	return 0;
}