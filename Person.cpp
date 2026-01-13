#include "Person.h"
#include <sstream>

Person::Person(const std::string& firstName, const std::string& lastName,
               const std::string& middleName, int age,
               const std::string& documentId)
    : firstName(firstName), lastName(lastName), 
      middleName(middleName), age(age), documentId(documentId) 
{
}

std::string Person::getFullName() const 
{
    return lastName + " " + firstName + " " + middleName;
}
