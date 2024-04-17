#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void removeExtraSpaces(char *inputFilename, char *outputFilename) {
    FILE *inputFile, *outputFile;
    char c, prevChar = '\0';

    inputFile = fopen(inputFilename, "r");
    outputFile = fopen(outputFilename, "w");

    while ((c = fgetc(inputFile)) != EOF) {
        if (isspace(c)) {
            if (!isspace(prevChar)) {
                fputc(c, outputFile);
            }
        } else {
            fputc(c, outputFile);
        }
        prevChar = c;
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    char inputFilename[] = "input.txt"; 
    char outputFilename[] = "output.txt"; 

    removeExtraSpaces(inputFilename, outputFilename);

    return 0;
}
