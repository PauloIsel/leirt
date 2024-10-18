#include <stdio.h>
#include <time.h>

// Function to generate a random number in the range [min, max]
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

int random_subset(int numbers[], int numbers_size, int set[], int set_size) {
    if (numbers_size < set_size) {
        return -1; // Not enough elements in numbers
    }

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    for (int i = 0; i < set_size; i++) {
        int random_index = rand_range(0, numbers_size - 1);

        // Swap the randomly chosen element with the last element
        int temp = numbers[random_index];
        numbers[random_index] = numbers[numbers_size - 1];
        numbers[numbers_size - 1] = temp;

        // Copy the swapped element to the set
        set[i] = temp;

        // Reduce the effective size of the numbers array
        numbers_size--;
    }

    return numbers_size; // Return the new dimension of numbers
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numbers_size = 10;

    int set[5];
    int set_size = 5;

    int new_numbers_size = random_subset(numbers, numbers_size, set, set_size);

    if (new_numbers_size == -1) {
        printf("Not enough elements in numbers.\n");
    } else {
        printf("Random Subset: { ");
        for (int i = 0; i < set_size; i++) {
            printf("%d ", set[i]);
        }
        printf("}\n");

        printf("New dimension of numbers: %d\n", new_numbers_size);
    }

    return 0;
}
