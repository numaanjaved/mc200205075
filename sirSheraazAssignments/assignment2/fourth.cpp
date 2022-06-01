//Question 4
//iv.	Given an input  n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main(){
    int number;
    cout << "Enter upto 4 digit positive integer: ";     
    cin>>number;
    while(number < 0){
        cout << "You have entered a negative number. Please input a positive number" << endl;
        cout << "Enter upto 4 digit positive integer: ";     
        cin>>number;
    }
    while(number > 9999){
        cout << "Your number is greater than 4 digit capacity. Please input maximum 4 digit number." << endl;
        cout << "Enter upto 4 digit positive integer: ";
        cin>>number;
    }
    int digit = 1; int numberOf1s = 0;
    for(int i = 0; i <= number; ++ i){
        if(i == digit){
            ++numberOf1s;
        }
        if(i > 9){
            if((i/10)%10 == digit){
                ++numberOf1s;
            }
            if(i%10 == digit){
                ++numberOf1s;
            }
            if(i > 99){
                if((i/100)%10 == digit){
                    ++numberOf1s;
                }
                if(i > 999){
                    if((i/1000)%10 == digit){
                        ++numberOf1s;
                    }
                }
            }  
        }
    }
    cout << "Number of 1s = " << numberOf1s;
    return 0;
}