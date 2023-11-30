#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/msg.h>

int main() {
    // Create or get a message queue
    key_t key = ftok("message_queue_example", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    // Send a message
    char msg[100] = "Hello from Process 1";
    msgsnd(msgid, msg, sizeof(msg), 0);
    printf("Message sent: %s\n", msg);

    // Receive a message
    msgrcv(msgid, msg, sizeof(msg), 1, 0);
    printf("Message received: %s\n", msg);

    // Remove the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
