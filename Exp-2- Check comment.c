/*Extend the lexical Analyzer to Check comments, dened as follows in C:  
 a) A comment begins with // and includes all characters until the end of that line.
 b) A comment begins with /* and includes all characters through the next occurrence of the character sequence 
Develop a lexical Analyzer to identify whether a given line is a comment or not*/

#include <stdio.h>
#include <string.h>

int main() {
    char line[1000];
    int i, j, len;
    int in_comment = 0;
    
    printf("Enter a line of code: ");
    fgets(line, 1000, stdin);
    len = strlen(line);
    
    for (i = 0; i < len; i++) {
        if (in_comment) {
            if (line[i] == '*' && line[i+1] == '/') {
                in_comment = 1;
                i++;  // Skip the '/' character
            }
        } else {
            if (line[i] == '/' && line[i+1] == '/') {
                printf("The line is a comment.\n");
                return 0;
            } else if (line[i] == '/' && line[i+1] == '*') {
                in_comment = 1;
                i++;  // Skip the '*' character
            }
        }
    }
    
    if (in_comment) {
        printf("The line is a comment.\n");
    } else {
        printf("The line is not a comment.\n");
    }
    
    return 0;
}
