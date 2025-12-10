#include "Appointment.h"
#include <sstream>

Appointment::Appointment(std::shared_ptr<Doctor> doctor,
    std::shared_ptr<Patient> patient,
    const std::string& date, const std::string& time,
    const std::string& purpose)
    : doctor(doctor), patient(patient), date(date),
    time(time), purpose(purpose), isCompleted(false) 
{
}

std::string Appointment::getInfo() const 
{
    std::stringstream ss;
    ss << "Запись на прием:\n"
        << "Дата: " << date << "\n"
        << "Время: " << time << "\n"
        << "Врач: " << doctor->getFullName() << " (" << doctor->getSpecialization() << ")\n"
        << "Пациент: " << patient->getFullName() << "\n"
        << "Цель визита: " << purpose << "\n"
        << "Статус: " << (isCompleted ? "Завершен" : "Запланирован") << "\n";

    return ss.str();
}