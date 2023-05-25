#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int checkPassword(char username[], char pass[]) {
    FILE* file;
    char buffer[100][100] = {0};
    int i = 0;

    file = fopen("user.txt", "r");

    while (fgets(buffer[i], 100, file)) {
        buffer[i][strcspn(buffer[i], "\n")] = '\0';
        i++;
    }

    int lineBuffer;

    for (lineBuffer = 0; lineBuffer < i; lineBuffer++) {
        char tempUser[30] = {0};
        int indxBuffer;
        char tempLine[30] = {0};

        strcpy(tempLine, buffer[lineBuffer]);
        for (indxBuffer = 0; indxBuffer <= strlen(tempLine); indxBuffer++) {
            int j = 0;
            int c = tempLine[indxBuffer];
            if (c == 32) { break; }
            else {
                tempUser[indxBuffer] = tempLine[indxBuffer];
                j++;
            }
        }

        char tempPass[30] = {0};
        int checkUser = strcmp(username, tempUser);
        int indx2;

        if (checkUser == 0) {
            int n = 0;
            for (indx2 = strlen(tempUser) + 3; indx2 <= strlen(tempLine); indx2++) {
                int c = tempLine[indx2];
                if (c == 32) { break; }
                else {
                    tempPass[n] = tempLine[indx2];
                    n++;
                }
            }
            int checkPass = strcmp(pass, tempPass);
            if (checkPass == 0) {
                return 0;
            }
            else { 
                return 1; 
                break;
            }
        }
    }
   
    return 0;
}

