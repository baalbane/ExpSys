#ifndef OPERAND_H_
#define OPERAND_H_

struct nodes;

enum OPERAND_TYPES {
    OPERAND_TYPE_XOR = 0,
    OPERAND_TYPE_OR,
    OPERAND_TYPE_AND,
    OPERAND_TYPE_NOT,
    NB_OPERAND_TYPE
};

typedef struct  t_operand
{
    char	   node_type;
    char        operand_type;
    nodes      *right;
    nodes      *left;
}               operand, **operand_list;


operand *operand_new(graph*, Stack*, char);
ret_type init_operand_list(graph*);

#endif