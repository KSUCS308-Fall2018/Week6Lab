//
//  core.c
//  Week 6 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>

#include "core.h"

// This function should add all elements of list together
// and return the result
//
// i.e. 1 -> 2 -> 3 should return 6
//
// Hints:
//    If list is NULL return 0
//    You will need a pointer to keep track of the "current" node
//    You will need to loop while current isn't NULL
//    On each loop add the current value to the total
//
int sum_list(LinkedList * list) {
    return 0;
}

// This function should remove the last node in the list
// and return FALSE if there is an error, TRUE otherwise
//
// i.e. l1 -> l2 -> l3 should remove l3
//
// Hints:
//     The list needs to have at least *2* elements to remove the last element
//         if the list has 0 (list is NULL) or 1 (list->next is NULL) return false
//     To "remove" the last element you need to find the *second to last* element 
//         and set that elements next to NULL
//     You can chain as many "->next" as you want as long as you are checking for NULL
//         i.e. list->next->next is valid as long as nothing is NULL
int remove_last(LinkedList * list) {
    return FALSE;
}

// Nothing needs to be done in core_main
int core_main(int argc, const char * argv[]) {
    return 0;
}
