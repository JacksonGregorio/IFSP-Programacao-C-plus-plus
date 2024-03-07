#include <iostream>
#include <vector>

class Bilheteria {
    std::vector<std::vector<bool>> poltronas;
    std::vector<int> precos = {50, 30, 15};
public:
    Bilheteria(int fileiras, int colunas) : poltronas(fileiras, std::vector<bool>(colunas, false)) {}

    bool reservarPoltrona(int fileira, int coluna) {
        if (fileira < 0 || fileira >= poltronas.size() || coluna < 0 || coluna >= poltronas[0].size()) {
            std::cout << "Número de poltrona inválido.\n";
            std::cout << fileira << std::endl;
            std::cout << coluna << std::endl;
            return false;
        }
        if (poltronas[fileira][coluna]) {
            std::cout << "Poltrona já reservada.\n";
            return false;
        }
        poltronas[fileira][coluna] = true;
        std::cout << "Poltrona reservada com sucesso.\n";
        std::cout << fileira << std::endl;
        std::cout << coluna << std::endl;
        return true;
    }

    void mostrarOcupacao() {
        for (const auto& fileira : poltronas) {
            for (bool poltrona : fileira) {
                std::cout << (poltrona ? '#' : '.');
            }
            std::cout << '\n';
        }
    }

    void mostrarFaturamento() {
        int ocupadas = 0;
        int faturamento = 0;
        for (int i = 0; i < poltronas.size(); ++i) {
            for (bool poltrona : poltronas[i]) {
                if (poltrona) {
                    ++ocupadas;
                    faturamento += precos[i / 5];
                }
            }
        }
        std::cout << "Quantidade de poltronas ocupadas: " << ocupadas << '\n';
        std::cout << "Faturamento: R$ " << faturamento << ",00\n";
    }
};

int main() {
    Bilheteria bilheteria(15, 40);
    int opcao, fileira, coluna;
    while (true) {
        std::cout << "0. Finalizar\n1. Reservar poltrona\n2. Mostrar ocupação\n3. Mostrar faturamento\n";
        std::cin >> opcao;
        switch (opcao) {
        case 0:
            return 0;
        case 1:
            std::cout << "Digite a fileira e a coluna: ";
            std::cin >> fileira >> coluna;
            bilheteria.reservarPoltrona(fileira, coluna);
            break;
        case 2:
            bilheteria.mostrarOcupacao();
            break;
        case 3:
            bilheteria.mostrarFaturamento();
            break;
        default:
            std::cout << "Opção inválida.\n";
        }
    }
    return 0;
}