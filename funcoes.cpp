#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void listar_medicos(fstream& arquivo){
	// declaração de variavel e um vetor
	string x;
	vector<string> v_medicos;
	
	// abre o arquivo de texto dos medicos e começa a adicionar todos no arquivo
	arquivo.open("medicos.txt", ios::in);
	// guarda em um vetor
	while(getline(arquivo, x)){
		v_medicos.push_back(x);
	}
	cout << "---------------------------------------------" << endl << endl;
	cout << "Aqui está a lista de médicos: " << endl;
	// o for serve para printar os medicos e suas especialidades que foram adicionados
	for (int i=0; i < v_medicos.size(); i+=2){
	
		cout << "Médico: " << v_medicos[i] << endl;
	
		cout << "Especialidade: " << v_medicos[i+1] << endl << endl;
	}
	cout << "---------------------------------------------" << endl;
	arquivo.close();
}

void listar_especialidades(fstream& arquivo1){
	// declaração de variavel e um vetor
	string x;
	vector<string> v_especialidades;
	
	// aqui cria o arquivo de texto somente das especialidades, será útil para o comando 2 do gerente
	arquivo1.open("especialidades.txt", ios::in);
	
	while(getline(arquivo1, x)){
		v_especialidades.push_back(x);
	}
	cout << "---------------------------------------------" << endl << endl;
	cout << "Aqui está a lista de especialidades: " << endl;
	// printa todas as especialidades, ou seja, tudo que está no arquivo de texto
	for (int i=0; i < v_especialidades.size(); i++){
		cout << v_especialidades[i] << endl;
	}
	cout << endl << "---------------------------------------------" << endl;
	arquivo1.close();
}

void adicionar_medico(fstream& arquivo, fstream& arquivo1){
	// declaração de variaveis
	string medico;
	string funcao;
	
	// adiciona um medico e sua especialidade nos arquivos "arquivo" e "arquivo1" (medicos.txt e especialidades.txt)
	arquivo.open("medicos.txt", ios::app);
	arquivo1.open("especialidades.txt", ios::app);
	// faz a leitura do medico e da sua especialidade
	cout << "Digite o nome do(a) médico(a) a ser adicionado(a): " << endl;
	cin.ignore();
	getline(cin, medico);
	cout << "Digite a especialidade do(a) médico(a) adicionado(a): " << endl;
	getline(cin, funcao);
	// adiciona o que foi recebido dos cin's nos arquivos
	arquivo << medico <<  endl;
	arquivo << funcao << endl;
	arquivo1 << funcao << endl;
	
	arquivo.close();
	arquivo1.close();
}

void agendar(fstream& arquivo2){
	// declaração de variaveis
	string x, y;
	
	// cria o arquivo de agendamentos
	arquivo2.open("agendamentos.txt", ios::app);
	// faz a leitura do médico e depois do agendamento para o medico
	cout << "Digite o nome do(a) médico(a): " << endl;
	cin.ignore();
	getline(cin, x);
	cout << "Digite o dia e horário que você quer: (ex.: segunda - 14h as 15h)" << endl;
	getline(cin, y);
	// adiciona o nome do medico e o horario que o cliente agendou para o mesmo, ambos salvos no arquivo2 ("agendamentos.txt")
	arquivo2 << x << endl;
	arquivo2 << y << endl;
	
	arquivo2.close();
}

void ver_agenda(fstream& arquivo2){
	// declaração de variavel e um vetor
	string x;
	vector<string> v_agendamentos;
	
	// aqui sera printado parte especifica do arquivo de texto dos agendamentos, para mostrar quais são os horários ocupados do medico pesquisado
	arquivo2.open("agendamentos.txt", ios::in);
	// passa os agendamentos para um vetor, para assim facilitar o acesso
	while(getline(arquivo2, x)){
		v_agendamentos.push_back(x);
	}
	// faz a leitura do nome do médico
	cout << "Digite o nome do médico: " << endl;
	cin.ignore();
	getline(cin, x);
	
	cout << endl << "O médico selecionado: " << x << ", está com essas datas agendadas: " << endl;
	int cont=0;
	// passa um for para rodas o vetor e comparar o nome do médico para printar os horários do médico em específico
	for (int i=0; i < v_agendamentos.size(); i++){
		if(x == v_agendamentos[i]){
			cout << v_agendamentos[i+1] << endl << endl;
			cont=cont+1;
		}
	}
	// o cont (contador) serve para saber se o médico possui agendamentos
	if (cont==0){
		cout << "O médico selecionado não tem horários agendados!" << endl << endl;
	}
	
	arquivo2.close();
}

void qtd_prof_espec(fstream& arquivo1){
	// declaração de variaveis e um vetor
	string funcao;
	int aux;
	vector<string> v_especialidades;
	
	// abre o arquivo1 e passa as infos do .txt para um vetor
	arquivo1.open("especialidades.txt", ios::in);
	while(getline(arquivo1, funcao)){
		v_especialidades.push_back(funcao);
	}
	
	// o sort irá fazer a ordenação do vetor alfabeticamente, por isso é colocado o .begin e o .end, para que o vetor seja percorrido do inicio ao fim
	sort(v_especialidades.begin(), v_especialidades.end());

	cout << "Aqui está nossa lista da quantidade de profissionais por especialidade: (na forma: 'quantidade' 'especialidade')" << endl;

	// o laço é feito de uma forma que sejam identificadas as repetições, para que não sejam mostradas na tela, apenas quantas vezes ocorre a repetição
	for (int i=0; i<v_especialidades.size(); i++){
    	int aux = 0;
    	for (int j=0; j<v_especialidades.size(); j++){
        	if (v_especialidades[i] == v_especialidades[j]){
           		aux = aux+1;
       		}
    	}   
    	if (i == 0 || v_especialidades[i] != v_especialidades[i-1]){
        	cout << aux << " " << v_especialidades[i] << endl;
    	}
	}
}

void remover_medico(){
    // declaração das variaveis, arquivos e vetores usados
	string x;
	int y;
	vector<string> v_aux_medicos;
	vector<string> v_aux_especialidades;
	fstream arquivo, arquivo1;

	// abertura dos arquivos para leitura
	arquivo.open("medicos.txt", ios::in);
	arquivo1.open("especialidades.txt", ios::in);
	
	// aqui adiciona as linhas do arquivo em um vetor auxiliar
	while(getline(arquivo, x)){
		v_aux_medicos.push_back(x);
	}
	while(getline(arquivo1, x)){
		v_aux_especialidades.push_back(x);
	}

	// leitura do medico a ser removido
	cout << "Digite o nome do médico que será removido: " << endl << endl;
	cin.ignore();
	getline(cin, x);

	// o for serve para rodar o vetor e encontrar o medico a ser removido
	for(int i=0; i<v_aux_medicos.size(); i++){
		if(x == v_aux_medicos[i]){
			// apaga o medico
			v_aux_medicos.erase(v_aux_medicos.begin()+i);
			// apaga a especialidade (ambos do medicos.txt)
			v_aux_medicos.erase(v_aux_medicos.begin()+i);
			y=(i+1)/2;
			// apaga a especialidade do especialidades.txt (arquivo1)
			v_aux_especialidades.erase(v_aux_especialidades.begin()+y);
		}
	}
	// fecha tudo
	arquivo.close();
	arquivo1.close();
	// abre novamente para sobrescrever
	arquivo.open("medicos.txt", ios::out);
	arquivo1.open("especialidades.txt", ios::out);

	cout << "Médico(a) removido(a)." << endl;
	cout << "Agora a lista se encontra assim: " << endl;
	// print da nova lista com a alteração
	for (int i=0; i<v_aux_medicos.size(); i++){
		arquivo << v_aux_medicos[i] << endl;
		cout << v_aux_medicos[i] << endl << endl;
	}
	// passa as alterações para o arquivo1 também
	for (int i=0; i<v_aux_especialidades.size(); i++){
		arquivo1 << v_aux_especialidades[i] << endl << endl;
	}
	
	arquivo.close();
	arquivo1.close();

}

void alterar_especialidade(){
	// declaração das variaveis, arquivos e vetores usados
	string x, y;
	int aux;
	fstream arquivo, arquivo1;
	vector<string> v_aux_especialidades;
	vector<string> v_aux_medicos;

	// abertura dos arquivos
	arquivo.open("medicos.txt", ios::in);
	arquivo1.open("especialidades.txt", ios::in);
	//leitura e adicao das linhas do arquivo no vetor auxiliar
	while(getline(arquivo,x)){
	  v_aux_medicos.push_back(x);
	}
	while(getline(arquivo1,x)){
	  v_aux_especialidades.push_back(x);
	}
   
	// leitura do nome do medico a ser escolhido
	cout << "Digite o nome do médico que será alterada a especialidade: " << endl;
	cin.ignore();
	getline(cin, x);
	cout<< endl;
	cout << "Digite a nova especialidade: "<< endl;
	// leitura da nova especialidade escolhida
	getline(cin, y);
	cout << endl;
	
	//aqui faz a busca do medico escolhido na lista para alterar especialidade
	for(int i=0; i<v_aux_medicos.size(); i++){
		if(x==v_aux_medicos[i]){
		  v_aux_medicos[i+1]=y;
		  aux=(i+1)/2;
		  v_aux_especialidades[aux]=y;
	}
	// fecha os arquivos
	arquivo.close();
	arquivo1.close();
	// aqui faz a adicao do vetor atualizado no arquivo
	arquivo.open("medicos.txt", ios::out);
	arquivo1.open("especialidades.txt", ios::out);
	cout << "Especialiade alterada do médico: "<< x << endl;
	cout << "Nova lista dos médicos: " << endl << endl;

	// printa a nova lista
	for(int i=0; i<v_aux_medicos.size(); i+=2){
	  arquivo << v_aux_medicos[i] << endl;
	  arquivo << v_aux_medicos[i+1] << endl;
	  cout << v_aux_medicos[i] << endl;
	  cout << v_aux_medicos[i+1] << endl;
	  cout << endl;
	}
	// adicao da nova lista de especialidade no arquivo1 .txt (arquivo das especialidade)
	for(int i=0; i<v_aux_especialidades.size(); i++){
	  arquivo1 << v_aux_especialidades[i] << endl;
	}
	// fecha novamente
	arquivo.close();
	arquivo1.close();
	}
}