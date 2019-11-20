package com.company;

import java.util.ArrayList;

public class Company {
    private String NameOfCompany;


    private Boss boss;

    private ArrayList<Employee>PersonOfCompany = new ArrayList<Employee>();

    public Company (String NameOfCompany, String SurnameBoss, String NameBoss, String PatronymicBoss) {
        this.NameOfCompany = NameOfCompany;
        boss = new Boss(SurnameBoss, NameBoss, PatronymicBoss);
    }



    public Employee GetNameOfPerson (int i) {
        return PersonOfCompany.get(i);
    }

    public final Employee GetPerson (final String Surname, final String Name, final String Patronymic) {
        for (int i = 0; i < PersonOfCompany.size(); i++) {
            if (PersonOfCompany.get(i).GetNamePerson() == Name && PersonOfCompany.get(i).GetSurnamePerson() == Surname && PersonOfCompany.get(i).GetPatronymicPerson() == Patronymic) {
                return PersonOfCompany.get(i);
            }
        }

        return null;
    }

    public boolean CheckPerson (final String Surname, final String Name, final String Patronymic) {
        for (int i = 0; i < PersonOfCompany.size(); i++) {
            if (PersonOfCompany.get(i).GetNamePerson() == Name && PersonOfCompany.get(i).GetSurnamePerson() == Surname && PersonOfCompany.get(i).GetPatronymicPerson() == Patronymic) {
                return true;
            }
        }

        return false;
    }

    public int GetCountPerson () {
        return PersonOfCompany.size();
    }

    public boolean JoinAPerson (Employee employee) {
        if (!boss.JoinAPerson(employee)) {
            PersonOfCompany.add(employee);
            return true;
        } else {
            return false;
        }
    }

    public boolean DismissPerson (Employee employee) {
        if (!boss.DismissPerson(employee)) {
            PersonOfCompany.remove(employee);
            return true;
        } else {
            return false;
        }
    }
}
