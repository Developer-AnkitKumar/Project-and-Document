#include<iostream>
using namespace std;

//  enum week{
//     monday,
//     tuesday,
//     wednesday,
//     thrusday,
//     friday,
//     saturday,
//     sunday
// };

// int main(){
//     week days;
//     days = friday;
//     cout<<"days:"<<days+1<<endl;
//     return 0;
//}

// enum Animal{ANIMAL_CAT = -3, ANIMAL_DOG = -2, ANIMAL_PIG = -1, ANIMAL_HORSE = 5, ANIMAL_CHICKEN = 6};

// int main(){
//     Animal animal;
//     animal = ANIMAL_HORSE;
//     cout<<"animal:"<<animal+1<<endl;
//     return 0;
// }

void f(int a) {  //What are Static variables;

    while(a--){
        static int n = 0;
        static int x = 1;

        cin>>n>>x;
        cout<<"n =="<<n++<<'|';
        cout<<"x =="<<x++;
        cout<<endl; 
    }
}
int main(){
    f(3);
    f(2);
    return 0;
}