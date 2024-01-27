#include <bits/stdc++.h>

using namespace std;
const int maxproducts=100;
struct product{
string name;
string type;
float price;
int quantity;
};
product products[maxproducts];
int numproducts=0;
struct user{
string username;
string paswsword;
};
void signup()
{
    user newUser;
    cout<<"Enter User name:";
    cin>>newUser.username;
        if(user.username==newuser.username)
        {
            cout<<"username already exists.Please choose another username .\n";
        }

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
void displaymenu()
{
    cout<<"1.Add products\n2.Display products\n3.Modify products\n4.Delete products\n5.Exit\n";
    cout<<"Enter you choice:";
}
void addproducts()
{

if(numproducts<maxproducts)
{


    product newproduct;
    cout<<"Enter product name :";
    cin>>newproduct.name;
    cout<<"Enter product type(vegetable,crop,rice):";
    cin>>newproduct.type;
    cout<<"Enter product price:";
    cin>>newproduct.price;
    cout<<"Enter product quantity:";
    cin>>newproduct.quantity;
    cout<<"product added successfully"<<endl;
}
else
{
    cout<<"Max number of product reach\n";
}
}
void displayproducts()
{
    if(numproducts==0)
    {
        cout<<"No products available\n";
    }
    else
    {
        cout<<"product name \nprice\n quantity\n";
        for(int i=0;i<numproducts;++i)
        {
            cout<<poducts[i].name<<endl;
            cout<<poducts[i].price<<endl;
           cout<< poducts[i].quantity<<endl;
        }
    }
}
int main()
{
    cout<<"welcome to the agriculture management system"<<endl;
    char choice;
    do {
        cout<<"1.signup\n 2.login\n 3.add product\n 4.display product\n 5.Exit\n";
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
            addproducts();
            break;
        case 4:
            displayproducts();
            break;
            case 5:
            cout<<"exit Program\n";
            break;
        default:
            cout<<"Invalid choice";
        }
        while(choice!=5);

    }
    return 0;
}
