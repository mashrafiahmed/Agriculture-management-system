#include <bits/stdc++.h>

using namespace std;
const int maxproducts=100;
struct product{
string name;
string type;
int price;
float quantity;
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
        if(user.username==newUser.username)
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
void modifyproducts()
{
    if(numproducts==0)
    {
        cout<<"No products available to modify\n";
        return;
    }
    string productname;
    cout<<"Enter the name of the product to modify:";
    cin>>productname;
    for(int i=0;i<numproducts;++i )
    {
        if(products[i].name==productname)
        {
            cout<<"Enter new price\n";
            cin>>products[i].price;
            cout<<"Enter new quantity\n";
            cin>>products[i].quantity;;
            cout<<"Product modify successfully\n";
            return;
        }
    }
    cout<<"Product not found";
}
void deleteproduct()
{
    if(numproducts==0)
    {
        cout<<"No product available to delete\n";
        return;
    }
    string productname;
    cout<<"Enter name of the product to delete\n";
    cin>>poductname;
    for(int i=0;i<numproducts;++i)
    {
        if(products[i].name==productname)
        {
            for(int j=i;j<numproducts-1;++j)
            {
                products[j]=poducts[j+1];
            }
            numproducts--;
            cout<<"Product delete successfully\n";
            return;
        }
    }
    cout<<"Product not found \n";
}
int calculatetotal(product)
{
    int total=0;
    total=product.price*product.quantity;
    return total;

}
int main()
{
    cout<<"welcome to the agriculture management system"<<endl;
    char choice;
    do {
        cout<<"1.signup\n 2.login\n 3.add product\n 4.display product\n 5.Modify product\n6.Deleteproduct\n7.Calculate total\n8.Exit\n";
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
                modifyproducts();
                break;
            case 6:
                deleteproduct();
                break;
                case 7:
                    int totalamount=calculatetotal(products) ;
                    cout<<"Total amount"<<totalamount<<endl;
                    cout<<"Payment successfully\n";
                    product.clear();
                    break;
                    case 8:
            cout<<"Exit Agriculture management system .Good bye\n";
            break;
        default:
            cout<<"Invalid choice";
        }
        while(choice!=8);

    }
    return 0;
}
