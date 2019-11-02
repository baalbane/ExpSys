
#include "main.h"



int main(int argc, char **argv) {

    char            *file_name = argv[1];
    graph           *graph;

    if (argc != 2) {
        printf("ERROR: need input file\n");
        return (-1);
    }
    graph = new_graph();
    process_file(file_name, graph);

    // delete_graph(graph);
    
    return (0);
}