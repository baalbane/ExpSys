
#include "main.h"



int main(int argc, char **argv) {

    char            *file_name = argv[1];
    graph           *graph;

    printf("%lf | %lf\n", sizeof(char), sizeof(void*));
    if (argc != 2) {
        printf("ERROR: need file in input\n");
        return (-1);
    }
    graph = new_graph();
    process_file(file_name, graph);

    // delete_graph(graph);
    
    return (0);
}