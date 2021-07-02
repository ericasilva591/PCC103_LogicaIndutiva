// Exercicio3.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

# define MY_PI 3.14159265358979323846

double normal_distribution_pdf1(double x, double mu, double std_dev) {
    return (1 / (std_dev*(std::sqrt(2 * MY_PI)))) * (exp(-((pow((x - mu), 2)) / (2 * pow(std_dev, 2)))));
}
double normal_distribution_pdf2(double x) {
    return 1 / exp(pow(x, 2));
}

int main()
{
    double x;
    double mu;
    double std_dev;
    bool option;

    std::cout << "Selecione uma opcao para determinar a probabilidade de um ponto ocorrer em uma distribuição normal: " << std::endl;
    std::cout << "  " << "0 - para inserir o ponto, media e desvio padrao." << std::endl;
    std::cout << "  " << "1 - para inserir somente o ponto(media = 0 e desvio padrao = 1)" << std::endl;
    
    std::cin >> option;

    if (option != 0 && option != 1){
        std::cout << "Opcao nao disponivel " << std::endl;
    }
    else if (!option) {
        std::cout << "Insira o ponto. " << std::endl;
        std::cin >> x;

        std::cout << "Insira a media. " << std::endl;
        std::cin >> mu;

        std::cout << "Insira o desvio padrao. " << std::endl;
        std::cin >> std_dev;

        std::cout << "A probabilidade do ponto " << x << " ocorrer em uma distribuicao normal eh de: ";
        std::cout << std::setprecision(4) << normal_distribution_pdf1(x, mu, std_dev)*100 << "%" << std::endl;

    }
    else if(option) {
        std::cout << "Insira o ponto. " << std::endl;
        std::cin >> x;

        std::cout << "A probabilidade do ponto " << x << " ocorrer em uma distribuicao normal eh de: ";
        std::cout << std::setprecision(4) << normal_distribution_pdf2(x) * 100 << "%" << std::endl;
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
