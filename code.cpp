#include <stdio.h>

struct student_t {
	double scores[4];
	double total;
};

void register_student(student_t *student) {
	for (int i = 0; i < 4; i++) {
		printf("Insira a nota (%i): ", i + 1);
		scanf("%lf", &(student->scores)[i]);
		
		if (student->scores[i] < 0) {
			student->scores[i] = 0;
		}
		
		if (student->scores[i] > 10) {
			student->scores[i] = 10;
		}
		
		student->total += student->scores[i];
	}
}

void edit_student(student_t *students, int _s) {
	if (!_s) {
		printf("Nao ha estudantes cadastrados!\n");
		return;
	}

	int i;

	printf("Digite qual o estudante (1 - %d): ", _s);
	scanf("%d", &i);
	
	i--;
	
	if (i < 0 || i > _s - 1) {
		printf("Este estudante nao esta cadastrado!\n");
		return;
	}
	
	register_student(&students[i]);
}

void list_students(student_t *students, int _s) {
	if (!_s) {
		printf("Nao ha estudantes cadastrados!\n");
		return;
	}
	
	for (int i = 0; i < _s; i++) {
		double avg = students[i].total / 4;
		printf("Aluno (%d) - notas: %.2lf %.2lf %.2lf %.2lf - total: %.2lf - media: %.2lf", i + 1, students[i].scores[0], students[i].scores[1], students[i].scores[2], students[i].scores[3], students[i].total, avg);

		if (avg < 4) {
			printf(" - status: Reprovado\n");
		} else if (avg > 6) {
			printf(" - status: Aprovado\n");
		} else {
			printf(" - status: Recuperacao\n");
		}
	}
}

int main() {
	student_t students[5];
	
	printf("Seja bem vindo!");
	
	int _c = 1, qnt_s = 0;
	while (_c) {
		printf("\n");
		printf("1 - Adicionar estudante\n2 - Listar estudantes\n3 - Editar aluno\n0 - sair\n");
		printf("O que voce deseja fazer?: ");

		scanf("%d", &_c);

		if (!_c) return 0;
		
		switch (_c) {
			case 1:
				if (qnt_s == 5) {
					printf("Limite maximo de estudantes!\n");
					break;
				}
				
				register_student(&students[qnt_s]);
				qnt_s++;
				break;
			case 2:
				list_students(students, qnt_s);
				break;
			case 3:
				edit_student(students, qnt_s);
				break;
		}
	}
	
	return 0;
}

