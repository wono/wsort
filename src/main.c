/*  
 *      last modified:  2014/05/14
 *      first wrote:    2013/11/16
 *
 *      wono (a.k.a wonho)
 */
 
#include "main.h"

int main (int argc, char *argv[]) {
	Records rs;
    records_read (&rs);
    if (IS_VALID_ARGV (argc, argv)) {
        Cmptr c = GET_OPTION_FOR_COMPARE (argc, argv);
        DO_SORT (c, &rs);
    }
    records_print   (&rs);
    records_remove  (&rs);
    
    return 1;
}
