#include "func.h"
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>

//#include <Windows.h>
using namespace std;

string generateKey(vector<int> rot_keys, int refelc_keys, vector<pair<char, char>> plug_keys)
{
    srand(time(0));
    int num = rand();
    num %= 26;
    char c = (num + 65);
    string key = "";
    for (int i = 0; i < rot_keys.size(); i++)
    {
        key = key + c;
        key = key + to_string(rot_keys[i]);
        c++;
        c %= 26;
        c += 65;
    }
    key = key + c;
    key = key + to_string(refelc_keys);
    for (int i = 0; i < plug_keys.size(); i++)
    {
        key = key + plug_keys[i].first;
        key = key + plug_keys[i].second;
    }
    return key;
}
void DecryptKey(vector<int> &rot_keys, int &refelc_keys, vector<pair<char, char>> &plug_keys, string key)
{
    int st = key.length() - 1;
    while (key[st] - '0' < 0 || key[st] - '0' > 9)
    {
        plug_keys.push_back(make_pair(key[st - 1], key[st]));
        st -= 2;
    }
    refelc_keys = key[st] - '0';
    st -= 1;
    while (st > 0)
    {
        st -= 1;
        string temp = "";
        while (key[st] - '0' <= 9 && key[st] - '0' >= 0)
            temp = key[st--] + temp;
        if (temp != "")
            rot_keys.push_back(stoi(temp));
    }
    return;
}
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
    // m.rotors = std::vector<rotor>({rotor(w1), rotor(w2), rotor(w3)});
    // m.reflector = rotor(w_ra);
    // m.plugs.set('A', 'D');
    // m.plugs.set('O', 'L');
    // rotor_wiring r1 = rotor_wiring(14);
    // n.rotors = std::vector<rotor>({rotor(r1), rotor(w2), rotor(w3)});
    // n.reflector = rotor(w_ra);
    // n.plugs.set('A', 'D');
    // n.plugs.set('O', 'L');
    std::string rotor_wiringStr[] = {"straight", // Default wiring
                                     "c1 (Commercial Enigma A, B - 1924)",
                                     "c2 (Commercial Enigma A, B - 1924)",
                                     "c3 (Commercial Enigma A, B - 1924)", // Commercial Enigma A, B - 1924
                                     "gr1 (German Railway (Rocket) - 1941)",
                                     "gr2 (German Railway (Rocket) - 1941)",
                                     "gr3 (German Railway (Rocket) - 1941)",
                                     "gr_ukw (German Railway (Rocket) - 1941)",
                                     "gr_etw (German Railway (Rocket) - 1941)", // German Railway (Rocket) - 1941
                                     "k1 (Swiss K - 1939)",
                                     "k2 (Swiss K - 1939)",
                                     "k3 (Swiss K - 1939)",
                                     "k_ukw (Swiss K - 1939)",
                                     "k_etw (Swiss K - 1939)", // Swiss K - 1939
                                     "w1 (Military Rotors)",
                                     "w2 (Military Rotors)",
                                     "w3 (Military Rotor)",
                                     "w4 (M3 Army)",
                                     "w5 (M3 Army)",
                                     "w6 (M3 & M4 Naval (FEB 1942))",
                                     "w7 (M3 & M4 Naval (FEB 1942))",
                                     "w8 (M3 & M4 Naval (FEB 1942))", //   - 1930-1939
                                     "w_beta (Spring 1941)",
                                     "w_gamma (Spring 1942)",
                                     "w_ra",
                                     "w_rb",
                                     "w_rc",
                                     "w_rbt",
                                     "w_rct",
                                     "w_etw"};
    while (true)
    {
        machine m, n;
        vector<int> rot_keys;
        int refelc_keys = -1;
        vector<pair<char, char>> plug_keys;
        std::cout << "Encryptor>";
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
                 << "5. Print Machine Configurations\n"
                 << "6. Quit\n";
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
                refelc_keys = x;
                x += 23;
                m.reflector = rotor(rotor_wiring(x));

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
                    plug_keys.push_back(make_pair(s1[0], s2[0]));
                }
                break;
            }
            case 4:
            {
                if (plug_keys.size() == 0 || rot_keys.size() == 0 || refelc_keys == -1)
                {
                    cout << "NOT A VALID SETTING" << endl;
                    break;
                }
                cout << "Please choose from the following: " << endl;
                cout << "1. Encrypt a word or message\n2. Encrypt a file\n";
                int u;
                cin >> u;
                if (u == 1)
                {
                    cout << "Type the message: ";
                    string s;
                    cin >> s;
                    string t = m.encode_string(s);
                    cout << "encoding..." << endl;
                    // Sleep(3000);
                    cout << "The encrypted message is: " << t << endl;
                    cout << "The Decryption key is: " << generateKey(rot_keys, refelc_keys, plug_keys) << endl;
                    flag = false;
                    break;
                }
                if (u == 2)
                {
                    string fname;
                    cout << "Type the name of the file: ";
                    ofstream MyFile("encrypted.txt");
                    cin >> fname;
                    fstream file;
                    string word, t, q, filename;
                    filename = fname;
                    file.open(filename.c_str());
                    while (file >> word)
                    {
                        string k = m.encode_string(word);
                        MyFile << k << " ";
                    }
                    cout << "The Decryption key is: " << generateKey(rot_keys, refelc_keys, plug_keys) << endl;
                }
            }
            case 5:
            {
                cout << "ROTORS: " << endl;
                for (int i = 0; i < rot_keys.size(); i++)
                {
                    cout << endl;
                    cout << "ROTOR NUMBER: " << rot_keys[i] + 1 << endl;
                    cout << "NAME: " << rotor_wiringStr[rot_keys[i]] << endl;
                    cout << "State: " << i + 1 << endl;
                    cout << "Wiring: " << rotor().known_wiring(rotor_wiring(rot_keys[i])) << endl;
                }
                cout << endl;
                cout << "REFLECTOR NUMBER: " << refelc_keys << endl;
                cout << "REFLECTOR NAME: " << rotor_wiringStr[refelc_keys + 23] << endl;
                cout << "REFLECTOR WIRING : " << rotor().known_wiring(rotor_wiring(refelc_keys + 23)) << endl;
                cout << endl;
                cout << "PLUGS: " << endl;
                for (int i = 0; i < plug_keys.size(); i++)
                {
                    cout << "PLUG-" << i + 1 << ": " << plug_keys[i].first << "<->" << plug_keys[i].second << endl;
                }
                cout << endl;
                break;
            }
            case 6:
            {
                flag = false;
                break;
            }
            default:
                cout << "Not a valid choice" << endl;
                break;
            }
        }
        while (k == "decrypt" && flag != false)
        {
            cout << "Enter the key: ";
            string ke;
            cin >> ke;
            vector<rotor> vec;
            DecryptKey(rot_keys, refelc_keys, plug_keys, ke);
            for (int i = rot_keys.size() - 1; i >= 0; i--)
            {
                vec.push_back(rotor(rotor_wiring(rot_keys[i])));
            }
            n.rotors = vec;
            refelc_keys += 23;
            n.reflector = rotor(rotor_wiring(refelc_keys));
            for (int i = plug_keys.size() - 1; i >= 0; i--)
            {
                n.plugs.set(plug_keys[i].first, plug_keys[i].second);
            }
            cout << "Please choose from the following: " << endl;
            cout << "1. Decrypt a word or message\n2. Decrypt a file\n";
            int u;
            cin >> u;
            if (u == 1)
            {
                cout << "Enter the message: ";
                string t;
                cin >> t;

                string d = n.encode_string(t);
                cout << "Decrypted Message is: " << d << endl;
                flag = false;
                break;
            }
            else
            {
                string fname;
                cout << "Type the name of the file: ";
                ofstream MyFile("decrypted.txt");
                cin >> fname;
                fstream file;
                string word, t, q, filename;
                filename = fname;
                file.open(filename.c_str());
                cout << "decrypting..." << endl;
                while (file >> word)
                {
                    string k = n.encode_string(word);
                    MyFile << k << " ";
                }
                // Sleep(1000);
                cout << "Decryption Complete." << endl;
                break;
            }
        }
        if (k == "help")
        {
            cout << "To encrypt any message, you need to configure the machine first. To do so, type 'encrypt'. The Enigma Machine has 3 main parts, rotors, plugs and reflectors. You must select at least one configuration for ALL 3 to make a complete machine." << endl;
            cout << " " << endl;
            cout << "1. Rotors: Each rotor implements a substitution cipher. You can select from 30 different configurations. Multiple rotors can be added by typing their corresponding numbers separated by space." << endl;
            cout << "2. Reflector: You can select from 5 different combinations. The machine has only one reflector." << endl;
            cout << "3. Plug: Each plug swaps the 2 given letters. Multiple plugs can be added." << endl;
            cout << "After adding these 3 parts, you can press 6 to encrypt either a typed message (without spaces) or file. This will also generate a unique key. You can also see the final machine configuration by pressing 5." << endl;
            cout << " " << endl;
            cout << "To decrypt a message, type 'decrypt' and use the same key as encryption. You can decrypt either a typed message (without spaces) or file." << endl;
            cout << " " << endl;
            cout << "To know more about the Enigma Machine, type 'about'. Press exit to terminate" << endl;
            cout << " " << endl;
        }
        if (k == "about")
        {
            cout << "The Enigma Machine is a cipher device invented and used by Germany in World War 2 to protect commercial, diplomatic, and important military communication. It is used to encrypt and decrypt messages using a key. The Enigma machine was considered so secure that it was used to encipher the most top-secret messages. In typical use, one person types plain text on the Enigma's keyboard and the corresponding illuminated letters are the encoded ciphertext. This encrypted message is then communicated and as the receiver types the encoded message, the corresponding letters illuminated reveal the original plain text message. The sender and receiver share a common secret key. The security of the system depends on machine settings that were generally changed daily, based on secret key lists distributed in advance, and on other settings that were changed for each message." << endl
                 << endl;
        }
    }

    std::cout << "\n";
}