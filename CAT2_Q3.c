
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void writeIntegers();
void processIntegers();
void displayFiles();
// main function 
int main() {
    writeIntegers();    
    processIntegers();  
    displayFiles();      
    return 0;
}

void writeIntegers() {
    FILE *fp;
    int num, i;

    fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("Error opening input.txt for writing.\n");
        exit(1);
    }

    printf("Please enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &num);
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
    printf("Integers successfully saved to input.txt.\n\n");
}

// Step 2: Read integers, compute sum and average, and write to output.txt
void processIntegers() {
    FILE *inFile, *outFile;
    int num, sum = 0, count = 0;
    float avg;

    inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        printf("Error opening input.txt for reading.\n");
        exit(1);
    }

    while (fscanf(inFile, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(inFile);

    if (count == 0) {
        printf("Error: No integers found in input.txt.\n");
        exit(1);
    }

    avg = (float)sum / count;

    outFile = fopen("output.txt", "w");
    if (outFile == NULL) {
        printf("Error opening output.txt for writing.\n");
        exit(1);
    }

    fprintf(outFile, "Sum = %d\nAverage = %.2f\n", sum, avg);
    fclose(outFile);

    printf("Sum and average successfully written to output.txt.\n\n");
}

// Step 3: Display the contents of both files
void displayFiles() {
    FILE *fp;
    char ch;

    printf("Contents of input.txt:\n----------------------\n");
    
   fp = fopen("input.txt", "r");
   if (fp == NULL) {
       printf("Error opening input.txt.\n");
       exit(1);
   }
   
   while ((ch = fgetc(fp)) != EOF)
       putchar(ch);
   fclose(fp);

   printf("\n\nContents of output.txt:\n-----------------------\n");

   fp = fopen("output.txt", "r");
   if (fp == NULL) {
       printf("Error opening output.txt.\n");
       exit(1);
   }
   
   while ((ch = fgetc(fp)) != EOF)
       putchar(ch);
   fclose(fp);

   printf("\n");
}

