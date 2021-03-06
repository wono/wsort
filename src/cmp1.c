/*
 *      last modifed:   2014/05/14
 *      first worte:    2013/11/22
 *
 *      wono (a.k.a wonho)
 */

#include "cmp1.h"

/*  returns corresponding function pointer to the option */
Cmptr get_cmp_1(const char *op) {
    if (!strcmp(op, "+n")) return cmp_name_a;
    if (!strcmp(op, "-n")) return cmp_name_d;
    if (!strcmp(op, "+s")) return cmp_score_a;
    if (!strcmp(op, "-s")) return cmp_score_d;
    return 0;
}

/*  compares by name - ascending */
int cmp_name_a  (const void *ptr1, const void *ptr2)
{
    return  COMPARE_BY_NAME (ptr1, ptr2);
}

/*  compares by name - descending */
int cmp_name_d  (const void *ptr1, const void *ptr2) 
{
    return  COMPARE_BY_NAME (ptr2, ptr1);
}

/*  compares by score - ascending */
int cmp_score_a (const void *ptr1, const void *ptr2)
{
    return  COMPARE_BY_SCORE (ptr1, ptr2);
}

/*  compares by score - descending */
int cmp_score_d (const void *ptr1, const void *ptr2)
{
    return  COMPARE_BY_SCORE (ptr2, ptr1);
}
