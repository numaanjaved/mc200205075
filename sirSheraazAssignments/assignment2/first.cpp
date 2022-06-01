//Question 1
//i.	Write a C / C++ program which should read the n number of integers from the user and output total number of possible group (s) of two integer values if difference between two integer’s values is greater than their product to the power of total integer values but should be less than total number of palindromes in two different arrays of characters which are having odd and even strings simultaneously, in either case total sum of character values (Ascii values) of 2 arrays should be displayed as output only and only if the sum is less than total number of integers minus total number of characters in the two arrays. 


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int convertToAscii(int number){
    return number + '0';
}

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
        reverse += (pow(10,(count-1) ) )*last;
        number = number / 10;
        --count;
    }
    return reverse;
}
bool isPalindrome(int number){
    bool palindrome = false;
    int reverse = reverseNumber(number);
    if(number == reverse || noOfDigits(number) == 1){
        palindrome = true;
    }
    return palindrome;
}

int main(){
    int number;
    cout << "Input how many numbers you want to work with = ";
    cin >> number;
    vector<int> inputs;
    for(int i = 0; i < number; ++i){
        int input;
        cout << "Input number " << i + 1 << " upto 6 digit only = ";
        cin >> input;
        inputs.push_back(input);
    }
    vector<pair<int, int>> pairs;
    int numberOfPalindrome = 0;
    for(int i = 0; i < inputs.size(); ++i){
        for(int j = 0; j < inputs.size(); ++j){
            pair<int, int> temp;
            temp.first = inputs[i];
            temp.second = inputs[j];
            pairs.push_back(temp);
        }
    }
    for (int i = 0; i < pairs.size(); i++){
        bool oddAndEven = false;
        if(pairs[i].first%2 == 0 && pairs[i].second%2 != 0){
            oddAndEven = true;
        }
        if(pairs[i].first%2 != 0 && pairs[i].second%2 == 0){
            oddAndEven = true;
        }
        if(oddAndEven == true){
            if(isPalindrome(pairs[i].first)){
                ++numberOfPalindrome;
            }
            if(isPalindrome(pairs[i].second)){
                ++numberOfPalindrome;
            }
        }
    }
    int sum1 = 0; int sum2= 0;
    for (int i = 0; i < pairs.size(); i++){
        if(noOfDigits(pairs[i].first) < 2){
            sum1 = convertToAscii(pairs[i].first);
        }
        else{
            int value = pairs[i].first%10;
            int value2 = (pairs[i].first%100 - value)/10;
            int value3 = (pairs[i].first%1000 - value2 - value)/100;
            int value4 = (pairs[i].first%10000 - value3 - value2 - value)/1000;
            int value5 = (pairs[i].first%100000 - value4 - value3 - value2 - value)/10000;
            int value6 = (pairs[i].first%1000000 - value5 - value4 - value3 - value2 - value)/10000;

            sum1 = convertToAscii(value6) + convertToAscii(value5) + convertToAscii(value4) + convertToAscii(value3) + convertToAscii(value2) + convertToAscii(value);
        }
        if(noOfDigits(pairs[i].first) < 2){
            sum2 = convertToAscii(pairs[i].second);
        }
        else{
            int value = pairs[i].second%10;
            int value2 = (pairs[i].second%100 - value)/10;
            int value3 = (pairs[i].second%1000 - value2 - value)/100;
            int value4 = (pairs[i].second%10000 - value3 - value2 - value)/1000;
            int value5 = (pairs[i].second%100000 - value4 - value3 - value2 - value)/10000;
            int value6 = (pairs[i].second%1000000 - value5 - value4 - value3 - value2 - value)/10000;

            sum2 = convertToAscii(value6) + convertToAscii(value5) + convertToAscii(value4) + convertToAscii(value3) + convertToAscii(value2) + convertToAscii(value);
        }
        
        bool condition1 = abs(pairs[i].first - pairs[i].second) > pow((abs(pairs[i].first)*abs(pairs[i].second)), number);
        bool condition2 = abs(pairs[i].first - pairs[i].second) < numberOfPalindrome;
        bool condition3 = (sum1 + sum2) < (number - (noOfDigits(pairs[i].first) + noOfDigits(pairs[i].second)));
        if(condition1 == true && condition2 == true && condition3 == true){
            cout << "Pair Output " << i + 1 << " is " << pairs[i].first << "  " << pairs[i].second << endl; 
        }
    }    
}
