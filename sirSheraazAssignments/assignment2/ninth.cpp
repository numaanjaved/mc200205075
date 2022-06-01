//Question no 9
//ix.	Write a program which receive two strings and check whether there are atleast two substrings in string-1, if there are then swap their order within String-1


#include<iostream>
#include<set>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<stdio.h>

using namespace std;

int main(){
    string string1, string2; 
    vector<int> placement;
    cout << "Enter first string : ";
    getline(cin, string1);
    cout << "Enter second string : ";
    getline(cin, string2);
    for(int i = 0; i < string1.length(); ++i){
        for(int j = 0; j < string2.length(); ++j){
            if(string1[i] == string2[j]){
                cout << string1[i] << " ";
            }
            else{
                cout << 0 << " ";
                continue;
            }
        }
        cout << endl;
    }
    
    return 0;
}