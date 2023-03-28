#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    // Initialize the fast and slow pointers
    node *fast_ptr = head;
    node *slow_ptr = head;

    // Traverse the list with fast and slow pointers
    while (fast_ptr && fast_ptr->next) {
        // Advance the fast pointer by two nodes
        fast_ptr = fast_ptr->next->next;

        // Advance the slow pointer by one node
        slow_ptr = slow_ptr->next;

        // If the fast and slow pointers ever point to the same node, the list is cyclic
        if (fast_ptr == slow_ptr) {
            return 1;
        }
    }

    // If we reach the end of the list, it is acyclic
    return 0;
}
