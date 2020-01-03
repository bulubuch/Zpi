/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 22:03:56 by mbuch             #+#    #+#             */
/*   Updated: 2020/01/02 22:03:56 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int				ret_msg(char *msg, int ret)
{
	printf(msg);
	return (ret);
}



int				main(int ac, char **av)
{
	t_server	srv;

	if init_srv(&srv, ac, av);
		return (ret_msg(USAGE))
}