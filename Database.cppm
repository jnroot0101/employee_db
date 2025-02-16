export module database;

#include <iostream>

import employee;

namespace Records {
    constexpr int FirstEmployeeNumber{1'000};

    export class Database {
    public:
        Employee &addEmployee(const std::string &firstname, const std::string &lastname);

        Employee &getEmployee(int employeeNumber);

        Employee &getEmployee(const std::string &firstname, const std::string &lastname);

        void displayAll() const;

        void displayCurrent() const;

        void displayFormer() const;

    private:
        std::vector<Employee> employees;
        int nextEmployeeNumber{FirstEmployeeNumber};
    };
}
