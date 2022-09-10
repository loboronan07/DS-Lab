/* Samuel wants to store the data of his employees, which includes the following
	fields: 
	(i) Name of the employee 
	(ii) Date of birth which is a collection of {day, month, year} 
	(iii) Address which is a collection of {house number, zip code and
			state}. 
	Write a 'C' program to read and display the data of N employees using
	pointers to array of structures.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int day;
	int month;
	int year;
} DOB;

typedef struct {
	int house_number;
	int zip;
	char *state;
} ADDRESS;

typedef struct {
	char *name;
	DOB dob;
	ADDRESS address;
} EMPLOYEE;

EMPLOYEE* read_employee_info();
void display_employee_info(EMPLOYEE* student);
void free_employees(EMPLOYEE** employees, int n);

int main() {
	int n;

	printf("Enter the number of employees: ");
	scanf("%d", &n);

	EMPLOYEE** employees = (EMPLOYEE**) calloc(n, sizeof(EMPLOYEE*));

	printf("\n========= Enter Employee Details ========\n\n");
	for(int i=0; i<n; i++) {
		printf("----- Employee %2d-----\n", i+1);
		employees[i] = read_employee_info();
		printf("\n");
	}

	printf("\n\n========= Employee Details ========\n\n");
	for(int i=0; i<n; i++) {
		display_employee_info(employees[i]);
	}

	free_employees(employees, n);

	return 0;
}

EMPLOYEE* read_employee_info() {
	char name[50], state[20];
	EMPLOYEE* employee = (EMPLOYEE*) malloc(sizeof(EMPLOYEE));

	printf("Name: ");
	scanf(" %[^\n]s", name);
	printf("Date of Birth(dd mm yyyy): ");
	scanf("%d %d %d", &employee->dob.day, &employee->dob.month, &employee->dob.year);
	printf("Address(house_number zip_code state): ");
	scanf("%d %d %s", &employee->address.house_number, &employee->address.zip, state);

	char *name_ = (char*) calloc(strlen(name)+1, sizeof(char));
	strcpy(name_, name);

	char *state_ = (char*) calloc(strlen(state)+1, sizeof(char));
	strcpy(state_, state);

	employee->name = name_;
	employee->address.state = state_;

	return employee; 
}

void display_employee_info(EMPLOYEE* employee) {
	printf("Name: %s\n", employee->name);
	printf("Date of Birth: %d:%d:%d\n", employee->dob.day, employee->dob.month, employee->dob.year);
	printf("Address: House Number %d, Zip - %d, %s\n\n", employee->address.house_number, employee->address.zip, employee->address.state);
}

void free_employees(EMPLOYEE** employees, int n) {
	for(int i=0; i<n; i++) {
		free(employees[i]->address.state);
		free(employees[i]->name);
		free(employees[i]);
	}
	free(employees);
}
