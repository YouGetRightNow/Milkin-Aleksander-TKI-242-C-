#pragma once
#define ARRAYHANDLER_H

#include <vector>
#include <memory> 

/**
 * @brief  ласс дл€ работы с одномерным массивом целых чисел.
 */
class ArrayHandler 
{
private:
	
   /**
    * @brief ”мный указатель на вектор целых чисел, хран€щий массив.
    */
	std::unique_ptr<std::vector<int>> arr;

public:
    /**
     * @brief  онструктор класса.
     * @param n –азмер массива, который будет создан.
     */
	ArrayHandler(int n);

    /**
     * @brief «аполн€ет массив случайными числами или значени€ми, введенными пользователем.
     * @param randomFill ‘лаг, указывающий, заполн€ть ли массив случайными числами (true) или запрашивать ввод с клавиатуры (false).
     */
    void fillArray(bool randomFill);

    /**
    * @brief ¬ыводит элементы массива в стандартный поток вывода.
    */
	void printArray() const;

    /**
     * @brief «амен€ет первый элемент массива, кратный 5, нулем.
     */
	void replaceFirstMultipleOf5();
    
    /**
     * @brief ¬ставл€ет элемент со значением K после каждого нечетного элемента,
     * который начинаетс€ с цифры K (в строковом представлении).
     * @param k «начение дл€ вставки.
     */
	void insertAfterOddStartingWithK(int k);
    
    /**
     * @brief ‘ормирует новый массив на основе исходного по заданному правилу.
     * ѕервый и последний элементы нового массива равны нулю, остальные элементы вычисл€ютс€ по формуле: Mi = -Pi * (i + 1).
     * @return ”мный указатель на новый вектор, содержащий преобразованный массив.
     */
	std::unique_ptr<std::vector<int>> transformArray();

};
