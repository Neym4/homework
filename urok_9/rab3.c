#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000
#define MAX_NUMBERS 100

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    char str[MAX_CHARS];
    int numbers[MAX_NUMBERS];
    int num_count = 0;

    FILE *file = fopen("input.txt", "r");

    fgets(str, MAX_CHARS, file);
    fclose(file);

    char *token = strtok(str, " ");
    while (token != NULL && num_count < MAX_NUMBERS) {
        if (sscanf(token, "%d", &numbers[num_count]) == 1) {
            num_count++;
        }
        token = strtok(NULL, " ");
    }
    qsort(numbers, num_count, sizeof(int), compare);
    file = fopen("output.txt", "w");
    for (int i = 0; i < num_count; i++) {
        fprintf(file, "%d ", numbers[i]);
    }
    fclose(file);
    return 0;
}
