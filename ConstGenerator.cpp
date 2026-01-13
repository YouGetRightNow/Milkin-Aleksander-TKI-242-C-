#include "ConstGenerator.h"

namespace algebra
{
	ConstGenerator::ConstGenerator(int value) : constValue(value)
	{
	}

	int ConstGenerator::generate()
	{
		return constValue;
	}
}