1.The goal of this project is to design and develop a console-based vending machine application in C++. It allows users to select drinks and snacks from a menu, insert money, purchase an item and receive the correct change. The purpose of the project was to demonstrate programming skills learned during the module, like variables, arrays, functions, conditional statements, user input/output and arithmetic calculations.

The vending machine implemented has the following features:

A menu of drinks and snacks. Product selection based on number. A payment system that allows users to enter money. Automatic calculation of change. A message confirming item dispensing. A message showing the returned change. Comments explaining important parts of the code.

2.The vending machine process starts when it starts and immediately displays a menu of available items to the user. The user makes a choice, and the machine checks if the selection is valid or not and outputs an error message, returning to the menu to choose again. If the selection is valid, the machine displays the price of the selected item and waits for the user to insert money. As the money is inserted, the machine checks if all the money is sufficient to cover the price. If the amount is not enough, the machine returns the inserted money and goes back to the menu, effectively cancelling the transaction. If the user has inserted enough money, the machine proceeds to dispense the selected item. After dispensing the item, it calculates any change that needs to be returned to the user and dispenses that change. Once the item and change have been delivered, the transaction ends and the machine resets for the next user interaction.

3.The vending machine application was built in the C++ programming language and developed in Visual Studio Code. The objective of the program was to create a simple interactive console application that demonstrates the basic programming techniques covered in the module.

Several libraries are included at the beginning of the program. The iostream library is used for basic input and output operations, allowing the program to display information and receive user input. The iomanip library is used to format currency values, so prices and change are displayed with two decimal places. The string library allows product names to be stored and displayed.

The program uses a function called displayMenu() to show the available products to the user. This function contains the product names, selection numbers, and prices displayed on the console. The separate function makes the program more organized, as the menu display is separated from the main program logic.

The vending machine stores product information using arrays. One array stores the names of the products and the other stores their prices. Arrays are used because they can store multiple related values efficiently. Instead of creating variables for every product, the program can reference the products based on the position in the array.

The main function controls the overall operation of the vending machine. First, the menu is displayed and the user is asked to enter a product number. The choice is stored in an integer variable.

The if statement is used to check if the user's choice is valid. If the user enters a number outside the available range, then the program will display an error message. This prevents the program from accessing the wrong positions in the arrays and improves the reliability of the program.

When a valid selection is made, the program displays the selected product and its price. The product information is retrieved from the arrays using the user's selection. Since arrays start counting from zero, the program subtracts one from the user's choice when accessing the right position.

The next stage of the program deals with payment. The user enters the amount of money that they want to use, stored in a variable called money. The program then compares this value with the product price using another conditional statement.

If the inserted money is less than the cost of the item, the program informs the user that there are insufficient funds and returns the entered money. If enough money has been provided, the program continues with the purchase process.

The change is calculated by subtracting the product price from the amount inserted. The result is stored in the variable change. The program then displays a message informing the user that their selected item is being dispensed and displays the amount of change returned.

We tested many scenarios during testing. A successful purchase was determined by selecting a product and entering more money than required. The program showed the dispensing message correctly and calculated the correct change. An insufficient payment test was conducted to verify the program did not accept the purchase without enough money. Invalid product selections were tested to confirm that the program handled incorrect input.

The implementation demonstrates useful C++ programming concepts like variables, arrays, functions, conditional statements, user input, and mathematical operations. The program is structured in a clear manner and comments explain key operations to make it easy to understand and maintain.

4.The vending machine application fully meets the assignment requirements by allowing users to choose products, insert money, receive their chosen item and obtain the correct change. I feel that the best part of this project is the easy to understand and clear user interaction. The menu system is simple and the program also provides feedback at each level of the purchasing process.

One good thing about the code is the organisation. We store products and prices in arrays which minimize repetition and the menu displayed in a different function makes it easier to read. So the program can be modified if more products are needed in the future.

However, there are some flaws in the application that can be improved. Currently, the program only allows one transaction before closing and adding a loop would allow customers to buy products without restarting the program. Another point of improvement would be stock management for each product having a limited quantity and when stock is zero, it cannot be purchased.

Other payment methods could also enhance the realism of the application. For example, accepting individual coins, bank cards, or contactless payments would take the system closer to a real vending machine.

I would need to develop knowledge of more advanced C++ programming concepts to make these improvements. These include object-oriented programming with classes, file handling for saving data, vectors for dynamic storage and exception handling for handling unexpected user input.

I learned from this project how programming concepts can be married to creating a functional application. If I were to achieve this today, I would like to make the system much more realistic, scalable and user-friendly.

5.#include <iostream>
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
