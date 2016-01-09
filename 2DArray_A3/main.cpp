//
//  main.cpp
//  2DArray_A3
//
//  Created by Ian Murphy on 1/8/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;
#include "Array2D.h"
int main() {
    
    Array2D<int> myArray(5,5);
    int i = 0;
    for (int row = 0; row<4; row++) {
        for(int col = 0; col< 4; col++)
        {
            i++;
            myArray[row][col] = i;
        }
    }
    
    for (int row = 0; row<4; row++) {
        for(int col = 0; col< 4; col++)
        {
            cout<<myArray[row][col]<<endl;
        }
    }
    
    
    
    return 0;
}
