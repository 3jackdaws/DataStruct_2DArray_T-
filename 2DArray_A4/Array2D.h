//
//  Array2D.h
//  2DArray_A3
//
//  Created by Ian Murphy on 1/9/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//
#pragma once
#include "Row.h"
#include "Exception.h"
template <typename T>
class Array2D
{
public:
    friend class Row<T>;
    Array2D();
    Array2D(int row, int col);
    Array2D(const Array2D<T> & cp);
    ~Array2D();
    
    Array2D & operator = (const Array2D & rhs);
    Row<T> operator [] (int index);
    const Row<T> operator [] (int index) const;
    int getRow() const;
    void setRow(int rows);
    int getColumn() const;
    void setColumn(int col);
    T & Select(int row, int col);
    
private:
    T ** m_array;
    int _row;
    int _col;
};

template <typename T>
Array2D<T>::Array2D() : _col(0), _row(0)
{
    m_array = nullptr;;
}

template <typename T>
Array2D<T>::Array2D(int row, int col) : _col(col), _row(row)
{
    if(row < 1 || col < 1)
        throw Exception("InvalidSizeException");
    for(int i = 0; i< row; i++)
    {
        m_array = new T[col];
    }
    
}

template <typename T>
Array2D<T>::Array2D(const Array2D<T> & cp) : _col(cp._col), _row(cp._row), m_array(nullptr)
{
    if(cp.m_array)
        m_array = new T[_col*_row];
}

template <typename T>
Array2D<T>::~Array2D()
{
    delete [] m_array;
}


template <typename T>
Array2D<T> & Array2D<T>::operator=(const Array2D<T> &rhs)
{
    if(this != &rhs)
    {
        _row = rhs._row;
        _col = rhs._col;
        m_array = rhs.m_array;
    }
    return *this;
}


template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
    Row<T> row(*this, index);
    return row;
}

template <typename T>
const Row<T> Array2D<T>::operator[](int index) const
{
    return Row<T> (*this, index);
}




template <typename T>
int Array2D<T>::getRow() const
{
    return _row;
}

template <typename T>
void Array2D<T>::setRow(int rows)
{
    if(rows == _row)
    {
        
    }
    else if(rows > 0)
    {
        _row = rows;
        m_array.setLength(_row*_col);
    }
    else{
        throw Exception("InvalidRowNumberException");
    }
}

template <typename T>
int Array2D<T>::getColumn() const
{
    return _col;
}

template <typename T>
void Array2D<T>::setColumn(int col)
{
    if(col == _col)
    {
        
    }
    else if(col > 0)
    {
        _col = col;
        m_array.setLength(_row*_col);
    }
    else{
        throw Exception("InvalidColumnNumberException");
    }
}

template <typename T>
T & Array2D<T>::Select(int row, int col)
{
    return m_array[row*col+col];
}




