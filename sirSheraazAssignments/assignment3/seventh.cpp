//vii.	Write a function “perfect()” that determines if parameter number is a perfectnumber. Use this function in a program that determines and prints all the perfect numbers between 1 and 1000.
//[An integer number is said to be “perfect number” if its factors, including 1(but not the number itself), sum to the number. E.g., 6 is a perfect number because 6=1+2+3]. If total count of perfect numbers are more than total number of non-perfect  numbers from 1 to 3000 then check that how many Vowels exists in every perfect number between 1 to 1000 and if there are more than 2-consecutive Vowels then swap the next 2-non-consective and store all such vowels in an array. 


#include<iostream>
#include<vector>
using namespace std;
string vowels = "aeiou";
int countVowels(string input){
    int countVowel = 0;
    for(int j = 0; j < input.length(); ++j){
        if(input[j] == 'a' || input[j] == 'e' || input[j] == 'i' || input[j] == 'o' || input[j] == 'u'){
            ++countVowel;
        }
    }
    return countVowel;
}
bool isVowel(char input){
    bool isVowel = false;
    if(input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u'){
        isVowel = true;
    }
    
    return isVowel;
}
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
string convertToEnglish(int number){
    string oneDigit[10] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    string finalResult = "";
    int hundredth = number/100;
    int hundredth2last = number%100;
    int tenth = number/10;
    int tenthLast = tenth%10;
    int last = number%10;
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
    return finalResult;
}

bool perfect(int number){
    int sumOfDivisors = 0;
    bool isPerfect = false;
    for(int i = 1; i < number; ++i){
        if(number%i == 0){
            sumOfDivisors += i;
        }
    }
    if(sumOfDivisors == number){
        isPerfect = true;
    }
    return isPerfect;
}
int main(){
    int minimum = 1; int maximum = 1000; int perfectCountBetween1And1000 = 0; bool notPerfect; vector<int> perfectsBetween1And1000;
    cout << "Perfect numbers between " << minimum << " and " << maximum << " are ";
    notPerfect = true;
    for(int i = minimum; i < maximum + 1; ++i){
        if(perfect(i) == true){
            notPerfect = false;
            perfectsBetween1And1000.push_back(i);
            cout << i << " " ;
            ++perfectCountBetween1And1000;
        }
    }
    if(notPerfect == true){
        cout << "not present";
    }
    cout << endl;
    minimum = 1; maximum = 3000; int notPerfectCountBetween1And3000 = 0; int perfectCountBetween1And3000 = 0;
    cout << "Perfect numbers between " << minimum << " and " << maximum << " are ";
    notPerfect = true;
    for(int i = minimum; i < maximum + 1; ++i){
        if(perfect(i) == true){
            notPerfect = false;
            cout << i << " " ;
            ++perfectCountBetween1And3000;
        }
        else{
            ++notPerfectCountBetween1And3000;
        }
    }
    if(notPerfect == true){
        cout << "not present";
    }
    cout << endl;   
    
    if(perfectCountBetween1And3000 > notPerfectCountBetween1And3000){ // not executed 
        for(int i = 0; i < perfectsBetween1And1000.size(); ++i){
        vector<char> vowelsInConvert;
        string englishConvert = convertToEnglish(perfectsBetween1And1000[i]);
        cout << perfectsBetween1And1000[i] << " ";
        cout << englishConvert << " ";
        for(int j = 0; j < englishConvert.size() - 1; ++j){
            if(isVowel(englishConvert[j]) == true){
                vowelsInConvert.push_back(englishConvert[j]);
            }
        }
        cout << vowels.size() << endl;
        for(int j = 0; j < vowelsInConvert.size() - 1; ++j){
            for(int k = 0; k < vowels.size() - 1; ++k){
                if(vowelsInConvert[j] == vowels[k] && vowelsInConvert[j+1] == vowels[k+1]){
                    if(!vowelsInConvert[j+2] && !vowelsInConvert[j+3]){
                        char temp = vowelsInConvert[j+2];
                        vowelsInConvert[j+2] = vowelsInConvert[j+3];
                        vowelsInConvert[j+3] = temp;
                    }
                }
            }
        }
    }
    cout << endl;
    }

}