#include <bits/stdc++.h>
#include<stack>
  using namespace std;
  /*
  int countOperations(string str) {
    stack<char>st;
    int operations = 0;

    for (char c : str) {
        if (c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                operations++;
            } else {
                st.pop();
            }
        }
    }

    operations += st.size();
    return operations;
}
  int main()
  {
    //write your code here
    int testCase = 1;
    string input;

    while (1) {
        cin >> input;

        if (input == "-") {
            break;
        }

        int operations = countOperations(input);
        cout << testCase++ << ". " << operations << endl;
    }

    return 0;
  }
  */
  
  bool parentheses(string s){
    stack<char> st;
    
    for(int i = 0; i<s.length(); i++){
      if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
        st.push(s[i]);  
      }
      else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
       if(st.empty() || (s[i] == ')' && st.top() != '(') || (s[i] == ']' && st.top() != '[') || ( s[i] == '}' &&  st.top() != '{')){
         return false;
       }
      //  if(st.empty() || (s[i] == '(' && st.top() == ']') || s[i] == '(' && st.top() == '}'){
      //   return false;
      //  }
       st.pop();
      }
      else{
        return true;
      }
    }
    return st.empty();
  }
  
  int main()
  {
    //write your code here
   int t;
   cout<<"enter a nuber of parentheses:";
   cin>>t;
   
   for(int i = 0; i<t; i++){
      string input;
        cout << "parentheses string for test case " << i + 1 << ": ";
        cin >> input;

       if (parentheses(input)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
  }
  */
 /*
  int prec(char c){
    if(c == '^'){
      return 3;
    }
    else if(c == '/' || c == '*'){
      return 2;
    }
    else if(c == '-' || c == '+'){
      return 1;
    }
    else{
      return -1;
    }
  }

  void push(stack<char>& s, char c){
    s.push(c);
  }
  char pop(stack<char>& s){
    char top = s.top();
    s.pop();
    return top;
  }
  char peek(stack<char>& s){
    return s.top();
  }
  bool isEmpty(stack<char>& s){
    return s.empty();
  }
  // Infix to Postfix operation:
  void convertToPostfix(string s){
    stack<char> st;
    st.push('#');
    string ns;
    int l = s.length();
    
    for(int i = 0; i<l; i++){
      if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
        ns+= s[i];
      }
      else if(s[i] == '('){
        st.push(s[i]);
      }
      else if (s[i] == ')') {
    while (peek(st) != '#' && peek(st) != '(') {
        char c = pop(st);
        ns += c;
    }
    if (peek(st) == '(') {  // Fix: Correcting the condition
        pop(st);
    } 
    else {
        while (peek(st) != '#' && prec(s[i]) <= prec(peek(st))) {
            char c = pop(st);
            ns += c;
        }
        push(st, s[i]);
        }
      }
      else {
        while (peek(st) != '#' && prec(s[i]) <= prec(peek(st))) {
            char c = pop(st);
            ns += c;
        }
        push(st, s[i]);
        }
    }
    while(peek(st) != '#'){
      char c = pop(st);
      ns+=c;
    }
    cout<<ns<<"\n";
  }
  
  int main()
  {
    //write your code here
    int t;
    cout<<"enter the number of operation:";
    cin>>t;
    
    string s;
    cout<<"enter the expression of operation:";
    while(t--){
      cin>>s;
      convertToPostfix(s);
    }
    return 0;
  }*/