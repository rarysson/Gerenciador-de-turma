#define OP1 "Adicionar um aluno na turma"
#define OP2 "Remover um aluno da turma"
#define OP3 "Modificar um registro de aluno"
#define OP4 "Listar todos os alunos da turma"
#define OP5 "Imprimir a media da turma"
#define OP6 "Sair do programa"
#define APRESENTACAO "Bem-vindo ao programa de gerenciamento de turma.\n(Esse programa contem algumas funcoes que torna mais facil\no gerencionamento de uma turma, entao, bom proveito.)\n\nAutor: Rarysson Guilherme da Costa.\n\tRGC©.\nVersao: 5.5\n\n"
#define DESPEDIDA "\n\t\tObrigado por utilizar o programa.\n\t\t\tTchau."
#include "aluno.h"
#include "interacao.h"
#include "leitura.h"
#include "turma.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
    char *nome, *matricula;
    float nota1, nota2, nota3;
    int opcao;

    Turma classe;
    Aluno *estudante;
    No *busca;

    FILE *arquivo = fopen("Turma.txt", "a+t");

    if(arquivo == NULL){
        printf("\nFalha ao abrir arquivo.");
        exit(1);
    }

    classe = turma_carrega(arquivo);

    apresenta_programa(APRESENTACAO);

    do{
        apresenta_menu(6, 1, OP1, OP2, OP3, OP4, OP5, OP6);
        opcao = le_opcao(1, 6);

        switch(opcao){
            case 1:
                printf("\nAdicionando aluno na turma....\n");
                nome = le_nome();

                do{
                    matricula = le_matricula();
                    matricula[CARACTERES_EM_MATRICULA] = '\0';

                    busca = turma_busca(classe, matricula);

                    if(busca != NULL)
                        printf("\nA matricula ja existe, digite novamente.");

                } while (busca != NULL);

                nota1 = le_nota();
                nota2 = le_nota();
                nota3 = le_nota();

                estudante = aluno_cria(nome, matricula, nota1, nota2, nota3);
                classe = turma_insere(classe, estudante);

                free(nome);
                free(matricula);

                break;
            case 2:
                printf("\nRemovendo aluno da turma....\n");

                if(classe == NULL){
                    printf("\nA turma esta vazia.");
                } else {
                    char escolha;

                    printf("\nDeseja ver a lista de alunos na turma?(S/N) : ");
                    scanf("%c", &escolha);
                    limpa_buffer();

                    if((escolha == 's') || (escolha == 'S')){
                        turma_imprime(classe);
                    }

                    printf("\nA matricula que deseja retirar. ");
                    matricula = le_matricula();
                    matricula[CARACTERES_EM_MATRICULA] = '\0';

                    classe = turma_remove(classe, matricula);

                    free(matricula);
                }

                break;
            case 3:
                printf("\nModificando o registro do aluno....\n");

                if(classe == NULL){
                    printf("\nA turma esta vazia.");
                } else {
                    char escolha;

                    printf("\nDeseja ver a lista de alunos na turma?(S/N) : ");
                    scanf("%c", &escolha);
                    limpa_buffer();

                    if((escolha == 's') || (escolha == 'S')){
                        turma_imprime(classe);
                    }

                    printf("\nA matricula do aluno que deseja modificar. ");
                    matricula = le_matricula();
                    matricula[CARACTERES_EM_MATRICULA] = '\0';

                    busca = turma_busca(classe, matricula);

                    if(busca == NULL){
                        printf("\nA matricula nao esta presente na turma.");
                    } else {
                        nome = le_nome();
                        nota1 = le_nota();
                        nota2 = le_nota();
                        nota3 = le_nota();

                        turma_edita(busca, nome, nota1, nota2, nota3);

                        free(nome);

                        printf("\nAluno modificado.");
                    }

                    free(matricula);
                }

                break;
            case 4:
                printf("\nMostrando os alunos da turma.....\n");

                if(classe == NULL){
                    printf("\nA turma esta vazia.");
                } else {
                    turma_imprime(classe);
                }

                break;
            case 5:
                printf("\nCalculando a media da turma....\n");

                if(classe == NULL){
                    printf("\nA turma esta vazia.");
                } else {
                    printf("\nA media da turma e: %.2f", turma_media(classe));
                }

                break;
            case 6:
                printf("\nSaindo do programa......\n");
        }

        printf("\nAperte ENTER para continuar.........");
        scanf("%*c");

        limpa_buffer();

        limpa_tela();

    } while(opcao != 6);

    mensagem_despedida(DESPEDIDA);

    FILE *salva = fopen("Turma.txt", "w");

    if(salva == NULL){
        printf("\nErro ao criar arquivo.");
        exit(1);
    }

    turma_salva(salva, classe);

    fclose(arquivo);
    fclose(salva);

return 0;
}
