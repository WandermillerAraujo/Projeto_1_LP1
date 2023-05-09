#include <iostream>
#include <fstream>	
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "header.hpp"

using namespace std;

int main(){

	// variaveis globais
	int resposta;
	string senha, medico, funcao, x, y;
	fstream arquivo, arquivo1, arquivo2;
	vector<string> v_medicos;
	vector<string> v_aux_medicos;
	vector<string> v_especialidades;
	vector<string> v_aux_especialidades;
	vector<string> v_agendamentos;

	
	// esse while irá servir para escolha de usuário com o "cin"
	while (true){
		// aqui fica o texto de escolha de usuário
		cout << "Qual o usuário você quer abrir?" << endl;
		cout << "Atendente (Digite 1)" << endl;
		cout <<	"Gerente (Digite 2)" << endl; 
		cout <<	"Sair (Digite 3)" << endl;
		cin >> resposta;
		while (resposta == 1){
			// texto para mostrar as opções de escolhas de comandos
			cout << "------------------------------------------------------" << endl;
			cout << "O que deseja fazer?" << endl;
			cout << "(1) Listar todos os médicos." << endl;
			cout << "(2) Listar todas as especialidades." << endl;
			cout << "(3) Agendar consulta (nome/dia/horário)." << endl;
			cout << "(4) Ver agendamentos de um determinado médico (nome)." << endl;
			cout << "(5) Sair." << endl;
			cout << "------------------------------------------------------" << endl;

			// leitura do que será feito
			int acao;
			cin >> acao;
			// cada if e else if corresponde a um comando daquele texto acima, por isso acao == 1, acao == 2... 
			if (acao == 1){
				// funcao que lista medicos e especialidades
				listar_medicos(arquivo);
			}
			else if (acao == 2){
				// funcao que lista apenas as especialidades
				listar_especialidades(arquivo1);
			}
			else if (acao == 3){
				// funcao que agenda as consultas
				agendar(arquivo2);
			}
			else if (acao == 4){
				// funcao que printa os agendamentos de um medico em especifico
				ver_agenda(arquivo2);
			}
			else if (acao == 5){
				break;
			}
			// caso não haja ação para o número digitado, será pedido para que seja escolhida uma ação válida.
			else {
				cout << "Digite uma ação válida." << endl;
				cin >> acao;
			}
			break;
		}
		while (resposta == 2){
			// se for gerente, vai pedir a senha para entrar no usuário
			cout << "Digite a senha:" << endl;	
			cin >> senha;

			// digitando a senha correta, ele abre o painel de comandos do gerente
			if (senha == "admin"){
				cout << "-----------------------------------------------------------------" << endl;
				cout << "O que deseja fazer?" << endl;
				cout << "(1) Listar todos os médicos." << endl;
				cout << "(2) Listar especialidades e quantidade de profissionais de cada." << endl;
				cout << "(3) Adicionar um novo médico." << endl;
				cout << "(4) Ver agendamentos de um determinado médico (nome)." << endl;
				cout << "(5) Alterar a especialidade de um médico." << endl;
				cout << "(6) Excluir um médico." << endl;
				cout << "(7) Sair." << endl;
				cout << "-----------------------------------------------------------------" << endl;

				// leitura do que será feito
				int acao;
				cin >> acao;
				if (acao == 1){
					// funcao que lista medicos e especialidades
					listar_medicos(arquivo);
				}
				else if (acao == 2){
					// funcao que lista as especialidades e quantidade de medicos de cada	
					qtd_prof_espec(arquivo1);
				}
				else if (acao == 3){
					// funcao que adiciona medico + especialidade
					adicionar_medico(arquivo, arquivo1);
				}
				else if (acao == 4){
					// funcao que printa os agendamentos de um medico em especifico
					ver_agenda(arquivo2);
				}
				// funcao que altera a especialidade de um medico em especifico e printa a nova lista de medicos e especialidades de cada um
				else if (acao == 5){
					alterar_especialidade();
					break;
				}
				// funcao que remove um medico escolhido e mostra na tela a nova lista de medicos com a remocao do escolhido
				else if (acao == 6){
					remover_medico();
					break;
				}
				// fecha o while e não faz nada no painel do gerente
				else if (acao == 7){
					break;
				}
				// caso não haja ação para o número digitado, será pedido para que seja escolhida uma ação válida.
				else {
					cout << "Digite uma ação válida." << endl;
					cin >> acao;
				}
			}
			// mas se você errar a senha...
			else{
				cout << "Eita, você não é o gerente!" << endl;
			}
			break;
		} 
		// se for digitado um número maior que o 3 (comando "Sair"), ele pede para que digite outro número que haja comando
		while (resposta > 3) {
			cout << "Digite um usuário válido!" << endl;
			break;
		}
		// se o comando escolhido for o 3, não escolhe nenhum usuário e encerra o programa
		if (resposta == 3){
			cout << "Tudo bem, até a próxima." << endl;
			break;
		}
	}
	
	return 0;
}