#include <iostream>
#include <string>
#include <random>
#include <fstream>

int main() {
    // avaible chars for password
    std::string chars = "abcdefghijklmnopqrstuvwxyz"
                       "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                       "0123456789"
                       "!@#$%^&*()";
    int how_many;
    std::cout << "How many how many characters should your password have?: ";
    std::cin >> how_many;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    std::cout << "char pool: " << chars << " \n";
    std::cout << "how many chars: " << chars.size() << " \n";

    std::string password;
    for (int i = 0; i < how_many; i++) {
        int random_index = dist(gen);
        password += chars[random_index];
    }
    std::cout << "password: " << password << " \n";

    std::ofstream outfile;
    outfile.open("password.txt");
    outfile << password;
    outfile.close();

    return 0;
}