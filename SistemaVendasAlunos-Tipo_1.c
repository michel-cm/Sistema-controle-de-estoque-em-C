#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	int dia,mes,ano;
}tData;
typedef struct {
	char nome[40];
	tData dataCadastro;
	int qtdEstoque;
	float valorUnitario;
}tProdutos;
int qtd=0;

int cadastra(tProdutos p[]){
	if(qtd==100){
		return 0;
	}
	printf("*** Cadastro Americanas.com de Produtos ***\n");
	printf("Nome:");
	fflush(stdin);
	gets(p[qtd].nome);
	printf("Data do Cadastro dd mm aa:\n");
	printf("Dia: ");
	scanf("%d",&p[qtd].dataCadastro.dia);
	printf("Mes: ");
	scanf("%d",&p[qtd].dataCadastro.mes);
	printf("Ano: ");
	scanf("%d",&p[qtd].dataCadastro.ano);
	printf("Qtde Estoque:");
	scanf("%d",&p[qtd].qtdEstoque);
	printf("Valor Unitario:");
	scanf("%f",&p[qtd].valorUnitario);
	qtd++;
}
//-----------------------------
void lista(tProdutos p[]){
	
	int i;
	for(i=0;i<qtd;i++){
		printf("\n--- Produto: %d ---\n",i+1);
		printf("Nome: %s\nData do cadastro: %d/%d/%d\nQuantidade em estoque: %d\nValor unitario: %.2f\n",
		       p[i].nome, p[i].dataCadastro.dia,p[i].dataCadastro.mes,p[i].dataCadastro.ano,p[i].qtdEstoque, p[i].valorUnitario);
		printf("------------------------------------------------------------------------\n");
}
}
void lista2(tProdutos p[]){
	
	int i;
	for(i=0;i<qtd;i++){
		printf("\n--- Produto: %d ---\n",i+1);
		printf("Nome: %s\nValor unitario: %.2f",p[i].nome,p[i].valorUnitario);
		printf("\n------------------------------------------------------------------------\n");  
}
}

//-----------------------------------------------
float realizaVenda(tProdutos p[] , char nome[] ){
	int i, encontrou=0;
	int n,r;
	char nomeProdutos[40];
			
	for(i=0;i<qtd;i++){
		strcpy(nomeProdutos, p[i].nome);
		if(strcmp(strupr(nomeProdutos) , strupr(nome) )==0){ 
			printf ("quantos(a) %s ?", p[i].nome);
					fflush(stdin);
					scanf("%d", &n);
					if ( n > p[i].qtdEstoque )
					printf("Estoque insuficiente para realizar essa venda !!!");
					
					
					else{
					r = p[i].qtdEstoque - n;
					p[i].qtdEstoque = p[i].qtdEstoque - n;
					 printf("\nProduto Vendido , foi retirado do estoque %s, %d itens ! ",p[i].nome, n);
	   				printf("\nRestam %d iten(s) para esse estoque. ",r );
	   				printf("\n\nNome: %s\nQuantidade de estoque anterior a venda: %d\nQuantidade de estoque atual: %d\nValor unitario: %.2f\n",
		       	 p[i].nome,p[i].qtdEstoque+n,p[i].qtdEstoque, p[i].valorUnitario);
					}
		encontrou=1;	
		break;											  				
		 		 		    	   
	   	
	  	 }
	    }
	   		
	if(!encontrou) 
	   printf("\nNome incorreto, Produto nao encontrado !!! ");

}
//-----------------------------------------------
void adicionaEstoque(tProdutos p[], char nome[]){
		int i, encontrou=0;
	int n,r;
	char nomeProdutos[40];
			
	for(i=0;i<qtd;i++){
		strcpy(nomeProdutos, p[i].nome);
		if(strcmp(strupr(nomeProdutos) , strupr(nome) )==0){ 
			printf ("quantos itens vc quer adicionar ao estoque de %s ?", p[i].nome);
					scanf("%d", &n);
													
					printf("\nEstoque adicionado ! ");
	   				printf("\n Foram adicionados %d itens ao estoque",n );
	   				p[i].qtdEstoque += n ;
	   				printf("\n\nNome: %s\nData do cadastro: %d/%d/%d\nQuantidade em estoque: %d\nValor unitario: %.2f\n",
		       	 p[i].nome, p[i].dataCadastro.dia,p[i].dataCadastro.mes,p[i].dataCadastro.ano,p[i].qtdEstoque, p[i].valorUnitario);
					
		encontrou=1;	
		break;											  				
		 		 		    	   
	   		}
	  	 }
	    	   		
	if(!encontrou) 
	   printf("\nNome incorreto, Produto nao encontrado !!! ");

}
//-----------------------------------------------
void produtosAno(tProdutos p[], int ano){   
		int i, exis = 0;
	for(i=0; i<qtd; i++){
		if( ano <= p[i].dataCadastro.ano){
			printf("\n--- Produto: %d ---\n",i+1);
			printf("Nome: %s\n",p[i].nome);
			printf("Data do cadastro: %d/%d/%d\n", p[i].dataCadastro.dia,p[i].dataCadastro.mes,p[i].dataCadastro.ano);
			printf("Quantidade em estoque: %d\n",p[i].qtdEstoque);
			printf("Valor unitario: %.2f\n",p[i].valorUnitario);
			exis = 1;
		}
	}
	
	if(exis == 0){
		printf("Nao existe produtos cadastrados nesse ano!\n");
	}

}
//-----------------------------------------------
void busca(tProdutos p[],char nome[]){
	int i, encontrou=0;
	char nomeProdutos[40];
	for(i=0;i<qtd;i++){
		strcpy(nomeProdutos, p[i].nome);
		if(strcmp(strupr(nomeProdutos) , strupr(nome) )==0){
		printf("\n--- Produto: %d ---\n",i+1);
		printf("Nome: %s\nData do cadastro: %d/%d/%d\nQuantidade em estoque: %d\nValor unitario: %.2f\n",
		        p[i].nome, p[i].dataCadastro.dia,p[i].dataCadastro.mes,p[i].dataCadastro.ano,p[i].qtdEstoque, p[i].valorUnitario);
	printf("------------------------------------------------------------------------\n");
		encontrou=1;
		break; 
	}
	}
	if(!encontrou) 
	   printf(" -X- Produto nao consta no sistema -X- ");
	}
//------------------------------------------------
float valotTotalEstoque(tProdutos p[]){
	int i ;
		float mult = 0;
	
	for(i=0;i<qtd;i++){
		mult += p[i].qtdEstoque * p[i].valorUnitario;		
	}
	return mult ; 
}
//-----------------------------------------------
void salvaArquivoBinario(tProdutos p[]){
	FILE *arq;
	arq=fopen("americanas.txt","wb");
	fwrite(&p[0],sizeof(tProdutos),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//-----------------------------
void carregaBinario(tProdutos p[]){
	FILE *arq;
	arq=fopen("americanas.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado!\n");
	  return;
	  }// fim if
	 while(fread(&p[qtd],sizeof(tProdutos),1,arq) >0 )
	      qtd++;  
	 printf("Dados carregados com sucesso!\n");
	fclose(arq);
}
//----------------------------------------

int menu(){
	int op;
	printf("\t**** Struct em C - IFSULDEMINAS ****\n");
	printf("*** Sistemas de Cadastro de Produtos Americanas.com ***\n");
	printf("1-Cadastrar\n");
	printf("2-Listar\n");
	printf("3-Buscar por nome do produto\n");
	printf("4-Realizar venda\n");
	printf("5-Adicionar item ao estoque\n");
	printf("6-Produtos cadastrados a partir de um ano\n");
	printf("7-Valor total do estoque\n");
	printf("8-Salvar em arquivo\n");
	printf("9-Carregar arquivo\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//-----------------------------------------
int main(){
	tProdutos produtos[100];
	char nome[40];
    int op,ano;
	tData data;
		
    do{
    	op=menu();
    	switch(op){
    		case 1: cadastra(produtos);
    		break;
    		case 2: lista(produtos);
    		break;
    		case 3: printf("Nome do produto para ser buscado:");
      			fflush(stdin); gets(nome);
      			busca(produtos, nome);
      		break;	  
      		case 4: lista2(produtos);
      			    printf("Qual o nome do produto q sera vendido ? : ");
      				fflush(stdin); gets(nome);
			  		realizaVenda(produtos, nome);
			  	     			      	
      		break;
      			case 5: lista(produtos);
      			    printf("Qual produto vc quer adicionar + itens ao seu estoque ? : ");
      				fflush(stdin); gets(nome);
			  		adicionaEstoque(produtos, nome);
			  	     			      	
      		break;
			case 6: printf("Digite o ano: ");
					scanf("%d",& ano);
					produtosAno(produtos,ano);
			break;
			case 7: printf (" O valor total de todo o estoque eh de: $ %.2f", valotTotalEstoque(produtos));
							
    		break;		
    		case 8: salvaArquivoBinario(produtos);
    		break;
    		case 9: carregaBinario(produtos);
    		break;
    		
    		case 0: printf("Saindo....");
    		break;
		}// fim switch
		getch();
		system("cls");
	}while(op!=0);
	return 0;
}
