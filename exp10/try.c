#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Global Variables
int z = 0, i = 0, j = 0, c = 0;

// Modify array size to increase 
// length of string to be parsed
char input[20], ac[20], stk[20], act[20], grammar[10][10];
int numProductions;

// Function to check whether the stack contains input production rule to be reduced
void check() {
    strcpy(ac, "REDUCE TO ");
    
    // Iterate through the input string
    for (z = 0; z < c; z++) {
        // Check for each production rule
        for (int p = 0; p < numProductions; p++) {
            int len = strlen(grammar[p]);
            if (strncmp(stk + z, grammar[p], len) == 0) {
                printf("%s%s", ac, grammar[p]);
                stk[z] = grammar[p][0];
                stk[z + 1] = '\0';
                printf("\n$%s\t%s$\t", stk, input);
                return;
            }
        }
    }
}

// Driver Function
int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    getchar(); // Clearing the newline character from the input buffer

    printf("Enter the productions:\n");
    for (int p = 0; p < numProductions; p++) {
        printf("Production %d: ", p + 1);
        fgets(grammar[p], sizeof(grammar[p]), stdin);
        // Remove the newline character if present
        if (grammar[p][strlen(grammar[p]) - 1] == '\n')
            grammar[p][strlen(grammar[p]) - 1] = '\0';
    }

    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);

    // Length of input string
    c = strlen(input) - 1;

    // Initializing action label
    strcpy(act, "SHIFT");

    // Printing column names
    printf("\nstack \t input \t action");
    // Printing initial values of stack and input
    printf("\n$\t%s$\t", input);

    // Iterating through the input string
    for (i = 0; j < c; i++, j++) {
        printf("%s", act); // Printing action
        stk[i] = input[j]; // Pushing into stack
        stk[i + 1] = '\0';
        input[j] = ' '; // Moving the pointer
        printf("\n$%s\t%s$\t", stk, input); // Printing action
        check(); // Check if any production rule can be reduced
    }

    check(); // Rechecking if any valid production exists

    // If top of the stack is the starting symbol, then accept the input
    if (stk[0] == grammar[0][0] && stk[1] == '\0')
        printf("Accept\n");
    else
        printf("Reject\n"); // Otherwise, reject
}
