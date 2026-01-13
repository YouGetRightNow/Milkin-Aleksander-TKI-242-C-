#include "IStreamGenerator.h"
using namespace std;
namespace algebra
{

    IStreamGenerator::IStreamGenerator(istream& in) : in(in) {}

    int IStreamGenerator::generate()
    {
        int value;
        in >> value;
        return value;
    }

}