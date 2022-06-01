//Question no 8
//viii.	Write a program which should evaluate a given mathematical expression , hint you need use Stack
//For Example: (2+3) -2 + (3*2) = 5-2+6= 9


#include<iostream>
#include<stack>
#include<string>
#include<stdio.h>
///Constraint of this algorithm: it works with only single digit numbers 
using namespace std;

int noOfDigits(int number){
    int count = 0;
    while(number != 0){
        ++count;
        number = number/10;
    }
    return count;
}
int performOperation(int a, char oper, int b){
    int result = 0;
    if(oper == '*'){
        result = a * b;
    }
    else if(oper == '/'){
        result = a / b;
    }
    else if(oper == '+'){
        result = a + b;
    }
    else if(oper == '-'){
        result = a - b;
    }
    else if(oper == '%'){
        result = a % b;
    }
    return result;
}
bool isOperator(char operater){
    bool ope = false;
    string operations = "+-*/%";
    for(int i = 0; i < operations.length(); ++i){
        if(operater == operations[i]){
            ope = true;
        }
    }
    return ope;
};
int precendent(char operater){
    int precedent = 0;
    if(operater == '*' || operater == '/' || operater == '%'){
        precedent = 2;
    }
    else if(operater == '+' || operater == '-'){
        precedent = 1;
    }
    else{
        precedent = 0;
    }
    return precedent;
}
bool isParanthesis(char paranthese){
    bool para;
    string paranthesis = "()";
    for(int i = 0; i < paranthesis.length(); ++i){
        if(paranthese == paranthesis[i]){
            para = true;
        }
    }
    return para;
}
stack<char> operations;
stack<int> numbers;
int main(){   
    string expression;
    cout << "Please enter an expression with only single digit numbers: ";
    getline(cin, expression);
    cout << "Expression = " << expression << endl;
    for(int i = 0; i < expression.length(); ++i){
        //cout << expression[i] << " " << endl;
        if(isOperator(expression[i]) == true){
            
            if(operations.size() != 0){
                int levelOpTop = precendent(operations.top());
                int levelExpressionTop = precendent(expression[i]);        
                
                if(levelOpTop >= levelExpressionTop){
                    char operation = operations.top();
                    operations.pop();
                    int number2 = numbers.top();
                    numbers.pop();
                    int number1 = numbers.top();
                    numbers.pop();
                    int result = performOperation(number1, operation, number2);
                    numbers.push(result);
                    
                }
            }
            operations.push(expression[i]);
        }
        else if(isParanthesis(expression[i]) == true){
            if(expression[i] == '('){
                operations.push(expression[i]);
            }
            else{                
                char operation = operations.top();
                operations.pop();
                int number2 = numbers.top();
                numbers.pop();
                int number1 = numbers.top();
                numbers.pop();
                int result = performOperation(number1, operation, number2);
                numbers.push(result);
                operations.pop();
            } 
        }
        else{
            int number = int(expression[i])-48;
            numbers.push(number);
        }
    }
    while(operations.size() != 0){
        char operation = operations.top();
        int number2 = numbers.top();
        numbers.pop();
        int number1 = numbers.top();
        numbers.pop();
        int result = performOperation(number1, operation, number2);
        numbers.push(result);
        operations.pop();
    }
    
        cout << numbers.top();
       
    
    return 0;
}