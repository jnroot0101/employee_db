//
// Created by Redouane Jnah on 9/2/2025.
//

#include <iostream>

module employee;

namespace Records {
    Employee::Employee(const std::string &firstname, const std::string &lastname) {
    }

    void Employee::promote(int raiseAmount) {
        setSalary(getSalary() + raiseAmount);
    }
}
