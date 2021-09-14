#pragma once

#include <iostream>

class String
{
private:
	int m_length;
	char* m_string;

private:
	int m_getLength(const char* char_arr);
	void m_strcpy(char* a, const char* b);

public:
	String();
	String(const char* new_string);
	String(const String& new_string);

	const char operator[](int index) const;
	const char at_index(int index) const;

	void append(const char* child);
	void append(const char child);
	void append(int64_t integer);
	void append(const String& new_string);

	void operator+=(const String& new_string);
	void operator+=(const char* new_string);
	void operator+=(const char new_char);
	void operator+=(const int64_t int_to_string);
	void operator+=(const int32_t int_to_string);
	void operator=(const String& new_string);
	void operator=(const char* new_string);

	const char* __str__() const;

	const int __int__() const;
	const int length() const;

	bool operator>(const String& a) const;
	bool operator<(const String& a) const;
	bool operator>=(const String& a) const;
	bool operator<=(const String& a) const;
	bool operator==(const String& a) const;

	bool operator>(const char* a) const;
	bool operator<(const char* a) const;
	bool operator>=(const char* a) const;
	bool operator<=(const char* a) const;
	bool operator==(const char* a) const;

	bool has(const char* a);
	bool has(String& const a);

	friend std::ostream& operator<<(std::ostream& os, String& const string);
	friend std::istream& operator>>(std::istream& is, String& const string);
	// with a delimator of ^D or ASCII(4)
	friend std::istream& getbuffer(std::istream& is, String& const string);

	~String();
};
