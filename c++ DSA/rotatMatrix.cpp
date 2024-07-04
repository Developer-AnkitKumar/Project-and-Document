#include<iostream>
using namespace std;

int main()
{
     int n;
    cout<<"enter the size of matrix:";
    cin>>n;

    int matrix[n][n];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Swap the elements of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]); // Swap elements at (i, j) and (j, i)
        }
    }

    cout << "Transposed matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}