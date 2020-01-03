/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 22:11:36 by mbuch             #+#    #+#             */
/*   Updated: 2020/01/02 22:11:36 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			usage_error()
{
	printf("Usage: ./serveur -p <port> -x <width> -y ");
	printf("<height> -n <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
	exit(0);
}