#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include <iterator>
#include <iostream>

class Company;

class Person
{
    std::string Name; //имя
    std::string Surname;  //фамилия
    std::string Patronymic; //отчетство

    std::vector <std::string> NamesOfCompany; //компании, в которых работает работник

    //std::string NameCompany; //название компании

public:
    Person(const std::string Surname, const std::string Name, const std::string Patronymic);

    const std::string& get_name_person() const;  //получить имя работника
    const std::string& get_surname_person() const;  //получить фамилию работника
    const std::string& get_patronymic_person() const;  //получить отчество работника

    const std::string& GetNameOfCompany(unsigned i) const; //получить i-ую компанию, в которой работет работник

    void setCompany(std::string Company); //установить компании, в которых находится работник

    unsigned GetCountCompany(); //получить число компаний, в которых работает работник

    //void request(); //запрос в компанию

    bool JoinACompany(Company& company); //вступить в компанию

    bool LeaveCompany(std::string Company); //покинуть компанию

    ~Person();
};

std::ostream& operator<<(std::ostream& stream, Person& person);

#endif // PERSON_H
