//
//  main_test.c
//  Week 6 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "min_unit.h"
#include "core.h"

static char * test_sum_list() {
    mu_begin_case("sum_list");

    {
        mu_assert_i("sum_list(NULL) should return 0", 0, sum_list(NULL));
    }

    {
        LinkedList l1;
        LinkedList l2;
        LinkedList l3;
        LinkedList l4;

        l1.value = 1;
        l2.value = 2;
        l3.value = 4;
        l4.value = 8;

        l1.next = &l2;
        l2.next = &l3;
        l3.next = &l4;
        l4.next = NULL;

        int sum = sum_list(&l1);
        mu_assert_i("sum_list(&l1) should return 15", 15, sum);
    }

    {
        LinkedList l1;
        LinkedList l2;
        LinkedList l3;
        LinkedList l4;

        l1.value = 2;
        l2.value = 4;
        l3.value = 4;
        l4.value = 2;

        l1.next = &l2;
        l2.next = &l3;
        l3.next = &l4;
        l4.next = NULL;

        int sum = sum_list(&l1);
        mu_assert_i("sum_list(&l1) should return 12", 12, sum);
    }

    {
        LinkedList l1;
        l1.value = 2;
        l1.next = NULL;

        int sum = sum_list(&l1);
        mu_assert_i("sum_list(&l1) should return 2", 2, sum);
    }

    mu_end_case("sum_list");
    return 0;
}

static char * test_remove_last() {
    mu_begin_case("remove_last");

    {
        mu_assert_i("remove_last(NULL) should return FALSE", 0, remove_last(NULL));
    }

    {
        LinkedList l1;
        l1.value = 1;
        l1.next = NULL;

        mu_assert_i("remove_last(&l1) with only one element should return FALSE", 0, remove_last(NULL));
    }

    {
        LinkedList l1;
        LinkedList l2;

        l1.value = 1;
        l2.value = 2;

        l1.next = &l2;
        l2.next = NULL;

        int result = remove_last(&l1);
        mu_assert_i("remove_last(&l1) should return TRUE", 1, result);
        
        int passed = (l1.next == NULL);
        mu_assert_i("remove_last(&l1) should remove l2", 1, passed);
    }

    {
        LinkedList l1;
        LinkedList l2;
        LinkedList l3;
        LinkedList l4;

        l1.value = 1;
        l2.value = 2;
        l3.value = 4;
        l4.value = 8;

        l1.next = &l2;
        l2.next = &l3;
        l3.next = &l4;
        l4.next = NULL;

        int result = remove_last(&l1);
        mu_assert_i("remove_last(&l1) should return TRUE", 1, result);
        
        int passed = (l3.next == NULL);
        mu_assert_i("remove_last(&l1) should remove l4", 1, passed);
    }

    mu_end_case("remove_last");
    return 0;
}

static char * all_tests() {
    test_sum_list();
    test_remove_last();
    return 0;
}

#ifdef TEST
int main(int argc, char **argv) {
    mu_run(all_tests);
    return 0;
}
#endif

