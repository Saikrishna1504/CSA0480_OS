#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, direction, total_head_movement = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the head movement direction (1 for right, 0 for left): ");
    scanf("%d", &direction);

    // Sort the requests to make it easier to simulate SCAN
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((direction == 1 && requests[i] > requests[j]) || (direction == 0 && requests[i] < requests[j])) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    int index = 0;

    for (int i = 0; i < n; i++) {
        if ((direction == 1 && requests[i] > head) || (direction == 0 && requests[i] < head)) {
            index = i;
            break;
        }
    }

    if (direction == 1) {
        for (int i = index; i < n; i++) {
            total_head_movement += abs(requests[i] - head);
            head = requests[i];
        }
        total_head_movement += abs(requests[n - 1] - (direction == 1 ? 0 : 0));
    } else {
        for (int i = index - 1; i >= 0; i--) {
            total_head_movement += abs(requests[i] - head);
            head = requests[i];
        }
        total_head_movement += abs(requests[0] - (direction == 1 ? 0 : 0));
    }

    printf("Total head movement is: %d\n", total_head_movement);

    return 0;
}
