#include <iostream>
#include <stack>
using namespace std;

// bool isValid(string str)
// {
//     int balance = 0;
//     for (char c : str) {
//         switch (c) {
//             case '{':
//                 ++balance;
//                 break;
//             case '}':
//                 --balance;
//                 break;
//         }
//         // if (balance < 0) {
//         //     return false;
//         // }
//     }
//     return balance == 0;
// }

// void generateBeautifulStrings(int n)
//  {
//     if (n == 0) {
//         cout << "}{" << endl;
//         return;
//     }

//     for (int i = 0; i < n; i++) {
//         string str = "";
//         for (int j = 0; j < i; j++) {
//             str += "{";
//         }
//         for (int j = i; j < n; j++) {
//             str += "}";
//         }

//       if (isValid(str)) {
//             cout << str << endl;
//         }
//     }
// }

// int main()
//  {
//     int n;
//     cout<<"enter a number of curly braces:";
//     cin >> n;

//     generateBeautifulStrings(n);
//     return 0;
// }

  int countOperation(string str){
    stack<char>st;
    int operation = 0;

    for(char c : str){
        if(char(c) == '{'){
            st.push(c);
        }
        else{
            if(st.empty()){
                operation++;
            }
            else{
                st.pop();
            }
        }
    }
    operation += st.size();
    return operation;
 }

 int main(){
    int testCase = 1;
    string input;

    while(1){
        cin>>input;
        if(input == "-"){
            break;
        }
        int operation = countOperation(input);
        cout<<testCase++ <<" "<<operation<<endl;
    }
    return 0;
 }