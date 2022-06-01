//Question no 6
//vi.	You are given an n x n 2D matrix representing an image.
//Rotate the image by 180 degrees (anti-clockwise) but after sorting the n*n 2D array


#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<vector<int>> matrix = {
        {2, 3, 1, 4},
        {5, 6, 8, 7},
        {14, 16, 15, 13},
        {10, 9, 12, 11},
        
    };
    
    for(int i = 0; i < matrix.size(); ++i){
        sort(matrix[i].begin(), matrix[i].end());
    }
    
    sort(matrix.begin(), matrix.end());
    for(int i = 0; i < matrix.size(); ++i){
        reverse(matrix[i].begin(), matrix[i].end());
    };
    
    reverse(matrix.begin(), matrix.end());

    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            cout << matrix[i][j];
        }       
        cout << endl; 
    }
    return 0;
}