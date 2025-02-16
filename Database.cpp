module database;

#include <iostream>

using namespace std;

namespace Records {
    Employee &Database::addEmployee(const std::string &firstname, const std::string &lastname) {
        Employee emp{firstname, lastname};
        emp.setEmployeeNumber(nextEmployeeNumber++);
        emp.hire();
        employees.push_back(emp);

        return employees.back();
    }

    Employee &Database::getEmployee(int employeeNumber) {
        for (auto &employee: employees) {
            if (employee.getEmployeeNumber() == employeeNumber) {
                return employee;
            }
        }

        throw logic_error("No employee found.");
    }

    void Database::displayAll() const {
        for (const auto &employee: employees) {
            employee.display();
        }
    }

    void Database::displayCurrent() const {
        for (const auto &employee: employees) {
            if (employee.isHired()) { employee.display(); }
        }
    }

    void Database::displayFormer() const {
        for (const auto &employee: employees) {
            if (!employee.isHired()) { employee.display(); }
        }
    }
}
