#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int checkRepeatedUsername(char username[]) {
    FILE* file;
    int m;

    bool check = false;
    char buffer[100][50] = { NULL }; 
    int i = 0;

    file = fopen("user.txt", "r");
    //if (strlen(username) == 0) return 1;               // fix loi 'space' , 'space' trong file user.txt cho phan dang nhap
    while (fgets(buffer[i], 100, file)) {
        buffer[i][strcspn(buffer[i], "\n")] = '\0';
        i++;
    }
    fclose(file);

    int lineBuffer;
    int indxBuffer;

    for (lineBuffer = 0; lineBuffer < i; lineBuffer++) {
        int j = 0;
        int numChar = 0;
        char tempUser[30] = { 0 };
        for (indxBuffer = 0; indxBuffer <= strlen(buffer[lineBuffer]); indxBuffer++) {
            if (buffer[lineBuffer][indxBuffer] == 32) { break; }
            else {
                tempUser[j] = buffer[lineBuffer][indxBuffer];
                j++;
            }
        }
        int check = strcmp(username, tempUser);
        if (check == 0) { return 0;  }
        int m;
        for (m = 0; m <= j; m++) {
            tempUser[m] = '\0';
        }
    }
    return 1;
} 


