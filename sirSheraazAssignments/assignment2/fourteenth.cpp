//Question no 14
//xiv.	If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.


#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main(){
    vector<int> naturalNumbers;
    for(int i = 1; i < 1000; ++i){
        naturalNumbers.push_back(i);
    }
    vector<int> divisibleBy3And5;

    for(int i = 0; i < naturalNumbers.size(); ++i){
        if(naturalNumbers[i]%3 == 0 || naturalNumbers[i]%5 == 0){
            divisibleBy3And5.push_back(naturalNumbers[i]);
        }
    }
    for(int i = 0; i < divisibleBy3And5.size(); ++i){
        cout << divisibleBy3And5[i] << " ";
    }
    cout << endl;

    return 0;
}