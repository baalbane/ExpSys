/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:26:14 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/13 19:10:05 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			main(int argc, char **argv)
{
	t_graph	*graph;

	if (argc != 2)
	{
		printf("ERROR: need input file\n");
		return (-1);
	}
	graph = new_graph();
	process_file(argv[1], graph);
	return (0);
}
