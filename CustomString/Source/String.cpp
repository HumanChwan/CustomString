#include "../Header/String.h"

#include "../Header/math.h"

/*
	PRIVATE METHODS
*/
// <-----Method to return Length from Char Pointer----->
int String::m_getLength(const char* char_arr)
{
	int len = 0;
	while (char_arr[len] != '\0')
	{
		len++;
	}

	return len;
}

// <-----Method to copy char pointer----->
void String::m_strcpy(char* a, const char* b)
{
	if (b == nullptr)
	{
		a[0] = '\0';
		return;
	}

	int len;
	for (len = 0; b[len] != '\0'; len++)
	{
		a[len] = b[len];
	}
	a[len] = b[len];
}

/*
	PUBLIC METHODS
*/
// <-----Constructors----->
String::String()
{
	m_string = nullptr;
	m_length = 0;
}
String::String(const char* new_string)
{
	const int new_length = m_getLength(new_string);
	m_length = new_length;

	m_string = new char[new_length + 1];
	m_strcpy(m_string, new_string);
}
String::String(const String& new_string)
{
	(*this) += new_string;
}

// <-----Indexed Char Getters----->
const char String::operator[](int index) const
{
	return m_string[index];
}
const char String::at_index(int index) const
{
	return (*this)[index];
}

// <-----Append Overloaded Methods----->
void String::append(const char* child)
{
	const int new_length = m_length + m_getLength(child);
	char* new_string = new char[new_length + 1];

	m_strcpy(new_string, m_string);
	for (int i = m_length; i < new_length + 1; ++i)
	{
		new_string[i] = child[i - m_length];
	}

	m_length = new_length;
	delete[]m_string;
	m_string = new_string;
}
void String::append(const char child)
{
	m_length++;
	char* new_string = new char[m_length + 1];
	m_strcpy(new_string, m_string);

	new_string[m_length - 1] = child;
	new_string[m_length] = '\0';

	delete[]m_string;
	m_string = new_string;
}
void String::append(int64_t integer)
{
	if (integer < 0LL)
	{
		(*this) += '-';
	}
	integer = std::abs(integer);

	const int base10Length = math::getIntegerSize(integer);
	int64_t power10 = math::power(10, base10Length - 1LL);

	do
	{
		char digit = (char)((integer / power10) + '0');
		integer %= power10;
		power10 /= 10LL;

		(*this) += digit;
	} while (power10);
}
void String::append(const String& new_string)
{
	append(new_string.__str__());
}

// <-----Appending Operator overloads----->
void String::operator+=(const String& new_string)
{
	append(new_string.__str__());
}
void String::operator+=(const char* new_string)
{
	append(new_string);
}
void String::operator+=(const char new_char)
{
	append(new_char);
}
void String::operator+=(const int64_t int_to_string)
{
	append(int_to_string);
}
void String::operator+=(const int32_t int_to_string)
{
	append((int64_t)int_to_string);
}
void String::operator=(const String& new_string)
{
	delete[]m_string;

	const int len = new_string.length();
	m_string = new char[len + 1];
	m_strcpy(m_string, new_string.__str__());

	m_length = len;
}
void String::operator=(const char* new_string)
{
	delete[]m_string;

	const int len = m_getLength(new_string);
	m_string = new char[len + 1];
	m_strcpy(m_string, new_string);

	m_length = len;
}

// <----Ghar Pointer Getter----->
const char* String::__str__() const
{
	return m_string;
}

// <-----Length Getters----->
const int String::__int__() const
{
	return m_length;
}
const int String::length() const
{
	return m_length;
}

// <-----Comparison Methods----->
bool String::operator>(const String& a) const
{
	int min_length = std::min((*this).m_length, a.m_length);
	for (int i = 0; i < min_length; ++i)
	{
		if ((*this)[i] != a[i])
		{
			return ((*this)[i] > a[i]);
		}
	}

	return ((*this).m_length > a.length());
}
bool String::operator<(const String& a) const
{
	int min_length = std::min((*this).m_length, a.length());
	for (int i = 0; i < min_length; ++i)
	{
		if ((*this)[i] != a[i])
		{
			return ((*this)[i] < a[i]);
		}
	}

	return (this->m_length < a.length());
}
bool String::operator==(const String& a) const
{
	if (this->length() != a.length())
	{
		return false;
	}

	const int length = this->length();
	for (int i = 0; i < length; ++i)
	{
		if ((*this)[i] != a[i])
		{
			return false;
		}
	}

	return true;
}
bool String::operator>=(const String& a) const
{
	return !((*this) < a);
}
bool String::operator<=(const String& a) const
{
	return !((*this) > a);
}

bool String::operator>(const char* a) const
{
	String new_string(a);
	return (*this) > a;
}
bool String::operator<(const char* a) const
{
	String new_string(a);
	return (*this) < a;
}
bool String::operator==(const char* a) const
{
	String new_string(a);
	return (*this) == a;
}
bool String::operator>=(const char* a) const
{
	String new_string(a);
	return (*this) >= a;
}
bool String::operator<=(const char* a) const
{
	String new_string(a);
	return (*this) <= a;
}

bool String::has(const char* a)
{
	int len = m_getLength(a);
	for (int i = 0; i < this->m_length; ++i)
	{
		bool has = true;
		for (int j = 0; j < len && (i + j) < this->m_length; ++j)
		{
			if ((*this)[i + j] != a[j])
			{
				has = false;
				break;
			}
		}

		if (has)
		{
			return true;
		}
	}

	return false;
}
bool String::has(String& const a)
{
	for (int i = 0; i < this->m_length; ++i)
	{
		bool has = true;
		for (int j = 0; j < a.length() && (i + j) < this->m_length; ++j)
		{
			if ((*this)[i + j] != a[j])
			{
				has = false;
				break;
			}
		}

		if (has)
		{
			return true;
		}
	}

	return false;
}

// <-----Interaction with ostream & << operator----->
std::ostream& operator<<(std::ostream& os, String& const string)
{
	os << string.__str__();
	return os;
}
// <-----Interaction with istream----->
// <-----with >> operator----->
std::istream& operator>>(std::istream& is, String& const string)
{
	char new_string[1000];
	is >> new_string;
	string = new_string;
	return is;
}
// <-----as a function accepting istream buffer----->
std::istream& getbuffer(std::istream& is, String& const string)
{
	char new_string[1000];
	// ^D delimiter
	is.get(new_string, 1000, 4);

	char next_line;
	is.get(next_line);

	string = new_string;

	return is;
}

// <-----Destructor----->
String::~String()
{
	delete[]m_string;
}