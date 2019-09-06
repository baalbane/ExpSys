#ifndef OPERAND_H_
#define OPERAND_H_

struct nodes;

typedef struct  t_operand
{
    char        node_type;
    char        operand_type;
    nodes      *right;
    nodes      *left;
    nodes      *implies;
}               operand, **operand_list;

#endif