#ifndef __Enigma__machine__
#define __Enigma__machine__

#include <iostream>
#include "rotor.h"
#include "plug.h"

class machine
{
public:
    machine();

    char encode(char);
    std::string encode_string(std::string);

    plugboard plugs;
    rotor reflector;
    std::vector<rotor> rotors;

private:
    void rotor_turnover(int i);
};
#endif