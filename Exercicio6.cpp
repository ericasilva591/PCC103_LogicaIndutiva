#include <gsl/gsl_sf_hyperg.h>

#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>


template <typename T>
void print_vector(std::vector<T>& v) {
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Merge(std::vector<T>& b, std::vector<T>& c, std::vector<T>& a) {
    int i = 0;
    int j = 0;
    int k = 0;
    int p = b.size();
    int q = c.size();
    while (i < p && j < q) {
        if (b[i] <= c[j]) {
            a[k] = b[i];
            i += 1;
        }
        else {
            a[k] = c[j];
            j += 1;
        }
        k += 1;
        if (i == p) {
            int aux = k;
            for (int t = j; t < q; t++) {
                a[aux] = c[t];
                aux += 1;
            }
        }
        else {
            int aux = k;
            for (int t = i; t < p; t++) {
                a[aux] = b[t];
                aux += 1;
            }
        }
    }
}

template <typename T>
void MergeSort(std::vector<T>& a) {
    if (a.size() > 1) {
        std::vector<T> b;
        std::vector<T> c;
        int n = a.size() / 2;
        for (int i = 0; i < n; i++) {
            b.push_back(a[i]);
        }
        for (int j = n; j < a.size(); j++) {
            c.push_back(a[j]);
        }
        MergeSort(b);
        MergeSort(c);
        Merge(b, c, a);
    }
}

int binarySearch(std::vector<double> v, double k) {
    int n = v.size();
    int l = 0;
    int r = n - 1;
    bool flag = false;
    while (l <= r) {
        int m = (l + r) / 2;

        if (k == v[m]) {
            flag = true;
            return m;
            break;
        }
        else if (k < v[m]) {
            r = m - 1;
        }
        else l = m + 1;
    }
    if (!flag) {
        return -1;
    }

}


double t_distribution_cdf(double x, int v) {

    return 0.5 + (x * (tgamma((v + 1) / 2)) * (gsl_sf_hyperg_2F1(0.5, (v + 1) / 2, 3 / 2, -(pow(x, 2)) / v)) / (sqrt(v * 3.14) * tgamma(v / 2)));;
}

double mean(const std::vector<double>& data) {
    double soma = 0;
    for (auto i = data.begin(); i != data.end(); i++) {
        soma += *i;
    }
    return soma / data.size();
}

double t_distribution_confidence_interval(const std::vector<double>& data, int alpha) {
    double media = mean(data);
    double interval;
    int n = data.size();
    std::vector<double> cdf_vector(n, 0);

    for (int i = 0; i < n; i++) {
        cdf_vector[i] = round(100 * t_distribution_cdf(data[i], n - 1)); // função round arredonda os números
    }

    int index = binarySearch(cdf_vector, alpha);

    if (index == -1) {
        return -1;
    }
    else {
        return data[index];
    }

}


int main()
{
    double interval, media;
    int p;

    std::vector<double> data = { 2.4, 4.9, 3.9, 8.7, 5.6, 4.3, 5.4, 3.7, 3.1, 6.5 };

    std::cout << "Digite a probabilidade em porcentagem: " << std::endl;
    std::cin >> p;

    media = mean(data);

    MergeSort(data); // o algotimo de busca binário precisa que o vetor de dados esteja ordenado

    print_vector(data);

    interval = t_distribution_confidence_interval(data, p);

    if (interval == -1) {
        std::cout << "Nao foi possivel retornar um intervalo para essa probabilidade" << std::endl;
    }
    else {
        std::cout << "O intervalo de confianca em torno da media= " << media << " para uma probabilidade de " << p << "% eh de:" << std::endl;
        std::cout << "[" << media - interval << "," << media + interval << "]" << std::endl;
    }

}
