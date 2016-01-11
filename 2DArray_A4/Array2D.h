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
    T ** DuplicateArray(int rows, int cols) const;
    
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
    m_array = new T*[row];
    for(int i = 0; i< row; i++)
    {
        m_array[i] = new T[col];
    }
    
}

template <typename T>
Array2D<T>::Array2D(const Array2D<T> & cp) : _col(cp._col), _row(cp._row), m_array(nullptr)
{
    if(cp.m_array)
    {
        m_array = cp.DuplicateArray(_row, _col);
    }
    
}

template <typename T>
Array2D<T>::~Array2D()
{
    for(int row = 0; row<_row; row++)
    {
        delete [] m_array[row];
    }
    delete [] m_array;
}


template <typename T>
Array2D<T> & Array2D<T>::operator=(const Array2D<T> &rhs)
{
    if(this != &rhs)
    {
        m_array = rhs.DuplicateArray(rhs._row, rhs._col);
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
    if(index >= _row)
        throw Exception("OutofBoundsException");
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
         m_array = DuplicateArray(rows, _col);
        _row = rows;
        
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
        m_array = DuplicateArray(_row, col);
        _col = col;
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

template <typename T>
T ** Array2D<T>::DuplicateArray(int rows, int cols) const
{
    T ** return_val = nullptr;
    if(rows > 0 && cols > 0)
    {
        
        T ** newArray = new T*[rows];
        for(int i = 0; i< rows; i++)
        {
            newArray[i] = new T[cols];
        }
        
        if(rows > _row)
            rows = _row;        //find the smallest
        if(cols > _col)
            rows = _col;
        
        for(int row = 0; row<rows; row++)
        {
            for(int col = 0; col<cols; col++)
            {
                newArray[row][col] = m_array[row][col];
            }
        }
        return_val = newArray;
    }
    return return_val;
}


