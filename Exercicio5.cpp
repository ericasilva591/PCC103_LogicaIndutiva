#include <gsl/gsl_sf_hyperg.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <math.h>

# define MY_PI 3.14159265358979323846


double t_distribution_pdf(double x, int v) {

    return ((tgamma((v + 1) * 0.5)) / (sqrt(v * MY_PI) * tgamma(v * 0.5))) * pow((1 + (pow(x, 2) / v)), (-(v + 1) * 0.5));
}

double t_distribution_cdf(double x, int v) {
    return 0.5 + (x * (tgamma((v + 1) / 2)) * (gsl_sf_hyperg_2F1(0.5, (v + 1) * 0.5, 1.5, -(pow(x, 2)) / v)) / (sqrt(v * MY_PI) * tgamma(v / 2)));
}

double t_distribution_cdf2(double x1, double x2, int v) {
    double cdf_x1 = t_distribution_cdf(x1, v);
    double cdf_x2 = t_distribution_cdf(x2, v);

    return std::abs(cdf_x1 - cdf_x2);
}

int main()
{
    double x, v, x1, x2;
    int v_choice;

    std::cout << "Insira o ponto. " << std::endl;
    std::cin >> x;

    std::cout << "Insira os graus de liberdade. " << std::endl;
    std::cin >> v;

    std::cout << "A probabilidade de um ponto ser p em uma distribuicao-t com " << v << " graus de liberdade eh: ";
    std::cout << std::setprecision(4) << t_distribution_pdf(x, v) * 100 << "%" << std::endl;

    std::cout << "A probabilidade de um valor estar entre - inf e um certo ponto p em uma distribuicao-t com " << v << " graus de liberdade eh: ";
    std::cout << std::setprecision(4) << t_distribution_cdf(x, v) * 100 << "%" << std::endl;

    std::cout << "Insira dois pontos. " << std::endl;
    std::cout << "X1 = " << std::endl;
    std::cin >> x1;
    std::cout << "X2 = " << std::endl;
    std::cin >> x2;

    std::cout << "Insira os graus de liberdade. " << std::endl;
    std::cin >> v;

    std::cout << "A probabilidade de um ponto estar entre dois pontos " << x1 << " e " << x2 << " em uma distribuicao - t com " << v << " graus de liberdade eh: ";
    std::cout << std::setprecision(4) << t_distribution_cdf2(x1, x2, v) * 100 << "%" << std::endl;
}