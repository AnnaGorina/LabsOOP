#include "company.h"
#include "person.h"

Company::Company(const std::string& NameOfCompany) {
    this->NameOfCompany = NameOfCompany;
}

std::string& Company::GetCompany() {
    return NameOfCompany;
}

Person& Company::GetNameOfPerson(uint16_t i) const {
    return (*PersonOfCompany[i]);
}

Person* Company::GetPerson(const std::string& Surname, const std::string& Name, const std::string& Patronymic) const {
    for (uint16_t i = 0; i < PersonOfCompany.size(); i++) {
        if (PersonOfCompany[i]->GetNamePerson() == Name && PersonOfCompany[i]->GetSurnamePerson() == Surname && PersonOfCompany[i]->GetPatronymicPerson() == Patronymic) {
            return PersonOfCompany[i];
        }
    }

    return nullptr;
}

bool Company::CheckPerson(const std::string& Surname, const std::string& Name, const std::string& Patronymic) {
    for (uint16_t i = 0; i < PersonOfCompany.size(); i++) {
        if (PersonOfCompany[i]->GetNamePerson() == Name && PersonOfCompany[i]->GetSurnamePerson() == Surname && PersonOfCompany[i]->GetPatronymicPerson() == Patronymic) {
            return true;
        }
    }

    return false;
}

uint16_t Company::GetCountPerson() {
    return PersonOfCompany.size();
}

bool Company::JoinAPerson(Person& person) {
    if (person.GetCountCompany() < 5) {
        for (uint16_t i = 0; i < this->GetCountPerson(); i++) {
            if (PersonOfCompany[i] == &person) {
                return false;
            }
        }

        PersonOfCompany.push_back(&person);
        person.JoinACompany(*this);
        return true;
    }

    return false;
}

bool Company::DismissPerson(Person& person) {
    std::vector<Person*>::iterator it = PersonOfCompany.begin();

    for (uint16_t i = 0; i < PersonOfCompany.size(); i++) {
        if (*it == &person) {
            PersonOfCompany.erase(it);
            person.LeaveCompany(*this);
  
            return true;
        }

        it++;
    }

    return false;
}

Company::~Company() = default;

std::ostream& operator<<(std::ostream& stream, Company& company) {
    stream << "******************************************************" << std::endl;
    stream << "Компания: " << company.GetCompany() << std::endl;
    stream << "ФИО работников: " << std::endl;

    for (uint16_t i = 0; i < company.GetCountPerson(); i++) {
        stream << company.GetNameOfPerson(i).GetSurnamePerson() << " " << company.GetNameOfPerson(i).GetNamePerson() << " " << company.GetNameOfPerson(i).GetPatronymicPerson() << std::endl;
    }

    stream << "******************************************************" << std::endl;

    return stream;
}
