#pragma once
#include "Exception.h"
template <typename T>
class DynArray
{
	T * m_array;
	int m_length;
	int m_start_index;
public:
	DynArray();
	DynArray(int length, int start_index);
	DynArray(const DynArray & copy);

	~DynArray();

	DynArray<T> & operator = (const DynArray & rhs);
	T & operator [] (int index);
	int getStartIndex();
	void setStartIndex(int index);
	int getLength();
	void setLength(int len);
};

template <typename T>
DynArray<T>::DynArray() :m_array(nullptr), m_length(0), m_start_index(0)
{
	
}

template <typename T>
DynArray<T>::DynArray(int length, int start_index) : m_length(length), m_start_index(start_index)
{
    if(length < 0)
        throw new Exception("NegativeLengthException");
    if(length>0)
        m_array = new T[length];
    else{
        m_array = nullptr;
    }
}

template <typename T>
DynArray<T>::DynArray(const DynArray<T> & cp): m_length(cp.m_length), m_start_index(cp.m_start_index)
{
    if(m_length>0)
    {
        m_array = new T[m_length];
        for (int i = 0; i < m_length; i++)
        {
            m_array[i] = cp.m_array[i];
        }
    }
    else
        m_array = nullptr;
}

template <typename T>
DynArray<T>::~DynArray()
{
    delete[] m_array;
    m_array = nullptr;
}

template <typename T>
DynArray<T> & DynArray<T>::operator = (const DynArray<T> & rhs)
{
    if(this != &rhs)
    {
        delete[] m_array;
        m_array = nullptr;
        this->m_length = rhs.m_length;
        this->m_start_index = rhs.m_start_index;
        
        m_array = new T[m_length];
        for (int i = 0; i < m_length; i++)
        {
            m_array[i] = rhs.m_array[i];
        }
    }
    
	
    return *this;
}

template <typename T>
T & DynArray<T>::operator [] (int index)
{
	if (index >= m_start_index + m_length || index < m_start_index)
	{
        throw new Exception("OutOfBoundsException");
	}
	return m_array[index - m_start_index];
}

template <typename T>
int DynArray<T>::getStartIndex()
{
	return m_start_index;
}

template <typename T>
void DynArray<T>::setStartIndex(int index)
{
	m_start_index = index;
}

template <typename T>
int DynArray<T>::getLength()
{
	return m_length;
}

template <typename T>
void DynArray<T>::setLength(int new_len)
{
    if(new_len < 0)
        throw new Exception("NegativeLengthException");
    T * hold = new T[new_len];
    int smallest = 0;
    m_length < new_len ? smallest = m_length : smallest = new_len;
    for (int i = 0; i < smallest; i++)
    {
        hold[i] = m_array[i];
    }
    delete[] m_array;
    m_array = nullptr;
    m_array = hold;
	m_length = new_len;
}

