// Exercicio4.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

double normal_distribution_cdf1(double x, double mu, double std_dev) {
    return (0.5) * (1 + erf((x - mu) / (std_dev * sqrt(2))));
}

double normal_distribution_cdf2(double x) {
    return (0.5) * (1 + erf((x) / sqrt(2)));
}

double normal_distribution_cdf3(double x1, double x2, double mu, double std_dev) {
    double cdf_x1 = normal_distribution_cdf1(x1, mu, std_dev);
    double cdf_x2 = normal_distribution_cdf1(x2, mu, std_dev);

    return std::abs(cdf_x1 - cdf_x2);
}

double normal_distribution_cdf4(double x1, double x2) {
    double cdf_x1 = normal_distribution_cdf2(x1);
    double cdf_x2 = normal_distribution_cdf2(x2);

    return std::abs(cdf_x1 - cdf_x2);
}

int main()
{
    double mu;
    double std_dev;
    int option1;
    int option2;

    std::cout << "Selecione a opcao desejada para determinar: " << std::endl;
    std::cout << "  " << "1 - a probabilidade de um ponto estar entre -inf e um certo ponto p." << std::endl;
    std::cout << "  " << "2 - a probabilidade de um ponto estar entre dois pontos x1 e x2 em uma distribuição normal" << std::endl;

    std::cin >> option1;

    if (option1 != 1 && option1 != 2) {
        std::cout << "Opcao nao disponivel " << std::endl;
    }
    else if (option1 == 1) {
        std::cout << "Selecione uma opcao para determinar a probabilidade de um ponto estar entre -inf e um certo ponto p: " << std::endl;
        std::cout << "  " << "1 - para inserir o ponto, media e desvio padrao." << std::endl;
        std::cout << "  " << "2 - para inserir somente o ponto(media = 0 e desvio padrao = 1)" << std::endl;

        std::cin >> option2;

        double x;

        if (option2 != 1 && option2 != 2) {
            std::cout << "Opcao nao disponivel " << std::endl;
        }
        else if (option2 == 1) {
            std::cout << "Insira o ponto. " << std::endl;
            std::cin >> x;

            std::cout << "Insira a media. " << std::endl;
            std::cin >> mu;

            std::cout << "Insira o desvio padrao. " << std::endl;
            std::cin >> std_dev;

            std::cout << "A probabilidade do ponto " << x << " estar entre -inf e um certo ponto p e de: ";
            std::cout << std::setprecision(4) << normal_distribution_cdf1(x, mu, std_dev) * 100 << "%" << std::endl;

        }
        else if (option2 == 2) {
            std::cout << "Insira o ponto. " << std::endl;
            std::cin >> x;

            std::cout << "A probabilidade do ponto " << x << " estar entre -inf e um certo ponto p e de: ";
            std::cout << std::setprecision(4) << normal_distribution_cdf2(x) * 100 << "%" << std::endl;
        }
    }
    else if (option1 == 2) {
        std::cout << "Selecione uma opcao para determinar a probabilidade de um ponto estar entre dois pontos x1 e x2 em uma distribuicao normal: " << std::endl;
        std::cout << "  " << "1 - para inserir dois pontos, media e desvio padrao." << std::endl;
        std::cout << "  " << "2 - para inserir somente os dois pontos (media = 0 e desvio padrao = 1)" << std::endl;

        std::cin >> option2;

        double x1;
        double x2;

        if (option2 != 1 && option2 != 2) {
            std::cout << "Opcao nao disponivel " << std::endl;
        }
        else if (option2 == 1) {

            std::cout << "Insira o ponto x1. " << std::endl;
            std::cin >> x1;

            std::cout << "Insira o ponto x2. " << std::endl;
            std::cin >> x2;

            std::cout << "Insira a media. " << std::endl;
            std::cin >> mu;

            std::cout << "Insira o desvio padrao. " << std::endl;
            std::cin >> std_dev;

            std::cout << "A probabilidade do ponto estar entre " << x1 << " e " << x2 << " em uma distribuicao normal e de: ";
            std::cout << std::setprecision(4) << normal_distribution_cdf3(x1, x2, mu, std_dev) * 100 << "%" << std::endl;

        }
        else if (option2 == 2) {
            std::cout << "Insira o ponto x1. " << std::endl;
            std::cin >> x1;

            std::cout << "Insira o ponto x2. " << std::endl;
            std::cin >> x2;

            std::cout << "A probabilidade do ponto estar entre " << x1 << " e " << x2 << " em uma distribuicao normal e de: ";
            std::cout << std::setprecision(4) << normal_distribution_cdf4(x1, x2) * 100 << "%" << std::endl;
        }
    }

    
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
