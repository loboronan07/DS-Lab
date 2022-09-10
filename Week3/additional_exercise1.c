/* Design an application using suitable data structure to automate the process of class
	representative election. The application should take the inputs – No of students(voters)
	present in the class and No of Candidates and their name(s). During the voting process,
	the faculty on duty of conduction of election, need to initiate the voting (say by pressing
	a particular key during which a beep sound is heard). Then, a student can come and cast
	his/her vote against the candidate by entering the candidate’s serial number. After
	casting a vote, a beep sound is given to confirm that the voting is done. This process is
	repeated until all students cast their vote. At the end, the total votes obtained by each
	candidate should be displayed along with number of foul votes. the candidate who has
	won the maximum number of votes should be declared as class representative. 
	(Hint:	Use array of integers with array index as candidate number) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int n;
	int *votes;
} VOTERS;

typedef struct {
	int n;
	int *votes;
	char **names;
} CANDIDATES;

CANDIDATES* get_candidates();
VOTERS* get_voters();
void get_votes(VOTERS* voters, CANDIDATES* candidates);
char** init_strings_arr(int n);
char* copy_string(char* name);
void display_candidates(CANDIDATES* candidates);
void count_votes(VOTERS* voters, CANDIDATES* candidates);
void display_winner(CANDIDATES* candidates);
void free_candidates(CANDIDATES* candidates);
void free_voters(VOTERS* voters);

int main(void) {
	VOTERS* voters = get_voters();
	CANDIDATES* candidates = get_candidates();
	printf("\n\n\n\n\n\n");
	get_votes(voters, candidates);
	count_votes(voters, candidates);
	display_winner(candidates);
	
	free_voters(voters);
	free_candidates(candidates);
	return 0;
}

CANDIDATES* get_candidates() {
	CANDIDATES* candidates = (CANDIDATES *) malloc(sizeof(CANDIDATES));
	char name[100];
	
	printf("Enter number of candidates: ");
	scanf("%d", &candidates->n);
	printf("\n");
	
	char **names = (char **) calloc(candidates->n, sizeof(char *));
	
	for(int i=0; i < candidates->n; i++) {
		printf("Enter name of candidate %3d: ", i+1);
		scanf("%s", name);
		
		names[i] = copy_string(name);
	}
	
	candidates->votes = (int *) calloc(candidates->n, sizeof(int));
	candidates->names = names;
	
	return candidates;
}

VOTERS* get_voters() {
	VOTERS* voters = (VOTERS *) malloc(sizeof(VOTERS));
	
	printf("Enter the number of voters: ");
	scanf("%d", &voters->n);
	
	voters->votes = (int *) calloc(voters->n, sizeof(int));
	
	return voters;
}

void get_votes(VOTERS* voters, CANDIDATES* candidates) {
	char ch;
	printf("Enter y to start voting: ");
	do {
		scanf("%c", &ch);
	} while(ch != 'y');
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("============================================\n");
	printf("                 Start Voting\n");
	printf("============================================\n\n\n");
	
	for(int i=0; i < voters->n; i++) {
		display_candidates(candidates);
		printf("Voter %d can cast his/her vote: ", i+1);
		scanf("%d", &voters->votes[i]);
		while(!(voters->votes[i] >= 0 && voters->votes[i] < candidates->n)) {
			printf("\nInvalid Vote....\nTry entering again: ");
			scanf("%d", &voters->votes[i]);
		}
		printf("\a");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
}

char* copy_string(char* name) {
	int size = strlen(name);
	char *str = (char *) calloc(size+1, sizeof(char *));
	strcpy(str, name);
	return str;
}

void display_candidates(CANDIDATES* candidates) {
	printf("============== CANDIDATE LIST ==============\n");
	printf("\n\tSl.No.\t\tName\n\n");
	for(int i=0; i < candidates->n; i++) {
		printf("\n\t%3d\t\t%s", i, candidates->names[i]);
	}
	printf("\n\n");
}

void count_votes(VOTERS* voters, CANDIDATES* candidates) {
	for(int i=0; i < voters->n; i++) {
		candidates->votes[voters->votes[i]]++;
	}
}
void display_winner(CANDIDATES* candidates) {
	char *winner;
	int max_votes;
	
	winner = candidates->names[0];
	max_votes = candidates->votes[0];
	printf("\n\n============================================\n");
	printf("\tName \t\t Votes\n");
	for(int i=0; i < candidates->n; i++) {
		printf("\t%s \t\t %d\n", candidates->names[i], candidates->votes[i]);
		if(candidates->votes[i] > max_votes) {
			winner = candidates->names[i];
			max_votes = candidates->votes[i];
		}
	}
	printf("\n\n============================================\n");
	printf("\t   Winner is %s\n",  winner);
	printf("============================================\n");
}

void free_candidates(CANDIDATES* candidates) {
	for(int i=0; i < candidates->n; i++) {
		free(candidates->names[i]);
	}
	free(candidates->names);
	free(candidates->votes);
	free(candidates);
}

void free_voters(VOTERS* voters) {
	free(voters->votes);
	free(voters);
}		
