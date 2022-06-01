//Question 2 
// ii.	Write a C/C++ Program which should count the total number of vowel in the palindromes (if any) in an array and if the total number of vowels exceed total number of palindromes than create another array of character which should replace first vowel in first palindrome with last vowel in last palindrome and second palindrome in with second last and so on, in the end display the largest palindrome string with minimum number of vowels in Ascii values. 

#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

string reverse(string input){
    string reverse = input;
    int count  = reverse.length();
    int forwardIndex = 0; int backwardIndex = reverse.length() - 1;
    while(forwardIndex < backwardIndex){
        char temp = reverse[forwardIndex];
        reverse[forwardIndex] = reverse[backwardIndex];
        reverse[backwardIndex] = temp;
        ++forwardIndex;
        --backwardIndex;
        --count;
    }
    return reverse;
}
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
int findVowelPosition(string input, int position){
    int posVowel = 0; int pos = 0; 
    for(int j = 0; j < input.length(); ++j){
        if(input[j] == 'a' || input[j] == 'e' || input[j] == 'i' || input[j] == 'o' || input[j] == 'u'){
            if(pos >= position){
               posVowel = j;               
                
                break;
                
            }
            
        }
        ++pos;
    }
    return posVowel;
}
int findLastVowelPosition(string input, int position){
    int posVowel = 0; int pos = input.length() - 1; position = input.length() - position;
    for(int j = input.length() -1 ; j > -1; --j){
        if(input[j] == 'a' || input[j] == 'e' || input[j] == 'i' || input[j] == 'o' || input[j] == 'u'){
            if(pos <= position){
                posVowel = j;
                break;                  
            }     
        }
        --pos;
    }
    return posVowel;
}
bool isPalindrome(string& input){
    bool palindrome = false;
    string reversed = reverse(input);
    if(reversed == input){
        palindrome = true;
    }
    return palindrome;
}
int main(){
    
    
    string listOfStrings[10] = {
        "abcde", "bodob", "cueuc", "dofod", "efgfe", "fghij", "gijig", "hijkl", "ijklm", "jklmn"
        //input
    };
    int noOfVowels = 0; int noOfPalindromes = 0;
    int count = sizeof(listOfStrings)/sizeof(listOfStrings[0]);
    vector<string> listOfPalindrome;
        for(int i = 0; i < count; ++i ){
        if(isPalindrome(listOfStrings[i])){
            listOfPalindrome.push_back(listOfStrings[i]);
            noOfVowels += countVowels(listOfStrings[i]);
            ++noOfPalindromes;
        }        
    }
    if(noOfVowels > noOfPalindromes){
        int backpos = listOfPalindrome.size() - 1;
        int vowelPosition1 = 0; int vowelPosition2 = 0;
        for(int i = 0; i < listOfPalindrome.size(); ++i){
            vowelPosition1 = findVowelPosition(listOfPalindrome[i], i);
            vowelPosition2 = findLastVowelPosition(listOfPalindrome[backpos], backpos);
            if(isVowel(listOfPalindrome[i][vowelPosition1]) && isVowel(listOfPalindrome[backpos][vowelPosition2])){
                char temp = listOfPalindrome[i][vowelPosition1];
                listOfPalindrome[i][vowelPosition1] = listOfPalindrome[backpos][vowelPosition2];
                listOfPalindrome[backpos][vowelPosition2] = temp;
            }
            if(i >= backpos){
                
                    break;
            }      
            --backpos;               
        }
    }
    for(int i = 0; i < listOfPalindrome.size(); ++i){
        cout << listOfPalindrome[i] << endl;
    }
    return 0;
}