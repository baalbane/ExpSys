
#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define NULL 0
typedef enum {
        FALSE = 0,
        TRUE
} bool;

typedef enum {
        CRITICAL_ERROR,
        ERROR,
        OK,
        READ_EOF
} ret_type;

typedef struct  t_nodes
{
    char        node_type;
}               nodes;


#include "operand.h"
#include "fact.h"
#include "rpn_parsing.h"

ret_type process_file(char*, operand_list *, fact_list*);
ret_type cleanup_read();
ret_type init_read(char*);
ret_type get_new_line(char**);




#endif