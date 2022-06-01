//Question no 7 
//vii.	Given a string containing just the characters '(' and ')', find the length of the longest and shortest valid (well-formed) parentheses substring.
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.


#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<stack>
using namespace std;

int main(){
    string para;
    cout << "Enter combination of ( or ) in a line : ";
    getline(cin, para);
    stack<int> paranthesis;
    paranthesis.push(-1);
    int max = 0;
    for(int i = 0; i < para.length(); ++i){
        if(para[i] == '('){
            paranthesis.push(i);
        }
        else{
            paranthesis.pop();            
            if(paranthesis.size() == 0){
                paranthesis.push(i);
            }
            else{
                int length = i - paranthesis.top();
                max = std::max(max, length);
            }
        }
    }
    cout << max;
    return 0;
}