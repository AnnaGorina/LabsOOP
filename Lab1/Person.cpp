#include "person.h"
#include "company.h"
#include <iostream>

Person::Person(const std::string Surname, const std::string Name, const std::string Patronymic) {
    this->Name = Name;
    this->Surname = Surname;
    this->Patronymic = Patronymic;
}

const std::string& Person::get_name_person() const {
    return Name;
}

const std::string& Person::get_surname_person() const {
    return Surname;
}

const std::string& Person::get_patronymic_person() const {
    return Patronymic;
}

uint16_t Person::GetCountCompany() {
    return CompanyCount;
}

bool Person::JoinACompany(Company* company) {
    if(!company->JoinAPerson(this)) {
        CompanyCount++;

        return true;
    }

    else {
        return false;
    }
}


bool Person::LeaveCompany(Company* company) {
    if(!company->DismissPerson(this)) {
        CompanyCount--;

        return true;
    }

    else {
        return false;
    }
}

Person::~Person() = default;

std::ostream &operator<<(std::ostream &stream, Person &person) {
    stream << "******************************************************" << std::endl;
    stream << "ФИО работника: " << person.get_surname_person() << " " << person.get_name_person() << " " << person.get_patronymic_person() << std::endl;
    stream << "******************************************************" << std::endl;

    return stream;
}

