/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:26:14 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/03 16:03:39 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char **argv) {

    char            *file_name = argv[1];
    t_graph           *graph;

    if (argc != 2) {
        printf("ERROR: need input file\n");
        return (-1);
    }
    graph = new_graph();
    process_file(file_name, graph);

    // delete_graph(graph);
    
    return (0);
}