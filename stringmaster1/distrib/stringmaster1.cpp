// compile with -no-pie -fno-stack-protector -O1
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <limits>


using namespace std;

const string chars = "abcdefghijklmnopqrstuvwxy";


void spawn_shell() {
    char* args[] = {(char*)"/bin/bash", NULL};
    execve("/bin/bash", args, NULL);
}
  

void print_menu() {
    cout << endl;
    cout << "Enter the command you want to execute:" << endl;
    cout << "[1] swap <index1> <index2>                   (Cost: 1)" << endl;
    cout << "[2] replace <char1> <char2>                  (Cost: 1)" << endl;
    cout << "[3] print                                    (Cost: 1)" << endl;
    cout << "[4] quit                                              " << endl;
    cout << "> ";
}

void play() {
    string from(10, '\00');
    string to(10, '\00');
    for (int i = 0; i < 10; ++i) {
        from[i] = chars[rand() % (chars.length() - 1)];
        to[i] = chars[rand() % (chars.length() - 1)];
    }


    cout << "Perform the following operations on String1 to generate String2 with minimum costs." << endl << endl;
    cout << "[1] swap <index1> <index2>                   (Cost: 1)" << endl;
    cout << "    Swaps the char at index1 with the char at index2  " << endl;
    cout << "[2] replace <char1> <char2>                  (Cost: 1)" << endl;
    cout << "    Replaces the first occurence of char1 with char2  " << endl;
    cout << "[3] print                                    (Cost: 1)" << endl;
    cout << "    Prints the current version of the string          " << endl;
    cout << "[4] quit                                              " << endl;
    cout << "    Give up and leave the game                        " << endl;
    cout << endl;
    cout << "String1: " << from << endl;
    cout << "String2: " << to << endl;
    cout << endl;
        
    unsigned int costs = 0; 
    string s(from);

    while (true) {
        print_menu();

        string command;
        cin >> command;

        if (command == "swap") {
            unsigned int i1, i2;
            cin >> i1 >> i2;
            if (cin.good() && i1 < s.length() && i2 < s.length()) {
                swap(s[i1], s[i2]);
            }
            costs += 1;
        } else if (command == "replace") {
            char c1, c2;
            cin >> c1 >> c2;
            auto index = s.find(c1);
            cout << c1 << c2 << index << endl;
            if (index >= 0) {
                s[index] = c2;
            }
            costs += 1;
        } else if (command == "print") {
            cout << s << endl;
            costs += 1;
        } else if (command == "quit") {
            cout << "You lost." << endl;
            break;
        } else {
            cout << "Invalid command" << endl;
        }

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (!cout) {
            cout.clear();
        }

        if (s == to) {
            cout << s.length() << endl;
            cout << endl;
            cout << "****************************************" << endl;
            cout << "* Congratulations                       " << endl;
            cout << "* You solved the problem with cost: " << costs << endl;
            cout << "****************************************" << endl;
            cout << endl;
            break;
        }
    }
}




int main() {
    srand(time(nullptr));

    play();
}
