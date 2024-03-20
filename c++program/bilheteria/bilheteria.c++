#include <iostream>
#include <vector>

class Teatro {
    std::vector<std::vector<bool> > poltronas;
    std::vector<int> precos;
    public:
    Teatro(int fileiras, int colunas) : poltronas(fileiras, std::vector<bool>(colunas, false)) {
        precos.push_back(50);
        precos.push_back(30);
        precos.push_back(15);
    }

    bool reservarPoltrona(int fileira, int coluna) {
        if (fileira < 0 || fileira >= poltronas.size() || coluna < 0 || coluna >= poltronas[0].size()) {
            std::cout << "N�mero de poltrona inv�lido.\n";
            return false;
        }
        if (poltronas[fileira][coluna]) {
            std::cout << "Poltrona j� reservada.\n";
            return false;
        }
        poltronas[fileira][coluna] = true;
        std::cout << "Poltrona reservada com sucesso.\n";
        return true;
    };
    
    void mostrarOcupacao() {
    for (std::vector<std::vector<bool> >::const_iterator it = poltronas.begin(); it != poltronas.end(); ++it) {
        const std::vector<bool>& fileira = *it;
        for (std::vector<bool>::const_iterator it2 = fileira.begin(); it2 != fileira.end(); ++it2) {
            bool poltrona = *it2;
            std::cout << (poltrona ? '#' : '.');
        }
        std::cout << '\n';
    };
	};
    
   void mostrarReceita() {
    int ocupadas = 0;
    int receita = 0;
    for (int i = 0; i < poltronas.size(); ++i) {
        for (std::vector<bool>::const_iterator it = poltronas[i].begin(); it != poltronas[i].end(); ++it) {
            bool poltrona = *it;
            if (poltrona) {
                ++ocupadas;
                receita += precos[i / 5];
            }
        }
    }
    std::cout << "Numero de poltronas ocupadas: " << ocupadas << '\n';
    std::cout << "Receita: R$ " << receita << ",00\n";
    };

    int main() {
    Teatro teatro(15, 40);
    int opcao, fileira, coluna;
    while (true) {
        std::cout << "0. Finalizar\n1. Reservar poltrona\n2. Mostrar ocupacao\n3. Mostrar receita\n";
        std::cin >> opcao;
        switch (opcao) {
        case 0:
            return 0;
        case 1:
            std::cout << "Digite fileira e coluna: ";
            std::cin >> fileira >> coluna;
            teatro.reservarPoltrona(fileira, coluna);
            break;
        case 2:
            teatro.mostrarOcupacao();
            break;
        case 3:
            teatro.mostrarReceita();
            break;
        default:
            std::cout << "Opcao invalida.\n";
        }
    }
    return 0;
    }
};