#include "../PolyclinicLib/Person.h"
#include "../PolyclinicLib/Doctor.h"
#include "../PolyclinicLib/Patient.h"
#include "../PolyclinicLib/Appointment.h"
#include "../PolyclinicLib/Schedule.h"
#include "../PolyclinicLib/Polyclinic.h"
#include <iostream>
#include <memory>
#include <vector>
#include <locale.h>

int main() 
{
    setlocale(LC_ALL, "RU");

    Polyclinic polyclinic("Городская поликлиника №56", "ул. Образцова, 2", "+74951256666");

    std::vector<std::shared_ptr<Person>> people;

    auto doctor1 = std::make_shared<Doctor>("Иван", "Иванов", "Иванович", 45,
        "Терапевт", "LIC001", 20, "101");
    auto doctor2 = std::make_shared<Doctor>("Петр", "Петров", "Петрович", 50,
        "Хирург", "LIC002", 25, "205");
    auto doctor3 = std::make_shared<Doctor>("Анна", "Сидорова", "Алексеевна", 38,
        "Педиатр", "LIC003", 15, "302");

    auto patient1 = std::make_shared<Patient>("Алексей", "Кузнецов", "Сергеевич", 35,
        "CARD001", "+79011234567", "ул. Ленина, 10");
    auto patient2 = std::make_shared<Patient>("Мария", "Иванова", "Петровна", 28,
        "CARD002", "+79022345678", "ул. Мира, 15");
    auto patient3 = std::make_shared<Patient>("Сергей", "Петров", "Алексеевич", 42,
        "CARD003", "+79033456789", "ул. Советская, 20");

    polyclinic.addDoctor(doctor1);
    polyclinic.addDoctor(doctor2);
    polyclinic.addDoctor(doctor3);

    polyclinic.addPatient(patient1);
    polyclinic.addPatient(patient2);
    polyclinic.addPatient(patient3);

    people.push_back(doctor1);
    people.push_back(doctor2);
    people.push_back(doctor3);
    people.push_back(patient1);
    people.push_back(patient2);
    people.push_back(patient3);

    std::cout << "========== КОЛЛЕКЦИЯ ЛЮДЕЙ ==========\n";
    for (const auto& person : people) 
    {
        std::cout << person->getInfo() << std::endl;
    }


    auto schedule1 = std::make_shared<Schedule>(doctor1);
    schedule1->addWorkingDay("Понедельник", "08:00-16:00");
    schedule1->addWorkingDay("Среда", "08:00-16:00");
    schedule1->addWorkingDay("Пятница", "08:00-16:00");

    auto schedule2 = std::make_shared<Schedule>(doctor2);
    schedule2->addWorkingDay("Вторник", "09:00-17:00");
    schedule2->addWorkingDay("Четверг", "09:00-17:00");

    polyclinic.addSchedule(schedule1);
    polyclinic.addSchedule(schedule2);


    auto appointment1 = std::make_shared<Appointment>(doctor1, patient1,
        "2024-01-15", "10:00",
        "Профилактический осмотр");
    auto appointment2 = std::make_shared<Appointment>(doctor2, patient2,
        "2024-01-16", "11:00",
        "Консультация");
    auto appointment3 = std::make_shared<Appointment>(doctor3, patient3,
        "2024-01-17", "14:00",
        "Прививка");

    polyclinic.addAppointment(appointment1);
    polyclinic.addAppointment(appointment2);
    polyclinic.addAppointment(appointment3);

    std::cout << "\n========== СВОДНАЯ ИНФОРМАЦИЯ О ВРАЧАХ ==========\n";
    std::cout << polyclinic.getAllDoctorsInfo() << std::endl;

    std::cout << "========== СВОДНАЯ ИНФОРМАЦИЯ О ПАЦИЕНТАХ ==========\n";
    std::cout << polyclinic.getAllPatientsInfo() << std::endl;

    std::cout << "========== ИНФОРМАЦИЯ О ЗАПИСЯХ К ВРАЧУ ==========\n";
    std::cout << polyclinic.getAllAppointmentsInfo() << std::endl;

    std::cout << "========== РАСПИСАНИЕ ВРАЧЕЙ ==========\n";
    std::cout << polyclinic.getAllSchedulesInfo() << std::endl;

    std::cout << "========== ПРИМЕР ЗАПИСИ К ВРАЧУ ==========\n";
    if (!polyclinic.getAllAppointments().empty()) 
    {
        auto firstAppointment = polyclinic.getAllAppointments()[0];
        std::cout << "Первая запись в системе:\n";
        std::cout << firstAppointment->getInfo() << std::endl;

        firstAppointment->complete();
        std::cout << "После завершения приема:\n";
        std::cout << firstAppointment->getInfo() << std::endl;
    }

    return 0;
}
