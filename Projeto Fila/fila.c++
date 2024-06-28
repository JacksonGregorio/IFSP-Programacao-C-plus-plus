#include <iostream>
#include <queue>

int main() {
    std::queue<int> senhasGeradas;
    std::queue<int> senhasAtendidas;
    int senha = 0;
    int opcao;

    do {
        std::cout << "Senhas aguardando atendimento: " << senhasGeradas.size() << "\n";
        std::cout << "0. Sair\n1. Gerar senha\n2. Realizar atendimento\n";
        std::cin >> opcao;

        switch (opcao) {
            case 1: // Gerar senha
                senhasGeradas.push(++senha);
                std::cout << "Senha " << senha << " gerada.\n";
                break;
            case 2: // Realizar atendimento
                if (!senhasGeradas.empty()) {
                    int senhaAtendimento = senhasGeradas.front();
                    senhasGeradas.pop();
                    senhasAtendidas.push(senhaAtendimento);
                    std::cout << "Atendendo senha " << senhaAtendimento << ".\n";
                } else {
                    std::cout << "Nenhuma senha para atender.\n";
                }
                break;
        }
    } while (opcao != 0 || !senhasGeradas.empty());

    std::cout << "Quantidade de senhas atendidas: " << senhasAtendidas.size() << "\n";

    return 0;
}