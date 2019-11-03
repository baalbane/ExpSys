/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaborea <egaborea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:03:00 by egaborea          #+#    #+#             */
/*   Updated: 2019/11/03 16:36:56 by egaborea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# define READ_BUFF_SIZE 32

int cleanup_read();
int init_read(char *file_name);
int get_new_line(char **line);

#endif
