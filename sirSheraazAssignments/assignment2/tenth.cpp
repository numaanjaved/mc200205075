//Question no 10
//x.	Write a program to convert binary to octal and then octal to hex and hex to decimal. Input will be given in binary. There should be delay of 3 seconds in between every conversion. No built –in function should be used.

#include<iostream>
#include<cmath>
#include<string>
#include<stdio.h>
#include<windows.h>
using namespace std;
int convertToDecimal(int binary){
    int decimal = 0;
    int i = 0;
    while(binary > 0){
        int last = binary%10;
        decimal += last * pow(2, i);
        ++i;
        binary = binary/10;
    }
    return decimal;
}
void delay(int limit){
    int time = 0;
    int number = 713750000 * limit;
    while(time < number){
        ++time;
    }
}
int convertToOctal(int binary){
    int octal = 0;;
    int decimal = convertToDecimal(binary);
    int i = 1;
    while(decimal > 0){
        int last = decimal%8;
        octal += last * i;
        i *= 10;
        decimal = decimal/8;
    }
    return octal;
}
string convertToHexa(int binary){
    string hexa = "";
    int i = 0;
    int decimal = convertToDecimal(binary);
    while(decimal != 0){
        int last = decimal%16;
        if(last < 10){
            last += 48;
        }
        else{
            last += 55;
        }
        hexa += char(last);
        ++i;
        decimal = decimal/16;
    };
    int j = hexa.length() - 1; char temp;
    for(int i = 0; i < hexa.length(); ++i){
        if(i < j){
            temp = hexa[i];        
            hexa[i] = hexa[j];
            hexa[j] = temp; 
        }
        else{
            break;
        }        
        --j;
    }
    return hexa;
}
int main(){
    int binary, decimal, octal;
    string hexa = "";
    cout << "Please enter a binary number: ";
    cin>>binary;
    decimal = convertToDecimal(binary);
    octal = convertToOctal(binary);
    hexa = convertToHexa(binary);
    delay(3);
    cout << "Octal = " << octal << endl;
    delay(3);
    cout << "Hexa = " << hexa << endl;     
    delay(3);
    cout << "Decimal = " << decimal << endl;
    
    return 0;
}