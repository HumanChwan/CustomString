#include <iostream>

#include "../Header/String.h"

constexpr int MONKE = 0;

int main()
{
	String a, b, c;

	a = "bhaimerenadardhai";
	b = "mere";
	c = "merea";
	if (a.has(b))
	{
		std::cout << "Exists";
	}

	if (a.has(c))
	{
		std::cout << "yikes";
	}

	return MONKE;
}