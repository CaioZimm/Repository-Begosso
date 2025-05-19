#include<iostream>
#include<conio.h>
#include<string>
#include <locale.h>

using namespace std;

struct Cidade{
	int codigo;
	string nome;
	string uf;
};

struct Raca{
	int codigo;
	string descricao;
};

struct Animal{
	int codigo;
	string nome;
	int codRaca;
	int idade;
	float peso;
	int codTutor;
};

struct Tutor{
	int codigo;
	string nome;
	string cpf;
	string endereco;
	int codCidade;
};

struct Veterinario{
	int codigo;
	string nome;
	string endereco;
	int codCidade;
};

struct Consulta{
	int codigo;
	int codAnimal;
	int codVet;
	string data;
	float valor;
};

void cadastrarCidade(Cidade cidades[], int& totalCidades){
	Cidade novaCidade;
	
	cout << "\n ----- Cadastro de Cidade ------\n\n";
	cout << "Código da cidade: ";
	cin >> novaCidade.codigo;
	
	cout << "Nome da cidade: ";
	cin >> novaCidade.nome;
	
	cout << "UF: ";
	cin >> novaCidade.uf;
	
	cidades[totalCidades] = novaCidade;
	totalCidades++;
	
	cout << "Cidade cadastrada com sucesso!\n";
}

void cadastrarRaca(){
	Raca novaRaca;
	
	cout << "\n ----- Cadastro de Raça ------\n\n";
	cout << "Código da raça: ";
	cin >> novaRaca.codigo;
	
	cout << "Descrição: ";
	cin >> novaRaca.descricao;
	
	cout << "Raça cadastrada com sucesso!\n";
	system("pause");
	system("cls");
}

void cadastrarTutor(Cidade cidades[], int totalCidades){
	Tutor novoTutor;
	bool busca = false;
	
	cout << "\n ----- Cadastro de Tutor ------\n\n";
	cout << "Código do tutor: ";
	cin >> novoTutor.codigo;
	cin.ignore();
	
	cout << "Nome: ";
	getline(cin, novoTutor.nome);
	
	cout << "CPF: ";
	getline(cin, novoTutor.cpf);
	if(novoTutor.cpf.length() != 11){
		cout << "CPF inválido. Digite novamente.\n"; 
	}
	
	cout << "Endereço: ";
	getline(cin, novoTutor.endereco);
	
	
	cout << "Código da cidade: ";
	cin >> novoTutor.codCidade;
	
	for(int i = 0; i < totalCidades; i++){
		if(cidades[i].codigo == novoTutor.codCidade){
			cout << "Cidade: " << cidades[i].nome << ", Estado: " << cidades[i].uf << endl;
			busca = true;
            break;
		}
	}
	
	if (!busca) {
        cout << "Cidade não encontrada.\n";
        return;
    }
	
	cout << "Tutor cadastrado com sucesso!\n";
}

int main(){
	setlocale(LC_ALL,"");
	
	Cidade cidades[100];
	int totalCidades = 0;
	
	int op;
	
	do{
		cout << " Menu Principal - Clínica Veterinária \n";
		cout << " [1] Cadastrar cidade\n";
		cout << " [2] Cadastrar raça \n";
		cout << " [3] Cadastrar animal \n";
		cout << " [4] Cadastrar tutor \n";
		cout << " [5] Cadastrar veterinário \n";
		cout << " [6] Realizar consulta \n";
		cout << " [7] Buscar consulta por data \n";
		cout << " [8] Buscar consulta por data de veterinário \n";
		cout << " [0] Sair \n\n";
		cout << "Escolha uma opção: ";
		cin >> op;
		system("cls");
		
		switch(op){
			case 1:
				cadastrarCidade(cidades, totalCidades);
				break;
			case 2:
				cadastrarRaca();
				break;
			case 3:
				cout << "3";
				break;
			case 4:
				cadastrarTutor(cidades, totalCidades);
				break;
			case 5:
				cout << "5";
				break;
			case 6:
				cout << "6";
				break;
			case 7:
				cout << "7";
				break;
			case 8:
				cout << "8";
				break;
			case 0:
				cout << "Saindo do programa... \n";
				break;
			default:
				cout << "Opção inválida. \n";
		}
	} while (op != 0);
}
