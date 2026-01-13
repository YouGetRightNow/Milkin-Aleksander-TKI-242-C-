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

    std::cout << "=== СИСТЕМА УПРАВЛЕНИЯ ПОЛИКЛИНИКОЙ ===\n\n";

    Polyclinic polyclinic("Городская поликлиника №56", 
                          "ул. Образцова, 2", 
                          "+74951256666");
    
    std::cout << "Поликлиника: " << polyclinic.getName() << "\n";
    std::cout << "Адрес: " << polyclinic.getAddress() << "\n";
    std::cout << "Телефон: " << polyclinic.getPhoneNumber() << "\n\n";

    // Создание врачей с документами
    auto doctor1 = std::make_shared<Doctor>("Иван", "Иванов", "Иванович", 45,
        "PASS001", "Терапевт", "LIC001", 20, "101");
    
    auto doctor2 = std::make_shared<Doctor>("Петр", "Петров", "Петрович", 50,
        "PASS002", "Хирург", "LIC002", 25, "205");
    
    auto doctor3 = std::make_shared<Doctor>("Анна", "Сидорова", "Алексеевна", 38,
        "PASS003", "Педиатр", "LIC003", 15, "302");

    // Создание пациентов с документами
    auto patient1 = std::make_shared<Patient>("Алексей", "Кузнецов", "Сергеевич", 35,
        "PASS101", "CARD001", "+79011234567", "ул. Ленина, 10");
    
    auto patient2 = std::make_shared<Patient>("Мария", "Иванова", "Петровна", 28,
        "PASS102", "CARD002", "+79022345678", "ул. Мира, 15");
    
    auto patient3 = std::make_shared<Patient>("Сергей", "Петров", "Алексеевич", 42,
        "PASS103", "CARD003", "+79033456789", "ул. Советская, 20");
    
    std::cout << "========== ДОБАВЛЕНИЕ ВРАЧЕЙ ==========\n";
    polyclinic.addDoctor(doctor1);
    polyclinic.addDoctor(doctor2);
    polyclinic.addDoctor(doctor3);
    std::cout << "Врачи добавлены успешно\n\n";

    std::cout << "========== ДОБАВЛЕНИЕ ПАЦИЕНТОВ ==========\n";
    polyclinic.addPatient(patient1);
    polyclinic.addPatient(patient2);
    polyclinic.addPatient(patient3);
    std::cout << "Пациенты добавлены успешно\n\n";
    
    std::vector<std::shared_ptr<Person>> people;
    people.push_back(doctor1);
    people.push_back(doctor2);
    people.push_back(doctor3);
    people.push_back(patient1);
    people.push_back(patient2);
    people.push_back(patient3);

    std::cout << "========== ИНФОРМАЦИЯ О ВСЕХ ЛЮДЯХ ==========\n";
    for (const auto& person : people) 
    {
        std::cout << person->getInfo() << std::endl;
    }

    // Демонстрация поиска по документу
    std::cout << "========== ПОИСК ПО ДОКУМЕНТУ ==========\n";
    
    std::string searchDoc = "PASS001";
    auto foundDoctor = polyclinic.findDoctorByDocument(searchDoc);
    if (foundDoctor) 
    {
        std::cout << "✓ Найден врач с документом " << searchDoc << ":\n";
        std::cout << foundDoctor->getFullName() << " - " 
                  << foundDoctor->getSpecialization() << std::endl;
    } 
    else 
    {
        std::cout << "✗ Врач с документом " << searchDoc << " не найден.\n";
    }

    searchDoc = "PASS102";
    auto foundPatient = polyclinic.findPatientByDocument(searchDoc);
    if (foundPatient) 
    {
        std::cout << "\n✓ Найден пациент с документом " << searchDoc << ":\n";
        std::cout << foundPatient->getFullName() << " - " 
                  << foundPatient->getMedicalCardNumber() << std::endl;
    } 
    else 
    {
        std::cout << "\n✗ Пациент с документом " << searchDoc << " не найден.\n";
    }

    std::cout << "\n========== ПОИСК ЛЮБОГО ЧЕЛОВЕКА ПО ДОКУМЕНТУ ==========\n";
    std::vector<std::string> testDocs = {"PASS002", "PASS103", "PASS999"};
    
    for (const auto& doc : testDocs) 
    {
        auto person = polyclinic.findPersonByDocument(doc);
        if (person) 
        {
            std::cout << "✓ Документ " << doc << " принадлежит: " 
                      << person->getFullName() << std::endl;
        } 
        else 
        {
            std::cout << "✗ Документ " << doc << " не найден в системе\n";
        }
    }

    std::cout << "\n========== ПРОВЕРКА УНИКАЛЬНОСТИ ДОКУМЕНТА ==========\n";
    std::vector<std::string> testDocuments = {"PASS001", "PASS999", "PASS102"};
    
    for (const auto& doc : testDocuments) 
    {
        if (polyclinic.isDocumentUnique(doc)) 
        {
            std::cout << "✓ Документ " << doc << " уникален (можно добавить нового человека)\n";
        } 
        else 
        {
            std::cout << "✗ Документ " << doc << " уже используется в системе!\n";
        }
    }

    std::cout << "\n========== ПРОВЕРКА ДУБЛИРОВАНИЯ ДОКУМЕНТА ==========\n";
    auto duplicatePatient = std::make_shared<Patient>("Дубликат", "Тестов", "Тестович", 30,
        "PASS001", // Такой же документ как у doctor1
        "CARD004", "+79000000000", "ул. Тестовая, 1");

    if (!polyclinic.addPatient(duplicatePatient)) 
    {
        std::cout << "✓ Система корректно отклонила добавление пациента с существующим документом!\n";
    }

    std::cout << "\n========== СОЗДАНИЕ РАСПИСАНИЙ ==========\n";
    
    auto schedule1 = doctor1->createSchedule();
    schedule1->addWorkingDay("Понедельник", "08:00-16:00");
    schedule1->addWorkingDay("Среда", "08:00-16:00");
    schedule1->addWorkingDay("Пятница", "08:00-16:00");
    polyclinic.addSchedule(schedule1);

    auto schedule2 = doctor2->createSchedule();
    schedule2->addWorkingDay("Вторник", "09:00-17:00");
    schedule2->addWorkingDay("Четверг", "09:00-17:00");
    schedule2->addWorkingDay("Суббота", "10:00-14:00");
    polyclinic.addSchedule(schedule2);

    // Создание записей на прием (с двусторонней связью)
    std::cout << "\n========== СОЗДАНИЕ ЗАПИСЕЙ НА ПРИЕМ ==========\n";
    
    auto appointment1 = std::make_shared<Appointment>(doctor1, patient1,
        "2024-01-15", "10:00", "Профилактический осмотр");
    
    auto appointment2 = std::make_shared<Appointment>(doctor2, patient2,
        "2024-01-16", "11:00", "Консультация по результатам анализов");
    
    auto appointment3 = std::make_shared<Appointment>(doctor3, patient3,
        "2024-01-17", "14:00", "Плановый осмотр и прививка");
    
    auto appointment4 = std::make_shared<Appointment>(doctor1, patient2,
        "2024-01-18", "09:30", "Второй прием для наблюдения");
    
    polyclinic.addAppointment(appointment1);
    polyclinic.addAppointment(appointment2);
    polyclinic.addAppointment(appointment3);
    polyclinic.addAppointment(appointment4);
    
    std::cout << "\n========== СВОДНАЯ ИНФОРМАЦИЯ О ВРАЧАХ ==========\n";
    std::cout << polyclinic.getAllDoctorsInfo();

    std::cout << "\n========== СВОДНАЯ ИНФОРМАЦИЯ О ПАЦИЕНТАХ ==========\n";
    std::cout << polyclinic.getAllPatientsInfo();

    std::cout << "\n========== ИНФОРМАЦИЯ О ЗАПИСЯХ К ВРАЧУ ==========\n";
    std::cout << polyclinic.getAllAppointmentsInfo();

    std::cout << "\n========== РАСПИСАНИЕ ВРАЧЕЙ ==========\n";
    std::cout << polyclinic.getAllSchedulesInfo();

    std::cout << "\n========== ИСТОРИЯ ЗАПИСЕЙ ПАЦИЕНТА ==========\n";
    std::cout << "Пациент: " << patient2->getFullName() << "\n";
    std::cout << "Всего записей: " << patient2->getAppointments().size() << "\n";
    
    appointment1->complete();
    
    std::cout << "\nЗавершенные записи:\n";
    auto completed = patient1->getCompletedAppointments();
    for (const auto& app : completed) {
        std::cout << "  - " << app->getDate() << " " << app->getTime() 
                  << ": " << app->getPurpose() << std::endl;
    }
    
    std::cout << "\nПредстоящие записи:\n";
    auto upcoming = patient2->getUpcomingAppointments();
    for (const auto& app : upcoming) {
        std::cout << "  - " << app->getDate() << " " << app->getTime() 
                  << ": " << app->getPurpose() << std::endl;
    }

    std::cout << "\n========== УДАЛЕНИЕ ПО ДОКУМЕНТУ ==========\n";
    std::string docToDelete = "PASS103";
    
    if (polyclinic.removePatientByDocument(docToDelete)) 
    {
        std::cout << "✓ Пациент с документом " << docToDelete << " удален\n";
        std::cout << "Осталось пациентов: " << polyclinic.getAllPatients().size() << "\n";
    } 
    else 
    {
        std::cout << "✗ Пациент с документом " << docToDelete << " не найден\n";
    }
    
    std::cout << "\n========== ПОЛНАЯ ИНФОРМАЦИЯ О ВСЕХ В СИСТЕМЕ ==========\n";
    std::cout << polyclinic.getAllPersonsInfo();

    // Тестирование связи врач-расписание
    std::cout << "\n========== ТЕСТИРОВАНИЕ СВЯЗИ ВРАЧ-РАСПИСАНИЕ ==========\n";
    if (doctor1->getSchedule()) 
    {
        std::cout << "Врач " << doctor1->getFullName() << " имеет расписание:\n";
        auto docSchedule = doctor1->getSchedule();
        std::cout << "Рабочих дней: " << docSchedule->getWorkingDays().size() << "\n";
        
        // Проверка конкретного дня
        if (docSchedule->isWorkingDay("Понедельник")) 
        {
            std::cout << "✓ В понедельник врач работает\n";
        }
        
        if (!docSchedule->isWorkingDay("Воскресенье")) 
        {
            std::cout << "✓ В воскресенье врач не работает\n";
        }
    }

    std::cout << "\n========== ДОБАВЛЕНИЕ НОВОГО ВРАЧА ==========\n";
    auto newDoctor = std::make_shared<Doctor>("Ольга", "Васнецова", "Михайловна", 40,
        "PASS999", "Невролог", "LIC999", 12, "408");
    
    if (polyclinic.addDoctor(newDoctor)) 
    {
        std::cout << "Новый врач успешно добавлен: " << newDoctor->getFullName() << "\n";
        std::cout << "Всего врачей теперь: " << polyclinic.getAllDoctors().size() << "\n";
    }

    std::cout << "\n========== ИТОГОВАЯ СТАТИСТИКА ПОЛИКЛИНИКИ ==========\n";
    std::cout << "Название: " << polyclinic.getName() << "\n";
    std::cout << "Всего врачей: " << polyclinic.getAllDoctors().size() << "\n";
    std::cout << "Всего пациентов: " << polyclinic.getAllPatients().size() << "\n";
    std::cout << "Всего людей: " << (polyclinic.getAllDoctors().size() + 
                                     polyclinic.getAllPatients().size()) << "\n";
    std::cout << "Всего записей на прием: " << polyclinic.getAllAppointments().size() << "\n";
    std::cout << "Всего расписаний: " << polyclinic.getAllSchedules().size() << "\n";

    std::cout << "\n=== РАБОТА ПРОГРАММЫ ЗАВЕРШЕНА ===\n";
    return 0;
}
