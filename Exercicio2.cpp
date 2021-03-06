#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
void print_vector(std::vector<T>& v) {
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void interval(const std::vector<T>& data, std::vector<T>& min_max) {
    int n ;
    bool par ;
    if (data.size() % 2 == 0) {
        n = data.size() - 1;
        par = true;
    }
    else { // deixa o ultimo elemento de fora caso o vetor de dados tenha um número impar de elementos
        n = data.size() - 2; 
        par = false;
    }

    for (int i = 0; i < n; i += 2) {// compara os elementos dois a dois
        if (data[i] > data[i + 1]) {
            if (data[i] > min_max[1]) {
                min_max[1] = data[i];
            }
            if (data[i + 1] < min_max[0]) {
                min_max[0] = data[i + 1];
            }
        }
        else if (data[i] < data[i + 1]) {
            if (data[i + 1] > min_max[1]) {
                min_max[1] = data[i + 1];
            }
            if (data[i] < min_max[0]) {
                min_max[0] = min_max[1];
            }
        }
    }
    if (!par) {
        int val = data[data.size() - 1];
        if (val > min_max[1]) {
            min_max[1] = val;
        }
        if (val < min_max[0]) {
            min_max[0] = val;
        }

    }

}

double mean(const std::vector<double>& data) {
    double soma = 0;
    for (auto i = data.begin(); i != data.end(); i++) {
        soma += *i;
    }
    return soma / data.size();
}// O(n)

double variance(const std::vector<double>& data) {
    double media = mean(data);
    double soma = 0;
    for (int i = 0; i < data.size(); i++) {
        soma = soma + (data[i] - media)*(data[i] - media);
    }
    
    return soma / data.size();

}

double std_dev(const std::vector<double>& data) {
    return std::sqrt(variance(data));
}

int main()
{
    std::vector<double> data = { 1,4,3,6,7,2,4,5,8,11,3,17,3 }; 
    std::vector<double> minmax({ data[0],data[0] });
        
    print_vector(data);

    interval(data, minmax);

    std::cout << "Intervalo: [" << minmax[0] << "," << minmax[1] << "]" << std::endl;

    std::cout << "Varianacia: " << variance(data) << std::endl;

    std::cout << "Desvio padrao: " << std_dev(data) << std::endl;

    
}
