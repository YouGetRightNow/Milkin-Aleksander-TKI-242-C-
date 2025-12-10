#pragma once
#define PATIENT_H

#include "Person.h"
#include <string>

 /**
  * @brief Класс, представляющий пациента поликлиники
  */
class Patient : public Person 
{
private:

    std::string medicalCardNumber; 
    std::string phoneNumber;      
    std::string address;         

public:

    /**
     * @brief Конструктор класса Patient
     * @param firstName Имя пациента
     * @param lastName Фамилия пациента
     * @param middleName Отчество пациента
     * @param age Возраст пациента
     * @param medicalCardNumber Номер медицинской карты
     * @param phoneNumber Контактный телефон
     * @param address Адрес проживания
     */
    Patient(const std::string& firstName, const std::string& lastName,
        const std::string& middleName, int age,
        const std::string& medicalCardNumber,
        const std::string& phoneNumber, const std::string& address);

    /**
     * @brief Реализация виртуального метода getInfo()
     * @return Подробная информация о пациенте
     */
    std::string getInfo() const override;

    /**
     * @brief Получить номер медицинской карты
     * @return Номер медицинской карты
     */
    const std::string& getMedicalCardNumber() const { return medicalCardNumber; }

    /**
     * @brief Получить контактный телефон
     * @return Номер телефона
     */
    const std::string& getPhoneNumber() const { return phoneNumber; }

    /**
     * @brief Получить адрес проживания
     * @return Адрес пациента
     */
    const std::string& getAddress() const { return address; }

    /**
     * @brief Установить новый контактный телефон
     * @param phone Новый номер телефона
     */
    void setPhoneNumber(const std::string& phone) { phoneNumber = phone; }

    /**
     * @brief Установить новый адрес проживания
     * @param addr Новый адрес
     */
    void setAddress(const std::string& addr) { address = addr; }
};