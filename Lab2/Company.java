package com.company;

import java.util.ArrayList;

public class Company {
    private String NameOfCompany;


    //private Boss boss;

    private ArrayList<Employee>PersonOfCompany = new ArrayList<Employee>();

    public Company (String NameOfCompany) {
        this.NameOfCompany = NameOfCompany;
        //boss = new Boss(SurnameBoss, NameBoss, PatronymicBoss);
    }



    public Employee GetNameOfPerson (int i) {
        return PersonOfCompany.get(i);
    }

    public final Employee GetPerson (final String Surname, final String Name, final String Patronymic) {
        for (Employee employee : PersonOfCompany) {
            if (employee.compare(Surname, Name, Patronymic)) {
                return employee;
            }
        }

        return null;
    }

    public boolean isPerson (final String Surname, final String Name, final String Patronymic) {
        for (Employee employee : PersonOfCompany) {
            if (employee.compare(Surname, Name, Patronymic)) {
                return true;
            }
        }

        return false;
    }

    public int GetCountPerson () {
        return PersonOfCompany.size();
    }

    public boolean isPerson(Employee employee) {
        return PersonOfCompany.contains(employee);
    }

    public void addEmployee(Employee employee) {
        PersonOfCompany.add(employee);
    }

    public void removeEmployee(Employee employee) {
        PersonOfCompany.remove(employee);
    }
}
