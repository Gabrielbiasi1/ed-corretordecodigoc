#include<stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct dirent *dirt;



int xcase(char dir[]) {
	DIR *dirc;
	dirc = opendir(dir);
	int cEnc;
	if (dirc == NULL) {
	    printf("Nao foi possivel abrir o diretorio! Desculpa!");
	    return 0;
	}	
	while ((dirt = readdir(dirc)) != NULL){
    	if(dirt->d_namlen > 2){
    		cEnc++;
		}	
	}
	return cEnc;
}
void render() {
	DIR *dirc = opendir(".");
	char prob[26]="";
	int i, count=0, casu=0;
    if (dirc == NULL){
        printf("Nao foi possivel abrir o diretorio! Desculpa!" );
    }
    while ((dirt = readdir(dirc)) != NULL){
        if(dirt->d_namlen==1 && strcmp(dirt->d_name,".")!=0){
        	strcat(prob, dirt->d_name);
        	count++;
		}	
	}
	closedir(dirc);
	for(i=0;i<count;i++){
		char caminho[50];
		sprintf(caminho, ".\\%c\\entradas", prob[i]);
    	casu = xcase(caminho);
		printf("-->Problema: %c \n", prob[i], casu);
		casu=0;
		closedir(dirc);
	}
}
void inic(int casus, char prob) {
	int i;
	for(i=1; i<=casus; i++){
		char act[100];
		sprintf(act, ".\\%c\\respostas\\%c.exe < .\\%c\\entradas\\%d.txt > .\\%c\\respostas\\%d.txt", prob, prob, prob, i, prob, i);
		system(act);
	}
}
void delapp(char prob) {
	char folder[20], app[10], apag[20];
	sprintf(app, "%c.exe", prob);
	sprintf(folder, ".\\%c\\respostas", prob);
	sprintf(apag, "DEL .\\%c\\respostas\\%c.exe", prob, prob);
	DIR *dirc = opendir(folder);
    if (dirc == NULL){
        printf("Nao foi possivel abrir o diretorio! Desculpa!!" );
    }
    while ((dirt = readdir(dirc)) != NULL){
    
        if(strcmp(dirt->d_name, app)==0){
			system(apag); 
		}	
	}
	closedir(dirc);
}
void valu(int casus, char prob) {
	int i, error=0;
    FILE *saidas;
    FILE *respostas;
    char saida1, show, arquiv[50], texto[50];
    for(i=1; i<=casus; i++){
        sprintf(arquiv, ".\\%c\\saidas\\%d.txt", prob, i);
        saidas = fopen(arquiv, "r");
        sprintf(texto, ".\\%c\\respostas\\%d.txt", prob, i);
        respostas = fopen(texto, "r");
		while((show = fgetc(respostas)) != EOF){
            saida1 = fgetc(saidas);
        
            if(saida1 != show){
            	error=1;
            }
        }
        if(error == 0){
            printf("\n--> (caso %d) Codigo correto! Parabens!\n", i);
        }else{
            printf("--> (caso %d) Falha em passar no caso de teste! Tente novamente! \n", i);
        }
        fflush(stdout);
        fclose(saidas);
        fflush(stdout);
        fclose(respostas);
        error=0;
    }
}

int checa(char prob) {
	char folder[20];
	sprintf(folder, ".\\%c", prob);
	DIR *dirc = opendir(folder);	
    if (dirc == NULL){
        printf("Nao foi possivel abrir o diretorio! Desculpa!!" );
        return 0;
    }
	closedir(dirc);
	return 1;	
}

int appc(char prob) {
	char folder[20],app[10];
	sprintf(app, "%c.exe", prob);
	sprintf(folder, ".\\%c\\respostas", prob);
	DIR *dirc = opendir(folder);
	int irr = 0;	
    if (dirc == NULL){
        printf("Nao foi possivel abrir o diretorio! Desculpa!!" );
    }	
    while ((dirt = readdir(dirc)) != NULL){
    	
        if(strcmp(dirt->d_name, app)==0){
			irr++;
		}	
	}
	closedir(dirc);
	return irr;
}

int main(){
	int cEnc = 0;
	char compile[100], file[50], direc[50], prob;
    printf("______________________BEM VINDO AO SIMULATONA!______________________\n\n\n--> Corretor de exercicios de programacao em C\n\nTrabalho realizado por: \n Gabriel Guatura De Biasi \n Paulo Vitor De Souza Ferreira \n Adrian Pacheco \n\n\n\n Escolha entre os problemas listados:\n\n");
    render();
    printf("\n Escolha uma letra:\n\n ");
	scanf("%c", &prob);
	if(checa(prob) == 0){
		return 0;
	}
	printf("\n Insira o arquivo do codigo:\n (exemplo: HelloWorld.c)\n\n");
	scanf("%s", file);
	sprintf(direc, ".\\%c\\entradas", prob);
	dirt = opendir(direc);
	cEnc = xcase(direc);
	sprintf(compile,"gcc %s -o .\\%c\\respostas\\%c.exe 2> erros.txt", file, prob, prob);
	system(compile);
	
	system("DEL erros.txt");
	if(appc(prob) == 0){
		printf("\n\nVixi, vai ficar sem ponto extra, erro de compilacao!\n\n");
		return 0;
	}
	printf("Corrigindo...\n\n");
	inic(cEnc, prob);
	valu(cEnc, prob);
	delapp(prob);

	return 0;
}



