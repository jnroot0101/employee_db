#include <iostream>

import database;
import employee;

using namespace std;
using namespace Records;

int main() {
    Database db;

    Employee &emp1{db.addEmployee("Greg", "Wallis")};
    emp1.fire();

    Employee &emp2{db.addEmployee("Marc", "White")};
    emp2.setSalary(100'000);

    Employee &emp3{db.addEmployee("John", "Doe")};
    emp3.setSalary(10'000);
    emp3.promote();

    std::cout << "All employee: " << std::endl;
    db.displayAll();

    std::cout << "Current employee: " << std::endl;
    db.displayCurrent();

    std::cout << "Former employee: " << std::endl;
    db.displayFormer();
}
