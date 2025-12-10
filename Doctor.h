#pragma once
#define DOCTOR_H

#include "Person.h"
#include <string>
#include <vector>

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

public:

    /**
     * @brief Конструктор класса Doctor
     * @param firstName Имя врача
     * @param lastName Фамилия врача
     * @param middleName Отчество врача
     * @param age Возраст врача
     * @param specialization Специализация врача
     * @param licenseNumber Номер лицензии
     * @param experienceYears Стаж работы в годах
     * @param cabinetNumber Номер кабинета
     */
    Doctor(const std::string& firstName, const std::string& lastName,
        const std::string& middleName, int age,
        const std::string& specialization, const std::string& licenseNumber,
        int experienceYears, const std::string& cabinetNumber);

    /**
     * @brief Реализация виртуального метода getInfo()
     * @return Подробная информация о враче
     */
    std::string getInfo() const override;

    /**
     * @brief Получить специализацию врача
     * @return Специализация врача
     */
    const std::string& getSpecialization() const { return specialization; }

    /**
     * @brief Получить номер лицензии врача
     * @return Номер лицензии
     */
    const std::string& getLicenseNumber() const { return licenseNumber; }

    /**
     * @brief Получить стаж работы врача
     * @return Стаж работы в годах
     */
    int getExperienceYears() const { return experienceYears; }

    /**
     * @brief Получить номер кабинета врача
     * @return Номер кабинета
     */
    const std::string& getCabinetNumber() const { return cabinetNumber; }

    /**
     * @brief Установить специализацию врача
     * @param spec Новая специализация
     */
    void setSpecialization(const std::string& spec) { specialization = spec; }

    /**
     * @brief Установить номер кабинета врача
     * @param cabinet Новый номер кабинета
     */
    void setCabinetNumber(const std::string& cabinet) { cabinetNumber = cabinet; }
};