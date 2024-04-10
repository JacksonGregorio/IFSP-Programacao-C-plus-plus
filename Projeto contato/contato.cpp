#include <iostream>
#include <string>
#include <iomanip> 

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
     Data() {}

    Data(int dia, int mes, int ano) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    int getDia() const {
        return dia;
    }

    void setDia(int dia) {
        this->dia = dia;
    }

    int getMes() const {
        return mes;
    }

    void setMes(int mes) {
        this->mes = mes;
    }

    int getAno() const {
        return ano;
    }

    void setAno(int ano) {
        this->ano = ano;
    }
};

class Contato {
private:
    std::string email;
    std::string nome;
    std::string telefone;
    Data dtnasc;

public:
    Contato(const std::string& email, const std::string& nome, const std::string& telefone, const Data& dtnasc) {
        this->email = email;
        this->nome = nome;
        this->telefone = telefone;
        this->dtnasc = dtnasc;
    }

    std::string getEmail() const {
        return email;
    }

    void setEmail(const std::string& email) {
        this->email = email;
    }

    std::string getNome() const {
        return nome;
    }

    void setNome(const std::string& nome) {
        this->nome = nome;
    }

    std::string getTelefone() const {
        return telefone;
    }

    void setTelefone(const std::string& telefone) {
        this->telefone = telefone;
    }

    Data getDtnasc() const {
        return dtnasc;
    }

    void setDtnasc(const Data& dtnasc) {
        this->dtnasc = dtnasc;
    }

    int idade() const {
        
        int currentYear = 2024;
        return currentYear - dtnasc.getAno();
    }
};

void printData(const Data& data) {
    std::cout << "---------------------\n";
    std::cout << "| Data              |\n";
    std::cout << "|-------------------|\n";
    std::cout << "| - dia: " << data.getDia() << " | \n";
    std::cout << "| - mes: " << data.getMes() << " | \n";
    std::cout << "| - ano: " << data.getAno() << " | \n";
    std::cout << "---------------------\n";
}

void printContato(const Contato& contato) {
    std::cout << "---------------------------------------\n";
    std::cout << "| Contato                             |\n";
    std::cout << "|-------------------------------------|\n";
	std::cout << "| - email: " << contato.getEmail() << " | \n";	
    std::cout << "| - nome: " << contato.getNome() << " | \n";
    std::cout << "| - telefone: " << contato.getTelefone() << " | \n";	
    std::cout << "| - dtnasc:"  << contato.getDtnasc().getDia() << " | \n";
    std::cout << "|-------------------------------------|\n";
    std::cout << "| + idade(): " << contato.idade() << " | \n";
    std::cout << "---------------------------------------\n";
}


int main() {
    Contato contatos[5] = {
        Contato("email1@example.com", "Nome1", "123456789", Data(1, 1, 2000)),
        Contato("email2@example.com", "Nome2", "987654321", Data(2, 2, 1995)),
        Contato("email3@example.com", "Nome3", "555555555", Data(3, 3, 1988)),
        Contato("email4@example.com", "Nome4", "999999999", Data(4, 4, 1992)),
        Contato("email5@example.com", "Nome5", "111111111", Data(5, 5, 1999))
    };

    for (int i = 0; i < 5; i++) {
        printContato(contatos[i]);
    }

    return 0;
}