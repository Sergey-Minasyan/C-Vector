#include "vector_bool.hpp"

reference::reference(size_t* pt, size_t ind)
	:ptr{ pt }, index{ ind }
{
	val = ptr[index / bit_count] & (1 << (index % bit_count));
}

void reference::flip()
{
	ptr[index / bit_count] ^= (1 << (index % bit_count));
	val != val;
}

reference::reference(const reference& oth)
	:ptr{ oth.ptr }, index{ oth.index }, val{ oth.val }
{}

reference& reference::operator=(const reference& oth)
{
	if (val != oth.val)
		this->flip();
	return *this;
}

reference& reference::operator=(bool val)
{
	if (this->val != val)
		this->flip();
	return *this;
}

reference::operator bool()
{
	return val;
}
