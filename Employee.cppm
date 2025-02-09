//
// Created by Redouane Jnah on 9/2/2025.
//

#include <iostream>

export module employee;

namespace Records {
    constexpr int DefaultStartingSalary{30'000};
    export constexpr int DefaultRaiseAndDemeritAmount{1'000};

    export class Employee {
    public:
        Employee(const std::string &firstname, const std::string &lastname);

        void promote(int raiseAmount = DefaultRaiseAndDemeritAmount);

        void demote(int demeritAmount = DefaultRaiseAndDemeritAmount);

        void hire(); // hires or rehires the employee
        void fire(); // dismisses the employee
        void display() const; // prints employee info to console

        // Getters and setters
        void setFirstName(const std::string &firstname);

        const std::string &getFirstName() const;

        void setLastName(const std::string &lastname);

        const std::string &getLastName() const;

        void setEmployeeNumber(int num);

        int getEmployeeNumber() const;

        void setSalary(int salary);

        int getSalary() const;

        bool isHired() const;

    private:
        std::string firstName;
        std::string lastName;
        int employeeNumber{-1};
        int salary{DefaultStartingSalary};
        bool hired{false};
    };
}
