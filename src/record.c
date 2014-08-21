/*
 *      last modified:  2014/05/14
 *      first wrote:    2013/11/22
 *
 *      wono (a.k.a wonho)
 */
 
#include "record.h"

/*  prints all records */
void records_print (Records *recs) {
    size_t  i   = 0;
    
    do {
        printf ("%s %s %d\n",
            recs->list[i].name.last,
            recs->list[i].name.first,
            recs->list[i].score);
    } while (++i < recs->memory_size_used );
}

/*  reads records from stdin to records
 *
 *  MEMORY_ALLOCATE ()      is defined in wmalloc.h
 *  MEMORY_RELEASE  ()      is defined in wmalloc.h 
 *  WASSERT         ()      is defined in wassert.h */
void records_read (Records *recs) {
    Record  r;
    char    buffer[DEFAULT_SIZE_LINE] = {0};

    recs->memory_size_total = recs->memory_size_used    = 0;

    while (fgets (buffer, DEFAULT_SIZE_LINE, stdin)) {
        /*  if used memory is full, extends total memory size */
        if (recs->memory_size_total == recs->memory_size_used)
            WASSERT (records_extend (recs));
        
        if (get_record (buffer, &r))
            recs->list[recs->memory_size_used++] = r;
    }
}

/*  removes all rocords
 *
 *  MEMORY_RELEASE  ()      is defined in wmalloc.h */
void records_remove (Records *rs) 
{
    MEMORY_RELEASE (rs->list);
    rs->list              = 0;
    rs->memory_size_total = 0;
    rs->memory_size_used  = 0;
}

/*  returns 1 if memory spaces are extended 
 *
 *  DEFAULT_SIZE_BLOCK      is defined in record.h
 *  WCHECK      ()          is defiend in wassert.h */
int records_extend (Records *rs) {
    Record *temp = realloc ( 
        rs->list, 
        (DEFAULT_SIZE_BLOCK + rs->memory_size_total) * sizeof (Record)
    );
    
    WCHECK (temp, "unavailabe to allocate memory.");
    
    rs->list                 = temp;
    rs->memory_size_total   += DEFAULT_SIZE_BLOCK;

    return 1;
}

/*  returns 1 if record is successfully read from buffer
 *
 *  DEFAULT_SIZE_NAME           is defined in record.h
 *  IS_EMPTY_CHARACTER  ()      is defined in record.h
 *  IS_VALID_DATA       ()      is defined in record.h
 *  WSTRING_TO_LOWER    ()      is defined in wstring_tolower.h */
int get_record (char *buffer, Record *rec) {
    char c      =  0;
    int  sc     = -1;
    
    char f[DEFAULT_SIZE_NAME] = {0};
    char l[DEFAULT_SIZE_NAME] = {0};
    
    int sn = sscanf (buffer, "%s %s %d%c", f, l, &sc, &c);

    if ( ! IS_VALID_DATA (f, l, sc) )   return 0;

    if ( 3 == sn || IS_EMPTY_CHARACTER (c) ) {
        WSTRING_TO_LOWER    (f);
        WSTRING_TO_LOWER    (l);
        WSTRING_COPY        (rec->name.first, f, DEFAULT_SIZE_NAME);
        WSTRING_COPY        (rec->name.last,  l, DEFAULT_SIZE_NAME);

        rec->score  = sc;

        return 1;
    }

    return 0;
}
