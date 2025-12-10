#include "Tests.h"
#include "../PolyclinicLib/Person.h"
#include "../PolyclinicLib/Doctor.h"
#include "../PolyclinicLib/Patient.h"
#include "../PolyclinicLib/Appointment.h"
#include "../PolyclinicLib/Schedule.h"
#include "../PolyclinicLib/Polyclinic.h"
#include <cassert>
#include <iostream>

void testPerson() {
    std::cout << "Testing Person class...\n";
    Person* person = new Doctor("Иван", "Иванов", "Иванович", 45,
        "Терапевт", "LIC123", 20, "101");
    assert(person->getFullName() == "Иванов Иван Иванович");
    assert(person->getAge() == 45);
    delete person;
    std::cout << "Person tests passed!\n";
}

void testDoctor() {
    std::cout << "Testing Doctor class...\n";
    Doctor doc("Петр", "Петров", "Петрович", 50,
        "Хирург", "LIC456", 25, "205");
    assert(doc.getFullName() == "Петров Петр Петрович");
    assert(doc.getSpecialization() == "Хирург");
    assert(doc.getExperienceYears() == 25);
    std::cout << "Doctor tests passed!\n";
}

void testPatient() {
    std::cout << "Testing Patient class...\n";
    Patient patient("Анна", "Сидорова", "Алексеевна", 30,
        "CARD789", "+79001234567", "ул. Ленина, 10");
    assert(patient.getFullName() == "Сидорова Анна Алексеевна");
    assert(patient.getMedicalCardNumber() == "CARD789");
    std::cout << "Patient tests passed!\n";
}

void testAppointment() {
    std::cout << "Testing Appointment class...\n";
    auto doctor = std::make_shared<Doctor>("Иван", "Иванов", "Иванович", 45,
        "Терапевт", "LIC123", 20, "101");
    auto patient = std::make_shared<Patient>("Анна", "Сидорова", "Алексеевна", 30,
        "CARD789", "+79001234567", "ул. Ленина, 10");
    Appointment appointment(doctor, patient, "2024-01-15", "10:00", "Профилактический осмотр");
    assert(appointment.getDate() == "2024-01-15");
    assert(appointment.getPurpose() == "Профилактический осмотр");
    std::cout << "Appointment tests passed!\n";
}

void testSchedule() {
    std::cout << "Testing Schedule class...\n";
    auto doctor = std::make_shared<Doctor>("Иван", "Иванов", "Иванович", 45,
        "Терапевт", "LIC123", 20, "101");
    Schedule schedule(doctor);
    schedule.addWorkingDay("Понедельник", "09:00-18:00");
    schedule.addWorkingDay("Среда", "09:00-18:00");
    assert(schedule.getWorkingHours().size() == 2);
    std::cout << "Schedule tests passed!\n";
}

void testPolyclinic() {
    std::cout << "Testing Polyclinic class...\n";
    Polyclinic polyclinic("Городская поликлиника №56", "ул. Образцова, 2", "+74951256666");
    assert(polyclinic.getName() == "Городская поликлиника №56");

    auto doctor = std::make_shared<Doctor>("Иван", "Иванов", "Иванович", 45,
        "Терапевт", "LIC123", 20, "101");
    polyclinic.addDoctor(doctor);
    assert(polyclinic.getAllDoctors().size() == 1);
    std::cout << "Polyclinic tests passed!\n";
}

void runAllTests() {
    testPerson();
    testDoctor();
    testPatient();
    testAppointment();
    testSchedule();
    testPolyclinic();
    std::cout << "\nAll tests passed successfully!\n";
}
