#include "Doctor.h"
#include <sstream>

Doctor::Doctor(const std::string& firstName, const std::string& lastName,
               const std::string& middleName, int age,
               const std::string& documentId,
               const std::string& specialization, const std::string& licenseNumber,
               int experienceYears, const std::string& cabinetNumber)
    : Person(firstName, lastName, middleName, age, documentId),
      specialization(specialization), licenseNumber(licenseNumber),
      experienceYears(experienceYears), cabinetNumber(cabinetNumber),
      schedule(nullptr) 
{
}

std::string Doctor::getInfo() const 
{
    std::stringstream ss;
    ss << "Доктор: " << getFullName() << "\n"
       << "Документ: " << documentId << "\n"
       << "Специализация: " << specialization << "\n"
       << "Возраст: " << age << " лет\n"
       << "Опыт работы: " << experienceYears << " лет\n"
       << "Кабинет: " << cabinetNumber << "\n"
       << "Номер лицензии: " << licenseNumber << "\n";
    
    if (schedule) {
        ss << "Расписание: " << (schedule->getWorkingDays().empty() ? "не установлено" : "установлено") << "\n";
    }

    return ss.str();
}

std::shared_ptr<Schedule> Doctor::createSchedule()
{
    schedule = std::make_shared<Schedule>(std::static_pointer_cast<Doctor>(shared_from_this()));
    return schedule;
}
