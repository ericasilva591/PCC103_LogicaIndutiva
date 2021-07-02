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
