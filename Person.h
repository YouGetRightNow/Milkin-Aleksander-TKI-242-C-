#pragma once
#define PERSON_H

#include <string>
#include <memory>
#include <vector>

/**
 * @brief Абстрактный базовый класс, представляющий человека в системе
 */
class Person 
{
protected:
    std::string firstName;  
    std::string lastName;   
    std::string middleName; 
    int age;
    std::string documentId;

public:
    /**
     * @brief Конструктор класса Person
     * @param firstName Имя человека
     * @param lastName Фамилия человека
     * @param middleName Отчество человека
     * @param age Возраст человека
     * @param documentId Уникальный идентификатор документа
     */
    Person(const std::string& firstName, const std::string& lastName,
           const std::string& middleName, int age,
           const std::string& documentId);

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Person() = default;

    /**
     * @brief Получить полное имя человека
     * @return Полное имя в формате "Фамилия Имя Отчество"
     */
    virtual std::string getFullName() const;

    /**
     * @brief Чисто виртуальный метод для получения информации о человеке
     * @return Строка с информацией о человеке
     */
    virtual std::string getInfo() const = 0;

    
    const std::string& getFirstName() const { return firstName; }
    const std::string& getLastName() const { return lastName; }
    const std::string& getMiddleName() const { return middleName; }
    int getAge() const { return age; }
    const std::string& getDocumentId() const { return documentId; }
    
    
    void setDocumentId(const std::string& id) { documentId = id; }
};
