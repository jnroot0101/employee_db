#include <iostream>

module employee;

namespace Records {
    Employee::Employee(const std::string &firstname, const std::string &lastname) {
    }

    void Employee::promote(int raiseAmount) {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::demote(int demeritAmount) {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::hire() {
        hired = true;
    }

    void Employee::fire() {
        hired = false;
    }

    void Employee::display() const {
        std::cout << "Employee: " << getLastName() << ", " << getFirstName() << std::endl;
        std::cout << "----------" << std::endl;
        std::cout << (hired ? "Current Employee" : "Former Employee") << std::endl;
        std::cout << "Employee Number: " << getEmployeeNumber() << std::endl;
        std::cout << "Salary: " << getSalary() << std::endl;
    }

    // Getters and setters
    void Employee::setFirstName(const std::string &firstname) {
        firstName = firstname;
    }

    const std::string &Employee::getFirstName() const {
        return firstName;
    }

    void Employee::setLastName(const std::string &lastname) {
        lastName = lastname;
    }

    const std::string &Employee::getLastName() const {
        return lastName;
    }

    void Employee::setEmployeeNumber(int num) {
        employeeNumber = num;
    }

    int Employee::getEmployeeNumber() const {
        return employeeNumber;
    }

    void Employee::setSalary(int salary) {
        salary = salary;
    }

    int Employee::getSalary() const {
        return salary;
    }

    bool Employee::isHired() const {
        return hired;
    }
}
