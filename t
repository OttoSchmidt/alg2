#include <bits/stdc++.h>
using namespace std;

struct nodo {
    int quant;
    int filhos[16];
};

void zerarFilhos(nodo &node) {
    for (int i = 0; i < 16; i++) {
        node.filhos[i] = -1;
    }
}

int transformarNumero(char a) {
    if ((a - 'a') > 0) {
        return a - 'a';
    }

    return a - '0';
}

void imprimirArvore (vector<nodo> &arvore) {
    for (int i = 0; i < arvore.size(); i++) {
        cout << i << " QUANT = " << arvore[i].quant << "FILHOS:\n";
        for (int j = 0; j < 16; j++) {
            cout << j << " " << arvore[i].filhos[j];
        }
    }
}

void inserirStringArvore(vector<nodo> &arvore, string &input, int pos, int i) {
    if (i == input.size()) {
        return;
    }
    int idx = transformarNumero(input[i]);

    if (arvore[pos].filhos[idx] != -1) {
        arvore[arvore[pos].filhos[idx]].quant++;
    } else {
        arvore[pos].filhos[idx] = arvore.size();
        arvore.push_back({0, {0}});
    }

    inserirStringArvore(arvore, input, arvore[pos].filhos[idx], i+1);
}

int main () {
    int quant;
    vector<nodo> arvore;
    string input;

    cin >> quant;
    cin.ignore();

    arvore.push_back({-1, {0}});

    while (quant > 0) {
        getline(cin, input);
        inserirStringArvore(arvore, input, 0, 0);
        quant--;
    }
    
    imprimirArvore(arvore);

    return 0;
}
