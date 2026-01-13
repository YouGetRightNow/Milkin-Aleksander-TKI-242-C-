#pragma once
#define PATIENT_H

#include "Person.h"
#include "Appointment.h"
#include <string>
#include <vector>
#include <memory>

/**
 * @brief Класс, представляющий пациента поликлиники
 */
class Patient : public Person 
{
private:
    std::string medicalCardNumber; 
    std::string phoneNumber;      
    std::string address;
    std::vector<std::shared_ptr<Appointment>> appointments; 

public:
    /**
     * @brief Конструктор класса Patient
     */
    Patient(const std::string& firstName, const std::string& lastName,
            const std::string& middleName, int age,
            const std::string& documentId,
            const std::string& medicalCardNumber,
            const std::string& phoneNumber, const std::string& address);

    /**
     * @brief Реализация виртуального метода getInfo()
     * @return Подробная информация о пациенте
     */
    std::string getInfo() const override;

    // Геттеры
    const std::string& getMedicalCardNumber() const { return medicalCardNumber; }
    const std::string& getPhoneNumber() const { return phoneNumber; }
    const std::string& getAddress() const { return address; }
    const std::vector<std::shared_ptr<Appointment>>& getAppointments() const { return appointments; }
    
    /**
     * @brief Получить будущие записи пациента
     * @return Вектор будущих записей
     */
    std::vector<std::shared_ptr<Appointment>> getUpcomingAppointments() const;
    
    /**
     * @brief Получить завершенные записи пациента
     * @return Вектор завершенных записей
     */
    std::vector<std::shared_ptr<Appointment>> getCompletedAppointments() const;

    // Сеттеры
    void setPhoneNumber(const std::string& phone) { phoneNumber = phone; }
    void setAddress(const std::string& addr) { address = addr; }
    
    /**
     * @brief Добавить запись к пациенту
     * @param appointment Запись на прием
     */
    void addAppointment(std::shared_ptr<Appointment> appointment);
    
    /**
     * @brief Удалить запись пациента
     * @param appointment Запись для удаления
     * @return true если удалено успешно
     */
    bool removeAppointment(std::shared_ptr<Appointment> appointment);
};
