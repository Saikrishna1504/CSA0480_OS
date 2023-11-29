#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    // Create a file
    int fd = creat("example.txt", 0666);
    if (fd == -1) {
        perror("creat");
        exit(1);
    }
    printf("File 'example.txt' created.\n");

    // Write data to the file
    const char *data = "Hello, UNIX I/O system calls!";
    ssize_t bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("write");
        exit(1);
    }
    printf("Data written to the file.\n");

    // Close the file
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }
    printf("File 'example.txt' closed.\n");

    // Open the file
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    printf("File 'example.txt' opened for reading.\n");

    // Read and display data from the file
    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        exit(1);
    }
    buffer[bytes_read] = '\0';
    printf("Read data: %s\n", buffer);

    // Close the file
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }
    printf("File 'example.txt' closed.\n");

    // Remove the file
    if (remove("example.txt") == -1) {
        perror("remove");
        exit(1);
    }
    printf("File 'example.txt' removed.\n");

    return 0;
}
