/*
 *      last modified:  2014/05/14
 *      first wrote:    2013/11/22
 *
 *      wono (a.k.a wonho)
 */

#include "cmp2.h"

/*  returns corresponding function pointer to the options */
Cmptr get_cmp_2 (const char *op1, const char *op2) {
    if (!strcmp (op1, "+n")) {
        if (!strcmp(op2, "+s")) return cmp_nameA_scoreA;
        if (!strcmp(op2, "-s")) return cmp_nameA_scoreD;
    }
    if (!strcmp (op1, "-n")) {
        if (!strcmp (op2, "+s")) return cmp_nameD_scoreA;
        if (!strcmp (op2, "-s")) return cmp_nameD_scoreD;
    }
    if (!strcmp (op1, "+s")) {
        if (!strcmp (op2, "+n")) return cmp_scoreA_nameA;
        if (!strcmp (op2, "-n")) return cmp_scoreA_nameD;
    }
    if (!strcmp (op1, "-s")) {
        if (!strcmp (op2, "+n")) return cmp_scoreD_nameA;
        if (!strcmp (op2, "-n")) return cmp_scoreD_nameD;
    }
    return 0;
}

/*  1st name ascending, 2nd score ascending */
int cmp_nameA_scoreA (const void *p1, const void *p2) 
{
    return  COMPARE_BY_TWO_OPTIONS (cmp_name_a, cmp_score_a, p1, p2);
}

/*  1st name ascending, 2nd score descending */
int cmp_nameA_scoreD (const void *p1, const void *p2)
{
    return  COMPARE_BY_TWO_OPTIONS (cmp_name_a, cmp_score_d, p1, p2);
}

/*  1st name descending, 2nd score ascending */
int cmp_nameD_scoreA (const void *p1, const void *p2)
{
    return  COMPARE_BY_TWO_OPTIONS (cmp_name_d, cmp_score_a, p1, p2);
}

/*  1st name descending, 2nd score descending */
int cmp_nameD_scoreD (const void *p1, const void *p2)
{
    return  COMPARE_BY_TWO_OPTIONS (cmp_name_d, cmp_score_d, p1, p2);
}

/*  1st score ascending, 2nd name ascending */
int cmp_scoreA_nameA (const void *p1, const void *p2)
{
    return  COMPARE_BY_TWO_OPTIONS (cmp_score_a, cmp_name_a, p1, p2);
}

/*  1st score ascending, 2nd name descending */
int cmp_scoreA_nameD (const void *p1, const void *p2)
{
    return  COMPARE_BY_TWO_OPTIONS (cmp_score_a, cmp_name_d, p1, p2);
}

/*  1st score descending, 2nd name ascending */
int cmp_scoreD_nameA (const void *p1, const void *p2)
{
    return  COMPARE_BY_TWO_OPTIONS (cmp_score_d, cmp_name_a, p1, p2);
}

/*  1st score descending, 2nd name descending */
int cmp_scoreD_nameD (const void *p1, const void *p2)
{
    return  COMPARE_BY_TWO_OPTIONS (cmp_score_d, cmp_name_d, p1, p2);
}
