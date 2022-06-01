//i.	Write a Program to display lower alphabet when uppercase corresponding alphabet is pressed from keyboard but the catch is there should be gap of 2 sec at max between pressing the button and displaying character, Use of ASCII values is not allowed neither built-in delay function.

#include<iostream>
#include<chrono>
#include<conio.h>
using namespace std;
using namespace std::chrono;
void delay(int limit){
    int time = 0;
    int number = 713750000 * limit;
    while(time < number){
        ++time;
    }
}

int main(){
    char ch; 
    
    while(ch != '/'){
        ch = _getch();
        char output = tolower(ch);
        auto start = high_resolution_clock::now();
        delay(2);
        auto stop = high_resolution_clock::now();
        cout << output;
        auto duration = duration_cast<seconds>(stop - start);
        cout << endl << "The Timeloop took " << duration.count() << " seconds " << endl;
    }
    
    return 0;
}