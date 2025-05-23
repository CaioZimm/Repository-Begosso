#include<iostream>
#include<locale.h>
#include<conio.h>
#include<string>

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

//Função - verificar se já existe o código inserido
template <typename V>
bool verificarExistencia(V vetor[], int total, int codigo){
	for (int i = 0; i < total; i++) {
        if (vetor[i].codigo == codigo){
        	return true;	
		}
    }
    
    return false;
}

//Função - cancelar ação -> valores INT
bool verificarCancelamento(int valor){
	if(valor == 0){
		cout << "Ação cancelada.\n";
		system("pause");
        system("cls");
        return true;
	}
	
	return false;
}

//Função - cancelar ação -> valores STRING
bool verificarCancelamento(const string& valor){
	if(valor == "0"){
		cout << "Ação cancelada.\n";
		system("pause");
		system("cls");
		return true;
	}
	
	return false;
}

//  ---- CIDADE ----
void cadastrarCidade(Cidade cidades[], int& totalCidades){
	Cidade novaCidade;

	cout << "\n ----- Cadastro de Cidade ------\n";
	cout << "(Digite 0 a qualquer momento para cancelar)\n\n";
		
	while(true){
		cout << "Código da cidade: ";
		cin >> novaCidade.codigo;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Entrada inválida! Digite apenas números.\n\n";
			continue;
		}
		
		if(verificarCancelamento(novaCidade.codigo)) return;
		cin.ignore();
		
		if(verificarExistencia(cidades, totalCidades, novaCidade.codigo)) {
			cout << "Código já cadastrado! Tente novamente.\n\n";
			continue;
		}
		
		break;
	}

	cout << "Nome da cidade: ";
	getline(cin, novaCidade.nome);
	if(verificarCancelamento(novaCidade.nome)) return;

	cout << "UF: ";
	cin >> novaCidade.uf;
	if(verificarCancelamento(novaCidade.uf)) return;

	cidades[totalCidades] = novaCidade;
	totalCidades++;

	cout << "\nCidade cadastrada com sucesso!\n";
	system("pause");
	system("cls");
}

//  ---- TUTOR ----
void cadastrarTutor(Tutor tutores[], int& totalTutores, Cidade cidades[], int totalCidades){
	Tutor novoTutor;
	
	if (totalCidades == 0) {
	    cout << "Antes de cadastrar um tutor, cadastre pelo menos uma cidade para esse tutor.\n\n";
	    system("pause");
	    system("cls");
	    return;
	}

	cout << "\n ----- Cadastro de Tutor ------\n";
	cout << "(Digite 0 a qualquer momento para cancelar)\n\n";

	while(true){
		cout << "Código do tutor: ";
		cin >> novoTutor.codigo;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Entrada inválida! Digite apenas números.\n\n";
			continue;
		}
		
		if(verificarCancelamento(novoTutor.codigo)) return;
		cin.ignore();
		
		if(verificarExistencia(tutores, totalTutores, novoTutor.codigo)) {
			cout << "Código já cadastrado! Tente novamente.\n\n";
			continue;
		}
		
		break;
	}

	cout << "Nome: ";
	getline(cin, novoTutor.nome);
	if(verificarCancelamento(novoTutor.nome)) return;

	cout << "CPF: ";
	getline(cin, novoTutor.cpf);
	if(verificarCancelamento(novoTutor.cpf)) return;
	if(novoTutor.cpf.length() != 11){
		cout << "CPF inválido. Digite novamente.\n";
		return;
	}

	cout << "Endereço: ";
	getline(cin, novoTutor.endereco);
	if(verificarCancelamento(novoTutor.endereco)) return;

	cout << "Códigos das cidades\n";
			for(int i = 0; i < totalCidades; i++){
				cout << "   [" << cidades[i].codigo << "] " << cidades[i].nome << endl;
			}

	while(true){
		cout << "Selecione uma cidade: ";
		cin >> novoTutor.codCidade;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Entrada inválida! Digite apenas números.\n";
			continue;
		}
		if(verificarCancelamento(novoTutor.codCidade)) return;
	
		bool encontrado = false;
		for(int i = 0; i < totalCidades; i++){
			if(cidades[i].codigo == novoTutor.codCidade){
				cout << "\nCidade: " << cidades[i].nome << ", " << cidades[i].uf << endl;
				encontrado = true;
				break;
			}
		}
		
		if (encontrado) break;
			cout << "Cidade não encontrada! Tente novamente.\n";
	}
	
	tutores[totalTutores] = novoTutor;
	totalTutores++;

	cout << "\nTutor cadastrado com sucesso!\n";
	system("pause");
	system("cls");
}

//  ---- RAÇA ----
void cadastrarRaca(Raca racas[], int& totalRacas){
	Raca novaRaca;
	
	cout << "\n ----- Cadastro de Raça ------\n";
	cout << "(Digite 0 a qualquer momento para cancelar)\n\n";
	
	while(true){
		cout << "Código da raça: ";
		cin >> novaRaca.codigo;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Entrada inválida! Digite apenas números.\n\n";
			continue;
		}
		
		if(verificarCancelamento(novaRaca.codigo)) return;
		cin.ignore();
		
		if(verificarExistencia(racas, totalRacas, novaRaca.codigo)) {
			cout << "Código já cadastrado! Tente novamente.\n\n";
			continue;
		}
		
		break;
	}

	cout << "Descrição: ";
	getline(cin, novaRaca.descricao);
	if(verificarCancelamento(novaRaca.descricao)) return;
	
	racas[totalRacas] = novaRaca;
	totalRacas++;

	cout << "\nRaça cadastrada com sucesso!\n";
	system("pause");
	system("cls");
}

//  ---- ANIMAL ----
void cadastrarAnimal(Animal animais[], int& totalAnimais, Raca racas[], int totalRacas, Tutor tutores[], int totalTutores, Cidade cidades[], int totalCidades){
	Animal novoAnimal;
	
	if (totalTutores == 0 || totalRacas == 0) {
	    cout << "Antes de cadastrar um animal, cadastre pelo menos um tutor e uma raça.\n\n";
	    system("pause");
	    system("cls");
	    return;
	}

	cout << "\n ----- Cadastro de Animal ------\n";
	cout << "(Digite 0 a qualquer momento para cancelar)\n\n";
	
	while(true){
		cout << "Código do Animal: ";
		cin >> novoAnimal.codigo;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Entrada inválida! Digite apenas números.\n\n";
			continue;
		}
		
		if(verificarCancelamento(novoAnimal.codigo)) return;
		cin.ignore();
		
		if(verificarExistencia(animais, totalAnimais, novoAnimal.codigo)) {
			cout << "Código já cadastrado! Tente novamente.\n\n";
			continue;
		}
		
		break;
	}

	cout << "Nome: ";
	getline(cin, novoAnimal.nome);
	if(verificarCancelamento(novoAnimal.nome)) return;

	cout << "Códigos das raças: \n";
		for(int i = 0; i < totalRacas; i++){
			cout << "   [" << racas[i].codigo << "] " << racas[i].descricao << endl;
		}
	
		while(true){
			cout << "Selecione uma raça: ";
			cin >> novoAnimal.codRaca;
			
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entrada inválida! Digite apenas números.\n";
				continue;
			}
			if(verificarCancelamento(novoAnimal.codRaca)) return;
		
			bool encontrado = false;
			for(int i = 0; i < totalRacas; i++){
				if(racas[i].codigo == novoAnimal.codRaca){
					cout << "\nRaça: " << racas[i].descricao << endl;
					encontrado = true;
					break;
				}
			}
			
			if (encontrado) break;
				cout << "Raça não encontrada! Tente novamente.\n";
		}

	cout << "Idade: ";
	cin >> novoAnimal.idade;
	if(verificarCancelamento(novoAnimal.idade)) return;
	
	while (cin.fail() || novoAnimal.idade < 0) {
	    cin.clear();
	    cin.ignore(1000, '\n');
	    cout << "Entrada inválida! Digite uma idade válida: ";
	    cin >> novoAnimal.idade;
	}

	cout << "Peso (Kg): ";
	cin >> novoAnimal.peso;
	if(verificarCancelamento(novoAnimal.peso)) return;
	while (cin.fail() || novoAnimal.peso < 0) {
	    cin.clear();
	    cin.ignore(1000, '\n');
	    cout << "Entrada inválida! Digite um peso válido: ";
	    cin >> novoAnimal.peso;
	}

	cout << "Códigos dos tutores: \n";
		for(int i = 0; i < totalTutores; i++){
			cout << "   [" << tutores[i].codigo << "] " << tutores[i].nome << endl;
		}
		
		while(true){
			cout << "Selecione um tutor: ";
			cin >> novoAnimal.codTutor;
			
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entrada inválida! Digite apenas números.\n";
				continue;
			}
			if(verificarCancelamento(novoAnimal.codTutor)) return;
		
			bool encontrado = false;			
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
					encontrado = true;
					break;
				}
			}
			
			if (encontrado) break;
				cout << "Tutor não encontrado! Tente novamente.\n";
		}
	
	animais[totalAnimais] = novoAnimal;
	totalAnimais++;

	cout << "\nAnimal cadastrado com sucesso!\n";
	system("pause");
	system("cls");
}

//  ---- VETERINÁRIO ----
void cadastrarVeterinario(Veterinario veterinarios[], int& totalVets, Cidade cidades[], int totalCidades){
	Veterinario novoVet;
	
	if (totalCidades == 0) {
	    cout << "Antes de cadastrar um veterinário, cadastre pelo menos uma cidade para esse veterinário.\n\n";
	    system("pause");
	    system("cls");
	    return;
	}

	cout << "\n ----- Cadastro de Veterinário ------\n";
	cout << "(Digite 0 a qualquer momento para cancelar)\n\n";
	
	while(true){
		cout << "Código do veterinário: ";
		cin >> novoVet.codigo;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Entrada inválida! Digite apenas números.\n\n";
			continue;
		}
		
		if(verificarCancelamento(novoVet.codigo)) return;
		cin.ignore();
		
		if(verificarExistencia(veterinarios, totalVets, novoVet.codigo)) {
			cout << "Código já cadastrado! Tente novamente.\n\n";
			continue;
		}
		
		break;
	}

	cout << "Nome: ";
	getline(cin, novoVet.nome);
	if(verificarCancelamento(novoVet.nome)) return;

	cout << "Endereço: ";
	getline(cin, novoVet.endereco);
	if(verificarCancelamento(novoVet.endereco)) return;

	cout << "Códigos das cidades\n";
		for(int i = 0; i < totalCidades; i++){
			cout << "   [" << cidades[i].codigo << "] " << cidades[i].nome << endl;
		}
		
		while(true){
			cout << "Selecione uma cidade: ";
			cin >> novoVet.codCidade;
			
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entrada inválida! Digite apenas números.\n";
				continue;
			}
			if(verificarCancelamento(novoVet.codCidade)) return;
		
			bool encontrado = false;
			for(int i = 0; i < totalCidades; i++){
				if(cidades[i].codigo == novoVet.codCidade){
					cout << "\nCidade: " << cidades[i].nome << ", " << cidades[i].uf << endl;
					encontrado = true;
					break;
				}
			}
			
			if (encontrado) break;
				cout << "Cidade não encontrada! Tente novamente.\n";
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
	
	if (totalAnimais == 0 || totalVets == 0) {
		cout << "Cadastre ao menos um animal e um veterinário antes de registrar uma consulta.\n\n";
		system("pause");
		system("cls");
		return;
	}
	
	cout << "\n ----- Realizar Consulta ------\n";
	cout << "(Digite 0 a qualquer momento para cancelar)\n\n";
	cout << "Consulta número " << totalConsultas + 1 << ":\n";
	
	cout << "Códigos dos animais \n";
		for(int i = 0; i < totalAnimais; i++){
			cout << "   [" << animais[i].codigo << "] " << animais[i].nome << endl;
		}
		
		while(true){
			cout << "Selecione um animal: ";
			cin >> novaConsulta.codAnimal;
			
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entrada inválida! Digite apenas números.\n";
				continue;
			}
			
			if(verificarCancelamento(novaConsulta.codAnimal)) return;
		
			bool encontrado = false;	
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
				
				cout << "Animal: " << animais[i].nome << " | Raça: " << nomeRaca << " | Tutor: " << nomeTutor << endl << endl;
				encontrado = true;
				break;
				}
			}
			
			if (encontrado) break;
				cout << "Animal não encontrado! Tente novamente.\n";
		}
	
	cout << "Códigos dos veterinários \n";
		for(int i = 0; i < totalVets; i++){
			cout << "   [" << veterinarios[i].codigo << "] " << veterinarios[i].nome << endl;
		}
		
		while(true){
			cout << "Selecione um veterinário: ";
			cin >> novaConsulta.codVet;
			
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entrada inválida! Digite apenas números.\n";
				continue;
			}
			
			if(verificarCancelamento(novaConsulta.codVet)) return;
		
			bool encontrado = false;
			for(int i = 0; i < totalVets; i++){
				if(veterinarios[i].codigo == novaConsulta.codVet){
					
					string nomeCidade;
					
					for(int j = 0; j < totalCidades; j++){
						if(cidades[j].codigo == veterinarios[i].codCidade){
							nomeCidade = cidades[j].nome;
							break;
						}
					}
					
					cout << "Veterinário: " << veterinarios[i].nome << " | Cidade: " << nomeCidade << endl << endl;
					encontrado = true;
					break;
				}
			}
			
			if (encontrado) break;
				cout << "Veterinário não encontrado! Tente novamente.\n";
		}
		
	cout << "Data da consulta: ";
	cin.ignore();
	getline(cin, novaConsulta.data);
	if(verificarCancelamento(novaConsulta.data)) return;
	
	cout << "Valor: R$ ";
	cin >> novaConsulta.valor;
	if(verificarCancelamento(novaConsulta.valor)) return;
	while (cin.fail() || novaConsulta.valor < 0) {
	    cin.clear();
	    cin.ignore(1000, '\n');
	    cout << "Entrada inválida! Digite um peso válido: ";
	    cin >> novaConsulta.valor;
	}
	
	novaConsulta.codigo = totalConsultas;
	consultas[totalConsultas] = novaConsulta;
    totalConsultas++;
	
	cout << "\nConsulta registrada com sucesso!\n";
	system("pause");
	system("cls");
}

//  ---- CONSULTA -> POR DATA ----
void consultaPorData(Consulta consultas[], int totalConsultas, Animal animais[], int totalAnimais, 
					 Veterinario veterinarios[], int totalVets){
	string dataInicio, dataFinal;
	float valorTotal = 0;
	
	if (totalConsultas == 0) {
		cout << "Sem consultas para filtrar.\n\n";
		system("pause");
		system("cls");
		return;
	}
	
	cout << "\n ----- Consultas por datas ------\n";
	cout << "(Digite 0 a qualquer momento para cancelar)\n\n";
	
	cout << "Data inicial: ";
	cin >> dataInicio;
	if(verificarCancelamento(dataInicio)) return;
	
	cout << "Data final: ";
	cin >> dataFinal;
	if(verificarCancelamento(dataFinal)) return;
	
	cout << "\nConsultas realizadas entre " << dataInicio << " e " << dataFinal << ":\n";
	cout << "Código\t" << "Data\t\t" << "Animal\t\t" << "Veterinário\t\t" << "Valor\t\n";
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
			
			cout << consultas[i].codigo << "\t"
				 << consultas[i].data << "\t" 
				 << nomeAnimal << "\t\t" 
				 << nomeVeterinario << "\t\t" 
				 << "R$ " << consultas[i].valor << endl;

			valorTotal += consultas[i].valor;
		}
		
	}
	
	cout << "\nValor total das consultas no período: R$ " << valorTotal << "\n";
	system("pause");
	system("cls");
}

//  ---- CONSULTA -> POR VETERINÁRIO ----
void consultaPorVet(Consulta consultas[], int totalConsultas, Animal animais[], int totalAnimais, 
					Veterinario veterinarios[], int totalVets){
	string dataInicio, dataFinal;
	Veterinario vetSelect;
	float valorTotal = 0;
	
	if (totalConsultas == 0) {
		cout << "Sem consultas para filtrar.\n\n";
		system("pause");
		system("cls");
		return;
	}
	
	cout << "\n ----- Consultas por datas ------\n";
	cout << "(Digite 0 a qualquer momento para cancelar)\n\n";
	
	cout << "Data inicial: ";
	cin >> dataInicio;
	if(verificarCancelamento(dataInicio)) return;
	
	cout << "Data final: ";
	cin >> dataFinal;
	if(verificarCancelamento(dataFinal)) return;
	
	cout << "Qual veterinário você gostaria buscar: \n";
		for(int i = 0; i < totalVets; i++){
			cout << "   [" << veterinarios[i].codigo << "] " << veterinarios[i].nome << endl;
		}
		
		while(true){
			cout << "Selecione um veterinário: ";
			cin >> vetSelect.codigo;
				
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entrada inválida! Digite apenas números.\n";
				continue;
			}
			
			if(verificarCancelamento(vetSelect.codigo)) return;
		
			bool encontrado = false;	
			for(int i = 0; i < totalVets; i++){
				if(veterinarios[i].codigo == vetSelect.codigo){
					vetSelect = veterinarios[i];
					encontrado = true;
					break;
				}
			}
			
			if (encontrado) break;
				cout << "Veterinário não encontrado! Tente novamente.\n";
		}
	
	cout << "\nConsultas do veterinário: " << vetSelect.nome;
	cout << "\nPeríodo: " << dataInicio << " e " << dataFinal << ":\n\n";
	
	cout << "Código\t" << "Data\t\t" << "Animal\t\t" << "Valor\t\n";
	for(int i = 0; i < totalConsultas; i++){
		if(consultas[i].data >= dataInicio && consultas[i].data <= dataFinal && consultas[i].codVet == vetSelect.codigo){
			string nomeAnimal;
			
			for(int a = 0; a < totalAnimais; a++){
				if(animais[a].codigo == consultas[i].codAnimal){
					nomeAnimal = animais[a].nome;
					break;
				}
			}
			
			cout << consultas[i].codigo << "\t" 
				 << consultas[i].data << "\t" 
				 << nomeAnimal << "\t\t" 
				 << "R$" << consultas[i].valor << endl;
			
			valorTotal += consultas[i].valor;
		}
	}
	
	cout << "\nValor total das consultas: R$ " << valorTotal << "\n";
	system("pause");
	system("cls");
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
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
//	
//	consultas[0] = {0, 1, 2, "2025-05-01", 150.50};
//	consultas[1] = {1, 2, 1, "2025-05-15", 224.99};
//	totalConsultas = 2;

	int op;

	do{
		cout << " Menu Principal - Clínica Veterinária \n\n";
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
			consultaPorVet(consultas, totalConsultas, animais, totalAnimais, veterinarios, totalVets);
			break;
		case 0:
			cout << "Saindo do programa... \n";
			break;
		default:
			cout << "Opção inválida.\n";
			system("pause");
			system("cls");
		}
	} while (op != 0);
}