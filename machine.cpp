#include "machine.h"

#pragma mark - Constructor
machine::machine()
{
    rotors = std::vector<rotor>();
}

#pragma mark - Encoding
char machine::encode(char c)
{
    int nrotors = (int)this->rotors.size();
    if (nrotors == 0)
        throw std::runtime_error("No rotors found. Please set up at least one rotor.");

    if (!this->reflector.is_reflector())
        throw std::runtime_error("The reflector must have symetric wiring. Check rotor::is_reflector().");

    char e = c;
    e = plugs.encode(e);
    for (int i = nrotors - 1; i >= 0; i--)
    {
        e = rotors[i].encode_forward(e);
    }
    e = reflector.encode_forward(e);
    for (int i = 0; i < nrotors; i++)
    {
        e = rotors[i].encode_backward(e);
    }
    e = plugs.encode(e);
    rotor_turnover(nrotors - 1);
    return e;
}

void machine::rotor_turnover(int i)
{
    if (i < 0)
        return;
    if (rotors[i].is_in_turnover_position())
    {
        rotor_turnover(i - 1);
    }
    rotors[i].step();
}

std::string machine::encode_string(std::string s)
{
    std::string encoded = "";
    for (int i = 0; i < s.length(); i++)
    {
        encoded += encode(s[i]);
    }
    return encoded;
}