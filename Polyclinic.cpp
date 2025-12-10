#include "Polyclinic.h"
#include <sstream>
#include <algorithm>

Polyclinic::Polyclinic(const std::string& name, const std::string& address,
    const std::string& phoneNumber)
    : name(name), address(address), phoneNumber(phoneNumber) 
{
}

void Polyclinic::addDoctor(std::shared_ptr<Doctor> doctor) 
{
    doctors.push_back(doctor);
}

void Polyclinic::removeDoctor(const std::string& licenseNumber) 
{
    auto it = std::remove_if(doctors.begin(), doctors.end(),
        [&licenseNumber](const auto& doctor) 
        {
            return doctor->getLicenseNumber() == licenseNumber;
        });
    doctors.erase(it, doctors.end());
}

std::vector<std::shared_ptr<Doctor>> Polyclinic::getAllDoctors() const 
{
    return doctors;
}

std::string Polyclinic::getAllDoctorsInfo() const 
{
    std::stringstream ss;
    ss << "Список всех врачей поликлиники \"" << name << "\":\n";
    ss << "========================================\n";

    for (const auto& doctor : doctors) 
    {
        ss << doctor->getInfo() << "\n";
    }

    return ss.str();
}

void Polyclinic::addPatient(std::shared_ptr<Patient> patient) 
{
    patients.push_back(patient);
}

void Polyclinic::removePatient(const std::string& medicalCardNumber) 
{
    auto it = std::remove_if(patients.begin(), patients.end(),
        [&medicalCardNumber](const auto& patient) {
            return patient->getMedicalCardNumber() == medicalCardNumber;
        });
    patients.erase(it, patients.end());
}

std::vector<std::shared_ptr<Patient>> Polyclinic::getAllPatients() const 
{
    return patients;
}

std::string Polyclinic::getAllPatientsInfo() const 
{
    std::stringstream ss;
    ss << "Список всех пациентов поликлиники \"" << name << "\":\n";
    ss << "========================================\n";

    for (const auto& patient : patients) 
    {
        ss << patient->getInfo() << "\n";
    }

    return ss.str();
}

void Polyclinic::addAppointment(std::shared_ptr<Appointment> appointment) 
{
    appointments.push_back(appointment);
}

void Polyclinic::removeAppointment(size_t index) 
{
    if (index < appointments.size()) 
    {
        appointments.erase(appointments.begin() + index);
    }
}

std::vector<std::shared_ptr<Appointment>> Polyclinic::getAllAppointments() const 
{
    return appointments;
}

std::string Polyclinic::getAllAppointmentsInfo() const 
{
    std::stringstream ss;
    ss << "Список всех записей на прием:\n";
    ss << "========================================\n";

    for (const auto& appointment : appointments) 
    {
        ss << appointment->getInfo() << "\n";
    }

    return ss.str();
}

void Polyclinic::addSchedule(std::shared_ptr<Schedule> schedule) 
{
    schedules.push_back(schedule);
}

std::string Polyclinic::getAllSchedulesInfo() const 
{
    std::stringstream ss;
    ss << "Расписание работы врачей:\n";
    ss << "========================================\n";

    for (const auto& schedule : schedules) 
    {
        ss << schedule->getInfo() << "\n";
    }

    return ss.str();
}