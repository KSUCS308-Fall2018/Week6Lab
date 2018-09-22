//
//  core.h
//  Week 6 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef core_h
#define core_h

#include <stdio.h>

#include "types.h"

#define TRUE 1
#define FALSE 0

int sum_list(LinkedList * list);
int remove_last(LinkedList * list);

int core_main(int argc, const char * argv[]);

#endif /* core_h */
