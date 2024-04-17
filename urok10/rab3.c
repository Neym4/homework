#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void changeFileExtension(char *inputFilename, char *outputFilename) {
    FILE *inputFile, *outputFile;
    char address[256]; 
    char *newAddress;
    int len;

    inputFile = fopen(inputFilename, "r");
    outputFile = fopen(outputFilename, "w");

    fgets(address, sizeof(address), inputFile);
    fclose(inputFile);

    newAddress = strrchr(address, '.');
    if (newAddress != NULL) {
        len = newAddress - address;
    } else {
        len = strlen(address);
        newAddress = address + len;
    }

    strcpy(newAddress, ".html");
    fprintf(outputFile, "%s", address);
    fclose(outputFile);
}

int main() {
    char inputFilename[] = "address.txt";
    char outputFilename[] = "output_address.txt";

    changeFileExtension(inputFilename, outputFilename);
    return 0;
}
