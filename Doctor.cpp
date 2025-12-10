#include "Doctor.h"
#include <sstream>

Doctor::Doctor(const std::string& firstName, const std::string& lastName,
    const std::string& middleName, int age,
    const std::string& specialization, const std::string& licenseNumber,
    int experienceYears, const std::string& cabinetNumber)
    : Person(firstName, lastName, middleName, age),
    specialization(specialization), licenseNumber(licenseNumber),
    experienceYears(experienceYears), cabinetNumber(cabinetNumber) 
{
}

std::string Doctor::getInfo() const 
{
    std::stringstream ss;
    ss << "Доктор: " << getFullName() << "\n"
        << "Специализация: " << specialization << "\n"
        << "Возраст: " << age << " лет\n"
        << "Опыт работы: " << experienceYears << " лет\n"
        << "Кабинет: " << cabinetNumber << "\n"
        << "Номер лицензии: " << licenseNumber << "\n";

    return ss.str();
}