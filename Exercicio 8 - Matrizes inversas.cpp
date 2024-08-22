#include <iostream>

using namespace std;

int main() {
    int dim_l_a, dim_l_b, dim_c_a, dim_c_b;

    cout << "Informe o número de linhas e colunas da matriz A (linhas colunas): ";
    cin >> dim_l_a >> dim_c_a;
    cout << "Informe o número de linhas e colunas da matriz B (linhas colunas): ";
    cin >> dim_l_b >> dim_c_b;

    if (dim_c_a != dim_l_b) {
        cout << "As dimensões das matrizes não são compatíveis para multiplicação." << endl;
        return 1;
    }

    int matrizA[dim_l_a][dim_c_a];
    int matrizB[dim_l_b][dim_c_b];
    int matrizRes[dim_l_a][dim_c_b];

    for (int i = 0; i < dim_l_a; i++) {
        for (int j = 0; j < dim_c_a; j++) {
            cout << "Informe o item da posição [" << i + 1 << "][" << j + 1 << "] da matriz A: ";
            cin >> matrizA[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < dim_l_b; i++) {
        for (int j = 0; j < dim_c_b; j++) {
            cout << "Informe o item da posição [" << i + 1 << "][" << j + 1 << "] da matriz B: ";
            cin >> matrizB[i][j];
        }
    }

    for (int i = 0; i < dim_l_a; i++) {
        for (int j = 0; j < dim_c_b; j++) {
            matrizRes[i][j] = 0; 
            for (int k = 0; k < dim_c_a; k++) {
                matrizRes[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

   
    bool ehIdentidade = true;  
    for (int i = 0; i < dim_l_a; i++) {
        for (int j = 0; j < dim_c_b; j++) {
            if (matrizRes[i][j] != (i == j ? 1 : 0)) {
                ehIdentidade = false;  
                break;
            }
        }
        if (!ehIdentidade) break;  
    }

    if (ehIdentidade) {
        cout << "As matrizes são inversas." << endl;
    } else {
        cout << "As matrizes não são inversas." << endl;
    }

    return 0;
}
