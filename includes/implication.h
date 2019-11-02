#ifndef	IMPLICATION_H_
#define	IMPLICATION_H_

struct	nodes;

typedef struct	t_implication
{
    NODE_TYPE	node_type;
    nodes		*left;
    nodes		*right;
}				implication, **implication_list;


implication		*implication_new(graph*);
ret_type		init_implication_list(graph*);

#endif