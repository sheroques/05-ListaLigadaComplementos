#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
      // aloca memoria dinamicamente para o novo elemento
    NO* novo = new NO;
    if (novo == NULL)
    {
        return;
    }

    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;

    // verifica se o elemento ja existe na lista
    NO* aux = primeiro;
    NO* anterior = NULL;
    while (aux != NULL) {
        if (aux->valor == novo->valor) {
            cout << "Elemento ja existe na lista" << endl;
            delete novo;
            return;
        }
        if (aux->valor > novo->valor) {
            break;
        }
        anterior = aux;
        aux = aux->prox;
    }

    if (anterior == NULL) {
        novo->prox = primeiro;
        primeiro = novo;
    } else {
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }

}

void excluirElemento()
{ if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }

    int numero;
    cout << "Digite o elemento a ser excluido: ";
    cin >> numero;

    NO* anterior = NULL;
    NO* atual = primeiro;

    while (atual != NULL && atual->valor != numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        cout << "Elemento nao encontrado \n";
        return;
    }

    if (anterior == NULL) {
        primeiro = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    free(atual);
    cout << "Elemento excluido com sucesso \n";
}

NO* posicaoElemento(int numero)
{
    NO* anterior = NULL;
    NO* atual = primeiro;

    while (atual != NULL && atual->valor < numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->valor == numero) {
        return atual;
    }
    else {
        return NULL;
    }

}

void buscarElemento()
{ 
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }

    int numero;
    cout << "Digite o elemento a ser buscado: ";
    cin >> numero;

    NO* encontrado = posicaoElemento(numero);

    if (encontrado == NULL) {
        cout << "Elemento nao encontrado \n";
    }
    else {
        cout << "Elemento encontrado: " << encontrado->valor << endl;
    }

}



