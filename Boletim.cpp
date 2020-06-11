#include<stdio.h>
#include<math.h>
//Calcular media do aluno
float media(int notas[]){
	float resultado = 0;
	int i;
	for(i=0;i<5;i++){
		resultado = resultado + notas[i];
	}
	return resultado/5;
}
void lerNotas(int notas[], char aluno[]){
	int i;
	for(i=0;i<5;i++){
		printf("Informe as notas do aluno %s \n", aluno);
		scanf("%d", &notas[i]);
	}
}
int resultadoFinal(int notas[]){
	if(media(notas)>7){
		return 1;
	}
	else return 0;
}

int main(){
	//Ler o nome de um aluno
	char aluno [10];
	printf("Informe o nome do aluno: \n");
	scanf("%s", aluno);
	//Ler 5 notas de um aluno
	int notas[5];
	lerNotas(notas, aluno);
	FILE *boletim;
	boletim = fopen("Boletim.txt", "w+t");
	if(boletim!=NULL){
		fprintf(boletim,"Boletim Escolar\n");
		fprintf(boletim, "Aluno(a): %s \n", aluno);
		int c;
		for(c=0;c<5;c++){
			fprintf(boletim, "Nota: %d \n", notas[c]);	
		}
		fprintf(boletim, "A media do(a) aluno(a): %s foi %f \n", aluno, media(notas));
		if(resultadoFinal(notas)==1){
			fprintf(boletim, "O aluno(a) %s foi APROVADO com media %f \n", aluno, media(notas));
		}
		else fprintf(boletim,"O Aluno %s foi REPROVADO com media %f \n", aluno, media(notas));
	}
	fclose(boletim);
	
	return 0;
}
