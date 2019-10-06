#include "company.h"
#include "person.h"

Company::Company(std::string NameOfCompany)
{
    this->NameOfCompany = NameOfCompany;
}

const std::string &Company::get_company() const
{
    return NameOfCompany;
}

Person& Company::GetNameOfPerson(unsigned i) const
{
    return (*PersonOfCompany[i]);
}

const Person* Company::GetPerson(const std::string &Surname, const std::string &Name, const std::string &Patronymic) const
{
    for (uint16_t i = 0; i < PersonOfCompany.size(); i++)
    {
        if (PersonOfCompany[i]->get_name_person() == Name && PersonOfCompany[i]->get_surname_person() == Surname && PersonOfCompany[i]->get_patronymic_person() == Patronymic)
        {
            return PersonOfCompany[i];
        }
    }

    return nullptr;
}

bool Company::CheckPerson(const std::string &Surname, const std::string &Name, const std::string &Patronymic)
{
    for (uint16_t i = 0; i < PersonOfCompany.size(); i++)
    {
        if (PersonOfCompany[i]->get_name_person() == Name && PersonOfCompany[i]->get_surname_person() == Surname && PersonOfCompany[i]->get_patronymic_person() == Patronymic)
        {
            return true;
        }
    }

    return false;
}

unsigned Company::GetCountPerson()
{
    return PersonOfCompany.size();
}

bool Company::JoinAPerson(Person& person)
{
    if(person.GetCountCompany() != 5)
    {
       for (uint16_t i = 0; i < person.GetCountCompany(); i++)
       {
           if (person.GetNameOfCompany(i) == NameOfCompany)
           {
               return false;
           }
       }

        person.setCompany(NameOfCompany);
        PersonOfCompany.push_back(&person);

        return true;
    }
}

bool Company::DismissPerson(Person &person)
{
    std::vector <Person*>::iterator it = PersonOfCompany.begin();

    while (true)
    {
        if (*it == &person)
        {
            PersonOfCompany.erase(it);
            person.LeaveCompany(this->get_company());
            return true;
        }

        if (it == PersonOfCompany.end())
        {
            return false;
        }

        ++it;
    }
}

Company::~Company() = default;

std::ostream &operator<<(std::ostream &stream, Company &company)
{
    stream << "******************************************************" << std::endl;
    stream << "Компания: " << company.get_company() << std::endl;
    stream << "ФИО работников: " << std::endl;
    for (uint16_t i = 0; i < company.GetCountPerson(); i++)
    {
        stream << company.GetNameOfPerson(i).get_surname_person() << " " << company.GetNameOfPerson(i).get_name_person() << " " << company.GetNameOfPerson(i).get_patronymic_person() << std::endl;
    }
    stream << "******************************************************" << std::endl;

    return stream;
}
