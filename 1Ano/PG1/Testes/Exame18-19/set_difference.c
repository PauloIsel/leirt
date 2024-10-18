#include <stdio.h>

// Assuming Set is an array of integers in this example
typedef struct {
    int elements[100]; // Adjust the size as needed
    int size;
} Set;

void set_difference(const Set s1, const Set s2, Set sr) {
    int newSize = 0;

    // Iterate through elements in s1
    for (int i = 0; i < s1.size; ++i) {
        int element = s1.elements[i];
        int foundInS2 = 0;

        // Check if the element is present in s2
        for (int j = 0; j < s2.size; ++j) {
            if (s2.elements[j] == element) {
                foundInS2 = 1;
                break;
            }
        }

        // If the element is not present in s2, add it to sr
        if (!foundInS2 && newSize < sr.size) {
            sr.elements[newSize++] = element;
        }
    }

    // Set the size of sr to the actual number of elements added
    sr.size = newSize;
}

int main() {
    Set *set1 = {{1, 2, 3, 4, 5}, 5};
    Set *set2 = {{3, 4, 5, 6, 7}, 5};

    Set *sr;

    set_difference(set1, set2, sr);

    printf("%d", sr.size);

    return 0;
}
