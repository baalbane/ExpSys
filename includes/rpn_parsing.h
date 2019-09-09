#ifndef RPN_PARSING_H_
#define RPN_PARSING_H_

#define         OPERANDS   "^|+"

enum  compare_op_level {
    STACK_IS_LOWER = 0,
    STACK_IS_EQUAL,
    STACK_IS_HIGHTER
};

typedef struct  t_rpn_data
{
    char       *rpn;
    int         rpn_pt;

    char        stack[2048];
    int         stack_pt;

}               rpn_data;


char   *rpn_get(char *);


#endif