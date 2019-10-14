#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include <iostream>

class Company;

class Person
{
    std::string Name; //имя
    std::string Surname;  //фамилия
    std::string Patronymic; //отчетство

    uint16_t CompanyCount = 0; //количество компаний у работника

public:
    Person(const std::string Surname, const std::string Name, const std::string Patronymic);

    const std::string& get_name_person() const;  //получить имя работника

    const std::string& get_surname_person() const;  //получить фамилию работника

    const std::string& get_patronymic_person() const;  //получить отчество работника

    uint16_t GetCountCompany(); //получить число компаний, в которых работает работник

    bool JoinACompany(Company &company); //вступить в компанию

    bool LeaveCompany(Company &company); //покинуть компанию

    ~Person();
};


std::ostream& operator<<(std::ostream& stream, Person& person);

#endif // PERSON_H

