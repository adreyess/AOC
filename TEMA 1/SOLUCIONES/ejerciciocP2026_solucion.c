#include <stddef.h>

#define MAX 50

typedef struct Node {
    int VEC[MAX];       
    int Num_Parity;       
    struct Node *next;    
} Node;
struct elementType *list = NULL;

int count_ones(int num) {
    int count = 0;
    while (num) {
        count += num & 1;  
        num >>= 1;         
    }
    return count;
}

Node* calculate_parity_and_find_min(Node *head) {
    Node *min_node = NULL;
    Node *current = head;

    while (current != NULL) {
        int par_count = 0;

        for (int i = 0; i < MAX; i++) {
            if (count_ones(current->VEC[i]) % 2 == 0) {
                par_count++;
            }
        }
        current->Num_Parity = par_count;

        if (min_node == NULL || current->Num_Parity < min_node->Num_Parity) {
            min_node = current;
        }

        current = current->next;
    }

    return min_node;
}