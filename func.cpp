#include "func.h"
#include <iostream>
#include <sstream>

#include <Windows.h>
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
    vector<int> rot_keys;
    int refelc_keys;
    vector<pair<char, char>> plug_keys;
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
                rot_keys.clear();
                istringstream iss(rotors2);
                string rot;
                int x;
                while (iss >> rot)
                {
                    stringstream geek(rot.c_str());
                    geek >> x;
                    x = x - 1;
                    vec.push_back(rotor(rotor_wiring(x)));
                    rot_keys.push_back(x);
                }
                m.rotors = vec;
                break;
            }
            case 2:
            {
                cout << "Choose from the following reflector: \n";
                cout << "1. w_ra\n2. w_rb,\n3. w_rc\n4. w_rbt\n5. w_rct\n";
                int x;
                cin >> x;
                x += 23;
                m.reflector = rotor(rotor_wiring(x));
                refelc_keys = x;
                break;
            }
            case 3:
            {
                cout << "How many plugs would you like to add" << endl;
                int x;
                cin >> x;
                cout << "Add " << x << " plugs below in format A B" << endl;
                while (x--)
                {
                    string s1, s2;
                    cin >> s1 >> s2;
                    m.plugs.set(s1[0], s2[0]);
                }
                break;
            }
            case 4:
            {
                cout << "Type the message: ";
                string s;
                cin >> s;
                string t = m.encode_string(s);
                cout << "encoding..." << endl;
                Sleep(3000);
                cout << "The encrypted message is: " << t << endl;

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