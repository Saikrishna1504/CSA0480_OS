#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRECTORIES 100
#define MAX_FILES 100

struct File {
    char filename[50];
};

struct Directory {
    char dirname[50];
    struct File files[MAX_FILES];
    int numFiles;
};

struct RootDirectory {
    struct Directory directories[MAX_DIRECTORIES];
    int numDirectories;
};

void createDirectory(struct RootDirectory *rootDir, const char *dirname) {
    if (rootDir->numDirectories < MAX_DIRECTORIES) {
        strcpy(rootDir->directories[rootDir->numDirectories].dirname, dirname);
        rootDir->directories[rootDir->numDirectories].numFiles = 0;
        rootDir->numDirectories++;
        printf("Directory '%s' created in the root directory.\n", dirname);
    } else {
        printf("Root directory is full. Cannot create directory '%s'.\n", dirname);
    }
}

void createFile(struct RootDirectory *rootDir, const char *dirname, const char *filename) {
    int dirIndex = -1;
    for (int i = 0; i < rootDir->numDirectories; ++i) {
        if (strcmp(rootDir->directories[i].dirname, dirname) == 0) {
            dirIndex = i;
            break;
        }
    }

    if (dirIndex != -1) {
        struct Directory *dir = &rootDir->directories[dirIndex];
        if (dir->numFiles < MAX_FILES) {
            strcpy(dir->files[dir->numFiles].filename, filename);
            dir->numFiles++;
            printf("File '%s' created in the directory '%s'.\n", filename, dirname);
        } else {
            printf("Directory '%s' is full. Cannot create file '%s'.\n", dirname, filename);
        }
    } else {
        printf("Directory '%s' not found.\n", dirname);
    }
}

void listFiles(const struct RootDirectory *rootDir) {
    printf("Files in the root directory:\n");
    for (int i = 0; i < rootDir->numDirectories; ++i) {
        printf("%s:\n", rootDir->directories[i].dirname);
        for (int j = 0; j < rootDir->directories[i].numFiles; ++j) {
            printf("- %s\n", rootDir->directories[i].files[j].filename);
        }
    }
}

int main() {
    struct RootDirectory rootDirectory;
    rootDirectory.numDirectories = 0;

    while (1) {
        printf("\n1. Create Directory\n");
        printf("2. Create File\n");
        printf("3. List Files\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the directory name: ");
                char dirname[50];
                scanf("%s", dirname);
                createDirectory(&rootDirectory, dirname);
                break;
            case 2:
                printf("Enter the directory name: ");
                char dirName[50];
                scanf("%s", dirName);
                printf("Enter the filename: ");
                char filename[50];
                scanf("%s", filename);
                createFile(&rootDirectory, dirName, filename);
                break;
            case 3:
                listFiles(&rootDirectory);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}
