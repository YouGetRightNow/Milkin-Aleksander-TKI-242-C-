#include "Schedule.h"
#include <sstream>
#include <algorithm>

Schedule::Schedule(std::shared_ptr<Doctor> doctor) 
    : doctor(doctor) // Используем weak_ptr
{
}

void Schedule::addWorkingDay(const std::string& day, const std::string& hours) 
{
    workingHours.emplace_back(day, hours);
    workingDays.push_back(day);
}

void Schedule::removeWorkingDay(const std::string& day) 
{
    auto it = std::remove_if(workingHours.begin(), workingHours.end(),
        [&day](const std::pair<std::string, std::string>& pair) 
        {
            return pair.first == day;
        });
    workingHours.erase(it, workingHours.end());

    auto it2 = std::remove(workingDays.begin(), workingDays.end(), day);
    workingDays.erase(it2, workingDays.end());
}

std::string Schedule::getInfo() const 
{
    std::stringstream ss;
    auto doc = doctor.lock();
    if (doc) {
        ss << "Расписание врача: " << doc->getFullName() << "\n"
           << "Специализация: " << doc->getSpecialization() << "\n"
           << "Кабинет: " << doc->getCabinetNumber() << "\n"
           << "График работы:\n";
    } else {
        ss << "Расписание (врач не найден):\n";
    }

    for (size_t i = 0; i < workingHours.size(); ++i) 
    {
        const std::string& day = workingHours[i].first;
        const std::string& hours = workingHours[i].second;
        ss << "  " << day << ": " << hours << "\n";
    }

    return ss.str();
}

bool Schedule::isWorkingDay(const std::string& day) const
{
    return std::find(workingDays.begin(), workingDays.end(), day) != workingDays.end();
}
