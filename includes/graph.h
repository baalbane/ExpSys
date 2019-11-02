#ifndef	GRAPH_H_
#define	GRAPH_H_

struct	fact;
struct	operand;

typedef struct				t_graph {
	struct fact				**facts;
	int						fact_list_size;
	struct operand			**operands;
	int						operand_list_size;
	struct t_implication	**implications;
	int						implication_list_size;
}							graph;

graph						*new_graph();
ret_type					add_new_node(graph *graph, nodes *to_add);

#endif