#ifndef HEADER_HPP
#define HEADER_HPP

void listar_medicos(std::fstream& arquivo);
void listar_especialidades(std::fstream& arquivo1);
void adicionar_medico(std::fstream& arquivo, std::fstream& arquivo1);
void agendar(std::fstream& arquivo2);
void ver_agenda(std::fstream& arquivo2);
void qtd_prof_espec(std::fstream& arquivo1);
void alterar_especialidade();
void remover_medico();

#endif