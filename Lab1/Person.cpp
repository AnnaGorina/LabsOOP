#include "person.h"
#include "company.h"
#include <iostream>

Person::Person(const std::string Surname, const std::string Name, const std::string Patronymic)
{
    this->Name = Name;
    this->Surname = Surname;
    this->Patronymic = Patronymic;
}

const std::string &Person::get_name_person() const
{
    return Name;
}

const std::string &Person::get_surname_person() const
{
    return Surname;
}

const std::string &Person::get_patronymic_person() const
{
    return Patronymic;
}

const std::string &Person::GetNameOfCompany(unsigned i) const
{
    return NamesOfCompany[i];
}

void Person::setCompany(std::string Company)
{
    this->NamesOfCompany.push_back(Company);
}

unsigned Person::GetCountCompany()
{
    return NamesOfCompany.size();
}

bool Person::JoinACompany(Company& company)
{
    if (NamesOfCompany.size() != 5)
    {
        if (company.GetPerson(Surname, Name, Patronymic))
        {
            return false;
        }

        NamesOfCompany.push_back(company.get_company());
        company.JoinAPerson(*this);

        return true;
    }

    return false;
}


bool Person::LeaveCompany(std::string Company)
{
    std::vector <std::string>::iterator it = NamesOfCompany.begin();

    while (true)
    {
        if (*it == Company)
        {
            NamesOfCompany.erase(it);
            return true;
        }

        if (it == NamesOfCompany.end())
        {
            return false;
        }

        ++it;
    }
}

Person::~Person() = default;


std::ostream &operator<<(std::ostream &stream, Person &person)
{
    stream << "******************************************************" << std::endl;
    stream << "ФИО работника: " << person.get_surname_person() << " " << person.get_name_person() << " " << person.get_patronymic_person() << std::endl;
    stream << "Список компаний, в которых работает работник: " << std::endl;

    for (uint16_t i = 0; i < person.GetCountCompany(); i++)
    {
        stream << person.GetNameOfCompany(i) << std::endl;
    }
    stream << "******************************************************" << std::endl;

    return stream;
}
