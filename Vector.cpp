#include <iostream>
#include "vector.hpp"

template<typename T>
Vector<T>::Vector(const Vector<T>& rhs)
	:m_cap{ rhs.m_cap }, m_size{ rhs.m_size }
{
	if (!rhs.empty())
	{
		m_buf = new T[m_cap];
		for (int i = 0; i < m_size; ++i)
		{
			m_buf[i] = rhs.m_buf[i];
		}
	}
}

template<typename T>
void Vector<T>::push_back(const T& rhs)
{
	if (this->empty())
	{
		m_buf = new T[m_cap];
		m_buf[m_size++] = rhs;
	}
	else
	{
		if (m_size < m_cap)
		{
			m_buf[m_size++] = rhs;
		}
		else
		{
			T* tmp = new T[m_cap * 2];
			m_cap *= 2;
			for (int i = 0; i < m_size; ++i)
			{
				tmp[i] = m_buf[i];
			}
			delete[] m_buf;
			m_buf = tmp;
			tmp = nullptr;
			m_buf[m_size++] = rhs;
		}
	}
}


template<typename T>
void Vector<T>::pop_back()
{
	if (!this->empty())
	{
		m_buf[m_size--] = T{};
	}
}

template<typename T>
void Vector<T>::insert(size_t pos, const T& rhs)
{
	if (this->empty())
	{
		m_buf = new T[m - cap];
		m_buf = rhs;
	}
	else
	{
		if (m_size != m_cap)
		{
			for (int i = m_size - 1; i >= pos; --i)
			{
				m_buf[i + 1] = m_buf[i];
			}
			m_buf[pos] = rhs;
			++m_size;
		}
		else
		{
			T* tmp = new T[m_cap * 2];
			m_cap *= 2;
			for (int i = 0; i < pos; ++i)
			{
				tmp[i] = m_buf[i];
			}
			tmp[pos] = rhs;
			for (int i = m_size; i > pos; ++i)
			{
				tmp[i] = m_buf[i - 1];
			}
			delete[] m_buf;
			m_buf = tmp;
			tmp = nullptr;
			++m_size;
		}
	}
}

template<typename T>
bool Vector<T>::empty() const
{
	return (m_size == 0);
}

template<typename T>
size_t Vector<T>::size() const
{
	return m_size;
}

template<typename T>
size_t Vector<T>::capacity() const
{
	return m_cap;
}


template<typename T>
void Vector<T>::clear()
{
	if (!this->empty())
	{
		delete[] m_buf;
		m_cap = 1;
		m_size = 0;
	}
}

template<typename T>
void Vector<T>::resize(size_t size)
{
	if (m_cap < size)
	{
		m_cap = size;
		if (this->empty())
			m_buf = new T[m_cap];
		else
		{
			T* tmp = new T[m_cap];
			for (int i = 0; i < m_size; ++i)
			{
				tmp[i] = m_buf[i];
			}
			delete[] m_buf;
			m_buf = tmp;
			tmp = nullptr;
		}
	}
}

template<typename T>
T& Vector<T>::at(size_t pos)
{
	if (pos >= m_size)
	{
		throw std::out_of_range("");
	}
	return m_buf[pos];
}

template<typename T>
const T& Vector<T>::at(size_t pos) const
{
	if (pos >= m_size)
	{
		throw std::out_of_range("");
	}
	return m_buf[pos];
}

template<typename T>
T& Vector<T>::operator[](size_t pos)
{
	return m_buf[pos];
}

template<typename T>
const T& Vector<T>::operator[](size_t pos)
{
	return m_buf[pos];
}

template<typename T>
void Vector<T>::shrink_to_fit()
{
	if (!this->empty())
	{
		if (m_size != m_cap)
		{
			m_cap = m_size;
			T* tmp = new T[m_cap];
			for (int i = 0; i < m_size; ++i)
			{
				tmp[i] = m_buf[i];
			}
			delete[] m_buf;
			m_buf = tmp;
			tmp = nullptr;
		}
	}
}

template<typename T>
void Vector<T>::erase(size_t pos)
{
	if (!this->empty())
	{
		for (int i = m_size; i >= pos; --i)
		{
			m_buf[i - 1] = m_buf[i];
		}
		--m_size;
	}
}
