/*
 *      last modified:  2014/08/21
 *      wrote:          2013/11/22
 *
 *      wono (a.k.a wonho)
 */
 
#ifndef _record_h_
#define _record_h_

#include <stdio.h>

#include "util/wassert.h"
#include "util/wmalloc.h"
#include "util/wstring_copy.h"
#include "util/wstring_length.h"
#include "util/wstring_tolower.h"

typedef struct Name     Name;
typedef struct Record   Record;
typedef struct Records  Records;

#define DEFAULT_SIZE_BLOCK  8
#define DEFAULT_SIZE_NAME   20
#define DEFAULT_SIZE_LINE   256

struct Name {
    char first  [DEFAULT_SIZE_NAME];
    char last   [DEFAULT_SIZE_NAME];
};

struct Record {
    Name name;
    int  score;
};

struct Records {
    Record  *list;
    size_t  memory_size_total, memory_size_used;
};

/* validations for a record     */
static inline int IS_VALID_NAME     ( char *n )
{
    return  WSTRING_LENGTH (n) <= DEFAULT_SIZE_NAME;
}

static inline int IS_VALID_SCORE    ( int s )
{
    return  0 <= s && s <= 100;
}

static inline int IS_VALID_DATA     ( char *f, char *l, int s )
{
    return  IS_VALID_NAME   (f)
        &&  IS_VALID_NAME   (l)
        &&  IS_VALID_SCORE  (s);
}

static inline int IS_EMPTY_CHARACTER ( char c )
{
    return ' ' == c || '\t' == c || '\n' == c || '\0' == c;
}

/* prints all records */
void records_print  (Records *recs);

/* reads data from stdin */
void records_read   (Records *recs);

/* removes all rocords */
void records_remove (Records *recs);

/* returns 1 if record is successfully read from buffer */
int get_record  (char *buffer, Record *rec);

/*  returns 1 if memory spaces for records are extended */
int records_extend  (Records *recs);

#endif
