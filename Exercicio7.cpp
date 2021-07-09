#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <iomanip>

template <typename T>
void print_vector(std::vector<T>& v) {
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
    
}

double mean(const std::vector<double>& data) {
    double soma = 0;
    for (auto i = data.begin(); i != data.end(); i++) {
        soma += *i;
    }
    return soma / data.size();
}

double std_dev(const std::vector<double>& data, double mean) {
    double soma = 0;
    for (int i = 0; i < data.size(); i++) {
        soma = soma + (data[i] - mean) * (data[i] - mean);
    }

    return std::sqrt(soma / data.size() - 1);

}

double estatisica(const std::vector<double>& data1, const std::vector<double>& data2) {
    int n = data1.size() + data2.size() - 2;
    double m1 = mean(data1);
    double m2 = mean(data2);
    double s1 = std_dev(data1, m1);
    double s2 = std_dev(data2, m2);

    return std::abs((m1 - m2) / std::sqrt((s1 * s1 + s2 * s2) / n));
}

int main()
{
    std::vector<double> data1 = { 2.4, 4.9, 3.9, 8.7, 5.6, 4.3, 5.4, 3.7, 3.1, 6.5 };
    std::vector<double> data2 = { 5.4, 6.9, 1.9, 2.7, 6.6, 4.9, 9.4, 2.7, 5.1, 3.7};

    double mean1, mean2, std_dev1, std_dev2;

    mean1 = mean(data1);
    mean2 = mean(data2);

    std_dev1 = std_dev(data1, mean1);
    std_dev2 = std_dev(data2, mean2);

    std::cout << std::setprecision(4);

    std::cout << "Conjunto 1: [";
    print_vector(data1);
    std::cout << "]"<< std::endl;

    std::cout << "Media do conjunto 1 = " << mean1 << std::endl;
    std::cout << "Desvio padrao do conjunto 1 = " << std_dev1 << std::endl;

    std::cout << "Conjunto 2: [";
    print_vector(data2);
    std::cout << "]" << std::endl;

    std::cout << "Media do conjunto 2 = " << mean2 << std::endl;
    std::cout << "Desvio padrao do conjunto 2 = " << std_dev2 << std::endl;

    std::cout << "O valor t eh igual a: " << estatisica(data1, data2) << std::endl;


}

