#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

struct animal{
    char nome[30];
    char especie[20];
    char raca[20];
    char sexo[10];
    int idade;
    char cor[10];
    char cor_olhos[10];
    char pelo[10];
    char comportamento[15];
    struct animal *proximoAnimal;
};

void cadastrar(struct animal **cadastroAnimal, struct animal cadastroArquivo){

    if (*cadastroAnimal==NULL){
        (*cadastroAnimal) = (struct animal*) malloc(sizeof(struct animal));
        strcpy((**cadastroAnimal).nome, cadastroArquivo.nome);
        strcpy((**cadastroAnimal).especie, cadastroArquivo.especie);
        strcpy((**cadastroAnimal).raca, cadastroArquivo.raca);
        strcpy((**cadastroAnimal).sexo, cadastroArquivo.sexo);
        (**cadastroAnimal).idade = cadastroArquivo.idade;
        strcpy((**cadastroAnimal).cor, cadastroArquivo.cor);
        strcpy((**cadastroAnimal).cor_olhos, cadastroArquivo.cor_olhos);
        strcpy((**cadastroAnimal).pelo, cadastroArquivo.pelo);
        strcpy((**cadastroAnimal).comportamento, cadastroArquivo.comportamento);
    }
    else
    {
        struct animal *auxiliar = (struct animal*) malloc(sizeof(struct animal));
        strcpy((*auxiliar).nome, cadastroArquivo.nome);
        strcpy((*auxiliar).especie, cadastroArquivo.especie);
        strcpy((*auxiliar).raca, cadastroArquivo.raca);
        strcpy((*auxiliar).sexo, cadastroArquivo.sexo);
        (*auxiliar).idade = cadastroArquivo.idade;
        strcpy((*auxiliar).cor, cadastroArquivo.cor);
        strcpy((*auxiliar).cor_olhos, cadastroArquivo.cor_olhos);
        strcpy((*auxiliar).pelo, cadastroArquivo.pelo);
        strcpy((*auxiliar).comportamento, cadastroArquivo.comportamento);
        (*auxiliar).proximoAnimal = *cadastroAnimal;
        (*cadastroAnimal) = auxiliar;
    }
    

};

int buscaNome(struct animal *cadastroAnimal){

    char nome_busca[30];
    printf("\nDigite o nome do Pet: ");
    scanf("%s", nome_busca);

    while (cadastroAnimal!=NULL){
        if (strcmp((*cadastroAnimal).nome, nome_busca)==0) return(1);
        else
        cadastroAnimal = (*cadastroAnimal).proximoAnimal;
    }

    return 0;
    
}

void buscaEspecie(struct animal *cadastroAnimal){
    char especie[20];
    printf("Digite a especie: ");
    scanf("%s", especie);
    if (cadastroAnimal==NULL) printf("\nNao ha Pets cadastrados\n");
    while(cadastroAnimal!=NULL){
        if (strcmp((*cadastroAnimal).especie, especie) == 0){
            printf("\n=================================================================================\n");
            printf("| Pet %s\n", (*cadastroAnimal).nome);
            printf("| Especie: %s | Raca: %s | Sexo: %s | Idade: %d\n", (*cadastroAnimal).especie, (*cadastroAnimal).raca, (*cadastroAnimal).sexo, (*cadastroAnimal).idade);
            printf("| Cor: %s | Cor dos olhos: %s | Pelo: %s | Comportamento: %s\n", (*cadastroAnimal).cor, (*cadastroAnimal).cor_olhos, (*cadastroAnimal).pelo, (*cadastroAnimal).comportamento);
            printf("=================================================================================\n");
        }
        cadastroAnimal = (*cadastroAnimal).proximoAnimal;
    }
    printf("\nPressione qualquer tecla para continuar:\n");
    getch();
}

void buscaEspecieRaca(struct animal *cadastroAnimal){
    char especie[20];
    char raca[20];
    printf("Digite a especie: ");
    scanf("%s", especie);
    printf("Digite a raca: ");
    scanf("%s", raca);
    if (cadastroAnimal==NULL) printf("\nNao ha Pets cadastrados\n");
    while(cadastroAnimal!=NULL){
        if (strcmp((*cadastroAnimal).especie, especie) == 0 && strcmp((*cadastroAnimal).raca, raca) == 0){
            printf("\n=================================================================================\n");
            printf("| Pet %s\n", (*cadastroAnimal).nome);
            printf("| Especie: %s | Raca: %s | Sexo: %s | Idade: %d\n", (*cadastroAnimal).especie, (*cadastroAnimal).raca, (*cadastroAnimal).sexo, (*cadastroAnimal).idade);
            printf("| Cor: %s | Cor dos olhos: %s | Pelo: %s | Comportamento: %s\n", (*cadastroAnimal).cor, (*cadastroAnimal).cor_olhos, (*cadastroAnimal).pelo, (*cadastroAnimal).comportamento);
            printf("=================================================================================\n");
        }
        cadastroAnimal = (*cadastroAnimal).proximoAnimal;
    }
}

void buscaCompleta(struct animal *cadastroAnimal){
    char especie[20];
    char raca[20];
    char sexo[10];
    printf("Digite a especie: ");
    scanf("%s", especie);
    printf("Digite a raca: ");
    scanf("%s", raca);
    printf("Digite o sexo: ");
    scanf("%s", sexo);
    if (cadastroAnimal==NULL) printf("\nNao ha Pets cadastrados\n");
    while(cadastroAnimal!=NULL){
        if (strcmp((*cadastroAnimal).especie, especie) == 0 && strcmp((*cadastroAnimal).raca, raca) == 0 && strcmp((*cadastroAnimal).sexo, sexo) == 0){
            printf("\n=================================================================================\n");
            printf("| Pet %s\n", (*cadastroAnimal).nome);
            printf("| Especie: %s | Raca: %s | Sexo: %s | Idade: %d\n", (*cadastroAnimal).especie, (*cadastroAnimal).raca, (*cadastroAnimal).sexo, (*cadastroAnimal).idade);
            printf("| Cor: %s | Cor dos olhos: %s | Pelo: %s | Comportamento: %s\n", (*cadastroAnimal).cor, (*cadastroAnimal).cor_olhos, (*cadastroAnimal).pelo, (*cadastroAnimal).comportamento);
            printf("=================================================================================\n");
        }
        cadastroAnimal = (*cadastroAnimal).proximoAnimal;
    }
    printf("\nPressione qualquer tecla para continuar:\n");
    getch();
}

void imprimir(struct animal *cadastroAnimal){

    if (cadastroAnimal == NULL) printf("Nao ha Pets cadastrados");
    else do{
            printf("\n=================================================================================\n");
            printf("| Pet %s\n", (*cadastroAnimal).nome);
            printf("| Especie: %s | Raca: %s | Sexo: %s | Idade: %d\n", (*cadastroAnimal).especie, (*cadastroAnimal).raca, (*cadastroAnimal).sexo, (*cadastroAnimal).idade);
            printf("| Cor: %s | Cor dos olhos: %s | Pelo: %s | Comportamento: %s\n", (*cadastroAnimal).cor, (*cadastroAnimal).cor_olhos, (*cadastroAnimal).pelo, (*cadastroAnimal).comportamento);
            printf("=================================================================================\n");
        cadastroAnimal = (*cadastroAnimal).proximoAnimal;
    }while (cadastroAnimal!=NULL);

    printf("\nPressione qualquer tecla para continuar:\n");
    getch();
    
};

void quantidadeAnimais(struct animal *cadastroAnimal){

    int quantidade = 0;
    if (cadastroAnimal==NULL) printf("\nNao ha Pets cadastrados\n");
    while (cadastroAnimal!=NULL)
    {
        quantidade = quantidade + 1;
        cadastroAnimal = (*cadastroAnimal).proximoAnimal;
    }
    printf("\n Quantidade de Pets cadastrados: %d\n", quantidade);
    printf("\nPressione qualquer tecla para continuar:\n");
    getch();

};

void quantidadeEspecie(struct animal *cadastroAnimal){

    char especie[20];
    int contagem = 0;
    printf("Digite a especie: ");
    scanf("%s", especie);
    if (cadastroAnimal==NULL) printf("\nNao ha Pets cadastrados\n");
    while (cadastroAnimal!=NULL){
        if(strcmp((*cadastroAnimal).especie, especie) == 0){
            contagem = contagem + 1;
        }
        cadastroAnimal = (*cadastroAnimal).proximoAnimal; 
    }
        
   printf("\nQuantidade de Pets nessa especie: %d\n", contagem);
   printf("\nPressione qualquer tecla para continuar:\n");
    getch();

};

void removerAnimal(struct animal **cadastroAnimal){
    char nome[30];
    struct animal *removeCadastro = *cadastroAnimal;
    printf("Digite o nome do animal que deseja remover: ");
    scanf("%s", nome);
    while(removeCadastro!=NULL){
        if (strcmp((*removeCadastro).nome, nome) == 0){
            printf("Pet removido: %s ", (*removeCadastro).nome);
            free(removeCadastro);
            removeCadastro->proximoAnimal = NULL;
        }
        removeCadastro = (*removeCadastro).proximoAnimal;
    }
};

int main(){
	
    setlocale(LC_ALL, "Portuguese");
    FILE *arquivo;
    int opcao;
    struct animal *cadastroAnimal = NULL;
    struct animal cadastroArquivo;
    system("color 79");

    if ((arquivo = fopen("adocaoPet.txt", "r+")) == NULL){
        printf("Arquivo nao existente, inicializando...\n");
        arquivo = fopen("adocaoPet.txt", "w+");
    }
    else
    {
        printf("Leitura do arquivo de animais cadastrados...\n");
        while (!feof(arquivo))
        {
            fread(&cadastroArquivo, sizeof(struct animal), 1, arquivo);
            if (!feof(arquivo)){
                cadastrar(&cadastroAnimal, cadastroArquivo);
            }
        } 
    }
    

    do{
    	
        printf("\n=============================== Sistema Adoção ================================");
        printf("\n1 - Cadastrar Pet\n");
        printf("2 - Pets cadastrados\n");
        printf("3 - Buscar Pet\n");
        printf("4 - Quantidade de Pets cadastrados\n");
        printf("5 - Quantidade de Pets por espécie cadastrados\n");
        printf("6 - Buscar Pet por espécie\n");
        printf("7 - Buscar Pet por espécie e raça\n");
        printf("8 - Buscar Pet por espécie, raça e sexo\n");
        printf("9 - Remover Pet \n");
        printf("10 - Alterar cadastro de um Pet\n");
        printf("0 - Sair\n");
        printf("================================================================================\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao)

        {
        case 1: printf("Nome: ");
                scanf("%s", cadastroArquivo.nome);
                printf("Especie: ");
                scanf("%s", cadastroArquivo.especie);
                printf("Raca: ");
                scanf("%s", cadastroArquivo.raca);
                printf("Sexo (macho/femea): ");
                scanf("%s", cadastroArquivo.sexo);
                printf("Idade: ");
                scanf("%d", &cadastroArquivo.idade);
                printf("Cor do pelo: ");
                scanf("%s", cadastroArquivo.cor);
                printf("Cor dos olhos: ");
                scanf("%s", cadastroArquivo.cor_olhos);
                printf("Tipo de pelo: ");
                scanf("%s", cadastroArquivo.pelo);
                printf("Comportamento: ");
                scanf("%s", cadastroArquivo.comportamento);
                cadastrar(&cadastroAnimal, cadastroArquivo);
                printf("\nPet cadastrado\n");
                printf("\nPressione qualquer tecla para continuar:\n");
                getch();
            break;

        case 2: imprimir(cadastroAnimal);
            break;

        case 3: 
            if(buscaNome(cadastroAnimal)==1){
            printf("\n=================================================================================\n");
            printf("| Pet %s\n", (*cadastroAnimal).nome);
            printf("| Especie: %s | Raca: %s | Sexo: %s | Idade: %d\n", (*cadastroAnimal).especie, (*cadastroAnimal).raca, (*cadastroAnimal).sexo, (*cadastroAnimal).idade);
            printf("| Cor: %s | Cor dos olhos: %s | Comportamento: %s\n", (*cadastroAnimal).cor, (*cadastroAnimal).cor_olhos, (*cadastroAnimal).comportamento);
            printf("=================================================================================\n");
            printf("\nPressione qualquer tecla para continuar:\n");
            getch();
            }
            else
            printf("\nPet nao encontrado");
            break;

        case 4: quantidadeAnimais(cadastroAnimal);
            break;
            
        case 5: quantidadeEspecie(cadastroAnimal);
            break;

        case 6: buscaEspecie(cadastroAnimal);
            break;
        
        case 7: buscaEspecieRaca(cadastroAnimal);
            break;

        case 8: buscaCompleta(cadastroAnimal);
            break;

        case 9: removerAnimal(&cadastroAnimal);
            break;

        case 10:
            break;
        }
        
        


    }while(opcao != 0);

    rewind(arquivo);
    fflush(arquivo);
    struct animal *cadastroAuxiliar = cadastroAnimal;
    while (cadastroAuxiliar!=NULL){
        printf("Pets registrados");
        fwrite((char *)cadastroAuxiliar, sizeof(struct animal), 1, arquivo);
        cadastroAuxiliar = (*cadastroAuxiliar).proximoAnimal;
    }
    fflush(stdin);
    fclose(arquivo);
};
