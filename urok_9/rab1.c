//это код для 2 задания

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *inputFile, *outputFile;
    char inputString[1001];
    char outputString[1001];
    int i = 0;
    inputFile = fopen("input.txt", "r");

    fscanf(inputFile, "%s", inputString);
    fclose(inputFile);
    printf("%s ", inputString);
    while (inputString[i] != '\0') {
        printf("%c ", inputString[i]);
        if (islower(inputString[i])) {
            outputString[i] = (inputString[i] == 'a') ? 'b' : inputString[i]; 
        }else if (islower(inputString[i])) {
            outputString[i] = (inputString[i] == 'b') ? 'a' : inputString[i];
        } 
        if (isupper(inputString[i])) {
            outputString[i] = (inputString[i] == 'A') ? 'B' : inputString[i];
        }else if (isupper(inputString[i])) {
            outputString[i] = (inputString[i] == 'B') ? 'A' : inputString[i];
        }

        i++;
    }

    outputFile = fopen("output.txt", "w");
    fprintf(outputFile, "%s\n", outputString);
    printf("%s", outputString);
    fclose(outputFile);
    return 0;
}
