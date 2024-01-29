#include <bits/stdc++.h>
using namespace std;

const int maxproducts = 100;

struct product {
    string name;
    string type;
    int price;
    float quantity;
};

product products[maxproducts];
int numproducts = 0;

struct user {
    string username;
    string password;
};

vector<user> users;

void signup() {
    user newUser;
    cout << "Enter User name:";
    cin >> newUser.username;

    for (const auto& existingUser : users) {
        if (existingUser.username == newUser.username) {
            cout << "Username already exists. Please choose another username.\n";
            return;
        }
    }

    cout << "Enter Your Password:";
    cin >> newUser.password;
    users.push_back(newUser);
    cout << "Account created successfully\n";
}

bool login() {
    string username, password;
    cout << "Enter your username:";
    cin >> username;
    cout << "Enter your password:";
    cin >> password;

    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            cout << "Login successfully\n";
            return true;
        }
    }

    cout << "Login failed\n";
    return false;
}

void addproducts() {
    if (numproducts < maxproducts) {
        product newproduct;
        cout << "Enter product name :";
        cin >> newproduct.name;
        cout << "Enter product type (vegetable, crop, rice):";
        cin >> newproduct.type;
        cout << "Enter product price:";
        cin >> newproduct.price;
        cout << "Enter product quantity:";
        cin >> newproduct.quantity;
        products[numproducts++] = newproduct;
        cout << "Product added successfully\n";
    } else {
        cout << "Max number of products reached\n";
    }
}

void displayproducts() {
    if (numproducts == 0) {
        cout << "No products available\n";
    } else {
        cout << "Product name\nPrice\nQuantity\n";
        for (int i = 0; i < numproducts; i++) {
            cout << products[i].name << "\n";
            cout << products[i].price << "\n";
            cout << products[i].quantity << "\n";
        }
    }
}

void modifyproducts() {
    if (numproducts == 0) {
        cout << "No products available to modify\n";
        return;
    }
    string productname;
    cout << "Enter the name of the product to modify:";
    cin >> productname;
    for (int i = 0; i < numproducts; i++) {
        if (products[i].name == productname) {
            cout << "Enter new price:\n";
            cin >> products[i].price;
            cout << "Enter new quantity:\n";
            cin >> products[i].quantity;
            cout << "Product modified successfully\n";
            return;
        }
    }
    cout << "Product not found\n";
}

void deleteproduct() {
    if (numproducts == 0) {
        cout << "No products available to delete\n";
        return;
    }
    string productname;
    cout << "Enter name of the product to delete\n";
    cin >> productname;
    for (int i = 0; i < numproducts; i++) {
        if (products[i].name == productname) {
            for (int j = i; j < numproducts - 1; j++) {
                products[j] = products[j + 1];
            }
            numproducts--;
            cout << "Product deleted successfully\n";
            return;
        }
    }
    cout << "Product not found\n";
}

int calculatetotal(product p) {
    int total = 0;
    total = p.price * p.quantity;
    return total;
}

int main() {
    cout << "Welcome To The Agriculture Management System\n";
    char choice;
    do {
        cout << "1. Signup\n 2. Login\n 3. Add product\n 4. Display product\n 5. Modify product\n 6. Delete product\n 7. Calculate total\n 8. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                if (login()) {
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
            case 7: {
                int totalamount = 0;
                for (int i = 0; i < numproducts; i++) {
                    totalamount += calculatetotal(products[i]);
                }
                cout << "Total amount: " << totalamount << "\n";
                cout << "Payment successfully\n";
                break;
            }
            case 8:
                cout << "Exit Agriculture management system. Goodbye\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 8);

    return 0;
}
