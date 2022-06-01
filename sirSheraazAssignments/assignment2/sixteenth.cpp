//Question no 16
//xvi.	A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two digit and 3-digit numbers.


#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
using namespace std;

int noOfDigits(int number){
    int count = 0;
    while(number != 0){
        ++count;
        number = number/10;
    }
    return count;
}

int reverseNumber(int number){
    int last = 0;
    int reverse = 0;
    int count = noOfDigits(number);
    while(count != 0){
        last = number%10;
        reverse += (pow(10,(count-1)))*last;
        number = number / 10;
        --count;
    }
    return reverse;
}
bool isPalindrome(int number){
    bool palindrome = false;
    int reverse = reverseNumber(number);
    if(number == reverse){
        palindrome = true;
    }
    return palindrome;
}

int main(){
    vector<int> twoDigitNumbers;    
    for(int i = 10; i < 100; ++i){
        twoDigitNumbers.push_back(i);
    }
    vector<int> threeDigitNumbers;
    for(int i = 100; i < 1000; ++i){
        threeDigitNumbers.push_back(i);
    }
    vector<int> productOf2d3dNumbers; 
    for(int i = 0; i < twoDigitNumbers.size(); ++i){
        for(int j = 0; j < threeDigitNumbers.size(); ++j){
            int product = twoDigitNumbers[i]*threeDigitNumbers[j];
            productOf2d3dNumbers.push_back(product);            
        }
    }
    vector<int> palindromeInProduct;
    for(int i = 0; i < productOf2d3dNumbers.size(); ++i){
        if(isPalindrome(productOf2d3dNumbers[i])){
            palindromeInProduct.push_back(productOf2d3dNumbers[i]);
        }
    }
    int index = palindromeInProduct.size() - 1;
    cout << "The Largest Palindrome possible is " << palindromeInProduct[index];
    cout << endl;
    return 0;
}