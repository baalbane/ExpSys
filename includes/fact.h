#ifndef FACT_H_
#define FACT_H_

struct operand;

typedef struct  t_fact
{
    NODE_TYPE   node_type;
    char        name;

    char        initial_value;
    char        set_value;
}               fact, **fact_list;


fact    *fact_new(graph*, char);
ret_type init_fact_list(graph*);
fact    *get_fact(graph*, char);
#endif