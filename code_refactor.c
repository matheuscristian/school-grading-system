/*
COMPILED AND TESTED WITH WINDOWS GCC 13.2!
COMPILADO E TESTADO COM WINDOWS GCC 13.2!
*/

#include <stdio.h>
#include <locale.h>

struct Student
{
	double grades[4];
	double total;
};

int menu();

void register_student(struct Student *students, int size);
void     edit_student(struct Student *students, int size);
void    list_students(struct Student *students, int size);

int main() {
	setlocale(LC_ALL, "");

	struct Student students[5];
	int students_size = 0;

	int action = -1;
	while (action) {
		action = menu();

		switch (action)
		{
			case 1:
				if (students_size == 5) {
					printf("Limite de 5 estudantes atingido!\n");
					break;
				}

				students_size++;
				register_student(students, students_size);
				break;
			
			case 2:
				if (!students_size) {
					wprintf(L"Não há estudantes cadastrados!\n");
					break;
				}

				edit_student(students, students_size);
				break;

			case 3:
				if (!students_size) {
					wprintf(L"Não há estudantes cadastrados!\n");
					break;
				}

				list_students(students, students_size);
				break;
			
			case 0:
				return 0;
				break;
		}
	}

	return 0;
}

int menu() {
	wprintf(L"AÇÕES: \n");
	printf("1 --> Registrar estudante\n");
	printf("2 --> Editar estudante\n");
	printf("3 --> Listar estudantes\n");
	printf("0 --> Sair\n");
	printf("> ");

	int action;
	scanf("%d", &action);

	return action;
}

void register_student(struct Student *students, int size) {
	students[size - 1].total = 0;
	for (int i = 0; i < 4; i++) {
		printf("Digite a nota (%d) do estudante: ", i + 1);
		scanf("%lf", &students[size - 1].grades[i]);

		if (students[size - 1].grades[i] < 0) {
			students[size - 1].grades[i] = 0;
		} else if (students[size - 1].grades[i] > 10) {
			students[size - 1].grades[i] = 10;
		}

		students[size - 1].total += students[size - 1].grades[i];
	}
}

void edit_student(struct Student *students, int size) {	
	int index = 100;
	while (index < 1 || index > size) {
		wprintf(L"Qual estudante você deseja editar? (1-%d): ", size);
		scanf("%d", &index);
	}

	register_student(students, index);
}

void list_students(struct Student *students, int size) {
	for (int i = 0; i < size; i++) {
		double avg = students[i].total / 4;
		wprintf(L"Estudante %d - Notas: %lf %lf %lf %lf - Total: %lf - Média: %lf", i, students[i].grades[0], students[i].grades[1], students[i].grades[2], students[i].grades[3], students[i].total, avg);

		if (avg < 4) {
			printf(" - Status: Reprovado\n");
		} else if (avg > 6) {
			printf(" - Status: Aprovado\n");
		} else {
			wprintf(L" - Status: Recuperação\n");
		}
	}
}
