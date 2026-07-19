#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to display the vending machine menu
void displayMenu()
{
    cout << "=====================================\n";
    cout << "        SIMPLE VENDING MACHINE\n";
    cout << "=====================================\n";
    cout << "1. Coca Cola      - £1.50\n";
    cout << "2. Water          - £1.00\n";
    cout << "3. Orange Juice   - £1.80\n";
    cout << "4. Crisps         - £1.20\n";
    cout << "5. Chocolate Bar  - £1.40\n";
    cout << "6. Cookies        - £1.60\n";
    cout << "0. Exit\n";
    cout << "=====================================\n";
}

int main()
{
    // Arrays storing product names and prices
    string products[] =
    {
        "Coca Cola",
        "Water",
        "Orange Juice",
        "Crisps",
        "Chocolate Bar",
        "Cookies"
    };

    double prices[] =
    {
        1.50,
        1.00,
        1.80,
        1.20,
        1.40,
        1.60
    };

    int choice;
    double money;

    displayMenu();

    cout << "Please enter your selection: ";
    cin >> choice;

    // Exit option
    if (choice == 0)
    {
        cout << "Thank you for using the vending machine.\n";
        return 0;
    }

    // Check if the selection is valid
    if (choice < 1 || choice > 6)
    {
        cout << "Invalid selection.\n";
        return 0;
    }

    cout << fixed << setprecision(2);

    cout << "You selected: " << products[choice - 1] << endl;
    cout << "Price: £" << prices[choice - 1] << endl;

    // Ask the user to insert money
    cout << "Insert money (£): ";
    cin >> money;

    // Check if enough money has been inserted
    if (money < prices[choice - 1])
    {
        cout << "Insufficient funds.\n";
        cout << "Money returned: £" << money << endl;
    }
    else
    {
        double change = money - prices[choice - 1];

        // Dispensing message
        cout << "\nDispensing " << products[choice - 1] << "...\n";
        cout << "Please collect your item.\n";

        // Change message
        cout << "Your change is: £" << change << endl;

        cout << "Thank you for your purchase!\n";
    }

    return 0;
}
