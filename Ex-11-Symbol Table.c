#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100  
struct SymTableEntry {
    char name[50];   // Name of the variable
    int value;       // Value stored in the variable
} table[SIZE];

int count = 0;    // Count of the number of entries in the Symbol Table
int i;
// Function to check if an element is already present in the Symbol Table
int isPresent(char* name) {
    for(i = 0; i < count; i++) {
        if(strcmp(table[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to add an element to the Symbol Table
void addSymbol(char* name, int value) {
    if(count >= SIZE) {
        printf("Symbol Table is Full!\n");
        return;
    } 
    if(isPresent(name)) {
        printf("Variable %s is already present in the Symbol Table!\n", name);
        return;
    }
    strcpy(table[count].name, name);
    table[count].value = value;
    count++;
    printf("Variable %s with value %d added to the Symbol Table!\n", name, value);
}

// Function to search for an element in the Symbol Table
void searchSymbol(char* name) {
    for(i = 0; i < count; i++) {
        if(strcmp(table[i].name, name) == 0) {
            printf("Variable %s found in Symbol Table with value %d!\n", name, table[i].value);
            return;
        }
    }
    printf("Variable %s not found in the Symbol Table!\n", name);
}

// Function to delete an element from the Symbol Table
void deleteSymbol(char* name) {
    int found = 0;
    int j;
    for(i = 0; i < count; i++) {
        if(strcmp(table[i].name, name) == 0) {
            found = 1;
            for(j = i; j < count - 1; j++) {
                strcpy(table[j].name, table[j+1].name);
                table[j].value = table[j+1].value;
            }
            count--;
            printf("Variable %s with value %d has been deleted from the Symbol Table!\n", name, table[i].value);
            break;
        }
    }
    if(!found) {
        printf("Variable %s not found in the Symbol Table!\n", name);
    }
}

// Driver function
int main() {
    int choice, value;
    char name[50];

    while(1) {
        printf("Symbol Table Operations:\n");
        printf("1. Add Variable\n2. Search Variable\n3. Delete Variable\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the Variable and its value: ");
                scanf("%s%d", name, &value);
                addSymbol(name, value);
                break;
            case 2:
                printf("Enter the name of the Variable: ");
                scanf("%s", name);
                searchSymbol(name);
                break;
            case 3:
                printf("Enter the name of the Variable: ");
                scanf("%s", name);
                deleteSymbol(name);
                break;
            case 4:
                exit(0);   // Exit the program on choice 4
            default:
                printf("Invalid choice entered!\n");
        }
    }
    return 0;
}
