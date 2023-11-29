#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

struct File {
    char filename[50];
};

struct Directory {
    struct File files[MAX_FILES];
    int numFiles;
};

void createFile(struct Directory *dir, const char *filename) {
    if (dir->numFiles < MAX_FILES) {
        strcpy(dir->files[dir->numFiles].filename, filename);
        dir->numFiles++;
        printf("File '%s' created in the directory.\n", filename);
    } else {
        printf("Directory is full. Cannot create file '%s'.\n", filename);
    }
}

void listFiles(const struct Directory *dir) {
    printf("Files in the directory:\n");
    for (int i = 0; i < dir->numFiles; ++i) {
        printf("%d. %s\n", i + 1, dir->files[i].filename);
    }
}

int main() {
    struct Directory rootDirectory;
    rootDirectory.numFiles = 0;

    while (1) {
        printf("\n1. Create File\n");
        printf("2. List Files\n");
        printf("3. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename: ");
                char filename[50];
                scanf("%s", filename);
                createFile(&rootDirectory, filename);
                break;
            case 2:
                listFiles(&rootDirectory);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}
