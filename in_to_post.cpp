#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
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
    return 0;
}


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
//			operators.push(c);
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

int main() {
    string ex = "A+B*c-d/y";
    cout << "Infix: " << ex << endl
         << "Postfix: " << infix_to_postfix(ex);

    return 0;
}
