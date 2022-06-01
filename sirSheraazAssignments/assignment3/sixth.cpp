//Question no 6: vi.	Take an array of length n where all the numbers are nonnegative and unique. Find the element in the array possessing the highest value. Split the element into two parts where first part contains the next highest value in the array and second part hold the required additive entity to get the highest value. Print the array where the highest values get splitted into those two parts.
//Sample input: 4 8 6 3 2
//Sample output: 4 6 2 6 3 2

//Store the output in the text file and make sure that there is no palindrome in the text file by comparing their Binary Equivalent.  

#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;
int convertToBinary(int decimal){
    int binary = 0;;
    int i = 1;
    while(decimal > 0){
        int last = decimal%2;
        binary += last * i;
        i *= 10;
        decimal = decimal/2;
    }
    return binary;
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

bool isUnique(int mainArray[], int n){
    bool unique = true;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if((i != j) && (mainArray[i] == mainArray[j])){
                unique = false;
                break;
            }
        }
    }
    return unique;
}
int main(){
    int n, number; 
    cout << "Enter the size of array = ";
    cin >> n;
    
    
    int *mainArray = new int[n];
    for(int i = 0; i < n; ++i){
        cout << "Enter unique and non negative value in array = ";
        
        cin >> number;
        mainArray[i] = number;
    }
    while(isUnique(mainArray, n) == false){
        cout << "The numbers you entered in array are not unique" << endl;
        cout << "Please enter unique numbers" << endl;
        for(int i = 0; i < n; ++i){
            cout << "Enter unique and non negative value in array = ";
            
            cin >> number;
            mainArray[i] = number;
        }
    }
    cout << "Original Array = ";
    for(int i = 0; i < n; ++i){
        cout << mainArray[i] << " " ;
    }
    cout << endl;
    int max = mainArray[0]; int position = 0;
    for(int i = 0; i < n; ++i){
        if(max < mainArray[i]){
            max = mainArray[i];
            position = i;
        }
    }
    
    int divisor = rand()%max;
    int firstNumber = max - divisor;
    int secondNumber = max - firstNumber;

    int next = mainArray[position+1];
    mainArray[position] = std::max(firstNumber, secondNumber);     
    mainArray[position+1] = std::min(firstNumber, secondNumber);


    for(int i = n; i > position + 2; --i){
        mainArray[i] = mainArray[i-1];
    }
    mainArray[position+2] = next;
    int binary = 0;
    cout << "Output Array = "  << endl;
    for(int i = 0; i < n+1; ++i){
        binary = convertToBinary(mainArray[i]);
        cout << mainArray[i] << " " << convertToBinary(mainArray[i]) << endl;
        if(isPalindrome(binary) == false){
            fstream file;
            file.open("sixthOutput.txt", ios::app | ios::out);
            file << mainArray[i] << " ";
            file.close();
        }
    }
    return 0; 
}