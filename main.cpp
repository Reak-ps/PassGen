#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstdlib>

int main() {
    // avaible chars for password
    std::string chars;
    char auswahl;

    std::cout << "Capitals? (y/n): ";
    std::cin >> auswahl;
    if (auswahl == 'y') chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::cout << "LowerCase? (y/n): ";
    std::cin >> auswahl;
    if (auswahl == 'y') chars += "abcdefghijklmnopqrstuvwxyz";

    std::cout << "Numbers? (y/n): ";
    std::cin >> auswahl;
    if (auswahl == 'y') chars += "0123456789";

    std::cout << "Special Chars? (y/n): ";
    std::cin >> auswahl;
    if (auswahl == 'y') chars += "!@#$%^&*()";

    if (chars.empty()) {
        std::cout << "You Have To choose Atleast One Cmmon!\n";
        return 1;
    }
    int how_many;
    std::cout << "How many how many characters should your password have?: ";
    std::cin >> how_many;

    int how_many_passwords;
    std::cout << "How Many Passwords Should be Generatred: ";
    std::cin >> how_many_passwords;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    std::cout << "char pool: " << chars << " \n";
    std::cout << "how many chars: " << chars.size() << " \n";

    for (int j = 0; j < how_many_passwords; j++) {
    std::string password;
    for (int i = 0; i < how_many; i++) {
        int random_index = dist(gen);
        password += chars[random_index];
    }
    std::cout << "password: " << password << " \n";
    // Show Password strenght
    bool has_big = false, has_little = false, has_number = false, has_specials = false;

    for (char c : password) {
        if (c >= 'A' && c <= 'Z') has_big = true;
        else if (c >= 'a' && c <= 'z') has_little = true;
        else if (c >= '0' && c <= '9') has_number = true;
        else has_specials = true;
    }

    int strength = has_big + has_little + has_number + has_specials;

    std::cout << "Strength: ";
    if (password.length() < 8) std::cout << "WEAK (TOO SHORT)\n";
    else if (strength == 4) std::cout << "STRONG (ALL CHAR TYPES)\n";
    else if (strength >= 2) std::cout << "MEDIUM STRONG\n";
    else std::cout << "WEAK\n";

    std::string command = "echo " + password + " | clip";
    system(command.c_str());

        std::ofstream outfile;
        outfile.open("password.txt", std::ios::app);
        outfile << password << "\n";       // <-- DAS fehlt
        outfile << "----------\n";
        outfile.close();                    // <-- Auch wichtig!
    }
    std::cout << "\nPress enter to close...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}