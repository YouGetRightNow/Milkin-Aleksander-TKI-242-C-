#include "Person.h"
#include <sstream>

Person::Person(const std::string& firstName, const std::string& lastName,
    const std::string& middleName, int age)
    : firstName(firstName), lastName(lastName), middleName(middleName), age(age) 
{
}

std::string Person::getFullName() const 
{
    return lastName + " " + firstName + " " + middleName;
}