#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define fmt "%d"
using namespace std;
typedef int Item;
typedef struct no {
	Item item;
	struct no *prox;	
}*Lista;


Lista inclue(Item x, Lista p){
	Lista n = (Lista)malloc(sizeof(Lista));
	n->item = x;
	n->prox = p;
	return n;
}

void exibe(Lista L){
	while (L!=NULL){
		cout<<L->item<<endl;
		L=L->prox;
	}
	cout<<"---------------------"<<endl;
	
}


//versao passando o parametro Lista A diretamente 
void anexa1(Lista A, Lista B){
	if (B==NULL) return;
	while (A->prox!=NULL) 	    
	    A=A->prox;
	A->prox=B;
}

// a versao do livro est� assim: passando o parametro Lista INdiremente (endere�o para endere�o) 
void anexa0(Lista *A, Lista B){
	if (B==NULL) return;
	while (*A!=NULL) 
	    A = &(*A)->prox;	    
	*A=B;
}


// a versao do livro est� assim: passando o parametro Lista INdiremente (endere�o para endere�o) 
void destroi(Lista *L){	
    exibe(*L);
	while (*L !=NULL){
		Lista n = *L;
		*L = n->prox;
		free(n);
		exibe(*L);		
	}    
}

//versao passando o parametro Lista L diretamente 
void destroi1(Lista L){
	exibe(L);
	while (L!=NULL){
		Lista n = L;
		L = n->prox;
		free(n);
		exibe(L);
	}    
}

/*
main(){	
	Lista H = inclue(4,inclue(2,NULL));
	exibe(H);
	Lista I = inclue(3,inclue(1,inclue(5,NULL)));
	exibe(I);
	anexa0(&H,I);  // observe que aqui ele passa o endereco do endereco (&H)
	exibe(H);
}
*/
/*main(){	

	Lista L = inclue(40,inclue(20,NULL));
	exibe(L);
	Lista M = inclue(30,inclue(10,inclue(50,NULL)));
	exibe(M);
	anexa1(L,M);  //observe que aqui ele passa o endere�o L diretamente
	exibe(L);
	destroi(&L);
    destroi1(L);	
}*/



//1) Fun��o recursiva para determinar o tamanho da lista
int tam(Lista L){
	if(L == NULL) return 0;
	return 1 + tam(L->prox);
}

//2) Fun��o para verifica��o de pertin�ncia em lista
int pert(Item x, Lista L){
	if(L == NULL) return 0;
	if(x == L->item) return 1;
	return pert(x,L->prox);
}

//3) Fun��o para clonagem de lista
Lista clone(Lista L){
	if(L == NULL) return NULL;
	return inclue(L->item,clone(L->prox));
}

//4) Fun��o para exibi��o de lista em ordem inversa
void exibe_inv(Lista L){
	if(L ==NULL) return;
	exibe_inv(L->prox);
	cout << L->item << endl;
}

/*
5.1) Os m�todos recebem parametros diferentes, visto que o m�todo anexa1 recebe o endere�o da lista A diretamente, 
j� o m�todo anexa0 recebe um endere�o para o endere�o da lista A.

5.2) Se for passado o endere�o da lista A diretamente como parametro para o m�todo anexa0 ocorrer� um erro, mas 
se for passado o parametro da maneira correta (endere�o para endere�o da lista A) os dois m�todos realizar�o a
mesma opera��o com sucesso.
 
6.1) Mais uma vez, os m�todos recebem parametros diferentes, destroi recebe um endere�o para endere�o e destroi1 
recebe o endere�o da lista diretamente.

6.2) Ambos m�todos realizam a opera��o de destruir a lista, mas mais uma vez, a lista a ser destruida deve ser passada
de maneira correta como parametro de cada fun��o, no m�todo destroi deve ser passado um endere�o para o endere�o da lista
a ser destruida e o m�todo destroi1 deve receber o endere�o da lista diretamente.
*/

main(){
	
	Lista L = inclue(3,inclue(5,inclue(7,NULL)));
	cout << tam(L) << endl;
	if (pert(7, L) == 1){
		cout << "Pertence" << endl;
	}else{
		cout << "Nao Pertence" << endl;
	}
	exibe(clone(L));
	exibe_inv(L);
}

