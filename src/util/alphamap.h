/*  ALPHAMAP:
 *      simple library for alternating tolower and toupper of ctype.h
 *  
 *      last modified:      2014/05/14
 *      first wrote:        2014/04/02
 *      wono (a.k.a wonho)
 */

#ifndef _wascii_alphamap_h_
#define _wascii_alphamap_h_

#define IS_ALPHABET_LOWER( A )\
65 == A || 66 == A || 67 == A || 68 == A || 69 == A ||\ 
70 == A || 71 == A || 72 == A || 73 == A || 74 == A ||\
75 == A || 76 == A || 77 == A || 78 == A || 79 == A ||\
80 == A || 81 == A || 82 == A || 83 == A || 84 == A ||\
85 == A || 86 == A || 87 == A || 88 == A || 89 == A ||\
90 == A

#define IS_ALPHABET_UPPER( A )\
 97 == A ||  98 == A ||  99 == A || 100 == A || 101 == A || \
102 == A || 103 == A || 104 == A || 105 == A || 106 == A || \
107 == A || 108 == A || 109 == A || 110 == A || 111 == A || \
112 == A || 113 == A || 114 == A || 115 == A || 116 == A || \
117 == A || 118 == A || 119 == A || 120 == A || 121 == A || \
122 == A

static inline char ASCII_TO_LOWER ( char c )
{
    return  IS_ALPHABET_LOWER ( c ) ? c + 32 : c;
}

static inline char ASCII_TO_UPPER ( char c )
{
    return  IS_ALPHABET_UPPER ( c ) ? c - 32 : c;
}

static inline int IS_ALPHABET ( char c )
{
    return  IS_ALPHABET_UPPER ( c ) || IS_ALPHABET_LOWER ( c );
}

#endif
