package com.company;

import java.util.ArrayList;

public class Boss extends Person {

    private Company company;

    public Boss (String Surname, String Name, String Patronymic, Company company) {
        super(Surname, Name, Patronymic);
        this.company = company;
    }


    public boolean JoinAPerson (Employee employee) {

        if (employee.GetCountCompany() < 5) {
            if (company.isPerson(employee)) {
                return false;
            }

            company.addEmployee(employee);
            employee.JoinACompany(this);
            return true;
        }

        return false;
    }

    public void DismissPerson (Employee employee) {
        company.removeEmployee(employee);
    }
}

