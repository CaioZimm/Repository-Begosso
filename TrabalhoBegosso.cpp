#include<iostream>
#include<conio.h>
#include<string>
#include<locale.h>

using namespace std;

// Declarando as Structs
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

//  ---- CIDADE ----
void cadastrarCidade(Cidade cidades[], int& totalCidades){
	Cidade novaCidade;

	cout << "\n ----- Cadastro de Cidade ------\n\n";
	cout << "Código da cidade: ";
	cin >> novaCidade.codigo;
	cin.ignore();

	cout << "Nome da cidade: ";
	getline(cin, novaCidade.nome);

	cout << "UF: ";
	cin >> novaCidade.uf;

	cidades[totalCidades] = novaCidade;
	totalCidades++;

	cout << "\nCidade cadastrada com sucesso!\n";
	system("pause");
	system("cls");
}

//  ---- RAÇA ----
void cadastrarRaca(Raca racas[], int& totalRacas){
	Raca novaRaca;

	cout << "\n ----- Cadastro de Raça ------\n\n";
	cout << "Código da raça: ";
	cin >> novaRaca.codigo;
	cin.ignore();

	cout << "Descrição: ";
	getline(cin, novaRaca.descricao);
	
	racas[totalRacas] = novaRaca;
	totalRacas++;

	cout << "\nRaça cadastrada com sucesso!\n";
	system("pause");
	system("cls");
}

//  ---- ANIMAL ----
void cadastrarAnimal(Animal animais[], int& totalAnimais, Raca racas[], int totalRacas, Tutor tutores[], int totalTutores, Cidade cidades[], int totalCidades){
	Animal novoAnimal;
	bool busca = false;
	
	if (totalTutores == 0 || totalRacas == 0) {
	    cout << "Antes de cadastrar um animal, cadastre pelo menos um tutor e uma raça.\n";
	    system("pause");
	    system("cls");
	    return;
	}

	cout << "\n ----- Cadastro de Animal ------\n\n";
	cout << "Código do Animal: ";
	cin >> novoAnimal.codigo;
	cin.ignore();

	cout << "Nome: ";
	getline(cin, novoAnimal.nome);

	cout << "Códigos das raças: \n";
		for(int i = 0; i < totalRacas; i++){
			cout << "   [" << racas[i].codigo << "] " << racas[i].descricao << endl;
		}
		
		cout << "Selecione uma raça: ";
		cin >> novoAnimal.codRaca;

		for(int i = 0; i < totalRacas; i++){
			if(racas[i].codigo == novoAnimal.codRaca){
			cout << "\nRaça: " << racas[i].descricao << endl;
			busca = true;
			break;
		}
	}

	cout << "Idade: ";
	cin >> novoAnimal.idade;

	cout << "Peso (Kg): ";
	cin >> novoAnimal.peso;

	cout << "Códigos dos tutores: \n";
		for(int i = 0; i < totalTutores; i++){
			cout << "   [" << tutores[i].codigo << "] " << tutores[i].nome << endl;
		}
		
		cout << "Selecione um tutor: ";
		cin >> novoAnimal.codTutor;
	
		for(int i = 0; i < totalTutores; i++){
			if(tutores[i].codigo == novoAnimal.codTutor){
				
				string nomeCidade, siglaEstado;
				for (int j = 0; j < totalCidades; j++) {
					if (cidades[j].codigo == tutores[i].codCidade) {
						nomeCidade = cidades[j].nome;
						siglaEstado = cidades[j].uf;
						break;
					}
				}
				cout << "\nTutor: " << tutores[i].nome << " de " << nomeCidade << ", " << siglaEstado << endl;
				busca = true;
				break;
		}
	}
	
	animais[totalAnimais] = novoAnimal;
	totalAnimais++;

	cout << "\nAnimal cadastrado com sucesso!\n";
	system("pause");
	system("cls");
}

//  ---- TUTOR ----
void cadastrarTutor(Tutor tutores[], int& totalTutores, Cidade cidades[], int totalCidades){
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
		return;
	}

	cout << "Endereço: ";
	getline(cin, novoTutor.endereco);

	cout << "Códigos das cidades\n";
	for(int i = 0; i < totalCidades; i++){
		cout << "   [" << cidades[i].codigo << "] " << cidades[i].nome << endl;
	}
	cout << "Selecione uma cidade: ";

	cin >> novoTutor.codCidade;

	for(int i = 0; i < totalCidades; i++){
		if(cidades[i].codigo == novoTutor.codCidade){
			cout << "\nCidade: " << cidades[i].nome << ", " << cidades[i].uf << endl;
			busca = true;
			break;
		}
	}

	if (!busca) {
		cout << "Cidade não encontrada.\n";
		return;
	}
		
	tutores[totalTutores] = novoTutor;
	totalTutores++;

	cout << "\nTutor cadastrado com sucesso!\n";
	system("pause");
	system("cls");
}

//  ---- VETERINÁRIO ----
void cadastrarVeterinario(Veterinario veterinarios[], int& totalVets, Cidade cidades[], int totalCidades){
	Veterinario novoVet;
	bool busca = false;

	cout << "\n ----- Cadastro de Veterinário ------\n\n";
	cout << "Código do veterinário: ";
	cin >> novoVet.codigo;
	cin.ignore();

	cout << "Nome: ";
	getline(cin, novoVet.nome);

	cout << "Endereço: ";
	getline(cin, novoVet.endereco);

	cout << "Códigos das cidades\n";
	for(int i = 0; i < totalCidades; i++){
		cout << "   [" << cidades[i].codigo << "] " << cidades[i].nome << endl;
	}
	
	cout << "Selecione uma cidade: ";
	cin >> novoVet.codCidade;

	for(int i = 0; i < totalCidades; i++){
		if(cidades[i].codigo == novoVet.codCidade){
			cout << "\nCidade: " << cidades[i].nome << ", " << cidades[i].uf << endl;
			busca = true;
			break;
		}
	}

	if (!busca) {
		cout << "Cidade não encontrada.\n";
		return;
	}
	
	veterinarios[totalVets] = novoVet;
	totalVets++;

	cout << "\nVeterinário cadastrado com sucesso!\n";
	system("pause");
	system("cls");
}

//  ---- CONSULTA ----
void gerarConsulta(Consulta consultas[], int& totalConsultas, Animal animais[], int totalAnimais, 
					Veterinario veterinarios[], int totalVets, Raca racas[], int totalRacas, 
					Tutor tutores[], int totalTutores, Cidade cidades[], int totalCidades){
	Consulta novaConsulta;
	bool busca = false;
	
	if (totalAnimais == 0 || totalVets == 0) {
		cout << "Cadastre ao menos um animal e um veterinário antes de registrar uma consulta.\n";
		system("pause");
		system("cls");
		return;
	}
	
	cout << "\n ----- Realizar Consulta ------\n";
	cout << "Consulta número " << totalConsultas + 1 << ":\n";
	
	cout << "Códigos dos animais \n";
		for(int i = 0; i < totalAnimais; i++){
			cout << "   [" << animais[i].codigo << "] " << animais[i].nome << endl;
		}
		
		cout << "Selecione um animal: ";
		cin >> novaConsulta.codAnimal;
	
		for(int i = 0; i < totalAnimais; i++){
			if(animais[i].codigo == novaConsulta.codAnimal){
				
				string nomeRaca, nomeTutor;
				
				for(int j = 0; j < totalRacas; j++){
					if(racas[j].codigo == animais[i].codRaca){
						nomeRaca = racas[j].descricao;
                    	break;
					}
				}
				
				for (int j = 0; j < totalTutores; j++) {
	                if (tutores[j].codigo == animais[i].codTutor) {
	                    nomeTutor = tutores[j].nome;
	                    break;
	                }
	            }
				
				cout << "Animal: " << animais[i].nome << " | Raça: " << nomeRaca << " | Tutor: " << nomeTutor << endl;
				busca = true;
				break;
			}
		}
	
	cout << "Códigos dos veterinários \n";
		for(int i = 0; i < totalVets; i++){
			cout << "   [" << veterinarios[i].codigo << "] " << veterinarios[i].nome << endl;
		}
		
		cout << "Selecione um veterinário: ";
		cin >> novaConsulta.codVet;
	
		for(int i = 0; i < totalVets; i++){
			if(veterinarios[i].codigo == novaConsulta.codVet){
				
				string nomeCidade;
				
				for(int j = 0; j < totalCidades; j++){
					if(cidades[j].codigo == veterinarios[i].codCidade){
						nomeCidade = cidades[j].nome;
						break;
					}
				}
				
				cout << "Veterinário: " << veterinarios[i].nome << " | Cidade: " << nomeCidade << endl;
				busca = true;
				break;
			}
		}
		
	cout << "Data da consulta: ";
	cin.ignore();
	getline(cin, novaConsulta.data);
	
	cout << "Valor: R$ ";
	cin >> novaConsulta.valor;
	
	novaConsulta.codigo = totalConsultas + 1;
	consultas[totalConsultas] = novaConsulta;
    totalConsultas++;
	
	cout << "\nConsulta registrada com sucesso!\n";
	system("pause");
	system("cls");
}

//  ---- CONSULTA -> POR DATA ----
void consultaPorData(Consulta consultas[], int totalConsultas, Animal animais[], int totalAnimais, Veterinario veterinarios[], int totalVets){
	string dataInicio, dataFinal;
	float totalValor = 0;
	
	if (totalConsultas == 0) {
		cout << "Sem consultas para filtrar.\n";
		system("pause");
		system("cls");
		return;
	}
	
	cout << "\n ----- Consultas por datas ------\n";
	cout << "Data inicial: ";
	cin >> dataInicio;
	cout << "Data final: ";
	cin >> dataFinal;
	
	cout << "\nConsultas realizadas entre " << dataInicio << " e " << dataFinal << ":\n";
	cout << "Data\t\t" << "Animal\t\t" << "Veterinário\t" << "Valor\t\n";
	for(int i = 0; i < totalConsultas; i++){
		if(consultas[i].data >= dataInicio && consultas[i].data <= dataFinal){
	
			string nomeAnimal, nomeVeterinario;
		
			for(int a = 0; a < totalAnimais; a++) {
				if (animais[a].codigo == consultas[i].codAnimal) {
					nomeAnimal = animais[a].nome;
					break;
				}
			}
			
			for(int b = 0; b < totalVets; b++){
				if (veterinarios[b].codigo == consultas[i].codVet) {
					nomeVeterinario = veterinarios[b].nome;
					break;
				}
			}
			
			cout << consultas[i].data << "\t" 
				 << nomeAnimal << "\t\t" 
				 << nomeVeterinario << "\t" 
				 << "R$ " << consultas[i].valor << endl;

			totalValor += consultas[i].valor;
		}
		
	}
	
	cout << "\nValor total das consultas no período: R$ " << totalValor << "\n";
	system("pause");
	system("cls");
}

//  ---- CONSULTA -> POR VETERINÁRIO ----
void consultaPorVet(){
	
}

int main(){
	setlocale(LC_ALL,"");
	
	Cidade cidades[100];
	int totalCidades = 0;

	Raca racas[100];
	int totalRacas = 0;

	Tutor tutores[100];
	int totalTutores = 0;
	
	Animal animais[100];
	int totalAnimais = 0;
	
	Veterinario veterinarios[100];
	int totalVets = 0;
	
	Consulta consultas[100];
	int totalConsultas = 0;

	//	Seeders
//	cidades[0] = {1, "Assis", "SP"};
//	cidades[1] = {2, "Londrina", "PR"};
//	totalCidades = 2;
//	
//	racas[0] = {1, "Poodle"};
//	racas[1] = {2, "Labrador"};
//	totalRacas = 2;
//	
//	tutores[0] = {1, "Caio Venancio", "12345678901", "Rua A, 123", 1};
//	tutores[1] = {2, "Matheus", "98765432100", "Av. B, 456", 2};
//	totalTutores = 2;
//	
//	animais[0] = {1, "Thor", 1, 3, 12.5, 1};
//	animais[1] = {2, "Pipoca", 2, 2, 10.0, 2};
//	totalAnimais = 2;
//	
//	veterinarios[0] = {1, "Dr. Carlos", "Rua C, 99", 1};
//	veterinarios[1] = {2, "Dra. Ana", "Av. D, 88", 2};
//	totalVets = 2;

	int op;

	do{
		cout << " Menu Principal - Clínica Veterinária \n";
		cout << " [1] Cadastrar cidade\n";
		cout << " [2] Cadastrar tutor \n";
		cout << " [3] Cadastrar raça \n";
		cout << " [4] Cadastrar animal \n";
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
			cadastrarTutor(tutores, totalTutores, cidades, totalCidades);
			break;
		case 3:
			cadastrarRaca(racas, totalRacas);
			break;
		case 4:
			cadastrarAnimal(animais, totalAnimais, racas, totalRacas, tutores, totalTutores, cidades, totalCidades);
			break;
		case 5:
			cadastrarVeterinario(veterinarios, totalVets, cidades, totalCidades);
			break;
		case 6:
			gerarConsulta(consultas, totalConsultas, animais, totalAnimais, 
						  veterinarios, totalVets, racas, totalRacas, 
						  tutores, totalTutores, cidades, totalCidades);
			break;
		case 7:
			consultaPorData(consultas, totalConsultas, animais, totalAnimais, veterinarios, totalVets);
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