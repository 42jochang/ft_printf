/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_us.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 17:50:01 by jochang           #+#    #+#             */
/*   Updated: 2018/08/23 15:56:26 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	error_check(t_opts opts)
{
	if (opts.flags.pound + opts.flags.zero +
		opts.flags.plus + opts.flags.space > 0)
	{
		ft_putstr("error: undefined behavior\n");
		exit(1);
	}
	if (opts.length != 0)
	{
		ft_putstr("error: undefined behavior\n");
		exit(1);
	}
}

static void	ft_putspaces(int size)
{
	int		i;

	i = 0;
	while (i++ < size)
		ft_putchar(' ');
}

static void	padding(wchar_t *s, int size, int len, int left_align)
{
	if (!left_align && size > len)
		ft_putspaces(size - len);
	ft_putwstr(s);
	if (left_align && size > len)
		ft_putspaces(size - len);
}

int			d_us(t_opts opts, va_list ap)
{
	wchar_t		*w;
	uint32_t	len;

	error_check(opts);
	ZERO_CHECK(!(w = va_arg(ap, wchar_t*)));
	len = ft_wcslen(w);
	if (opts.precision >= 0)
		len = MIN((int)len, opts.precision);
	padding(w, opts.width, len, opts.flags.minus);
	len = MAX(len, opts.width);
	return (len);
}
