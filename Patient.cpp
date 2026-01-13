#include "Patient.h"
#include <sstream>
#include <algorithm>

Patient::Patient(const std::string& firstName, const std::string& lastName,
                 const std::string& middleName, int age,
                 const std::string& documentId,
                 const std::string& medicalCardNumber,
                 const std::string& phoneNumber, const std::string& address)
    : Person(firstName, lastName, middleName, age, documentId),
      medicalCardNumber(medicalCardNumber), phoneNumber(phoneNumber), address(address) 
{
}

std::string Patient::getInfo() const 
{
    std::stringstream ss;
    ss << "Пациент: " << getFullName() << "\n"
       << "Документ: " << documentId << "\n"
       << "Возраст: " << age << " лет\n"
       << "Номер мед. карты: " << medicalCardNumber << "\n"
       << "Телефон: " << phoneNumber << "\n"
       << "Адрес: " << address << "\n"
       << "Количество записей: " << appointments.size() << "\n";
    return ss.str();
}

void Patient::addAppointment(std::shared_ptr<Appointment> appointment)
{
    appointments.push_back(appointment);
}

bool Patient::removeAppointment(std::shared_ptr<Appointment> appointment)
{
    auto it = std::find(appointments.begin(), appointments.end(), appointment);
    if (it != appointments.end()) {
        appointments.erase(it);
        return true;
    }
    return false;
}

std::vector<std::shared_ptr<Appointment>> Patient::getUpcomingAppointments() const
{
    std::vector<std::shared_ptr<Appointment>> upcoming;
    std::copy_if(appointments.begin(), appointments.end(),
                 std::back_inserter(upcoming),
                 [](const std::shared_ptr<Appointment>& app) {
                     return !app->getIsCompleted();
                 });
    return upcoming;
}

std::vector<std::shared_ptr<Appointment>> Patient::getCompletedAppointments() const
{
    std::vector<std::shared_ptr<Appointment>> completed;
    std::copy_if(appointments.begin(), appointments.end(),
                 std::back_inserter(completed),
                 [](const std::shared_ptr<Appointment>& app) {
                     return app->getIsCompleted();
                 });
    return completed;
}
