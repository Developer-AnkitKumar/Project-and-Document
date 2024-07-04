#include<iostream>
//#include<vector>
  using namespace std;
  /*
  void generateBinaryNumbers(int N){
    
    queue<string>binaryQueue;
    binaryQueue.push("1");

    for(int i = 1; i<N; i++){
         cout << "Binary Numbers for N=" << i << ": ";
        
        int count = binaryQueue.size();

        for (int j = 0; j < count; j++) {
        string currentBinary = binaryQueue.front();
        binaryQueue.pop();

        cout<<"currentBinary"<<" ";

        binaryQueue.push(currentBinary + "0");
        binaryQueue.push(currentBinary + "1");
    }
    cout<<endl;
 }
}

  int main()
  {
    //write your code int main()
    // int T;
    // cout << "Enter the number of test cases: ";
    // cin >> T;

    // for (int i = 0; i < T; i++) {
    //     int N;
    //     cout << "Enter the value of N for test case " << i + 1 << ": ";
    //     cin >> N;

    //     cout << "Binary representation of numbers from 1 to " << N << ": ";
    //     generateBinaryNumbers(N);
    // }
    int input1 = 4;
    int input2 = 5;

    generateBinaryNumbers(input1);
    generateBinaryNumbers(input2);

    
    return 0;
  }

  */
/*
 int findStartingStation(const vector<int>& gas, const vector<int>& cost){
    int totalGas = 0;
    int totalCost = 0;
    int currentGas = 0;
    int startingStation = 0;

    for(int i = 0; i<gas.size(); i++){
        totalGas += gas[i];
        totalCost += cost[i];
        currentGas +=  gas[i] - cost[i];

        if(currentGas < 0){
            currentGas = 0;
            startingStation = i+1;
        }
        return (totalGas >= totalCost) ? startingStation : -1;
    }
 }
 int main()
{
    int t;
    cout<<"enter a number of circular path:";
    cin>>t;

    vector<int> gas(t);
    vector<int> cost(t);

    for(int i = 0; i<t; i++){
        cin>>gas[i];
    }
    for(int i = 0; i<t; i++){
        cin>>cost[i];
    }
    int result = findStartingStation(gas, cost);
    cout<<"output:"<<result <<endl; 
    return 0;
}
*/

struct node
{
    long long value;
    node *left;
    node *right;
};

bool isLeaf(node* root) {
    return (root != nullptr) && (root->left == nullptr) && (root->right == nullptr);
}

bool checkSumTree(node* n)
{
    if (n == nullptr || isLeaf(n)) {
        return true;
    }

    long long leftSum = checkSumTree(n->left) ? n->left->value : 0;
    long long rightSum = checkSumTree(n->right) ? n->right->value : 0;

    return (n->value == leftSum + rightSum) && checkSumTree(n->left) && checkSumTree(n->right);
}
