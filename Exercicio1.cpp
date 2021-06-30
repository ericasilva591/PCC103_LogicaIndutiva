// Exercicio1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void print_vector(std::vector<T>& v) {
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

double mean(const std::vector<double>& data) {
    double soma = 0;
    for (auto i = data.begin(); i != data.end(); i++) {
        soma += *i;
    }
    return soma / data.size();
}// O(n)

double mode(const std::vector<double>& data) {
    int n = data.size();
    int cont = 0;
    int cont_aux = 0;
    double	moda = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[i] == data[j]) {
                cont++;
                
                if (cont > cont_aux) {
                    
                    cont_aux = cont;
                    moda = data[i];
                }
            }
        }
        cont = 0;
    }

   
    return moda;

}

double percentile(const std::vector<double>& data, int p) {
    int data_size = data.size();
    int i = std::floor(p * data_size/100);
    return data[i];
}

double median(const std::vector<double>& data) {
    return percentile(data, 50);
}


template <typename T>
int lomutoPartition(std::vector<T>& v, int l, int r) { //particiona o vetor data
    int p = v[l];
    int s = l;
    for (int i = l + 1; i <= r; i++) {
        if (v[i] < p) {
            s = s + 1;
            std::swap(v[s], v[i]);
        }
    }
    std::swap(v[l], v[s]);
    return s;
}

template <typename T>
void QuickSort(std::vector<T>& data, int l, int r) { //Ordena o vetor de dados em O(log n)
    if (l < r) {
        int s = lomutoPartition(data, l, r);
        QuickSort(data, l, s - 1);
        QuickSort(data, s + 1, r);
    }
}

template <typename T>
void QuickSort(std::vector<T>& data) {
    return QuickSort(data, 0, data.size() - 1);
}

int main()
{
    std::vector<double> data = { 4,2,6,7,8,2,3,5,2,4,6,3,8,9,8,6,6 }; // média
    int p = 25;

    QuickSort(data);
    print_vector(data);
    
    std::cout << "Media: " << mean(data) << std::endl;

    std::cout << "Moda: " << mode(data) << std::endl;

    std::cout << "Percentil de " << p <<"%: " << percentile(data, p) << std::endl;

    std::cout << "Mediana: " << median(data) << std::endl;

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
