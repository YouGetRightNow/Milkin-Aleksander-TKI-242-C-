#pragma once
#define APPOINTMENT_H

#include <string>
#include <memory>
#include "Doctor.h"
#include "Patient.h"

 /**
  * @brief Класс, представляющий запись на прием в поликлинике
  */
class Appointment 
{
private:

    std::shared_ptr<Doctor> doctor;  
    std::shared_ptr<Patient> patient; 
    std::string date;              
    std::string time;              
    std::string purpose;             
    bool isCompleted;               

public:

    /**
     * @brief Конструктор класса Appointment
     * @param doctor Указатель на объект Doctor
     * @param patient Указатель на объект Patient
     * @param date Дата приема
     * @param time Время приема
     * @param purpose Цель визита
     */
    Appointment(std::shared_ptr<Doctor> doctor, std::shared_ptr<Patient> patient,
        const std::string& date, const std::string& time,
        const std::string& purpose);

    /**
     * @brief Получить информацию о записи
     * @return Подробная информация о записи на прием
     */
    std::string getInfo() const;

    /**
     * @brief Отметить прием как завершенный
     */
    void complete() { isCompleted = true; }

    /**
     * @brief Получить указатель на врача
     * @return Указатель на объект врача
     */
    std::shared_ptr<Doctor> getDoctor() const { return doctor; }

    /**
     * @brief Получить указатель на пациента
     * @return Указатель на объект пациента
     */
    std::shared_ptr<Patient> getPatient() const { return patient; }

    /**
     * @brief Получить дату приема
     * @return Дата приема
     */
    const std::string& getDate() const { return date; }

    /**
     * @brief Получить время приема
     * @return Время приема
     */
    const std::string& getTime() const { return time; }

    /**
     * @brief Получить цель визита
     * @return Цель визита
     */
    const std::string& getPurpose() const { return purpose; }

    /**
     * @brief Проверить, завершен ли прием
     * @return true Если прием завершен
     * @return false Если прием не завершен
     */
    bool getIsCompleted() const { return isCompleted; }
};
