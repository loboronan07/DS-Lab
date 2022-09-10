/* Write a C program to implement the following functions. Use pointers and
	dynamic memory management functions.
	i. To read one Student object where Student is a structure with name, roll
		number and CGPA as the data members
	ii. To display one Student object
	iii. To sort an array of Student structures according to the roll number.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *name;
	int roll_no;
	float CGPA;
} STUDENT;

STUDENT* read_student_info();
void display_student_info(STUDENT* student);
void sort_students(STUDENT** students, int n);

int main(void) {
	int n;

	printf("Enter the number of students: ");
	scanf("%d", &n);

	STUDENT** students = (STUDENT**) calloc(n, sizeof(STUDENT*));

	printf("\n========= Enter Student Details ========\n\n");
	for(int i=0; i<n; i++) {
		printf("----- Student %2d-----\n", i+1);
		students[i] = read_student_info();
		printf("\n");
	}

	printf("\n\n========= Student Details ========\n\n");
	for(int i=0; i<n; i++) {
		display_student_info(students[i]);
	}

	sort_students(students, n);

	printf("\n\n========= Student Details (Sorted By Roll No) ========\n\n");
	for(int i=0; i<n; i++) {
		display_student_info(students[i]);
	}

	for(int i=0; i<n; i++) {
		free(students[i]->name);
		free(students[i]);
	}
	free(students);

	return 0;
}

STUDENT* read_student_info() {
	char name[50];
	STUDENT* student = (STUDENT*) malloc(sizeof(STUDENT));

	printf("Roll No: ");
	scanf("%d", &student->roll_no);
	printf("Name: ");
	scanf("%s", name);
	printf("CGPA: ");
	scanf("%f", &student->CGPA);

	char *name_ = (char*) calloc(strlen(name)+1, sizeof(char));
	strcpy(name_, name);

	student->name = name_;

	return student; 
}

void display_student_info(STUDENT* student) {
	printf("Roll No: %d\n", student->roll_no);
	printf("Name: %s\n", student->name);
	printf("CGPA: %.2f\n\n", student->CGPA);
}

void sort_students(STUDENT** students, int n) {
	STUDENT* temp;

	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-i-1; j++) {
			if(students[j]->roll_no > students[j+1]->roll_no) {
				temp = students[j];
				students[j] = students[j+1];
				students[j+1] = temp;
			}
		}
	}

	return;
}