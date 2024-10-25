#include <iostream>
#include <cstdlib>  
#include <string>   

using namespace std;


void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();


char menuInput;  
string userId, userPassword;  
double balance = 0;  

// Main function
int main() {
    cout << "Hi! Welcome to Ms. Jasmine’s ATM Machine!\n";
    start();  // Starts the whole program
    return 0;
}

// prints the intro menu
void printIntroMenu() {
    cout << "Please select an option from the menu below:\n";
    cout << "l  -> Login\n";
    cout << "c -> Create New Account\n";
    cout << "q -> Quit\n";
    cout << "> ";
}


void printMainMenu() {
    cout << "d -> Deposit Money\n";
    cout << "w -> Withdraw Money\n";
    cout << "r -> Request Balance\n";
    cout << "q -> Quit\n";
    cout << "> ";
}


void start() {
    do {
        printIntroMenu();
        cin >> menuInput;

        switch (menuInput) {
            case 'l':
                login();
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                exit(0);  
                break;
            default:
                cout << "Invalid option! Try again.\n";
        }
    } while (menuInput != 'q');
}

//  creates a new account
void createAccount() {
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> userPassword;
    cout << "Thank You! Your account has been created!\n";
}


void login() {
    string id, password;
    cout << "Please enter your user id: ";
    cin >> id;
    cout << "Please enter your password: ";
    cin >> password;

    if (id == userId && password == userPassword) {
        cout << "Access Granted!\n";
        char mainMenuChoice;
        do {
            printMainMenu();
            cin >> mainMenuChoice;
            
            switch (mainMenuChoice) {
                case 'd': {  // Deposit money
                    double depositAmount;
                    cout << "Amount of deposit: $";
                    cin >> depositAmount;
                    balance += depositAmount;
                    break;
                }
                case 'w': {  // Withdraw money
                    double withdrawAmount;
                    cout << "Amount of withdrawal: $";
                    cin >> withdrawAmount;
                    if (withdrawAmount <= balance) {
                        balance -= withdrawAmount;
                    } else {
                        cout << "Insufficient balance!\n";
                    }
                    break;
                }
                case 'r':  // Request balance
                    cout << "Your balance is $" << balance << ".\n";
                    break;
                case 'q':  // Quit
                    cout << "Thanks for stopping by!\n";
                    break;
                default:
                    cout << "Invalid option! Try again.\n";
            }
        } while (mainMenuChoice != 'q');
    } else {
        cout << "******** LOGIN FAILED! ********\n";
    }
}
