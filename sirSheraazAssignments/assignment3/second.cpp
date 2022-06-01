//Question 2 
//ii.	A three digit number is called Armstrong number if sum of cube of its digit is equal to number itself.
//E.g.- 153 is an Armstrong number because (13)+(53)+(33) = 153.
//Write all Armstrong numbers between 100 to 1000, if the sum of all the Armstrong numbers between 100 and 1000 are greater than non-Armstrong numbers from 100-200 then write all Armstrong numbers  from 100 to 1000  in Text File in sorted order ( No built-in function to be used for Sorting) else create an array and store the numbers in the array with their Ascii equivalent.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool isArmStrong(int number){
    bool armStrong = false;
    int oneth = number%10;
    int tenth = (number/10)%10;
    int hundredth = (number/100)%100;
    int cubeOfOneth = oneth * oneth * oneth;
    int cubeOfTenth = tenth * tenth * tenth;
    int cubeOfHundredth = hundredth * hundredth * hundredth;
    int sumOfAllCubes = cubeOfHundredth + cubeOfTenth + cubeOfOneth;
    
    if(sumOfAllCubes == number){
        armStrong = true;
    }
    return armStrong;
}
int convertToAscii(int number){
    int oneth = number%10;
    int tenth = (number/10)%10;
    int hundredth = (number/100)%100;
    int ascIIofHundredth = hundredth + 48;
    int ascIIofTenth = tenth + 48;
    int ascIIofOneth = oneth + 48;
    return  ascIIofHundredth*10000 + ascIIofTenth*100 + ascIIofOneth;
}
int main(){
    cout << "List of ArmStrong Numbers from 100 to 1000" << endl;
    int sumOfArmStrongNumbers = 0;
    int sumOfNotArmStrongNumbers = 0;
    vector<int> armStrongNumbers;
    for(int i = 101; i < 1000; ++i){        
        if(isArmStrong(i)){
            cout << i << endl;
            armStrongNumbers.push_back(i);

            sumOfArmStrongNumbers += i;
        }
        if(i < 200 && isArmStrong(i) == false){
            sumOfNotArmStrongNumbers += i;
        }
    }
    if(sumOfArmStrongNumbers > sumOfNotArmStrongNumbers){
        fstream file;
        file.open("second.txt", ios::app | ios::out);
        for(int i = 0; i < armStrongNumbers.size(); ++i){
            file << armStrongNumbers[i];
        }
        file.close();
    }
    else{
        int **arrayOfArmStrongNumbers = new int*[armStrongNumbers.size()];
        for(int i = 0; i < armStrongNumbers.size(); ++i){
            arrayOfArmStrongNumbers[i] = new int[2];
        }
        for(int i = 0; i < armStrongNumbers.size(); ++i){
            arrayOfArmStrongNumbers[i][0] = armStrongNumbers[i];
            arrayOfArmStrongNumbers[i][1] = convertToAscii(armStrongNumbers[i]);
        }
        cout << "Numbers are saved with their corresponding ASCII Values in the array" << endl;
        cout << "Displaying the array in order" << endl;
        for(int i = 0; i < armStrongNumbers.size(); ++i){
            for(int j = 0; j < 2; ++j){
                cout << arrayOfArmStrongNumbers[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < armStrongNumbers.size(); ++i){
            delete [] arrayOfArmStrongNumbers[i];
        }
        delete [] arrayOfArmStrongNumbers;
    }
    
    return 0;
}