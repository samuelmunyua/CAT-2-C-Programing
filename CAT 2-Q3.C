#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void writeInputFile();
void processFile();
void displayFiles();

int main() {
    writeInputFile();   // Step 1: Get integers and write to input.txt
    processFile();      // Step 2: Read, calculate sum and average, and write to output.txt
    displayFiles();     // Step 3: Display both files

    return 0;
}

// Function 1: Prompts user to input 10 integers and writes them to "input.txt"
void writeInputFile() {
    FILE *file;
    int numbers[10];

    file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error: Could not create input.txt file.\n");
        exit(1);
    }
    int num;
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        fprintf(file, "%d ", numbers[i]);
    }

    fclose(file);
    printf("\nData successfully written to input.txt\n\n");
}

// Function 2: Reads integers from "input.txt", computes sum and average, and writes to "output.txt"
void processFile() {
    FILE *inFile, *outFile;
    int num, count = 0, sum = 0;
    float average;

    inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        printf("Error: Could not open input.txt for reading.\n");
        exit(1);
    }

    while (fscanf(inFile, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(inFile);

    if (count == 0) {
        printf("Error: No data found in input.txt.\n");
        exit(1);
    }

    average = (float)sum / count;

    outFile = fopen("output.txt", "w");
    if (outFile == NULL) {
        printf("Error: Could not create output.txt file.\n");
        exit(1);
    }

    fprintf(outFile, "Sum = %d\nAverage = %.2f\n", sum, average);
    fclose(outFile);

    printf("Results successfully written to output.txt\n\n");
}

// Function 3: Reads and displays the contents of both files
void displayFiles() {
    FILE *file;
    char ch;

    printf("----- Contents of input.txt -----\n");
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input.txt for display.\n");
        exit(1);
    }
    while ((ch = fgetc(file)) != EOF)
        putchar(ch);
    fclose(file);

    printf("\n\n----- Contents of output.txt -----\n");
    file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open output.txt for display.\n");
        exit(1);
    }
    while ((ch = fgetc(file)) != EOF)
        putchar(ch);
    fclose(file);

    printf("\n---------------------------------\n");
}