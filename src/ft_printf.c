/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:08:51 by gbourgeo          #+#    #+#             */
/*   Updated: 2018/05/08 10:16:32 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void		ft_printf_write(t_dt *data)
{
	data->ret += data->pos;
	write(STDOUT_FILENO, data->buff, data->pos);
}

int				ft_printf(const char *restrict format, ...)
{
	t_dt		data;

	ft_memset(&data, 0, sizeof(data));
	data.tail = (char *)format;
	va_start(data.ap, format);
	data.write_method = ft_printf_write;
	ft_base(&data);
	ft_printf_write(&data);
	va_end(data.ap);
	return (data.ret - data.less);
}
