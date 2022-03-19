#include "func.h"
void start_machine()
{
    machine m, n;

    m.rotors = std::vector<rotor>({rotor(w1), rotor(w2), rotor(w3)});
    m.reflector = rotor(w_ra);
    m.plugs.set('A', 'D');
    m.plugs.set('O', 'L');

    n.rotors = std::vector<rotor>({rotor(w1), rotor(w2), rotor(w3)});
    n.reflector = rotor(w_ra);
    n.plugs.set('A', 'D');
    n.plugs.set('O', 'L');

    while (true)
    {
        std::cout << "Decrypt>>";
        std::string k;
        std::cin >> k;
        if (k == "exit")
        {
            std::cout << "BYE";
            return;
        }
        std::string s = m.encode_string(k);
        std::cout << "\nEntire encoded message: " << s;
        std::cout << "\nDecoding now...";

        std::string t = n.encode_string(s);
        std::cout << "\nEntire decoded message: " << t << "\n";
    }

    std::cout << "\n";
}