//
//  Row.h
//  2DArray_A3
//
//  Created by Ian Murphy on 1/9/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#pragma once
template <typename T> class Array2D;

template <typename T>
class Row
{
public:
    Row(Array2D<T> & array, int row);
    T & operator [] (int column);
    
private:
    Array2D<T> & m_array2D;
    int m_row;
};
