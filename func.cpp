#include "func.h"
#include <iostream>
#include <sstream>
using namespace std;
void start_machine()
{
    std::cout << "######## ##    ##  ######  ########  ##    ## ########  ########  #######  ######## " << std::endl;
    std::cout << "##       ###   ## ##    ## ##     ##  ##  ##  ##     ##    ##    ##     ## ##     ##" << std::endl;
    std::cout << "##       ####  ## ##       ##     ##   ####   ##     ##    ##    ##     ## ##     ##" << std::endl;
    std::cout << "######   ## ## ## ##       ########     ##    ########     ##    ##     ## ######## " << std::endl;
    std::cout << "##       ##  #### ##       ##   ##      ##    ##           ##    ##     ## ##   ##  " << std::endl;
    std::cout << "##       ##   ### ##    ## ##    ##     ##    ##           ##    ##     ## ##    ## " << std::endl;
    std::cout << "######## ##    ##  ######  ##     ##    ##    ##           ##     #######  ##     ##" << std::endl;
    std::cout << std::endl;
    std::cout << "                  {}\n";
    std::cout << "  ,   A           {}\n";
    std::cout << " / \\, | ,        .--.\n";
    std::cout << "|  =|= >        /.--.\\\n";
    std::cout << " \\ /` | `       |====|\n";
    std::cout << "  `   |         |`::`|\n";
    std::cout << "      |     .-;`\\..../`;_.-^-._\n";
    std::cout << "     /\\\\/  /  |...::..|`   :   `|\n";
    std::cout << "     |:'\\ |   /'''::''|   .:.   |\n";
    std::cout << "      \\ /\\;-,/\\   ::  |.........|\n";
    std::cout << "      |\\ <` >  >._::_.| ':   :' |\n";
    std::cout << "      | `";
    std::cout << "      |       |       \\    :   /\n";
    std::cout << "      |       |       \\    :   /\n";
    std::cout << "      |       |        \\   :   /\n";
    std::cout << "      |       |___/\\___|`-.:.-`\n";
    std::cout << "      |        \\_ || _/    `\n";
    std::cout << "      |        <_ >< _>\n";
    std::cout << "      |        |  ||  |\n";
    std::cout << "      |        |  ||  |\n";
    std::cout << "      |       _\\.:||:./_\n";
    std::cout << "      |      /____/\\____\\\n";
    std::cout << "\n";
    std::cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:" << std::endl;
    machine m, n;
    // m.rotors = std::vector<rotor>({rotor(w1), rotor(w2), rotor(w3)});
    // m.reflector = rotor(w_ra);
    // m.plugs.set('A', 'D');
    // m.plugs.set('O', 'L');
    // rotor_wiring r1 = rotor_wiring(14);
    // n.rotors = std::vector<rotor>({rotor(r1), rotor(w2), rotor(w3)});
    // n.reflector = rotor(w_ra);
    // n.plugs.set('A', 'D');
    // n.plugs.set('O', 'L');
    while (true)
    {
        std::cout << "Encryptor>>";
        bool flag = true;
        std::string k;
        std::cin >> k;
        if (k == "exit")
        {
            std::cout << "BYE";
            return;
        }
        while (k == "encrypt" && flag != false)
        {
            cout << "Preparing to encrypt..." << endl;
            cout << "Choose from the following:" << endl;
            cout << "1. Add Rotor\n"
                 << "2. Add Reflector\n"
                 << "3. Add Plugs\n"
                 << "4. Encrypt with chosen settings\n"
                 << "5. Quit\n";
            int choice;
            cin >> choice;
            string rotors2;
            switch (choice)
            {
            case 1:
            {
                cout << "Choose from the following rotors: \n";
                cout << "Note that you can choose multiple rotors separated by space" << endl;
                cout << "1. straight Default wiring\n2. c1\n3. c2\n4. c3 (Commercial Enigma A, B - 1924)\n5. gr1\n6. gr2\n7. gr3\n8. gr_ukw\n9. gr_etw (German Railway (Rocket) - 1941)\n10. k1\n11. k2\n12. k3\n13. k_ukw\n14. k_etw  (Swiss K - 1939)\n15. w1\n16. w2\n17. w3\n18. w4\n19. w5\n20. w6\n21. w7\n22. w8 (Military Rotors - 1930-1939)\n23. w_beta\n24. w_gamma\n25. w_ra\n26. w_rb\n27. w_rc\n28. w_rbt\n29. w_rct\n30. w_etw\n";
                getline(cin >> ws, rotors2);
                vector<rotor> vec;
                istringstream iss(rotors2);
                string rot;
                int x;
                while (iss >> rot)
                {
                    stringstream geek(rot.c_str());
                    geek >> x;
                    x = x - 1;
                    vec.push_back(rotor(rotor_wiring(x)));
                }
                m.rotors = vec;
                break;
            }
            case 2:
            {
                cout << "Choose from the following rotors: \n";
                cout << "Note that you can choose multiple rotors separated by space" << endl;
                break;
            }
            case 5:
            {
                flag = false;
                break;
            }
            default:
                break;
            }
        }
        // std::string s = m.encode_string(k);
        // std::cout << "\nEntire encoded message: " << s;
        // std::cout << "\nDecoding now...";

        // std::string t = n.encode_string(s);
        // std::cout << "\nEntire decoded message: " << t << "\n";
    }

    std::cout << "\n";
}