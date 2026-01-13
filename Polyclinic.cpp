#include "Polyclinic.h"
#include <sstream>
#include <algorithm>
#include <iostream>

Polyclinic::Polyclinic(const std::string& name, const std::string& address,
                       const std::string& phoneNumber)
    : name(name), address(address), phoneNumber(phoneNumber) 
{
}

std::shared_ptr<Doctor> Polyclinic::findDoctorByDocument(const std::string& documentId) const 
{
    auto it = std::find_if(doctors.begin(), doctors.end(),
        [&documentId](const std::shared_ptr<Doctor>& doctor) {
            return doctor->getDocumentId() == documentId;
        });
    
    return (it != doctors.end()) ? *it : nullptr;
}

std::shared_ptr<Patient> Polyclinic::findPatientByDocument(const std::string& documentId) const 
{
    auto it = std::find_if(patients.begin(), patients.end(),
        [&documentId](const std::shared_ptr<Patient>& patient) {
            return patient->getDocumentId() == documentId;
        });
    
    return (it != patients.end()) ? *it : nullptr;
}

std::shared_ptr<Person> Polyclinic::findPersonByDocument(const std::string& documentId) const
{
    // Сначала ищем среди врачей
    auto doctor = findDoctorByDocument(documentId);
    if (doctor) {
        return std::static_pointer_cast<Person>(doctor);
    }
    
    // Затем среди пациентов
    auto patient = findPatientByDocument(documentId);
    if (patient) {
        return std::static_pointer_cast<Person>(patient);
    }
    
    return nullptr;
}

bool Polyclinic::isDocumentUnique(const std::string& documentId) const
{
    return (findDoctorByDocument(documentId) == nullptr && 
            findPatientByDocument(documentId) == nullptr);
}

bool Polyclinic::addDoctor(std::shared_ptr<Doctor> doctor)
{
    if (!isDocumentUnique(doctor->getDocumentId())) {
        std::cerr << "Ошибка: документ " << doctor->getDocumentId() 
                  << " уже существует в системе!" << std::endl;
        return false;
    }
    
    doctors.push_back(doctor);
    return true;
}

bool Polyclinic::addPatient(std::shared_ptr<Patient> patient)
{
    if (!isDocumentUnique(patient->getDocumentId())) {
        std::cerr << "Ошибка: документ " << patient->getDocumentId() 
                  << " уже существует в системе!" << std::endl;
        return false;
    }
    
    patients.push_back(patient);
    return true;
}

bool Polyclinic::removeDoctorByDocument(const std::string& documentId)
{
    auto it = std::remove_if(doctors.begin(), doctors.end(),
        [&documentId](const std::shared_ptr<Doctor>& doctor) {
            return doctor->getDocumentId() == documentId;
        });
    
    bool removed = (it != doctors.end());
    doctors.erase(it, doctors.end());
    return removed;
}

bool Polyclinic::removePatientByDocument(const std::string& documentId)
{
    auto it = std::remove_if(patients.begin(), patients.end(),
        [&documentId](const std::shared_ptr<Patient>& patient) {
            return patient->getDocumentId() == documentId;
        });
    
    bool removed = (it != patients.end());
    patients.erase(it, patients.end());
    return removed;
}

std::vector<std::shared_ptr<Person>> Polyclinic::getAllPersons() const
{
    std::vector<std::shared_ptr<Person>> persons;
    
    // Добавляем врачей
    for (const auto& doctor : doctors) {
        persons.push_back(std::static_pointer_cast<Person>(doctor));
    }
    
    // Добавляем пациентов
    for (const auto& patient : patients) {
        persons.push_back(std::static_pointer_cast<Person>(patient));
    }
    
    return persons;
}

std::string Polyclinic::getAllPersonsInfo() const
{
    std::stringstream ss;
    ss << "=== ВСЕ ЛЮДИ В ПОЛИКЛИНИКЕ \"" << name << "\" ===\n";
    ss << "Всего людей: " << (doctors.size() + patients.size()) << "\n";
    ss << "========================================\n\n";
    
    ss << "ВРАЧИ (" << doctors.size() << " чел.):\n";
    ss << "----------------------------------------\n";
    for (const auto& doctor : doctors) {
        ss << "Документ: " << doctor->getDocumentId() << "\n";
        ss << doctor->getInfo() << "\n";
    }
    
    ss << "\nПАЦИЕНТЫ (" << patients.size() << " чел.):\n";
    ss << "----------------------------------------\n";
    for (const auto& patient : patients) {
        ss << "Документ: " << patient->getDocumentId() << "\n";
        ss << patient->getInfo() << "\n";
    }
    
    return ss.str();
}

void Polyclinic::removeDoctor(const std::string& licenseNumber) 
{
    auto it = std::remove_if(doctors.begin(), doctors.end(),
        [&licenseNumber](const auto& doctor) {
            return doctor->getLicenseNumber() == licenseNumber;
        });
    doctors.erase(it, doctors.end());
}
