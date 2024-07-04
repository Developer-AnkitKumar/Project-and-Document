#include<iostream>
using namespace std;
/*
int main()
{
    int n ;
    cout<<"enter a number:";   
    cin>>n;                     
                                
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){  //put j<=i: output is: Triangle and put j<=n: output is: square
            cout<<"n"<<" ";
            cout<<*<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/


/*
int main()
{
    int n;
    cout<<"enter a number of row:";
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
           cout<<j+1<<" ";
           //cout<<(char)(j+64)<<" ";  //output is A B C D in nuber depend of row input, but put j<=n:
        }
        cout<<endl;
    }
    return 0;
}
*/


int main()
{
    int n;
  cout << "enter a number of row:";
  cin >> n;

  int j; // Declare j here so it's accessible in both loops

  for (int i = 1; i <= n; i++) {
    if (i % 2 != 0) {
      for (j = 1; j <= i; j++) {
        cout << j << " ";
      }
    } else {
      for (j = 1; j <= i; j++) { // Add a for loop here for even rows
        cout << (char)(j + 64) << " ";
      }
    }

    cout << endl;
  }
    return 0;
}

/*
int main()
{
  int n;
  cout<<"enter a number:";
  cin>>n;

  for(int i=1; i<=n; i++){  //count a int.number and char.number:
    //cout<<i<<" ";
    //cout<<(char)(i+64)<<" ";
  }
  cout<<endl;
}
*/

/*
int main()  // total count a number:
{
  int n;
  cout<<"enter a number:";
  cin>>n;

  int count = 0;
  while( n ){
    n /= 10;
    count++;
  }
  cout<<count<<" ";
}
*/

/*
int main()
{
    int n ;
    cout<<"enter a number:";   
    cin>>n;                     
                                
    for(int i=n; i>=1; i--){  // these condition is print the value(*) in high row to loe row:
        for(int j=1; j<=i; j++){

           cout<<'*'<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
int main()
{
    int n ;
    cout<<"enter a number:";   
    cin>>n;                     
                                
    for(int i=1; i<=n; i++){  
        for(int j=1; j<=i; j++){

          // cout<<2*j-1<<" ";  //print the even number of row 1 and 1 3 and 1 3 5 and also:
           //cout<<1*j<<" ";  //print the serial number of row 1 and 1 2 and 1 2 3 and also:
           cout<<3*i<< " ";  // print the square term of value:
        }
        cout<<endl;
    }
    return 0;
}
*/
/*
int main()
{
    int n ;
    cout<<"enter a number:";   
    cin>>n;                     
         //int a = 1;                       
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){  //put j<=i: output is: Triangle and put j<=n: output is: square
        //cout<<'n'<<" ";
            //cout<<a++<<" ";//a =1:
            if((i+j)%2 == 0){
              cout<<1<<" ";
            }
            else{
              cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
    int n ;
    cout<<"enter a number:";   
    cin>>n;                     
                                
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){  //put j<=i: output is: Triangle and put j<=n: output is: square
        if(i == 3 || j == 3){
          cout<<'*' ;
        }
        else{
          cout<<"  ";
        }
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
    int n ;
    cout<<"enter a number:";   
    cin>>n;                     
          int first = 1 , last = n;                      
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+2; j++){  //put j<=i: output is: Triangle and put j<=n: output is: square
        if(i == first || i == last || j == first || j == last+last){
          cout<<'*'<<" ";
        }
        else{
          cout<<" ";
        }
        }
        cout<<endl;
    }
    return 0;
}
*/

// int main()
// {
//     int n ;
//     cout<<"enter a number:";   
//     cin>>n;                     
                                
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n-i; j++){  //put j<=i: output is: Triangle and put j<=n: output is: square
//             cout<<' ' ;
//         }
//         for(int j=1; j<=i; j++){
//           cout<<'*' ;
//         }
//         cout<<endl;
//     }
//     return 0;
// }
