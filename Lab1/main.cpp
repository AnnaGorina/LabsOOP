#include <QCoreApplication>
#include "person.h"
#include "company.h"
#include <clocale>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    setlocale(LC_ALL, "Russian");
    
    Person FirstPerson("Иванов", "Иван", "Иванович");
    Person SecondPerson("Петров", "Петр", "Петрович");
    Person ThirdPerson("Александров", "Александр", "Александрович");
    Person FourthPerson("Николаев", "Николай", "Николаевич");
    Person FifthPerson("Матвеев", "Матвей", "Матвеевич");
    Person SixthPerson("Андреев", "Андрей", "Андреевич");
    Person SeventhPerson("Павлов", "Павел", "Павлович");
    Person EighthPerson("Дмитриев", "Дмитрий", "Дмитриевич");
    Person NinthPerson("Евгеньев", "Евгений", "Евгеньевич");
    Person TenthPerson("Максимов", "Максим", "Максимович");

    Company Microsoft("Microsoft");
    Company Apple("Apple");
    Company Samsung("Samsung");
    Company Google("Google");
    Company Intel("Intel");
    Company Cisco("Cisco");
    Company Oracle("Oracle");
    
   /* Microsoft.JoinAPerson(FirstPerson);
    Microsoft.JoinAPerson(ThirdPerson);
    Microsoft.JoinAPerson(FifthPerson);
    Microsoft.JoinAPerson(SeventhPerson);
    Microsoft.JoinAPerson(NinthPerson);
    
    Apple.JoinAPerson(SecondPerson);
    Apple.JoinAPerson(FourthPerson);
    Apple.JoinAPerson(SixthPerson);
    Apple.JoinAPerson(EighthPerson);
    Apple.JoinAPerson(TenthPerson);
    
    Samsung.JoinAPerson(ThirdPerson);
    Samsung.JoinAPerson(SixthPerson);
    Samsung.JoinAPerson(NinthPerson);
    
    Google.JoinAPerson(FourthPerson);
    Google.JoinAPerson(EighthPerson);
    
    Intel.JoinAPerson(FifthPerson);
    Intel.JoinAPerson(TenthPerson);
    
    Cisco.JoinAPerson(FirstPerson);
    Cisco.JoinAPerson(SecondPerson);
    Cisco.JoinAPerson(ThirdPerson);
    Cisco.JoinAPerson(FourthPerson);
    Cisco.JoinAPerson(FifthPerson);
    
    Oracle.JoinAPerson(SixthPerson);
    Oracle.JoinAPerson(SeventhPerson);
    Oracle.JoinAPerson(EighthPerson);
    Oracle.JoinAPerson(NinthPerson);
    Oracle.JoinAPerson(TenthPerson);

    std::vector <Person> Person = Microsoft;*/

    std::vector <Company> company;

    company.push_back(Microsoft);
    company.push_back(Apple);
    company.push_back(Samsung);
    company.push_back(Google);
    company.push_back(Intel);
    company.push_back(Cisco);
    company.push_back(Oracle);

    company[0].JoinAPerson(FirstPerson);
    company[0].JoinAPerson(ThirdPerson);
    company[0].JoinAPerson(FifthPerson);
    company[0].JoinAPerson(SeventhPerson);
    company[0].JoinAPerson(NinthPerson);

    company[1].JoinAPerson(SecondPerson);
    company[1].JoinAPerson(FourthPerson);
    company[1].JoinAPerson(SixthPerson);
    company[1].JoinAPerson(EighthPerson);
    company[1].JoinAPerson(TenthPerson);

    company[2].JoinAPerson(ThirdPerson);
    company[2].JoinAPerson(SixthPerson);
    company[2].JoinAPerson(NinthPerson);

    company[3].JoinAPerson(FourthPerson);
    company[3].JoinAPerson(EighthPerson);

    company[4].JoinAPerson(FifthPerson);
    company[4].JoinAPerson(TenthPerson);

    company[5].JoinAPerson(FirstPerson);
    company[5].JoinAPerson(SecondPerson);
    company[5].JoinAPerson(ThirdPerson);
    company[5].JoinAPerson(FourthPerson);
    company[5].JoinAPerson(FifthPerson);

    company[6].JoinAPerson(SixthPerson);
    company[6].JoinAPerson(SeventhPerson);
    company[6].JoinAPerson(EighthPerson);
    company[6].JoinAPerson(NinthPerson);
    company[6].JoinAPerson(TenthPerson);

    for (uint16_t i = 0; i < company.size(); i++)
    {
        std::cout << "******************************************************" << std::endl;
        std::cout << "Компания: " << company[i] << std::endl;
        std::cout << "ФИО работников: " << std::endl;
        std::cout << company[i].GetNameOfPerson(i).get_surname_person() << " " << company[i].GetNameOfPerson(i).get_name_person() << " " << company[i].GetNameOfPerson(i).get_patronymic_person() << std::endl;
        std::cout << "******************************************************" << std::endl;
    }

    system("Pause");

    return 0;
}
