#include "Appointment.h"
#include <sstream>

Appointment::Appointment(std::shared_ptr<Doctor> doctor,
                         std::shared_ptr<Patient> patient,
                         const std::string& date, const std::string& time,
                         const std::string& purpose)
    : doctor(doctor), patient(patient), date(date),
      time(time), purpose(purpose), isCompleted(false) 
{
    // Автоматически добавляем запись пациенту
    if (auto pat = patient.lock()) {
        pat->addAppointment(std::shared_ptr<Appointment>(this));
    }
}

std::string Appointment::getInfo() const 
{
    std::stringstream ss;
    ss << "Запись на прием:\n"
       << "Дата: " << date << "\n"
       << "Время: " << time << "\n";
    
    if (auto doc = doctor.lock()) {
        ss << "Врач: " << doc->getFullName() << " (" << doc->getSpecialization() << ")\n";
    }
    
    if (auto pat = patient.lock()) {
        ss << "Пациент: " << pat->getFullName() << " (документ: " << pat->getDocumentId() << ")\n";
    }
    
    ss << "Цель визита: " << purpose << "\n"
       << "Статус: " << (isCompleted ? "Завершен" : "Запланирован") << "\n";

    return ss.str();
}
