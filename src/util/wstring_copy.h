/*  WSTRING_COPY
 *              
 *      last modified:  2014/08/21
 *      first wrote:    2014/05/01
 *
 *      wono (a.k.a wonho)
 */

#ifndef _wstring_copy_
#define _wstring_copy_

#include <stdlib.h>
#include "wstring_length.h"

/*  result string should be dynamically allocated within memory *
 *      - i.e., assumed to be used calloc, malloc, or realloc.  *
 *  char type of array may also be used.                        */
static inline void WSTRING_COPY (   char *  result,
                                    char *  original,
                                    size_t  length      )
{
    size_t  i   = 0;
    
    /*  copies characters until result gets first null character    */
    while ((result[i++] = original[i]));
    
    /*  fills the rest of length with null characters if there any  */ 
    while (i <= length) result[i++] = 0;
}
  
#endif
