/*
 *  simple library with neat format to replace <assert.h>
 *
 *      last modified:  2014/04/02
 *      first wrote:    2014/04/02
 *
 *      wono (a.k.a wonho)
 */

#ifndef _wassert_h_
#define _wassert_h_

#   ifndef  _STDIO_H_
#   include <stdio.h>
#   endif

#   ifndef  _STDLIB_H_
#   include <stdlib.h>
#   endif

#define _assert( A )\
if (!(A)) {\
    fprintf ( stderr, "\n\tassert fail at %s line %d\n\n", \
              __FILE__, __LINE__ );\
    exit(0);\
}

#define _check( C , M )\
if (!(C)) {\
    fprintf ( stderr, \
              "\n\tassert fail at %s line %d: \n\t" M "\n\n", \
              __FILE__, __LINE__ );\
    exit(0);\
}

#endif
