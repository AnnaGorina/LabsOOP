package com.company;


public class Employee extends Person {

    private int CompanyCount = 0;

    public Employee (String Surname, String Name, String Patronymic) {
        super(Surname, Name, Patronymic);
    }



    public int GetCountCompany () {
        return CompanyCount;
    }

    public boolean JoinACompany (Boss boss) {
        if (boss.JoinAPerson(this)) {
            CompanyCount++;
            return true;
        } else {
            return false;
        }
    }

    public void LeaveACompany (Boss boss) {
        boss.DismissPerson(this);
    }

}
