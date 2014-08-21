/*
 *      last modified:  2014/05/13
 *      first worte:    2013/11/24
 *
 *      wono (a.k.a wonho)
 */

#ifndef _main_h_
#define _main_h_

#include <stdio.h>
#include <stdlib.h>

#include "cmp1.h"
#include "cmp2.h"
#include "record.h"
#include "util/wmalloc.h"

#define _is_valid_option( OP )\
( OP[0] == '-' || OP[0] == '+' ) && \
( OP[1] == 'n' || OP[1] == 's' )

/*  checks if two options differ - ie, not ('n' 'n') nor ('s' 's') */
#define _has_unique_option( ARGV )   ARGV[1][1] != ARGV[2][1]

static inline int IS_VALID_ARGV ( int argc, char *argv[] )
{
    return  (argc == 2  && _is_valid_option( argv[1] ))
        ||  (argc == 3  && _is_valid_option( argv[1] )
                        && _is_valid_option( argv[2] )
                        && _has_unique_option( argv ));
}

static inline Cmptr GET_OPTION_FOR_COMPARE ( int argc, char *argv[] )
{
    return  2 == argc
        ?   get_cmp_1 (argv[1])
        :   get_cmp_2 (argv[1], argv[2]);
}

static inline void DO_SORT ( Cmptr cmp, Records *rs )
{
    qsort (rs->list, rs->memory_size_used, sizeof (*rs->list), cmp);
}

#endif
