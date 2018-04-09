#include "h.h"

ssize_t	output_padding(ssize_t yay_much, char of_this)
{
	ssize_t	const much_yay = yay_much;
	ssize_t	outputten;

	outputten = 0;
	while (yay_much-- > 0)
		outputten += write(g_os.out_stream, &of_this, 1);
	if (outputten < much_yay)
	{
		outputten = -(much_yay - (much_yay - outputten) / 2);
		g_os.output_len += -outputten;
		g_os.errored++;
	}
	else
		g_os.output_len += outputten;
	return (outputten);
}
