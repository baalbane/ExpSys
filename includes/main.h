
#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define         OPERANDS   "^|+!"

#define         LIST_DEFAULT_SIZE   1

typedef enum {
        FALSE = 0,
        TRUE
} bool;

typedef enum {
        CRITICAL_ERROR = -2,
        ERROR,
        READ_EOF,
        OK
} ret_type;

typedef enum {
        NODE_TYPE_FACT,
        NODE_TYPE_OPERAND,
        NODE_TYPE_IMPLICATION
} NODE_TYPE;

typedef struct  t_nodes
{
    NODE_TYPE   node_type;
}               nodes, **node_list;


#include "read.h"
#include "stack.h"
#include "rpn_parsing.h"
#include "graph.h"
#include "implication.h"
#include "operand.h"
#include "fact.h"

ret_type process_file(char*, graph*);
ret_type compute_graph_state(graph*);
ret_type process_implication(char*, graph*);




#endif