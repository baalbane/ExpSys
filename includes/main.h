/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:24:26 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/18 21:10:01 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# include "node.h"
# include "read.h"
# include "stack.h"
# include "rpn_parsing.h"
# include "graph.h"
# include "implication.h"
# include "operand.h"
# include "fact.h"

# define OPERANDS "^|+!"

# define LIST_DEFAULT_SIZE   1

# define FALSE 0
# define TRUE 1

# define CRITICAL_ERROR -2
# define ERROR -1
# define READ_EOF 0
# define OK 1

# define NODE_TYPE_FACT 1
# define NODE_TYPE_OPERAND 2
# define NODE_TYPE_IMPLICATION 3

int		process_file(char *line, t_graph *graph);
int		compute_graph_state(t_graph *graph);
int		process_implication(char *line, t_graph *graph);

int		evaluate_expression(int left, int right, char operand);
int		evalute_node(t_node *node);
int		evalute_implication(t_implication *implication);

int		infer_node(t_node *node, int value);

int		rpn_init(t_rpn_data **to_init, char *line);
int		rpn_cleanup(t_rpn_data *to_del);

int		remove_space(char **line);
int		count_non_whitespace(char *line);

int 	check_line(char *line, int left);

int		ft_error(char *error);
void	*ft_malloc(size_t size);

#endif
