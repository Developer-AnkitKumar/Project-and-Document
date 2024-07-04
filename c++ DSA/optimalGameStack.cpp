#include <iostream>
//#include <vector>
#include <stack>
 using namespace std;

/*
 int main()
 {
    int n;    //decide the number of player:
    cout<<"enter number of element:";
    cin>>n;

     vector<int> numbers(n);  //declare "vector<dataType>vector_name;"

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int playerX = 0, playerY = n-1;   //initional position is "0" and last position is "n-1":
    vector<int> output;

    while(playerX <= playerY){
        if(numbers[playerX] > numbers[playerY]){
            output.push_back(1);
             playerY--;
        }
    else if(numbers[playerY] > numbers[playerX]){
            output.push_back(2);
            playerX++;
          }
     else{
        output.push_back(0);
         playerX++;
         playerY--;
     }
    }
    for(int i=0; i<output.size(); i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return 0;
 }
 */

//GetMinimum Element From Stack
int main()
{
    int q;
    cin>>q;

    stack<int>mainStack;
    stack<int>minStack;

    while(q--){
        int quearyType;
        cin>>quearyType;

        switch(quearyType){
            case 1:
            int x;
            cout<<"enter number of input value";
            cin>>x;
            mainStack.push(x);
            if(minStack.empty() || x <= minStack.top()){
                minStack.push(x);
            }
            break;

            case 2:
            mainStack.pop();
            if(mainStack.top() == minStack.top()){
                minStack.pop();
            }
            break;

            case 3:
            cout<<minStack.top()<<endl;
            break;

            case 4:
            cout<<minStack.top()<<endl;
            break;

            default:
            cout<<"invalid queary type"<<endl;
        }
    }
    return 0;
}