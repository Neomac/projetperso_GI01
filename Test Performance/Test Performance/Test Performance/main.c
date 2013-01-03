//
//  main.c
//  Test Performance
//
//  Created by Antoine Galluet on 03/01/13.
//  Copyright (c) 2013 Antoine Galluet. All rights reserved.
//

#include <stdio.h>
#include "indiv.h"
#include "listebit.h"

int main(int argc, const char * argv[])
{
    printf("Hello, World!\n");
    return 0;
    
    ListeBit A;
    ListeBit B;
    
    A = InitialiserIndivIteratif(10000000, 50);
    
}

