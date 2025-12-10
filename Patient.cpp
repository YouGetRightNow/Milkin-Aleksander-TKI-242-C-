#include "Patient.h"
#include <sstream>

Patient::Patient(const std::string& firstName, const std::string& lastName,
    const std::string& middleName, int age,
    const std::string& medicalCardNumber,
    const std::string& phoneNumber, const std::string& address)
    : Person(firstName, lastName, middleName, age),
    medicalCardNumber(medicalCardNumber), phoneNumber(phoneNumber), address(address) 
{
}

std::string Patient::getInfo() const 
{
    std::stringstream ss;
    ss << "Пациент: " << getFullName() << "\n"
        << "Возраст: " << age << " лет\n"
        << "Номер мед. карты: " << medicalCardNumber << "\n"
        << "Телефон: " << phoneNumber << "\n"
        << "Адрес: " << address << "\n";
    return ss.str();
}