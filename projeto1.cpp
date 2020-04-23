#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void cadastrarElemento(int *cod, char nomeP[][100], double *valorP, int cont);
void listarProduto(int *cod, char nomeP[][100], double *valorP, int i);
void pesquisaCodigo(int *cod, int i, int pesquisaCod, char nomeP[][100], double *valorP);
void alterarProduto(int *cod, int i, int pesquisaCod, char nomeP[][100], double *valorP);
int organizarCodigo(int *cod, char nomeP[][100], double *valorP, int cont);
	int main(){
		setlocale(LC_ALL, "Portuguese");
	int cod[4],backupC[4], i,j, pesquisaCod,op,res,cont=0;
	char nomeP[4][100],backupN[4][100];
	double valorP[4], backupV[4];
	do{
	printf(" <<<  Menu >>>\n");
	printf(" 1.Cadastrar Produtos\n 2.Listar Produtos\n 3.Pesquisar Produtos pelo código\n 4.Alterar produtos pelo código \n 5.Fazer backup dos produtos\n 6.Restaurar elemento do backup por codigo\n 7- Excluir um produto\n 8.Ordenar por código \n 0.Encerrar o Programa\n");
    printf("Qual opção deseja?\n");
	scanf("%d", &op);
	fflush(stdin);
    switch(op){
    	case 1:
    		do{
				cadastrarElemento(cod,nomeP,valorP,cont);
				printf("incluir mais algum produto? 1.Sim 2.Não\n");
	            scanf("%d",&res);
	            fflush(stdin);
	            cont++;
    		}while(res==1 and res!=2);
		case 2:
    	printf("<<<<<Lista dos Produtos Cadastrados>>>>\n");
			for(i=0;i<cont;i++){
		listarProduto(cod,nomeP,valorP,i);
			}
    	break;
    	case 3:
    		printf("Qual código do produto que deseja pesquisar?\n ");
			scanf("%d", &pesquisaCod);
			fflush(stdin);
				for(i=0;i<cont;i++){
					pesquisaCodigo(cod,i,pesquisaCod,nomeP,valorP);
				}
    	break;
    	case 4:
    		printf("Qual o código do produto que deseja alterar?\n");
			scanf("%d", &pesquisaCod);
			fflush(stdin);
			for(i=0;i<cont;i++){
				alterarProduto(cod,i,pesquisaCod,nomeP,valorP);
			}
    	case 5:
			for(i=0;i<cont;i++){
    			backupC[i]=cod[i];
    			strcpy(backupN[i],nomeP[i]);
    			backupV[i]=valorP[i];
			}
    	break;
    	case 6:
    		printf("Qual o código do produto que deseja recuperar? \n");
			scanf("%d", &pesquisaCod);
			fflush(stdin);
			for(i=0;i<cont;i++){
				if(backupC[i]==pesquisaCod){
					cod[i]=backupC[i];
					strcpy(nomeP[i],backupN[i]);
					valorP[i]=backupV[i];
					}
			}
    	break;
    		case 7:
    		printf("Digite o código do produto que deseja excluir:\n ");
			scanf("%d", &pesquisaCod);
			fflush(stdin);
			for(i=0;i<cont;i++){
				if(pesquisaCod==cod[i]){
					for(j=i;j<cont;j++){
						cod[j]=cod[j+1];
						strcpy(nomeP[j],nomeP[j+1]);
						valorP[j]=valorP[j+1];
					}
				}
			}
			cont--;
    	break;
    	case 8:
			if( organizarCodigo(cod,nomeP,valorP,cont)==0){
    			printf("Organizacao Concluida!!!\n");
			}
    	break;
    	case 0: 
		return 0;
		}
	printf("Escolher mais alguma opcao? 1.Sim 0.Não\n");
	scanf("%d",&res);
}while(res==1);
}
void cadastrarElemento(int *cod, char nomeP[][100], double *valorP, int cont){
		printf(" Qual o código do produto?\n ");
		scanf("%d", &cod[cont]);
		fflush(stdin);
		printf(" Qual o nome do produto?\n ");
		scanf("%s", &nomeP[cont]);
		fflush(stdin);
		printf(" Qual valor do produto?\n");
		scanf("%lf", &valorP[cont]);
		fflush(stdin);
}
void listarProduto(int *cod, char nomeP[][100], double *valorP, int i){
	printf("Codigo.Produto: %d\n Nome do produto: %s\n Valor: %.2lf\n", cod[i],nomeP[i],valorP[i]);
}
void pesquisaCodigo(int *cod, int i, int pesquisaCod, char nomeP[][100], double *valorP){
	if(cod[i]==pesquisaCod){
		printf("código do Produto: %d\n Nome do produto: %s\n Valor: %.2lf\n", cod[i],nomeP[i],valorP[i]);
	}
}
void alterarProduto(int *cod, int i, int pesquisaCod, char nomeP[][100], double *valorP){
	int op;
	if(pesquisaCod==cod[i]){
		printf("Deseja alterar o produto \n 1.Nome do Produto\n 2.Valor do produto\n 3.Os dois\n");
			scanf("%d", &op);
			fflush(stdin);
			switch (op){
				case 1: printf("Novo nome do Produto: \n");
						scanf("%s", &nomeP[i]);
						fflush(stdin);
						break;
				case 2: printf("valor:\n");
						scanf("%lf", &valorP[i]);
						fflush(stdin);
						break;
				case 3: printf("Nome do Produto: \n");
						scanf("%s", &nomeP[i]);
						fflush(stdin);
						printf("Nome do valor:\n");
						scanf("%lf", &valorP[i]);
						fflush(stdin);
						break;
				default: printf("código não existe!\n");
			}
	}
}
int organizarCodigo(int *cod, char nomeP[][100], double *valorP, int cont){
	int i, j, trocaC;
	double trocaV;
	char trocaN[100];
		for (i=0;i<cont;i++){
			for (j=i+1;j<cont;j++){
				if (cod[i]>cod[j]){
					trocaC = cod[i];
					cod[i] = cod[j];
					cod[j] = trocaC;
					
					trocaV = valorP[i];
					valorP[i] = valorP[j];
					valorP[j] = trocaV;
					
					strcpy(trocaN,nomeP[i]);
					strcpy(nomeP[i],nomeP[j]);
					strcpy(nomeP[j],trocaN);
				}
			}
		}
return 0;
}
