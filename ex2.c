#include <stdio.h>
#include <stdlib.h>
#define QTD 5

typedef struct Aluno{
    char nome[51];
    int matricula;
    float nota;
}Aluno;

float media(Aluno aluno[]);

int main(){
    Aluno aluno[QTD];

    for(int i = 0; i < QTD ; i++){
       printf("Informe o Nome do %dº Aluno:\n", i+1);
       scanf("%[^\n]",aluno[i].nome);
       printf("Informe o Número de Matrícula de %s:\n", aluno[i].nome);
       scanf("%d",&aluno[i].matricula);
       printf("Informe a Nota de %s:\n", aluno[i].nome);
       scanf("%f",&aluno[i].nota);
       getchar();
    }

    
    float media_alunos = media(aluno);
    
    printf("Média das Notas: %.2f\n", media_alunos);

    return 0;
}

float media(Aluno aluno[]){
    float sum,media;
    for(int i = 0; i < QTD; i++){
        sum+=aluno[i].nota;
    }
    return media = sum/QTD;
}