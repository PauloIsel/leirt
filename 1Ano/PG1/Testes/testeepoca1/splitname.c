#include <stdio.h>

int countwords (const char str[]) {
    int count = 0;

    for(int k = 0; str[k] != '\0'; k++) {
        if(str[k] != ' ' && (str[k+1] == ' ' || str[k+1] == '\0')) {
            count++;
            
        }
    }

    return count;
}

int charlength(const char str[]) {
    int count = 0;
    for(int i = 0; str[i]!= '\0'; i++) {
        count++;
    }
    return count;
}
void splitName(const char name[], char lastName[], char restOfName[]) {
    int nameLength = countwords(name);
    int currentlength = 0;
    int FullnameLength = charlength(name);

    for(int i = 0, j = 0; name[i] != '\0'; i++) {
        restOfName[j++] = name[i];

        if(name[i] != ' ' && name[i+1] == ' ' ) {
            currentlength++;
        }
        if(currentlength == nameLength - 1) {
            restOfName[j] = '\0';
            int startoflastname = j + 1;
            int lastNameLength = FullnameLength - startoflastname;

            for (int k = 0; k < lastNameLength; k++) {
                lastName[k] = name[startoflastname + k];
            }
            lastName[lastNameLength] = '\0'; 
            break;
        } 
    }

}

int main() {
    char name[] = "Luis Filipe M Caeiro Figo";
    char lastName[50];
    char restOfName[50];
    splitName("Luis Filipe M Caeiro Figo", lastName, restOfName);
    printf("%s\n", lastName);
    printf("%s\n", restOfName);

}