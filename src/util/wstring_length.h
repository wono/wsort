/*  WSTRING_LENGTH
 *
 *      last modified:  2014/05/04
 *      first wrote:    2014/05/01
 *
 *      wono (a.k.a wonho)
 */

#ifndef _wstring_length_h_
#define _wstring_length_h_

inline static size_t WSTRING_LENGTH (char *string)
{
    size_t i = 0;
    
    while ('\0' != string[i++]);
    
    return i;
}

#endif
