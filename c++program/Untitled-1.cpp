#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::ifstream file("nomes.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string nome, sobrenome;
        while (iss >> nome) {
            sobrenome = nome;
        }
        std::cout << sobrenome << ", " << line.substr(0, line.rfind(sobrenome)) << std::endl;
    }
    return 0;
}