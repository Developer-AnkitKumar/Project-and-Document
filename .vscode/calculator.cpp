#include<iostream>
#include<stack>
using namespace std;

int evaluateExpression(const string& expression){
    stack<int> operands;
    stack<char> operators;

    for(char ch : expression){
        if(isdigit(ch)){
            operands.push(ch - '0');
        }
        else if(ch == '('){
            operators.push(ch);
        }
        else if(ch == ')'){
            while(!operators.empty() && operators.top() != '('){
                int operands2 = operands.top();
                    operands.pop();

                    int operands1 = operands.top();
                    operands.pop();

                    char op = operators.top();
                    operators.pop();

            if(op == '+'){
                operands.push(operands1 + operands2);
            }
            else if(op == '-'){
                operands.push(operands1 - operands2);
            }
        }
        operators.pop();
    }
    else if(ch == '+' || ch == '-'){
        while(!operators.empty() && operators.top() == '+' || operators.top() == '-'){
            int operands2 = operands.top();
                    operands.pop();

                    int operands1 = operands.top();
                    operands.pop();

                    char op = operators.top();
                    operators.pop();

            if(op == '+'){
                operands.push(operands1 + operands2);
            }
            else if(op == '-'){
                operands.push(operands1 - operands2);
            }
        }
         operators.push(ch);
    }
 }
        while(!operators.empty()){
                int operands2 = operands.top();
                    operands.pop();

                    int operands1 = operands.top();
                    operands.pop();

                    char op = operators.top();
                    operators.pop();

            if(op == '+'){
                operands.push(operands1 + operands2);
            }
            else if(op == '-'){
                operands.push(operands1 - operands2);
            }
       }
        return operands.top();    
   }

   int main(){
    int T;
    cout<<"enter a calculate string number:";
    cin >> T;

    while (T--) {
        string expression;
        cin.ignore(); 
        getline(cin, expression);

        int result = evaluateExpression(expression);
        cout << result << endl;
    }

    return 0;
   }