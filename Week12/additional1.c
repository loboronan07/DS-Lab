/* Additional Exercise 1
    Phone book application for student records using roll number as key: Implement a
    menu driven program to create a phone book for student records where in each
    student record will contain roll-no, name, section, CGPA and phone number. The
    phone book must have an option to search for a record based on roll no of the
    student. Search is done using a Binary Search Tree
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roll;
    char* name;
    char section;
    float CGPA;
    long phone;
} student;

typedef struct node {
	student data;
	struct node* left;
	struct node* right;
} node;

void insert(node**, node*);
void search(node*, int);
node* getnode(int, char*, char, float, long);
void inorder(node*);
void freetree(node*);

int main() {
    node *root = NULL, *temp;
    int roll, choice;
    char name[30], section;
    float cgpa;
    long phone;


    printf("Available Operations on Phone Book: ");
    printf("\n\t1. Insert Student Data");
    printf("\n\t2. Search for Student");
    printf("\n\t3. Display Sorted");
    printf("\n\t4. Exit");
    printf("\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter Student Details:\n");
            printf("\tRoll No: ");
            scanf("%d", &roll);
            printf("\tName: ");
            scanf(" %[^\n]s", name);
            printf("\tSection: ");
            scanf(" %c", &section);
            printf("\tCGPA: ");
            scanf("%f", &cgpa);
            printf("\tPhone Number: ");
            scanf("%ld", &phone);

            temp = getnode(roll, name, section, cgpa, phone);
            insert(&root, temp);
        }
        else if(choice == 2) {
            printf("Enter the roll no of the student to search: ");
            scanf("%d", &roll);
            search(root, roll);
        }
        else if(choice == 3) {
            if(!root) 
                printf("\nPhone Book Empty...\n");
            else {
                printf("\nPhone Book Records in Sorted Order: \n");
                inorder(root);
            }
        }
        else if(choice == 4)
            break;
        else 
            printf("Invalid Operation... Try Again...\n");
    }

    freetree(root);

	return 0;
}

node* getnode(int roll, char* name, char section, float cgpa, long phone) {
    node* new = (node*) malloc(sizeof(node));
    new->data.roll = roll;
    new->data.name = (char*) calloc(strlen(name)+1, sizeof(char));
    strcpy(new->data.name, name);
    new->data.section = section;
    new->data.CGPA = cgpa;
    new->data.phone = phone;
    new->left = new->right = NULL;
    return new;
}

void insert(node** root, node* item) {
	if(*root == NULL) {
		*root = item;
		return;
	}

	node* prev = NULL, *curr = *root;
	while(curr != NULL) {
		if(curr->data.roll == item->data.roll) {
			free(item);
			return;
		}
		else if(curr->data.roll > item->data.roll) {
			prev = curr;
			curr = curr->left;
		}
		else {
			prev = curr;
			curr = curr->right;
		}
	}

	if(prev->data.roll > item->data.roll) 
		prev->left = item;
	else
		prev->right = item;
} 

void inorder(node* root) {
	if(!root) 
		return;

    inorder(root->left);

    printf("\n\tRoll No: %d", root->data.roll);
    printf("\n\tName: %s", root->data.name);
    printf("\n\tSection: %c", root->data.section);
    printf("\n\tCGPA: %f", root->data.CGPA);
    printf("\n\tPhone Number: %ld", root->data.phone);
    printf("\n");
    
	inorder(root->right);
}

void search(node* root, int roll) {
    node* curr = root;
    while(curr) {
        if(curr->data.roll == roll) 
            break;
        curr = roll < curr->data.roll ? curr->left : curr->right;
    }

    if(curr) {
        printf("\nInfo on Student with Roll No %d: ", roll);
        printf("\n\tName: %s", curr->data.name);
        printf("\n\tSection: %c", curr->data.section);
        printf("\n\tCGPA: %f", curr->data.CGPA);
        printf("\n\tPhone Number: %ld", curr->data.phone);
        printf("\n");
    }
    else 
        printf("\nThe requested Student's Details are not in the phonebook...\n");
}

void freetree(node* root) {
	if(!root) 
		return;

	freetree(root->left);
	freetree(root->right);

    free(root->data.name);
	free(root);
}