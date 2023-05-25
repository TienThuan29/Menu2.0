#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h> 

int checkRepeatedUsername(char username[], char password[]);

bool writeIntoText (char username[], char password[]) {

	FILE* file;
    
		file = fopen("user.txt", "a");
		fprintf(file, username);
		fclose(file);

		file = fopen("user.txt", "a");
		fprintf(file ," , ");
		fclose(file);

		file = fopen("user.txt", "a");
		fprintf(file , password);
		fclose(file);

		file = fopen("user.txt", "a");
		fprintf(file, " , \n");
		fclose(file);

        return true;
}

bool checkUsername(char username[]) {
    int i = 0;

    if (strlen(username) == 0) { return false; }
    if (strlen(username) > 22) { return false; }
    if (username[0] >= '0' && username[0] <= '9') {
        return false;
    }
    else {
        if (!((username[i] >= '0' && username[i] <= '9') || (username[i] >= 'a' && username[i] <= 'z') || (username[i] >= 'A' && username[i] <= 'Z') || (username[i] == '_'))) {
            return false;
        }
        else {
            i = 1;
            for (i; i < strlen(username); i++) {
                if ((username[i] >= '0' && username[i] <= '9') || (username[i] >= 'a' && username[i] <= 'z') || (username[i] >= 'A' && username[i] <= 'Z') || (username[i] == '_')) {
                    continue;
                }
                else
                    return false;
            }
        }
    }
    return true;
}

bool checkRepeatPassword(char pass[], char repeatPass[]) {
    int i;
    if (strlen(pass) != strlen(repeatPass)) {
        return false;
    }
    else {
        for (i = 0; i < strlen(pass); i++) {
            if (pass[i] != repeatPass[i]) {
                return false;
                break;
            }
        }
    }
    return true;
}