#ifndef COMPANY_H
#define COMPANY_H
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

enum company{Microsoft, Apple, Samsung, Google, Intel, Cisco, Oracle};

class Person;

class Company {
    std::string NameOfCompany; //название компании

    std::vector <Person*> PersonOfCompany; //список работников в компании

public:
    Company(std::string NameOfCompany);

    std::string& get_company(); //получить название компании

    Person& GetNameOfPerson(uint16_t i) const; //получить i-го работника компании

    Person* GetPerson(const std::string& Surname, const std::string& Name, const std::string& Patronymic) const; //получить работника по ФИО

    bool CheckPerson(const std::string& Surname, const std::string& Name, const std::string& Patronymic); //проверить, устроен ли работник в компанию

    uint16_t GetCountPerson(); //получить число работников в компании

    bool JoinAPerson(Person& person); //принять работника в компанию

    bool DismissPerson(Person& person); //убрать работника из компании

    ~Company();
};

std::ostream& operator<<(std::ostream& stream, Company& company);

#endif // COMPANY_H

