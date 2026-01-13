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
    std::weak_ptr<Doctor> doctor;  // Слабая ссылка
    std::weak_ptr<Patient> patient; // Слабая ссылка
    std::string date;              
    std::string time;              
    std::string purpose;             
    bool isCompleted;               

public:
    /**
     * @brief Конструктор класса Appointment
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

    std::shared_ptr<Doctor> getDoctor() const { return doctor.lock(); }
    std::shared_ptr<Patient> getPatient() const { return patient.lock(); }
    const std::string& getDate() const { return date; }
    const std::string& getTime() const { return time; }
    const std::string& getPurpose() const { return purpose; }
    bool getIsCompleted() const { return isCompleted; }
    
    void setDate(const std::string& newDate) { date = newDate; }
    void setTime(const std::string& newTime) { time = newTime; }
    void setPurpose(const std::string& newPurpose) { purpose = newPurpose; }
};
