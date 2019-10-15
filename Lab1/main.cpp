#include <QCoreApplication>
#include "person.h"
#include "company.h"
#include <clocale>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

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

    std::vector<Company> company;

    company.push_back(Microsoft);
    company.push_back(Apple);
    company.push_back(Samsung);
    company.push_back(Google);
    company.push_back(Intel);
    company.push_back(Cisco);
    company.push_back(Oracle);

    /******************************************************************************************
     *                                        ТЕСТ №1                                         *
     * ***************************************************************************************/
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

    std::cout << "ТЕСТ №1: " << std::endl;
    for (uint16_t i = 0; i < company.size(); i++) {
        std::cout << company[i] << std::endl;
    }

    /******************************************************************************************
     *                                        ТЕСТ №2                                         *
     * ***************************************************************************************/

    company[0].DismissPerson(FifthPerson);
    company[1].DismissPerson(FourthPerson);
    company[6].DismissPerson(EighthPerson);

    std::cout << "ТЕСТ №2: " << std::endl;
    for (uint16_t i = 0; i < company.size(); i++) {
        std::cout << company[i] << std::endl;
    }

    /******************************************************************************************
     *                                        ТЕСТ №3                                         *
     * ***************************************************************************************/

    company[1].JoinAPerson(ThirdPerson);
    company[3].JoinAPerson(ThirdPerson);
    company[4].JoinAPerson(ThirdPerson); //не добавит, так как у работника уже имеется 5 компаний!!!

    std::cout << "ТЕСТ №3: " << std::endl;
    for (uint16_t i = 0; i < company.size(); i++) {
        std::cout << company[i] << std::endl;
    }

    /******************************************************************************************
     *                                        ТЕСТ №4                                         *
     * ***************************************************************************************/

    std::cout << "ТЕСТ №4: " << std::endl;
    std::cout << "******************************************************" << std::endl;
    std::cout << "Иванов Иван Иванович = " << company[0].CheckPerson("Иванов", "Иван", "Иванович") << std::endl; //вернет true, так как устроен в компанию
    std::cout << "Петров Петр Петрович = " << company[0].CheckPerson("Петров", "Петр", "Петрович") << std::endl; //вернет false, так как не устроен в компанию
    std::cout << "******************************************************" << std::endl;

    /******************************************************************************************
     *                                        ТЕСТ №5                                         *
     * ***************************************************************************************/

    std::cout << "ТЕСТ №5: " << std::endl;
    std::cout << *company[0].GetPerson("Иванов", "Иван", "Иванович") << std::endl;

    company.clear();

    return 0;
}

