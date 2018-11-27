#include <iostream>
#include <vector>
#include <string>
 
int main()
{
	std::vector<int> ints {1, 2, 4, 8, 16};
	std::vector<std::string> fruits {"orange", "apple", "raspberry"};
	std::vector<char> empty;
 
	// Sums all integers in the vector ints (if any), printing only the result.
	int sum = 0;
	for (auto it = ints.cbegin(); it != ints.cend(); it++)
		sum += *it;
	std::cout << "Sum of ints: " << sum << "\n";
 
	// Prints the first fruit in the vector fruits, without checking if there is one.
	std::cout << "First fruit: " << *fruits.begin() << "\n";
 
	if (empty.begin() == empty.end())
		std::cout << "vector 'empty' is indeed empty.\n";
}