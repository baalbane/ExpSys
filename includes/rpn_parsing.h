#ifndef RPN_PARSING_H_
#define RPN_PARSING_H_



typedef enum  compare_op_level {
    STACK_IS_LOWER = -1,
    STACK_IS_EQUAL,
    STACK_IS_HIGHTER
}   STACK_CMP;

typedef struct  t_rpn_data
{
    char       *rpn;
    int         rpn_pt;
    Stack      *stack;
}               rpn_data;


char   *rpn_get(char *);


#endif