// reverse Polish (or postfix) notation
// is used to represent algebraic expressions. 
// see https://en.wikipedia.org/wiki/Reverse_Polish_notation

// for example:
// vec={"12", "4", "2", "+", "*"};
// is: (4+2)*12

//parse input expression (walk the string vector) and for every element:
//  if the element is a number, push it into the stack 
//  else (the element is an operator), 
//      pop 2 operands for the operator from the stack. 
//      evaluate the operation and push result back into the stack 
// when the input vector expression is finished, the value remaining in the stack should be the final result

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isNumber(const string& str){
    for (char const &c : str) 
        if (std::isdigit(c) == 0) return false;
    
    return true;
}

//returns false if error detected in the expression or division by 0
bool evaluatePolish (const vector<string> &expression, int &result){
    stack<string> myStack;
    
    for (auto const &s:expression)
        if (isNumber(s))//number
            myStack.push(s);
        else{ 
            //operation
            if (myStack.empty())    return false;
            auto num1 = stoi(myStack.top()); 
            myStack.pop();
            if (myStack.empty())    return false;
            auto num2 = stoi(myStack.top());  
            myStack.pop();
            switch (s[0]){ 
                case '+': 
                    myStack.push(to_string(num1 + num2));
                    break; 
                case '-': 
                    myStack.push(to_string(num2 - num1)); 
                    break; 
                case '*': 
                    myStack.push(to_string(num2 * num1));                     
                    break; 
                case '/': 
                    if (num1==0) return false;//division by 0
                    myStack.push(to_string(num2 / num1)); 
                    break; 
                case '%': //operator not in the original
                    if (num1==0) return false;//division by 0
                    myStack.push(to_string(num2%num1)); 
                    break; 
                case '^'://operator not in the original
                    myStack.push(to_string(num1 ^ num2));
                default://eror!!!!
                    return false;
            }
        }
 
    if (myStack.empty()) return false;//error!!!
    result=stoi(myStack.top());
    return true;
}

vector<string> infix2Polish (vector<string> in);

int main(){
    const vector<string> postfixV={"12", "4", "2", "+", "*"}; //(4+2)*12
    int result=0;
    auto st=evaluatePolish(postfixV, result);
    if (!st)
        cout<<"error!!"<<endl;
    else
        cout<<"result: "<<result<<endl;
        
    //this is just for fun, not in the evaluation
    const vector<string> infix ={"2", "+", "3", "*", "(","10", "-", "4", ")"};
    auto r=infix2Polish(infix);
    
    cout<<"infix 2 polish result: ";
    for( auto const &s: r){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}


