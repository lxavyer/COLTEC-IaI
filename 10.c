#include <stdio.h>
#define DONE 0

typedef struct Aluno {
    char name[30];
    char course[30];
    int age;

} Registro;

int lerAluno(struct Aluno *aluno) {
    printf("Digite o nome do aluno: ");
    scanf("%s", aluno->name);

    printf("Entre o curso do aluno: ");
    scanf("%s", aluno->course);

    printf("Entre a idade: ");
    scanf("%d", &(aluno->age));

    return 0;
}

void imprimirAluno(struct Aluno aluno) {
    printf("Nome: %s\n", aluno.name);
    printf("Curso: %s\n", aluno.course);
    printf("Idade: %d\n", aluno.age);
}

void vetorAlunos(struct Aluno *alunos, int size) {
    for (int i = 0; i < size; i++) {
        printf("Aluno %d:\n", i + 1);
        imprimirAluno(alunos[i]);
        printf("\n");
    }
}

float calcMed(struct Aluno *alunos, int size) {
    int ageSum = 0;

    for (int i = 0; i < size; i++) {
        ageSum += alunos[i].age;
    }

    float med = (float)ageSum / size;
    return med;
}

void ex1() {
    int size;

    printf("Entre a quantidade de alunos: ");
    scanf("%d", &size);

    struct Aluno alunos[size];

    for (int i = 0; i < size; i++) {
        printf("Digite os dados do aluno %d:\n", i + 1);
        lerAluno(&alunos[i]);
        printf("\n");
    }

    printf("Dados do aluno 1:\n");
    imprimirAluno(alunos[0]);
    printf("\n");

    vetorAlunos(alunos, size);

    float med = calcMed(alunos, size);
    printf("A media de idade dos alunos e: %.2f\n", med);
}


int main(int argc, char ** argv) {
    int opN;
    
    do {
        printf("Entre o numero do exercicio a ser executado... \n");
        printf("Exercicios do (1 ao 8) \t Entre 0 para cancelar \n");
        scanf("%d", &opN);

        switch (opN)
        {
        case 0: break;
        case 1:
            ex1();
            break;
        // case 2:
        //     ex2();
        //     break;
        // case 3:
        //     ex3();
        //     break;
        // case 4:
        //     ex4();
        //     break;
        // case 5:
        //     ex5();
        //     break;
        // case 6:
        //     ex6();
        //     break;
        // case 7:
        //     ex7();
        //     break;
        // case 8:
        //     ex8();
        //     break;
        default:
            break;
        }
    } while (opN != 0);

    return DONE;

}