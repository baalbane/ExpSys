
#include "main.h"


typedef struct nodes
{
    char    node_type;
};


typedef struct fact
{
    char    node_type;
    char    name;

    operand   *affects_value_of;
    char        initial_value;
    char        set_value;
};

typedef struct operand
{
    char    node_type;
    char    operand_type;
    nodes   *right;
    nodes   *left;
    nodes   *implies;
};

int main(int argc, char **argv) {

    if (argc != 2)
        return (-1);
    char file_name = argv[1];
    
    operand *operands;
    fact    *facts;
    
    process_file(file_name, &operands, &facts);



    char    *new_line;
    while (new_line = get_new_line()) {
        process_line(new_line, &operands, &facts);
        free(new_line);
    }
    return (0);
}