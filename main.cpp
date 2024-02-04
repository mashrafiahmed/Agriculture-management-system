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

    for (const auto &existingUser : users) {
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
    for (const auto &user : users) {
        if (user.username == username && user.password == password) {
            cout << "Login successful\n";
            return true;
        }
    }
    cout << "Invalid username or password\n";
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
        for (int i = 0; i < numproducts; ++i) {
            cout << products[i].name << endl << products[i].price << endl << products[i].quantity << endl;
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
    for (int i = 0; i < numproducts; ++i) {
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
    for (int i = 0; i < numproducts; ++i) {
        if (products[i].name == productname) {
            for (int j = i; j < numproducts - 1; ++j) {
                products[j] = products[j + 1];
            }
            numproducts--;
            cout << "Product deleted successfully\n";
            return;
        }
    }
    cout << "Product not found\n";
}

int calculatetotal(const product &p) {
    int total = 0;
    total = p.price * p.quantity;
    return total;
}

void searchproduct() {
    if (numproducts == 0) {
        cout << "No products available to search\n";
        return;
    }
    string productname;
    cout << "Enter the name of the product to search:";
    cin >> productname;
    for (int i = 0; i < numproducts; ++i) {
        if (products[i].name == productname) {
            cout << "Product found!\n";
            cout << "Product name: " << products[i].name << endl;
            cout << "Product type: " << products[i].type << endl;
            cout << "Product price: " << products[i].price << endl;
            cout << "Product quantity: " << products[i].quantity << endl;
            return;
        }
    }
    cout << "Product not found\n";
}

int main() {
    cout << "Welcome to the agriculture management system\n";

    int choice;
    do {
        cout << "1. Signup\n2. Login\n3. Add product\n4. Display product\n5. Modify product\n6. Delete product\n7. Search product\n8. Calculate total\n9. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                login();
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
                searchproduct();
                break;
            case 8:
                if (numproducts > 0) {
                    int totalamount = calculatetotal(products[0]);
                    cout << "Total amount: " << totalamount << endl;
                    cout << "Payment show to the user successfully\n";
                } else {
                    cout << "No products available to calculate total\n";
                }
                break;
            case 9:
                cout << "Exit Agriculture management system. Goodbye\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 9);

    return 0;
}
