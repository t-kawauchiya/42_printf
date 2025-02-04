/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:36:53 by takawauc          #+#    #+#             */
/*   Updated: 2025/02/02 20:06:25 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>

void	positive_test(void)
{
	printf("====== Positeve test =====\n");
	printf("ret = %i\n", printf("NO_NEW_LINE"));
	printf("ret = %i\n", ft_printf("NO_NEW_LINE"));
	printf("ret = %i\n", printf("WITH_NEW_LINE\n"));
	printf("ret = %i\n", ft_printf("WITH_NEW_LINE\n"));
	printf("empty string\n");
	printf("ret = %i\n", printf(""));
	printf("ret = %i\n", ft_printf(""));
	printf("only spaces\n");
	printf("ret = %i\n", printf("\t\n "));
	printf("ret = %i\n", ft_printf("\t\n "));
	printf("ret = %i\n", printf("char:%c\n", 'a'));
	printf("ret = %i\n", ft_printf("char:%c\n", 'a'));
	printf("ret = %i\n", printf("str: %s\n", "teststr"));
	printf("ret = %i\n", ft_printf("str: %s\n", "teststr"));
	printf("ret = %i\n", printf("ptr: %p\n", "testptrstr"));
	printf("ret = %i\n", ft_printf("ptr: %p\n", "testptrstr"));
	printf("ret = %i\n", printf("INT: %i\n", 123));
	printf("ret = %i\n", ft_printf("INT: %i\n", 123));
	printf("ret = %i\n", printf("INT_ZERO: %i\n", 0));
	printf("ret = %i\n", ft_printf("INT_ZERO: %i\n", 0));
	printf("ret = %i\n", printf("INT_HEX: %i\n", 0x88));
	printf("ret = %i\n", ft_printf("INT_HEX: %i\n", 0x88));
	printf("ret = %i\n", printf("INT_MAX: %i\n", INT_MAX));
	printf("ret = %i\n", ft_printf("INT_MAX: %i\n", INT_MAX));
	printf("ret = %i\n", printf("INT_MIN: %i\n", INT_MIN));
	printf("ret = %i\n", ft_printf("INT_MIN: %i\n", INT_MIN));
	printf("ret = %i\n", printf("INT_MAX-1: %i\n", INT_MAX - 1));
	printf("ret = %i\n", ft_printf("INT_MAX-1: %i\n", INT_MAX - 1));
	printf("ret = %i\n", printf("INT_MIN+1: %i\n", INT_MIN + 1));
	printf("ret = %i\n", ft_printf("INT_MIN+1: %i\n", INT_MIN + 1));
	printf("ret = %i\n", printf("INT_d: %d\n", 123));
	printf("ret = %i\n", ft_printf("INT_d: %d\n", 123));
	printf("ret = %i\n", printf("INT_ZERO_d: %d\n", 0));
	printf("ret = %i\n", ft_printf("INT_ZERO_d: %d\n", 0));
	printf("ret = %i\n", printf("INT_HEX_d: %i\n", 0x88));
	printf("ret = %i\n", ft_printf("INT_HEX_d: %i\n", 0x88));
	printf("ret = %i\n", printf("INT_MAX_d: %d\n", INT_MAX));
	printf("ret = %i\n", ft_printf("INT_MAX_d: %d\n", INT_MAX));
	printf("ret = %i\n", printf("INT_MIN_d: %d\n", INT_MIN));
	printf("ret = %i\n", ft_printf("INT_MIN_d: %d\n", INT_MIN));
	printf("ret = %i\n", printf("INT_MAX-1_d: %d\n", INT_MAX - 1));
	printf("ret = %i\n", ft_printf("INT_MAX-1_d: %d\n", INT_MAX - 1));
	printf("ret = %i\n", printf("INT_MIN+1_d: %d\n", INT_MIN + 1));
	printf("ret = %i\n", ft_printf("INT_MIN+1_d: %d\n", INT_MIN + 1));
	printf("ret = %i\n", printf("UINT_MAX: %u\n", UINT_MAX));
	printf("ret = %i\n", ft_printf("UINT_MAX: %u\n", UINT_MAX));
	printf("ret = %i\n", printf("UINT_ZERO: %u\n", 0));
	printf("ret = %i\n", ft_printf("UINT_ZERO: %u\n", 0));
	printf("ret = %i\n", printf("HEx_UINT_MAX: %x\n", UINT_MAX));
	printf("ret = %i\n", ft_printf("HEx_UINT_MAX: %x\n", UINT_MAX));
	printf("ret = %i\n", printf("HEx_ZERO: %x\n", 0));
	printf("ret = %i\n", ft_printf("HEx_ZERO: %x\n", 0));
	printf("ret = %i\n", printf("HEX_UINT_MAX: %X\n", UINT_MAX));
	printf("ret = %i\n", ft_printf("HEX_UINT_MAX: %X\n", UINT_MAX));
	printf("ret = %i\n", printf("HEX_ZERO: %X\n", 0));
	printf("ret = %i\n", ft_printf("HEX_ZERO: %X\n", 0));
	printf("ret = %i\n", printf("CHAR_STR: %c_%s\n", 'a', "123"));
	printf("ret = %i\n", ft_printf("CHAR_STR: %c_%s\n", 'a', "123"));
	printf("ret = %i\n", printf("STR_PTR: %s_%p\n", "str", "testptrstr"));
	printf("ret = %i\n", ft_printf("STR_PTR: %s_%p\n", "str", "testptrstr"));
	printf("ret = %i\n", printf("PTR_INT: %p_%i\n", "testptrstr", INT_MAX));
	printf("ret = %i\n", ft_printf("PTR_INT: %p_%i\n", "testptrstr", INT_MAX));
	printf("ret = %i\n", printf("INT_INTd: %i_%d\n", INT_MAX, INT_MIN));
	printf("ret = %i\n", ft_printf("INT_INTd: %i_%d\n", INT_MAX, INT_MIN));
	printf("ret = %i\n", printf("INTd_HEx: %d_%x\n", INT_MAX, 0));
	printf("ret = %i\n", ft_printf("INTd_HEx: %d_%x\n", INT_MAX, 0));
	printf("ret = %i\n", printf("HEx_HEX: %x_%X\n", UINT_MAX, 0));
	printf("ret = %i\n", ft_printf("HEx_HEX: %x_%X\n", UINT_MAX, 0));
	printf("ret = %i\n", printf("HEX_percent: %X_%%\n", UINT_MAX));
	printf("ret = %i\n", ft_printf("HEX_percent: %X_%%\n", UINT_MAX));
	printf("ret = %i\n", printf("percent_CHAR: %%_%c\n", '1'));
	printf("ret = %i\n", ft_printf("percent_CHAR: %%_%c\n", '1'));
	ft_printf("==========================\n\n\n");
}

void	negative_test(void)
{
	ft_printf("====== Negative test =====\n");
	printf("NULL_FORMAT\n");
	printf("ret = %i\n", printf(NULL));
	printf("ret = %i\n", ft_printf(NULL));
	printf("ret = %i\n", printf("INVALID_FORMAT: %z\n", 123));
	printf("ret = %i\n", ft_printf("INVALID_FORMAT: %z\n", 123));
	printf("ret = %i\n", printf("TOO_MANY_ARGS: %c\n", 'a', 'b'));
	printf("ret = %i\n", ft_printf("TOO_MANY_ARGS: %c\n", 'a', 'b'));
	printf("ret = %i\n", printf("TOO_FEW_ARGS: %c\n"));
	printf("ret = %i\n", ft_printf("TOO_FEW_ARGS: %c\n"));
	printf("ret = %i\n", printf("OVER_FLOW_INPUT_CHAR: %c\n", CHAR_MAX + 1));
	printf("ret = %i\n", ft_printf("OVER_FLOW_INPUT_CHAR: %c\n", CHAR_MAX + 1));
	printf("ret = %i\n", printf("OVER_FLOW_INPUT_INT: %i\n", INT_MAX + 1));
	printf("ret = %i\n", ft_printf("OVER_FLOW_INPUT_INT: %i\n", INT_MAX + 1));
	printf("ret = %i\n", printf("OVER_FLOW_INPUT_INT_d: %d\n", INT_MAX + 1));
	printf("ret = %i\n", ft_printf("OVER_FLOW_INPUT_INT_d: %d\n", INT_MAX + 1));
	printf("ret = %i\n", printf("OVER_FLOW_INPUT_UINT: %u\n", UINT_MAX + 1));
	printf("ret = %i\n", ft_printf("OVER_FLOW_INPUT_UINT: %u\n", UINT_MAX + 1));
	printf("ret = %i\n", printf("OVER_FLOW_INPUT_HEx: %x\n", UINT_MAX + 1));
	printf("ret = %i\n", ft_printf("OVER_FLOW_INPUT_HEx: %x\n", UINT_MAX + 1));
	printf("ret = %i\n", printf("UNDER_FLOW_INPUT_CHAR: %c\n", CHAR_MIN - 1));
	printf("ret = %i\n", ft_printf("UNDER_FLOW_INPUT_CHAR: %c\n", CHAR_MIN
			- 1));
	printf("ret = %i\n", printf("UNDER_FLOW_INPUT_INT: %i\n", INT_MIN - 1));
	printf("ret = %i\n", ft_printf("UNDER_FLOW_INPUT_INT: %i\n", INT_MIN - 1));
	printf("ret = %i\n", printf("UNDER_FLOW_INPUT_INT_d: %d\n", INT_MIN - 1));
	printf("ret = %i\n", ft_printf("UNDER_FLOW_INPUT_INT_d: %d\n", INT_MIN
			- 1));
	printf("ret = %i\n", printf("UNDER_FLOW_INPUT_UINT: %u\n", -1));
	printf("ret = %i\n", ft_printf("UNDER_FLOW_INPUT_UINT: %u\n", -1));
	printf("ret = %i\n", printf("UNDER_FLOW_INPUT_HEx: %x\n", -1));
	printf("ret = %i\n", ft_printf("UNDER_FLOW_INPUT_HEx: %x\n", -1));
	printf("ret = %i\n", printf("UNDER_FLOW_INPUT_HEX: %X\n", -1));
	printf("ret = %i\n", ft_printf("UNDER_FLOW_INPUT_HEX: %X\n", -1));
	printf("ret = %i\n", printf("NULL_INPUT_CHAR: %c\n", NULL));
	printf("ret = %i\n", ft_printf("NULL_INPUT_CHAR: %c\n", NULL));
	printf("ret = %i\n", printf("NULL_INPUT_STR: %s\n", NULL));
	printf("ret = %i\n", ft_printf("NULL_INPUT_STR: %s\n", NULL));
	printf("ret = %i\n", printf("NULL_INPUT_PTR: %p\n", NULL));
	printf("ret = %i\n", ft_printf("NULL_INPUT_PTR: %p\n", NULL));
	printf("ret = %i\n", printf("NULL_INPUT_INT: %i\n", NULL));
	printf("ret = %i\n", ft_printf("NULL_INPUT_INT: %i\n", NULL));
	printf("ret = %i\n", printf("NULL_INPUT_INT_d: %d\n", NULL));
	printf("ret = %i\n", ft_printf("NULL_INPUT_INT_d: %d\n", NULL));
	printf("ret = %i\n", printf("NULL_INPUT_UINT: %u\n", NULL));
	printf("ret = %i\n", ft_printf("NULL_INPUT_UINT: %u\n", NULL));
	printf("ret = %i\n", printf("NULL_INPUT_HEx: %x\n", NULL));
	printf("ret = %i\n", ft_printf("NULL_INPUT_HEx: %x\n", NULL));
	printf("ret = %i\n", printf("NULL_INPUT_HEX: %X\n", NULL));
	printf("ret = %i\n", ft_printf("NULL_INPUT_HEX: %X\n", NULL));
	printf("ret = %i\n", printf("NULL_INPUT_percent: %%\n", NULL));
	printf("ret = %i\n", ft_printf("NULL_INPUT_percent: %%\n", NULL));
	ft_printf("==========================\n\n\n");
}

void	write_to_closed_stdout_test(void)
{
	int	out;
	int	eout;
	int	tout;
	int	eout_c;
	int	tout_c;
	int	eout_s;
	int	tout_s;
	int	eout_p;
	int	tout_p;
	int	eout_i;
	int	tout_i;
	int	eout_d;
	int	tout_d;
	int	eout_u;
	int	tout_u;
	int	eout_x;
	int	tout_x;
	int	eout_X;
	int	tout_X;
	int	saved_stdout;

	printf("====== Write to closed stdout =====\n");
	saved_stdout = dup(1);
	close(1);
	eout = printf("NO_FORMAT");
	tout = ft_printf("NO_FORMAT");
	eout_c = printf("%c\n", 'a');
	tout_c = ft_printf("%c\n", 'a');
	eout_s = printf("%s\n", "teststr");
	tout_s = printf("%s\n", "teststr");
	eout_p = printf("%p\n", "teststr");
	tout_p = printf("%p\n", "teststr");
	eout_i = printf("%i\n", 123);
	tout_i = ft_printf("%i\n", 123);
	eout_d = printf("%d\n", 123);
	tout_d = ft_printf("%d\n", 123);
	eout_u = printf("%u\n", 123);
	tout_u = ft_printf("%u\n", 123);
	eout_x = printf("%x\n", 123);
	tout_x = ft_printf("%x\n", 123);
	eout_X = printf("%X\n", 123);
	tout_X = ft_printf("%X\n", 123);
	dup2(saved_stdout, 1);
	close(saved_stdout);
	printf("NO_FORMAT: expected %i, test %i\n", eout, tout);
	printf("CHAR: expected %i, test %i\n", eout_c, tout_c);
	printf("STR: expected %i, test %i\n", eout_p, tout_p);
	printf("PTR: expected %i, test %i\n", eout_p, tout_p);
	printf("INT: expected %i, test %i\n", eout_i, tout_i);
	printf("DECIMAL: expected %i, test %i\n", eout_d, tout_d);
	printf("UINT: expected %i, test %i\n", eout_u, tout_u);
	printf("HEx: expected %i, test %i\n", eout_x, tout_x);
	printf("HEX: expected %i, test %i\n", eout_X, tout_X);
	printf("==========================\n\n\n");
}

int	main(void)
{
	positive_test();
	negative_test();
	write_to_closed_stdout_test();
}
