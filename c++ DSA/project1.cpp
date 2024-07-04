//this project is Login, Registration and forgot Password Application page:
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void login();
void registration();
void forgot();

int main(){
    int c;
    cout<<"\t\t\t___________________________________________________\n\n\n";
    cout<<"\t\t\t              Welcome to the Login page             \n\n\n";
    cout<<"\t\t\t_____________________MENU____________________________\n\n";
    cout<<"                                                            \n\n";
    cout<<"\t\t\t Press 1 to LOGIN                              |\n";
    cout<<"\t\t\t Press 2 to REGISTRATION                       |\n";
    cout<<"\t\t\t Press 3 if you forgot PASSWORD                |\n";
    cout<<"\t\t\t Press 4 to EXIT                               |\n";
    cout<<"\t\t\t please enter your choice:";
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;

        case 4:
            cout<<"\t\t\t THANK YOU!   \n\n";
            break;

        default:
            system("cls");
            cout<<"\t\t\t please select from the options given above \n"<<endl;
            main();
    }
}

void login(){
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout<<"\t\t\t please enter your username and password: \n"<<endl;
    cout<<"\t\t\t USERNAME";
    cin>>userId;
    cout<<"\t\t\t password"<<endl;
    cin>>password;

    ifstream input("records.txt");
    while(input >> id >> pass){
        if(id == userId && pass == password){
            count = 1;
            break;
        }
    }
    input.close();

    if(count == 1){
        cout<<userId<<"\n your LOGIN is successful \n Thanks for logging in ! \n";
    }
    else{
        cout<<"\n LOGIN ERROR \n please check your username and password \n";
    }

    main();
}

void registration(){
    string ruserId, rpassword;
    system("cls");
    cout<<"\t\t\t      enter the username: \n";
    cin>>ruserId;
    cout<<"\t\t\t      enter the password:  \n";
    cin>>rpassword;

    ofstream f1("records.txt", ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    f1.close();
    system("cls");
    cout<<"\t\t\t         registration is successful!   \n";
    main();
}

void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t    Forgot your password? No worries \n";
    cout<<"press 1 to search your id by username"<<endl;
    cout<<"press 2 to go back to the main menu"<<endl;
    cout<<"\t\t\t       enter your choice:";
    cin>>option;

    switch (option){
        case 1:
            int count = 0;
            string suserId, sId, spass;
            cout<<"\n\t\t\t    enter the username which you remember:";
            cin>>suserId;

            ifstream f2("records.txt"); 
            while(f2>>sId>>spass){
                if(sId == suserId){
                    count = 1;
                }
            }
            f2.close();

            if(count == 1){
                cout<<"\n\n your account is found! \n";
                cout<<"\n\n your password is:"<<spass;
            }
            else{
                cout<<"\n\t sorry! your account is not found! \n";
            }
            break;

        case 2:
            break;

        default:
            cout<<"\t\t\t   wrong choice! please try again"<<endl;
            break;
    }

    main();
}


