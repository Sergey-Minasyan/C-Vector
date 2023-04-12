#pragma once
#include <stdio.h>
template<typename T>
class Vector
{
public:
	Vector(const Vector<T>& rhs);
	void push_back(const T& rhs);
	void push_back(T&& rhs);
	void pop_back();
	void insert(size_t pos, const T& rhs);
	void insert(size_t pos, T&& rhs);
	bool empty() const;
	size_t size() const;
	size_t capacity() const;
	void clear();
	void resize(size_t size);
	void erase(size_t pos);
	T& at(size_t pos);
	const T& at(size_t pos) const;
	T& operator[](size_t pos);
	const T& operator[](size_t pos) const;
	void shrink_to_fit();
private:
	size_t m_cap;
	size_t m_size;
	T* m_buf;
};
#include "Vector.cpp"