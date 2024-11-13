#include <stdio.h>
#include <locale.h>
#ifdef _WIN32
    #include <windows.h>
#endif
#include "banco_de_dados.h"

enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_ALTERAR,
    OP_EXCLUIR,
    OP_PROCURAR,
    OP_RELATORIO,
    OP_SAIR
};

void menu() {
    printf("\nBem-vindo ao Consultorio Navabundo");
    printf("\n==================== MENU ===========================\n");
    printf("1. Cadastrar Paciente\n");
    printf("2. Alterar Cadastro\n");
    printf("3. Inativar Paciente\n");
    printf("4. Procurar paciente\n");
    printf("5. Relatório de pacientes\n");
    printf("6. Sair\n");
    printf("=================================================\n");
    printf("Selecione uma opção: ");
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    NodoLista* listaNomes = NULL;
    NodoArvore* arvoreCPFs = NULL;
    NodoListaDinamica* listaDados = NULL;
    int opcao = OP_NAO_SELECIONADA;

    while (opcao != OP_SAIR) {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case OP_ADICIONAR:
                adicionarRegistro(&listaNomes, &arvoreCPFs, &listaDados);
                break;
            case OP_ALTERAR:
                alterarRegistro(&listaNomes, arvoreCPFs, listaDados);
                break;
            case OP_EXCLUIR:
                excluirRegistro(&listaNomes, &arvoreCPFs, listaDados);
                break;
            case OP_PROCURAR:
                procurarRegistro(arvoreCPFs);
                break;
            case OP_RELATORIO:
                printf("Relatório: \n");
                imprimirListaDinamicaOrdenada(listaNomes, listaDados);
                break;
            case OP_SAIR:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
        }
    }

    return 0;
}
