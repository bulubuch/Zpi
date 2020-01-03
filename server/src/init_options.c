/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 22:33:53 by mbuch             #+#    #+#             */
/*   Updated: 2020/01/02 22:33:53 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int				set_port(t_server *srv, int *ai, int ac, char **av)
{
	*ai = *ai + 1;
	if (*ai < ac)
	{
		srv->opt_nbr++;
		srv->gate.in_addr = (struct sockaddr_in*)&srv->gate.addr;
		srv->gate.in_addr->sin_family = AF_INET;
		srv->gate.in_addr->sin_addr.s_addr = htonl(0);
		srv->gate.in_addr->sin_port = htons(atoi(av[*ai]));
		*ai = *ai + 1;
	}
}