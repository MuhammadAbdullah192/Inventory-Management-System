#include <iostream>
#include <string>
using namespace std;

#define MAX_PRODUCTS 100

// Structure definition for product
struct Product {
    string name;
    float price;
    int quantity;
};

// Function to add a new product to the inventory
void addProduct(Product products[], int &count) {
    Product newProduct;
    
    cout << "Enter product name: ";
    cin >> newProduct.name;
    
    cout << "Enter product price: ";
    cin >> newProduct.price;
    
    cout << "Enter product quantity: ";
    cin >> newProduct.quantity;
    
    products[count++] = newProduct;
}

// Function to display all products in the inventory
void displayInventory(const Product products[], int count) {
    cout << "\n--- Inventory ---\n";
    
    for (int i = 0; i < count; i++) {
        cout << "Product " << i+1 << ":\n";
        cout << "Name: " << products[i].name << endl;
        cout << "Price: " << products[i].price << endl;
        cout << "Quantity: " << products[i].quantity << endl;
        cout << "----------------\n";
    }
}

// Function to calculate the total value of the inventory
float calculateInventoryValue(const Product products[], int count) {
    float totalValue = 0;
    
    for (int i = 0; i < count; i++) {
        totalValue += products[i].price * products[i].quantity;
    }
    
    return totalValue;
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;
    
    do {
        cout << "1. Add Product\n";
        cout << "2. Display Inventory\n";
        cout << "3. Calculate Inventory Value\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addProduct(inventory, count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3: {
                float totalValue = calculateInventoryValue(inventory, count);
                cout << "\nTotal inventory value: " << totalValue << endl;
                break;
            }
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
        cout << "\n";
    } while (choice != 4);
    
    return 0;
}