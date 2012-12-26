//
//  population.h
//  LO44
//
//  Created by Antoine Galluet on 18/12/12.
//  Copyright (c) 2012 Antoine Galluet. All rights reserved.
//

#ifndef LO44_population_h
#define LO44_population_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listebit.h"

typedef struct elemp{
    ListeBit Indiv;
    struct elemp * suivant;
}element;

typedef element * Population;

#endif
