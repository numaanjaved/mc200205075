//Question 3 
//iii.	Convert a non-negative integer to its English words representation and print in reverse if total characters in English words are more than total words in a sentence.

#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

string last2Digits(int number, string oneDigit[]){
    string teenDigit[10] = {
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };
    string tenthDigit[10] = {
        "zero","ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };
    string finalResult = "";
    int tenth = number/10;
    int last = number%10;
    if(number > 19){
        
        if(last == 0){
            finalResult += tenthDigit[tenth%10] ;
        }
        else{
            finalResult += tenthDigit[tenth%10];
            finalResult +=  " ";
            finalResult += oneDigit[last];
        }
        
    }
    else if(number > 9){
        finalResult +=  teenDigit[last];
    }
    else if(number < 10){
       finalResult += oneDigit[number]; 
    }
    return finalResult;
};
int main(){
    
    int number;
    cout << "Enter the positive integer: ";     
    cin>>number;    
    while(number < 0){
        cout << "You have entered a negative number. Please input a positive number" << endl;
        cout << "Enter the positive integer: ";     
        cin>>number;
    }
    string oneDigit[10] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    string finalResult = "";
    int hundredth = number/100;
    int hundredth2last = number%100;
    int tenth = number/10;
    int tenthLast = tenth%10;
    int last = number%10;
    cout << hundredth%10 << endl;
    if(number > 99){
        finalResult += oneDigit[hundredth%10];
        if(last == 0 && tenthLast == 0){
            finalResult += " hundred";
        }
        else{           
            finalResult += " hundred and ";
            finalResult += last2Digits(hundredth2last, oneDigit);            
        }
    }
    else{
        finalResult += last2Digits(number, oneDigit);
    }
    cout << "Correct English Representation = "<< finalResult << endl;
    
    int countWord = 1;
    int countCharacters = 0;
    int lengthSentence = finalResult.length();
    for(int i = 0; i < lengthSentence; ++i){
        if(finalResult[i] == ' '){
            ++countWord;
        }
        else{
            ++countCharacters;
        }        
    }
    cout << "Total Words  = " << countWord << endl;
    cout << "Total Characters = " << countCharacters << endl;  
    if(countCharacters > countWord){
        int j = lengthSentence - 1;
        for(int i = 0; i < lengthSentence; ++i){
            if(i < j){
                char temp = finalResult[i];
                finalResult[i] = finalResult[j];
                finalResult[j] = temp;
            }
            else{
                break;
            }
            --j;
        }
        cout << "As total Characters are More than total Words, so Reverse English representation is " << endl << finalResult;
    }
    
    return 0;
}