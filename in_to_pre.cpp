#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int op_val(char op) {
    switch (op) {
        case '+':
            return 5;
        case '-':
            return 4;
        case '*':
            return 3;
        case '/':
            return 2;
        case '^':
            return 1;
    }
    throw "Unknown Operator";
    return 0;
}

// first convert to postfix
string infix_to_postfix(string infix){
	string postfix;
	stack<char> operators;
	
	for(int i = 0; infix[i] != NULL; i++){
		char c = infix[i];
		
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
			postfix += infix[i];
		}
		else if(c == '+' || c=='-' || c=='*' || c=='/' || c=='^'){
			while(!operators.empty() && op_val(c) >= op_val(operators.top())){
				postfix += operators.top();
				operators.pop();
			}
			operators.push(c);
		}
		
	}
	
	while(!operators.empty()){
		postfix += operators.top();
		operators.pop();
	}
	
	return postfix;
}


string infix_to_prefix(string infix) {
    reverse(infix.begin(), infix.end()); // Reverse infix expression
    string postfix = infix_to_postfix(infix); // Convert reversed infix to postfix
    reverse(postfix.begin(), postfix.end()); // Reverse postfix to get prefix
    return postfix;
}

int main() {
	try{
	    string ex = "A+B*c-d/y";
	    cout << "Infix: " << ex << endl
	    	 << "Postfic: "<< infix_to_postfix(ex)<<endl
	         << "Prefix: " << infix_to_prefix(ex);
		
	} catch(char *error){
		cerr<<error<<endl;
	}
    return 0;
}
