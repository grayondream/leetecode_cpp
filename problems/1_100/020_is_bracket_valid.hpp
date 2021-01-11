#include "ios_include.hpp"


bool isValid(string s) {
    stack<char> stk;
    for(auto ch : s){
        if(ch == '(' || ch =='{' || ch =='['){
            stk.push(ch);
        }else{
            if(stk.empty()) return false;
            if(ch == ')'){
                if(stk.top() != '(') return false;
                stk.pop();
            } else if(ch == ']'){
                if(stk.top() != '[') return false;
                stk.pop();
            } else if(ch == '}'){
                if(stk.top() != '{') return false;
                stk.pop();
            }
        }
    }

    if(stk.empty()) return true;
    return false;
}