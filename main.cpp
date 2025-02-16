#include <iostream>

import database;
import employee;

using namespace std;
using namespace Records;

int displayMenu() {
    int selection;
    std::cout << "" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "1) Hire a new employee" << std::endl;
    std::cout << "2) Fire an employee" << std::endl;
    std::cout << "3) Promote an employee" << std::endl;
    std::cout << "4) List all employees" << std::endl;
    std::cout << "5) List all current employees" << std::endl;
    std::cout << "6) List all former employees" << std::endl;
    std::cout << "0) Quit" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "------>" << std::endl;

    cin >> selection;
    return selection;
}

void doHire(Database &db) {
    string firstname;
    string lastname;

    cout << "First name? " << std::endl;
    cin >> firstname;

    cout << "Last name? " << std::endl;
    cin >> lastname;

    auto &employee{db.addEmployee(firstname, lastname)};
    cout << "Hired employee " << firstname << " " << lastname << " with employee number " << employee.
            getEmployeeNumber() << std::endl;
}

void doFire(Database &db) {
    int employeeNumber;
    std::cout << "Employee number? " << std::endl;
    std::cin >> employeeNumber;

    try {
        auto &emp{db.getEmployee(employeeNumber)};
        emp.fire();
        std::cout << "Employee " << employeeNumber << " terminated." << std::endl;
    } catch (const logic_error &exception) {
        std::cout << "Unable to terminate employee." << std::endl;
        std::cout << exception.what() << std::endl;
    }
}

void doPromote(Database &db) {
    int employeeNumber;
    std::cout << "Employee number? " << std::endl;
    std::cin >> employeeNumber;

    int raiseAmount;
    std::cout << "How much of a raise? " << std::endl;
    std::cin >> raiseAmount;

    try {
        auto &emp{db.getEmployee(employeeNumber)};
        emp.promote(raiseAmount);
        std::cout << "Employee " << employeeNumber << " has a raise in salary." << std::endl;
    } catch (const logic_error &exception) {
        std::cout << "Unable to promote employee " << employeeNumber << "." << std::endl;
        std::cout << exception.what() << std::endl;
    }
}

int main() {
    Database db;
    bool done{false};

    while (!done) {
        int selection{displayMenu()};

        switch (selection) {
            case 0:
                done = true;
                break;
            case 1:
                doHire(db);
                break;
            case 2:
                doFire(db);
                break;
            case 3:
                doPromote(db);
                break;
            case 4:
                db.displayAll();
                break;
            case 5:
                db.displayCurrent();
                break;
            case 6:
                db.displayFormer();
                break;
            default:
                std::cout << "Unknown command" << std::endl;
                break;
        }
    }


    return 0;
}
