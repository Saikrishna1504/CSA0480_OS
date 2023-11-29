#include <stdio.h>
#include <stdlib.h>

int main() {
    // Creating a new file
    FILE *fp = fopen("file.txt", "w");
    if (fp == NULL) {
        printf("Error creating file\n");
        exit(1);
    }
    fprintf(fp, "Hello, world!\n");
    fclose(fp);

    // Opening an existing file
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char buffer[100];
    fgets(buffer, 100, fp);
    printf("File contents: %s", buffer);
    fclose(fp);

    // Writing data to a file
    fp = fopen("file.txt", "a");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "This is a new line\n");
    fclose(fp);

    // Reading data from an existing file
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while (fgets(buffer, 100, fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);

    // Moving data to a specific location on the file
    fp = fopen("file.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fseek(fp, 7, SEEK_SET);
    fprintf(fp, "WORLD");
    fclose(fp);

    // Deleting a file
    if (remove("file.txt") == 0) {
        printf("File deleted successfully\n");
    } else {
        printf("Error deleting file\n");
    }

    return 0;
}
