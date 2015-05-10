#include <sstream>
#include <string>
std::string n2s(double in)
{
    std::stringstream as;
    as << in;
    return as.str();
}
