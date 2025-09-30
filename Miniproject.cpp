#include <iostream>
#include <string>
#include <limits>

class BankAccount {
private:
    std::string ownerName;
    double balance;

public:
    BankAccount(std::string name, double initialBalance) {
        ownerName = name;
        balance = initialBalance;
        std::cout << "\nAccount successfully created for " << ownerName << "." << std::endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully deposited " << amount << ". New balance: " << balance << std::endl;
        } else {
            std::cout << "Error: Deposit amount must be positive." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Successfully withdrew " << amount << ". New balance: " << balance << std::endl;
        } else if (amount > balance) {
            std::cout << "Error: Insufficient funds. Current balance is " << balance << std::endl;
        } else {
            std::cout << "Error: Withdrawal amount must be positive." << std::endl;
        }
    }

    void checkBalance() const {
        std::cout << "Current balance for " << ownerName << " is: " << balance << std::endl;
    }
};

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::string name;
    double initialDeposit;
    int choice;
    double amount;

    std::cout << "Welcome to the Bank of ARSJ!\n";
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Please enter your initial deposit amount: ";
    std::cin >> initialDeposit;

    if (std::cin.fail() || initialDeposit < 0) {
        std::cout << "Invalid input. Starting with a balance of 0." << std::endl;
        initialDeposit = 0.0;
        clearInputBuffer();
    }

    BankAccount myAccount(name, initialDeposit);

    do {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number from the menu.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                if (std::cin.fail()) {
                    std::cout << "Invalid amount entered. Please try again.\n";
                    clearInputBuffer();
                } else {
                    myAccount.deposit(amount);
                }
                break;
            case 2:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                if (std::cin.fail()) {
                    std::cout << "Invalid amount entered. Please try again.\n";
                    clearInputBuffer();
                } else {
                    myAccount.withdraw(amount);
                }
                break;
            case 3:
                myAccount.checkBalance();
                break;
            case 4:
                std::cout << "Thank you for banking with us. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please select an option from 1 to 4.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
