
#include "main.h"




int main(int argc, char **argv) {

    char            *file_name = argv[1];
    operand_list    operands;
    fact_list       facts;

    if (argc != 2) {
        printf("ERROR: need file in input\n");
        return (-1);
    }
    
    process_file(file_name, &operands, &facts);

    
    return (0);
}