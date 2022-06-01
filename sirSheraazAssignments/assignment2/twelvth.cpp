//Question no 12
//xii.	A 3x3 normal magic square is a 3x3 grid where the numbers on each row, each column, and both diagonals all add up to the same number, and the square contains the numbers 1 to 9 exactly. 
//4 9 2
//3 5 7
//8 1 6
//Implement a function which, given a two-dimensional 3 by 3 array of ints returns a Boolean that tells us if the given square (represented by the array) is a normal 3 by 3 magic square or not.


#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class magicSquare{
    public:
    magicSquare(){
        this->inputSquare();
        this->setSize();
        this->setSize2();
        this->addIntoSumOfArray();
        this->setIsMagicSquare();
    };
    void setSize(){
        this->size = sizeof(this->square)/sizeof(this->square[0]);
    }
    void setSize2(){
        this->size2 = sizeof(this->square[0])/sizeof(this->square[0][0]);
    }
    void display(){
        for(int i = 0; i < this->size; ++i){  
            for(int j = 0; j < this->size2; ++j){
                cout << " " << this->square[i][j];
            }
            cout << endl;
        }
    }
    void inputSquare(){
        cout << "Please Enter entries in all magic square" << endl;
        for(int i = 0; i < 3; ++i){  
            for(int j = 0; j < 3; ++j){
                cin >> this->square[i][j];
            }
        }
    }
    void addIntoSumOfArray(){
        int sumOfFirstDiagonal = 0;
        int sumOfSecondDiagonal = 0;
        for(int i = 0; i < size; ++i){  
            
            int sumOfRows = 0;
            int sumOfColumns = 0;
            
            for(int j = 0; j < size2; ++j){
                sumOfRows += this->square[i][j];
                sumOfColumns += this->square[j][i];
                if(i == j){
                    sumOfFirstDiagonal += this->square[i][j];                
                }
                if(j == size2 - 1 - i){
                    sumOfSecondDiagonal += this->square[i][j];
                }
                if(j == size2 - 1){
                    this->sumOfArray.push_back(sumOfRows);
                    this->sumOfArray.push_back(sumOfColumns);
                }            
            }
        }
        this->tempSum = sumOfFirstDiagonal;
        this->sumOfArray.push_back(sumOfFirstDiagonal);
        this->sumOfArray.push_back(sumOfSecondDiagonal);
    }
    void setIsMagicSquare(){
        this->isMagic = false;
        for(int i = 0; i < sumOfArray.size(); ++i){
            if(tempSum != sumOfArray[i]){
                break;
            }
            else{
                this->isMagic = true;
                break;
            }
        }
    }
    void displaySumOfArray(){
        for(int i = 0; i < this->sumOfArray.size(); ++i){
            cout << this->sumOfArray[i] << " ";
        }
        cout << endl;
    }
    int square[3][3];
    int size;
    int size2;
    int tempSum;
    bool isMagic;
    vector <int> sumOfArray;

};





int main(){
    
    
    magicSquare* Square = new magicSquare();
    if(Square->isMagic){
        cout << "This square is a magic Square" << endl;
    }
    else{
        cout << "This square is not a magic Square";
    }

    
    return 0;
}