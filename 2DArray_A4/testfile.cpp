//
//  main.cpp
//  2DArray_A3
//
//  Created by Ian Murphy on 1/8/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//
#include <string>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
#include "Array2D.h"

template <typename T>
void DisplayContents(const Array2D<T> & arr);

template <typename T>
void DisplayContentsLinear(const Array2D<T> & arr);

template <typename T>
void TestDuplication(Array2D<T> * arr);

template <typename T>
void TestDuplication(const Array2D<T> * arr);

template <typename T>
void TestSpecialCases(Array2D<T> * arr);

template <typename T>
void TestOtherFeatures(Array2D<T> * arr);

template <typename T>
void TestConstness(const Array2D<T> &arr);

int main() {
    
    
    
    //Initialize Array
    Array2D<int> * myArray = new Array2D<int>(5,5);
    int i = 1;
    for (int row = 0; row<5; row++) {
        for(int col = 0; col< 5; col++)
        {
            (*myArray)[row][col] = i;
            i++;
        }
    }
    DisplayContents(*myArray);
    
    
    
    TestDuplication(myArray);
    TestSpecialCases(myArray);
    TestOtherFeatures(myArray);
    
    Array2D<std::string> * strArray = new Array2D<std::string>(3, 3);
    
    //init array
    char c[2] = "a";
    for (int row = 0; row<3; row++) {
        for(int col = 0; col< 3; col++)
        {
            c[0]++;
            std::string str = c;
            str += str;
            (*strArray)[row][col] = str;
            
        }
    }
    
    DisplayContents(*strArray);
    TestDuplication(strArray);
    TestSpecialCases(strArray);
    TestOtherFeatures(strArray);
    return 0;
}

template <typename T>
void DisplayContents(const Array2D<T> &arr)
{
    cout<<"------ Displaying Array contents-----"<<endl;
    
    int row_s = arr.getRow();
    int col_s = arr.getColumn();
    cout<<"------ Size: " << row_s << " by " << col_s<< " -----"<<endl;
    for (int row = 0; row<row_s; row++) {
        
        for(int col = 0; col< col_s; col++)
        {
            cout<<std::setw(3)<<arr[row][col];
        }
        cout<<endl;
    }
}

template <typename T>
void DisplayContentsLinear(const Array2D<T> &arr)
{
    int row_s = arr.getRow();
    int col_s = arr.getColumn();
    
    for (int row = 0; row<row_s; row++) {
        
        for(int col = 0; col< col_s; col++)
        {
            cout<<std::setw(3)<<arr[row][col];
        }
        
    }
    cout<<endl;
}


template <typename T>
void TestDuplication(Array2D<T> *arr)
{
    cout<<"************* TESTING COPY CTOR **************"<<endl;
    cout<<"************* After pass by reference ************"<<endl;
    DisplayContents(*arr);
    
    Array2D<T> * arr2 = new Array2D<T>(*arr);
    cout<<"************* After copy ctor ************"<<endl;
    DisplayContents(*arr2);
    
    cout<<"************ Change some values **********"<<endl;
    for (int row = 0; row<arr->getRow(); row++) {
        for (int col = 0; col<arr->getColumn(); col++) {
            (*arr2)[row][col] = 100;
        }
    }
    
    
    DisplayContents(*arr2);
    
    cout<<"************ Testing OP =  **********"<<endl;
    
    arr = arr2;
    DisplayContents(*arr);
    
    
}

template <typename T>
void TestSpecialCases(Array2D<T> *arr)
{
    cout<<"************* TESTING SPECIAL CASES **************"<<endl;
    cout<<"************* Testing out of bounds **************"<<endl;
    try{
        cout<<(*arr)[6][7]<<endl;
    }
    catch(Exception &e){
        cout<<e<<endl;
    }
    
    cout<<"************* Testing set column to -1 **************"<<endl;
    
    try{
        arr->setColumn(-1);
    }
    catch(Exception &e){
        cout<<e<<endl;
    }
    cout<<"************* Testing set row to -1 **************"<<endl;
    try{
        arr->setRow(-1);
    }
    catch(Exception &e){
        cout<<e<<endl;
    }
    cout<<"************* Testing set row to 0 **************"<<endl;
    try{
        arr->setRow(0);
    }
    catch(Exception &e){
        cout<<e<<endl;
    }
    cout<<"************* Testing set col to 0 **************"<<endl;
    try{
        arr->setColumn(-1);
    }
    catch(Exception &e){
        cout<<e<<endl;
    }
}

template <typename T>
void TestOtherFeatures(Array2D<T> *arr)
{
    DisplayContents(*arr);
    cout<<"************* TESTING OTHER FEATURES **************"<<endl;
    cout<<"************* Testing set lower bounds **************"<<endl;
    arr->setRow(3);
    arr->setColumn(2);
    DisplayContents(*arr);
    
    cout<<"\n************* Testing set higher bounds **************"<<endl;
    arr->setRow(4);
    arr->setColumn(6);
    DisplayContents(*arr);
    
    TestConstness(*arr);
    
    cout<<"\n************* Testing select **************"<<endl;
    cout<<"\n************* put 23 in [2][2] **************"<<endl;
    (*arr)[2][2] = 23;
    cout<<arr->Select(2,2)<<endl;

    
}

template <typename T>
void TestConstness(const Array2D<T> &arr)
{
    cout<<"\n************* TESTING CONST METHODS **************"<<endl;
    cout<<"\n************* Testing modify const values **************\nBefore"<<endl;
    DisplayContents(arr);
    //arr[0][0] = 90;       //won't compile, doesn't allow assignment
    DisplayContents(arr);
}
