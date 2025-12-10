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

public:
    /**
     * @brief Конструктор класса Person
     * @param firstName Имя человека
     * @param lastName Фамилия человека
     * @param middleName Отчество человека
     * @param age Возраст человека
     */
    Person(const std::string& firstName, const std::string& lastName,
        const std::string& middleName, int age);

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

    /**
     * @brief Получить имя человека
     * @return Имя человека
     */
    const std::string& getFirstName() const { return firstName; }

    /**
     * @brief Получить фамилию человека
     * @return Фамилия человека
     */
    const std::string& getLastName() const { return lastName; }

    /**
     * @brief Получить отчество человека
     * @return Отчество человека
     */
    const std::string& getMiddleName() const { return middleName; }

    /**
     * @brief Получить возраст человека
     * @return Возраст человека
     */
    int getAge() const { return age; }
};
