#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct no {
	int cod;
	char nome[20];
} No;
No vetor[10];
int pos = 0;

// 2.	Preencha a fun��o que inclui elementos na �ltima posi��o OCUPADA do �vetor�.
void incluir (No novo){
	vetor[pos] = novo;
	pos++;
}

// 3.	Preencha a fun��o que consulta de um elemento especifico em �vetor�. 
// A fun��o deve retornar a posi��o do elemento se ele for encontrado. Se o elemento n�o for encontrado a fun��o deve retornar -1.
int procura(int mat) {
	int cont = 0;
	int posi = 0;
	while (cont < 10){
		if (vetor[cont].cod == mat){
			return posi;
		}
		posi++;
		cont++;
	}
	return -1;
}

// 4.	Preencha a fun��o que mostra todos os elementos do vetor. 
// Considere a vari�vel �pos� no c�digo como a �ltima posi��o ocupada e n�o considere posi��es vazias.
void mostra(){
	int cont = 0;
	while(cont < pos){
		cout << "Cod: " << vetor[cont].cod << endl;
		cout << "Nome: " << vetor[cont].nome << endl;
		cont++;
	}
}

// 5.	Preencha a fun��o que remove um elemento da lista, a posi��o do elemento a ser removido � passado como par�metro na fun��o 
// (colocar o �ltimo elemento da lista na posi��o do elemento removido).
// Se o elemento for encontrado e removido retorne 1. Se o elemento N�O for encontrado retorne 0.
int remove (int posicao){
	if (posicao >= pos){
		return 0;
	}else{
		vetor[posicao] = vetor[pos - 1];
		pos--;
		return 1;
	}
}

main() {

	No primeiro = {1, "ana maria"};
	No segundo = {2, "carla gomes"};
	No terceiro = {3, "lucas gabriel"};
	No quarto = {4, "pedro luis"};
	incluir(primeiro);  //Incluindo item no vetor.
	incluir(segundo);   //Incluindo item no vetor.
	incluir(terceiro);  //Incluindo item no vetor.
	incluir(quarto);   //Incluindo item no vetor.
	cout << "Posicao cod 3: " << procura(3) << endl; // Exibindo a posi��o do item com cod = 3.
	mostra(); // Mostrando elementos do vetor.
	remove(1); // Removendo a posi��o 1 do vetor.
	mostra(); // Mostrando elementos do vetor aops remover o item do indice 1.
}
