/*
 *      last modified:  2014/05/14
 *      first wrote:    2013/11/22
 *
 *      wono (a.k.a wonho)
 */

#ifndef _cmp1_h_
#define _cmp1_h_

#include <string.h>
#include "record.h"

typedef int (*Cmptr) (const void *, const void *);

/*  returns corresponding function pointer to the option    */
Cmptr get_cmp_1 ( const char *op );

/*  compares by name - ascending    */
int cmp_name_a  ( const void *ptr1, const void *ptr2 );

/*  compares by name - descending   */
int cmp_name_d  ( const void *ptr1, const void *ptr2 );

/*  compares by score - ascending   */
int cmp_score_a ( const void *ptr1, const void *ptr2 );

/*  compares by score - descending  */
int cmp_score_d ( const void *ptr1, const void *ptr2 );

static inline int 
COMPARE_BY_NAME (   const Record * p1,
                    const Record * p2   )
{
    int     n     = strcmp (p1->name.last,  p2->name.last );
    return  n ? n : strcmp (p1->name.first, p2->name.first);
}

static inline int 
COMPARE_BY_SCORE (  const Record * p1,
                    const Record * p2   )
{
    return  p1->score - p2->score;
}

#endif
