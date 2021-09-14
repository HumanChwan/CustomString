#include <algorithm>
#include "../Header/math.h"

const int math::getIntegerSize(int integer)
{
	integer = std::abs(integer);
	int length = 0;
	do
	{
		length++;
		integer /= 10;
	} while (integer);

	return length;
}

const int64_t math::power(int64_t base, int64_t surd)
{
	int64_t res = 1LL;
	while (surd)
	{
		if (surd & 1)
		{
			res *= base;
		}

		base *= base;
		surd >>= 1;
	}

	return res;
}