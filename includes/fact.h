#ifndef FACT_H_
#define FACT_H_

struct operand;

typedef struct  t_fact
{
    char        node_type;
    char        name;

    operand    *affects_value_of;
    char        initial_value;
    char        set_value;
}               fact, **fact_list;

#endif