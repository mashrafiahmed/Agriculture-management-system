#include <bits/stdc++.h>

using namespace std;
struct product{
string name;
string type;
float price;
int quantity;
};
struct user{
string username;
string paswsword;
};
void signup()
{
    user newUser;
    cout<<"Enter User name:";
    cin>>newUser.username;
    cout<<"Enter Your Password:";
    cin>>newUser.password;
    users.push_back(newUser);
    cout<<"account created successfully";
}
bool login()
{
    string username,password;
    cout<<"Enter your username:";
    cin>>username;
    cout<<"Enter your password:";
    cin>>password;
    if(user.username==username&&user.password==password)
    {
        cout<<"log in successfully";
    }
}

int main()
{
    char choice;
    do {
        cout<<"1.signup\n 2.login\n 3.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            signup();
            break;
        case 2:
            if(login())
            {
                return 0;
            }
            break;
        case 3:
            cout<<"exit Program\n
            break;
        default:
            cout<<"Invalid choice";
        }
        while(choice!=3);

    }
    return 0;
}
