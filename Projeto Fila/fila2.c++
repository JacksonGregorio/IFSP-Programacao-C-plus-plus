#include <iostream>
#include <queue>
#include <list>
#include <algorithm>

struct Guiche {
    int id;
    std::queue<int> senhasAtendidas;
};

int main() {
    std::queue<int> senhasGeradas;
    std::list<Guiche> guiches;
    int senha = 0;
    int opcao;
    int totalSenhasAtendidas = 0;

    do {
        std::cout << "Senhas aguardando atendimento: " << senhasGeradas.size() << "\n";
        std::cout << "Guichês abertos para atendimento: " << guiches.size() << "\n";
        std::cout << "0. Sair\n1. Gerar senha\n2. Abrir guichê\n3. Realizar atendimento\n4. Listar senhas atendidas\n";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                senhasGeradas.push(++senha);
                std::cout << "Senha " << senha << " gerada.\n";
                break;
            case 2:
                int id;
                std::cout << "Digite o id do guichê a ser aberto: ";
                std::cin >> id;
                guiches.push_back(Guiche{id});
                std::cout << "Guichê " << id << " aberto.\n";
                break;
            case 3:
                if (!senhasGeradas.empty()) {
                    std::cout << "Digite o id do guichê para atendimento: ";
                    std::cin >> id;
                    auto it = std::find_if(guiches.begin(), guiches.end(), [id](const Guiche& g) { return g.id == id; });
                    if (it != guiches.end()) {
                        int senhaAtendimento = senhasGeradas.front();
                        senhasGeradas.pop();
                       it->senhasAtendidas.push(senhaAtendimento);
                        totalSenhasAtendidas++;
                        std::cout << "Atendendo senha " << senhaAtendimento << " no guichê " << id << ".\n";
                    } else {
                        std::cout << "Guichê não encontrado.\n";
                    }
                } else {
                    std::cout << "Nenhuma senha para atender.\n";
                }
                break;
            case 4:
                std::cout << "Digite o id do guichê para listar senhas atendidas: ";
                std::cin >> id;
                auto it = std::find_if(guiches.begin(), guiches.end(), [id](const Guiche& g) { return g.id == id; });
                if (it != guiches.end()) {
                    std::cout << "Senhas atendidas no guichê " << id << ": ";
                    while (!it->senhasAtendidas.empty()) {
                        std::cout << it->senhasAtendidas.front() << " ";
                        it->senhasAtendidas.pop();
                    }
                    std::cout << "\n";
                } else {
                    std::cout << "Guichê não encontrado.\n";
                }
                break;
               }
    } while (opcao != 0 && !senhasGeradas.empty());

    std::cout << "Quantidade de senhas atendidas: " << totalSenhasAtendidas << "\n";

    return 0;
}