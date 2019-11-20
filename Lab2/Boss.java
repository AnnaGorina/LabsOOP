package com.company;

import java.util.ArrayList;

public class Boss extends Person {

    private Company company;
    private ArrayList<Employee> PersonOfCompany = new ArrayList<Employee>();

    public Boss (String Surname, String Name, String Patronymic) {
        super(Surname, Name, Patronymic);

    }

//    public int GetCountPerson (Company company) {
//        return company.GetCountPerson();
//    }

    public boolean JoinAPerson (Employee employee) {

        if (employee.GetCountCompany() < 5) {
            for (int i = 0; i < company.GetCountPerson(); i++) {
                if (PersonOfCompany.get(i) == employee) {
                    return false;
                }
            }

            PersonOfCompany.add(employee);
            employee.JoinACompany(this);
            company.JoinAPerson(employee);
            return true;
        }

        return false;
    }

    public boolean DismissPerson (Employee employee) {
        for (int i = 0; i < PersonOfCompany.size(); i++) {
            PersonOfCompany.remove(i);
        }

        return false;
    }
}
