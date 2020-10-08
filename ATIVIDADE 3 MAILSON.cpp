#include <iostream>
#include <locale.h>

using namespace std;

class celula
{
private:
	string nome;
	char sexo;
	int idade;
	bool bebe;
	celula * proxima;
public:
	celula()
	{
		proxima = NULL;
	}
	celula(string n)
	{
		nome = n;
	}
	celula(string n, celula *prox)
	{
		nome = n;
		proxima = prox;
	}
	celula(string nome, char sexo, int idade, bool bebe, celula *prox)
	{
		this->nome = nome;
		this->sexo = sexo;
		this->idade = idade;
		this->bebe = bebe;
		proxima = prox;
	}
	string getNome()
	{
		return nome;
	}
	void setNome(string nome)
	{
		this->nome = nome;
	}
	
	char getSexo(){
		return sexo;
	}
	void setSexo(char sexo){
		this->sexo = sexo;
	}
	
	int getIdade(){
		return idade;
	}
	void setIdade(int idade){
		this->idade = idade;
	}
	
	bool getBebe(){
		return bebe;
	}
	void setBebe(bool bebe){
		this->bebe = bebe;
	}

	celula * getProxima()
	{
		return proxima;
	}

	void setProxima(celula * l)
	{
		proxima = l;
	}
	
};


class lista
{
private:
	celula * inicio;

public:
	lista()
	{
		inicio = NULL;
	}
	~lista()
	{
		esvaziar();
	}
	lista(celula *i)
	{
		inicio = i;
	}
	celula * getInicio()
	{
		return inicio;
	}

	void inserirInicio(string nome, char sexo, int idade, bool bebe)
	{
		celula *nova = new celula;
		nova->setNome(nome);
		nova->setSexo(sexo);
		nova->setIdade(idade);
		nova->setBebe(bebe);
		nova->setProxima(inicio);
		inicio = nova;
	}

	void inserirFim(string nome, char sexo, int idade, bool bebe)
	{
		if(inicio == NULL)
		{
			inserirInicio(nome, sexo, idade, bebe);
		}
		else
		{
			celula *aux = inicio;
			while(aux->getProxima() != NULL)
			{
				aux = aux->getProxima();
			}
			celula *nova = new celula(nome, sexo, idade, bebe, NULL);
			aux->setProxima(nova);
		}
	}


	void imprimir()
	{
		if(inicio == NULL)
		{
			cout << "Lista vazia.\n";
		}
		else
		{
			celula *aux = inicio;
			while(aux != NULL)
			{
				cout << aux->getNome() << " - " << aux->getSexo() << " - " << aux->getIdade() << " - " << aux->getBebe() << endl;
				aux = aux->getProxima();
			}
		}
	}

	void esvaziar()
	{
		celula *aux = inicio;
		while(aux != NULL)
		{
			inicio = inicio->getProxima();
			delete aux;
			aux = inicio;
		}
		cout << "\n----Memoria liberada----\n";
	}
};

int main()
{
	setlocale(LC_ALL, "portuguese");
	lista listaChurras;
	cout << "--- LISTA CHURRASCO ---" << endl;
	cout << endl;
	cout << " 0 - BEBE " << endl;
	cout << " 1 - NÃO BEBE " << endl;
	cout << endl;
	listaChurras.inserirInicio("DANIEL", 'M', 20, true);
	listaChurras.inserirFim("IVAIR", 'M', 18, true);
	listaChurras.inserirFim("ANA", 'F', 25, true);
	listaChurras.inserirInicio("MARCELLA", 'F', 20, false);
	listaChurras.imprimir();
	return 0;
}