#include "Schedule.h"
#include <sstream>
#include <algorithm>

Schedule::Schedule(std::shared_ptr<Doctor> doctor) : doctor(doctor) {}

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
    ss << "Расписание врача: " << doctor->getFullName() << "\n"
        << "Специализация: " << doctor->getSpecialization() << "\n"
        << "Кабинет: " << doctor->getCabinetNumber() << "\n"
        << "График работы:\n";

    for (size_t i = 0; i < workingHours.size(); ++i) 
    {
        const std::string& day = workingHours[i].first;
        const std::string& hours = workingHours[i].second;
        ss << "  " << day << ": " << hours << "\n";
    }

    return ss.str();
}