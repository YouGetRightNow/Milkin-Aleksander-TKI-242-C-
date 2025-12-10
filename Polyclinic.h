#pragma once
#define POLYCLINIC_H

#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include "Schedule.h"
#include <vector>
#include <memory>
#include <string>

 /**
  * @brief Основной класс системы поликлиники
  */
class Polyclinic 
{
private:

    std::vector<std::shared_ptr<Doctor>> doctors;       
    std::vector<std::shared_ptr<Patient>> patients;    
    std::vector<std::shared_ptr<Appointment>> appointments; 
    std::vector<std::shared_ptr<Schedule>> schedules;   

    std::string name;       
    std::string address;    
    std::string phoneNumber; 

public:

    /**
     * @brief Конструктор класса Polyclinic
     * @param name Название поликлиники
     * @param address Адрес поликлиники
     * @param phoneNumber Телефон поликлиники
     */
    Polyclinic(const std::string& name, const std::string& address,
        const std::string& phoneNumber);

    /**
     * @brief Добавить врача в систему
     * @param doctor Указатель на объект Doctor
     */
    void addDoctor(std::shared_ptr<Doctor> doctor);

    /**
     * @brief Удалить врача из системы
     * @param licenseNumber Номер лицензии врача для удаления
     */
    void removeDoctor(const std::string& licenseNumber);

    /**
     * @brief Получить всех врачей поликлиники
     * @return Вектор указателей на всех врачей
     */
    std::vector<std::shared_ptr<Doctor>> getAllDoctors() const;

    /**
     * @brief Получить информацию о всех врачах
     * @return Форматированная информация о всех врачах
     */
    std::string getAllDoctorsInfo() const;

    /**
     * @brief Добавить пациента в систему
     * @param patient Указатель на объект Patient
     */
    void addPatient(std::shared_ptr<Patient> patient);

    /**
     * @brief Удалить пациента из системы
     * @param medicalCardNumber Номер медицинской карты пациента для удаления
     */
    void removePatient(const std::string& medicalCardNumber);

    /**
     * @brief Получить всех пациентов поликлиники
     * @return Вектор указателей на всех пациентов
     */
    std::vector<std::shared_ptr<Patient>> getAllPatients() const;

    /**
     * @brief Получить информацию о всех пациентах
     * @return Форматированная информация о всех пациентах
     */
    std::string getAllPatientsInfo() const;

    /**
     * @brief Добавить запись на прием
     * @param appointment Указатель на объект Appointment
     */
    void addAppointment(std::shared_ptr<Appointment> appointment);

    /**
     * @brief Удалить запись на прием по индексу
     * @param index Индекс записи в векторе
     */
    void removeAppointment(size_t index);

    /**
     * @brief Получить все записи на прием
     * @return Вектор указателей на все записи
     */
    std::vector<std::shared_ptr<Appointment>> getAllAppointments() const;

    /**
     * @brief Получить информацию о всех записях
     * @return Форматированная информация о всех записях
     */
    std::string getAllAppointmentsInfo() const;

    /**
     * @brief Добавить расписание врача
     * @param schedule Указатель на объект Schedule
     */
    void addSchedule(std::shared_ptr<Schedule> schedule);

    /**
     * @brief Получить информацию о всех расписаниях
     * @return Форматированная информация о всех расписаниях
     */
    std::string getAllSchedulesInfo() const;

    /**
     * @brief Получить название поликлиники
     * @return Название поликлиники
     */
    const std::string& getName() const { return name; }

    /**
     * @brief Получить адрес поликлиники
     * @return Адрес поликлиники
     */
    const std::string& getAddress() const { return address; }

    /**
     * @brief Получить телефон поликлиники
     * @return Телефон поликлиники
     */
    const std::string& getPhoneNumber() const { return phoneNumber; }

};