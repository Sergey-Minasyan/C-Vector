#pragma once
#include <stdio.h>
enum { bit_count = 8 * sizeof(size_t) };

class reference
{
public:
	reference(size_t* pt, size_t index);
	reference(const reference& oth);
	reference& operator=(const reference& oth);
	reference& operator=(bool val);
	operator bool() const;
	void flip();
private:
	size_t* ptr;
	size_t index;
	bool val;
};
