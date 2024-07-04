#include<iostream>
//#include<cstring>
using namespace std;

// int main(){
//     char s[] = "HELLO";
//     int length = strlen(s);

//     for(int i = 0; i<length; i++){
//         s[i] = tolower(s[i]);
//         cout<< s[i];
//     }
//     return 0;
// }

// int firstOccurence(int *arr, int start, int end, int flag = -1){
//     while(start <= end){
//         int mid = start + (end - start)/2;

//         if(arr[mid] == 1){
//             flag = mid;
//             end = mid -1;
//         }
//         else{
//             start = mid + 1;
//         }
//     }
//     return flag;
// }
// int main(){
//     int t;
//     cin>>t;
//     cout<<"enter a number of firstOccurence";
//     while(t--){
//         int n;
//         cin>>n;
//         cout<<"insert the value";
//         int arr[n];

//         for(int i = 0; i<n; i++){
//             cin>>arr[i];
//         }
//          cout<<firstOccurence(arr, 0, n-1)<<endl;
//     }
//     return 0;
// }

int firstOccurence(int *arr, int start, int end){
    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid + 1]){
            return arr[mid];
        }
        else if(arr[mid] > arr[mid - 1]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
}
int main(){
    int t;
    cin>>t;
    //cout<<"enter a number of firstOccurence";
    while(t--){
        int n;
        cin>>n;
       // cout<<"insert the value";
        int arr[n];

        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
         cout<<firstOccurence(arr, 0, n-1)<<endl;
    }
    return 0;
}