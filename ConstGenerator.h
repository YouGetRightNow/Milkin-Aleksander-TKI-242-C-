#pragma once
#define CONSTGENERATOR_H
#include "Generator.h"

namespace algebra
{
	/**
	 * @brief Класс, реализующий генератор, всегда возвращающий одно и то же значение.
	 */
	class ConstGenerator : public Generator
	{
	private:

		int constValue;

	public:

		/**
		 * @brief Конструктор ConstantGenerator
		 * @param value Константное значение, которое будет возвращаться
		 */
		ConstGenerator(int value = 0);

		/**
		 * @brief Генерирует константное значение.
		 * @return Всегда возвращает одно и то же значение.
		 */
		int generate() override;
	};

}
