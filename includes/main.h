/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:24:26 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/03 16:33:50 by egaborea         ###   ########.fr       */
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

int	process_file(char *line, t_graph *graph);
int	compute_graph_state(t_graph *graph);
int	process_implication(char *line, t_graph *graph);

#endif
