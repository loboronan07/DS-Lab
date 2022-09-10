/* Create a structure STUDENT consisting of variables of structures:
	i. DOB {day, month (use pointer), year},
	ii. STU_INFO {reg_no, name(use pointer), address},
	iii. COLLEGE {college_name (use pointer), university_name}
		where structure types from i to iii are declared outside the STUDENT independently.
	Show how to read and display member variables of DOB type if pointer variable is
	created for DOB inside STUDENT and STUDENT variable is also a pointer variable.
	The program should read and display the values of all members of STUDENT structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int day;
	char *month;
	int year;
} DOB;

typedef struct {
	int reg_no;
	char *name;
	char *address;
} STU_INFO;

typedef struct {
	char *college;
	char *university;
} COLLEGE;

typedef struct {
	STU_INFO* info;
	DOB* dob;
	COLLEGE* college;
} STUDENT;

STUDENT* read_student_info();
void display_student_info(STUDENT* student);
void free_students(STUDENT** students, int n);

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
		printf("\n");
	}

	free_students(students, n);

	return 0;
}


STUDENT* read_student_info() {
	char name[50], address[200], month[10], college[100], university[100];
	
	STUDENT* student = (STUDENT*) malloc(sizeof(STUDENT));
	student->info = (STU_INFO*) malloc(sizeof(STU_INFO));
	student->dob = (DOB*) malloc(sizeof(DOB));
	student->college = (COLLEGE*) malloc(sizeof(COLLEGE));
	printf("Registration No: ");
	scanf("%d", &student->info->reg_no);
	printf("Name: ");
	scanf(" %[^\n]s", name);
	printf("Address: ");
	scanf(" %[^\n]s", address);
	printf("Date of Birth(dd month yyyy): ");
	scanf("%d %s %d", &student->dob->day, month, &student->dob->year);
	printf("College Name: ");
	scanf(" %[^\n]s", college);
	printf("University Name: ");
	scanf(" %[^\n]s", university);

	char *name_ = (char*) calloc(strlen(name)+1, sizeof(char));
	strcpy(name_, name);
	char *address_ = (char*) calloc(strlen(address)+1, sizeof(char));
	strcpy(address_, address);
	char *month_ = (char*) calloc(strlen(month)+1, sizeof(char));
	strcpy(month_, month);
	char *college_ = (char*) calloc(strlen(college)+1, sizeof(char));
	strcpy(college_, college);
	char *university_ = (char*) calloc(strlen(university)+1, sizeof(char));
	strcpy(university_, university);

	student->info->name = name_;
	student->dob->month = month_;
	student->info->address = address_;
	student->college->college = college_;
	student->college->university = university_;

	return student; 
}

void display_student_info(STUDENT* student) {
	printf("Registration No: %d\n", student->info->reg_no);
	printf("Name: %s\n", student->info->name);
	printf("Address: %s\n", student->info->address);
	printf("Date of Birth: %d %s %d\n", student->dob->day, student->dob->month, student->dob->year);
	printf("College Name: %s\n", student->college->college);
	printf("University Name: %s\n", student->college->university);
}

void free_students(STUDENT** students, int n) {
	for(int i=0; i<n; i++) {
		free(students[i]->dob->month);
		free(students[i]->info->name);
		free(students[i]->info->address);
		free(students[i]->college->college);
		free(students[i]->college->university);
		free(students[i]->dob);
		free(students[i]->info);
		free(students[i]->college);
		free(students[i]);
	}
	free(students);
}
