package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
	    Boss boss = new Boss("Sokolov","Ivan", "Ivanovich", new Company("Microsoft"));
        ArrayList<Employee> Mrazi = new ArrayList<>();
        {
            Mrazi.add(new Employee("Ivanov", "Ivan", "Ivanovich"));
            Mrazi.add(new Employee("P","K","I"));
        }

        Mrazi.get(0).JoinACompany(boss);
        if (Mrazi.get(0).JoinACompany(boss)) {
            System.out.println("Error");
        }
    }
}

