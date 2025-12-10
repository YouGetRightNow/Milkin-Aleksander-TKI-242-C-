#pragma once
#define SCHEDULE_H

#include "Doctor.h"
#include <vector>
#include <string>
#include <memory>

 /**
  * @brief Класс, представляющий расписание работы врача
  */
class Schedule 
{
private:

    std::shared_ptr<Doctor> doctor; 
    std::vector<std::pair<std::string, std::string>> workingHours; 
    std::vector<std::string> workingDays; 

public:
    /**
     * @brief Конструктор класса Schedule
     * @param doctor Указатель на объект Doctor
     */
    Schedule(std::shared_ptr<Doctor> doctor);

    /**
     * @brief Добавить рабочий день в расписание
     * @param day Название дня недели
     * @param hours Временной интервал работы
     */
    void addWorkingDay(const std::string& day, const std::string& hours);

    /**
     * @brief Удалить рабочий день из расписания
     * @param day Название дня недели для удаления
     */
    void removeWorkingDay(const std::string& day);

    /**
     * @brief Получить информацию о расписании
     * @return Подробная информация о расписании
     */
    std::string getInfo() const;

    /**
     * @brief Получить указатель на врача
     * @return Указатель на объект врача
     */
    std::shared_ptr<Doctor> getDoctor() const { return doctor; }

    /**
     * @brief Получить рабочие часы врача
     * @return Вектор пар (день, часы)
     */
    const std::vector<std::pair<std::string, std::string>>& getWorkingHours() const 
    {
        return workingHours;
    }
};
