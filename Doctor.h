#pragma once
#define DOCTOR_H

#include "Person.h"
#include "Schedule.h"
#include <string>
#include <vector>
#include <memory>

/**
 * @brief Класс, представляющий врача поликлиники
 */
class Doctor : public Person 
{
private:
    std::string specialization; 
    std::string licenseNumber;   
    int experienceYears;         
    std::string cabinetNumber;
    std::shared_ptr<Schedule> schedule; // Связь с расписанием

public:
    /**
     * @brief Конструктор класса Doctor
     */
    Doctor(const std::string& firstName, const std::string& lastName,
           const std::string& middleName, int age,
           const std::string& documentId,
           const std::string& specialization, const std::string& licenseNumber,
           int experienceYears, const std::string& cabinetNumber);

    /**
     * @brief Реализация виртуального метода getInfo()
     * @return Подробная информация о враче
     */
    std::string getInfo() const override;

    const std::string& getSpecialization() const { return specialization; }
    const std::string& getLicenseNumber() const { return licenseNumber; }
    int getExperienceYears() const { return experienceYears; }
    const std::string& getCabinetNumber() const { return cabinetNumber; }
    std::shared_ptr<Schedule> getSchedule() const { return schedule; }

    void setSpecialization(const std::string& spec) { specialization = spec; }
    void setCabinetNumber(const std::string& cabinet) { cabinetNumber = cabinet; }
    void setSchedule(std::shared_ptr<Schedule> newSchedule) { schedule = newSchedule; }
    
    /**
     * @brief Создать новое расписание для врача
     * @return Указатель на созданное расписание
     */
    std::shared_ptr<Schedule> createSchedule();
};
