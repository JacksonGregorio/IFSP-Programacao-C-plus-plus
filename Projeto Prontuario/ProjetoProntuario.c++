#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Funcionario {
    std::string prontuario; // Alterado para std::string
    std::string nome;
    double salario;
};

void incluirFuncionario(std::vector<Funcionario>& funcionarios) {
    Funcionario novoFuncionario;
    std::cout << "Digite o prontuario do funcionario: ";
    std::cin >> novoFuncionario.prontuario;

    std::vector<Funcionario>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == novoFuncionario.prontuario) {
            break;
        }
    }

    if (it != funcionarios.end()) {
        std::cout << "Ja existe um funcionario com esse prontuario!" << std::endl;
        return;
    }

    std::cout << "Digite o nome do funcionario: ";
    std::cin.ignore();
    std::getline(std::cin, novoFuncionario.nome);

    std::cout << "Digite o salario do funcionario: ";
    std::cin >> novoFuncionario.salario;

    funcionarios.push_back(novoFuncionario);
    std::cout << "Funcionario incluido com sucesso!" << std::endl;
}

void excluirFuncionario(std::vector<Funcionario>& funcionarios) {
    std::string prontuario; // Change type to std::string
    std::cout << "Digite o prontuario do funcionario a ser excluido: ";
    std::cin >> prontuario;

    std::vector<Funcionario>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == prontuario) {
            break;
        }
    }

    if (it != funcionarios.end()) {
        funcionarios.erase(it);
        std::cout << "Funcionario excluido com sucesso!" << std::endl;
    } else {
        std::cout << "Funcionario nao encontrado!" << std::endl;
    }
}

void pesquisarFuncionario(const std::vector<Funcionario>& funcionarios) {
    std::string prontuario; // Change type to std::string
    std::cout << "Digite o prontuario do funcionario a ser pesquisado: ";
    std::cin >> prontuario;

    std::vector<Funcionario>::const_iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == prontuario) {
            break;
        }
    }

    if (it != funcionarios.end()) {
        std::cout << "Funcionario encontrado:" << std::endl;
        std::cout << "Prontuario: " << it->prontuario << std::endl;
        std::cout << "Nome: " << it->nome << std::endl;
        std::cout << "Salario: " << it->salario << std::endl;
    } else {
        std::cout << "Funcionario nao encontrado!" << std::endl;
    }
}

void listarFuncionarios(const std::vector<Funcionario>& funcionarios) {
    std::cout << "Lista de funcionarios:" << std::endl;
    double totalSalarios = 0.0;

    for (std::vector<Funcionario>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        std::cout << "Prontuario: " << it->prontuario << std::endl;
        std::cout << "Nome: " << it->nome << std::endl;
        std::cout << "Salario: " << it->salario << std::endl;
        totalSalarios += it->salario;
        std::cout << std::endl;
    }

    std::cout << "Total de salarios: " << totalSalarios << std::endl;
}

int main() {
    std::vector<Funcionario> funcionarios;
    int opcao;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "1. Incluir" << std::endl;
        std::cout << "2. Excluir" << std::endl;
        std::cout << "3. Pesquisar" << std::endl;
        std::cout << "4. Listar" << std::endl;
        std::cout << "Digite a opcao desejada: ";

        
		if (!(std::cin >> opcao)) {
	    std::cin.clear();
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	    continue;
		}

        switch (opcao) {
            case 0:
                std::cout << "Saindo do programa..." << std::endl;
                break;
            case 1:
                incluirFuncionario(funcionarios);
                break;
            case 2:
                excluirFuncionario(funcionarios);
                break;
            case 3:
                pesquisarFuncionario(funcionarios);
                break;
            case 4:
                listarFuncionarios(funcionarios);
                break;
            default:
                std::cout << "Opcao invalida!" << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcao != 0);

    return 0;
}