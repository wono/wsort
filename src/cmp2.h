/*
 *      last modified:  2014/05/10
 *      created:        2013/11/22
 *
 *      wono (a.k.a wonho)
 */

#ifndef _cmp2_h_
#define _cmp2_h_

#include <string.h>
#include "cmp1.h" 

/*  returns corresponding function pointer to the options */
Cmptr get_cmp_2         ( const char *op1, const char *op2 );

/*  1st name ascending, 2nd score ascending */
int cmp_nameA_scoreA    ( const void *p1, const void *p2 );

/*  1st name ascending, 2nd score descending */
int cmp_nameA_scoreD    ( const void *p1, const void *p2 );

/*  1st name descending, 2nd score ascending */
int cmp_nameD_scoreA    ( const void *p1, const void *p2 );

/*  1st name descending, 2nd score descending */
int cmp_nameD_scoreD    ( const void *p1, const void *p2 );

/*  1st score ascending, 2nd name ascending */
int cmp_scoreA_nameA    ( const void *p1, const void *p2 );

/*  1st score ascending, 2nd name descending */
int cmp_scoreA_nameD    ( const void *p1, const void *p2 );

/*  1st score descending, 2nd name ascending */
int cmp_scoreD_nameA    ( const void *p1, const void *p2 );

/*  1st score descending, 2nd name descending */
int cmp_scoreD_nameD    ( const void *p1, const void *p2 );

static inline int
COMPARE_BY_TWO_OPTIONS (    Cmptr           option1,
                            Cmptr           option2,
                            const void *    p1,
                            const void *    p2        )
{
    int     n =     option1 (p1, p2);
    return  n ? n : option2 (p1, p2); 
}

#endif
