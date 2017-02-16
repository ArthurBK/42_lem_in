#include "lem_in.h"
void    ft_putdigit_base(unsigned long n, unsigned int base)
{
    if (n > base || base > 62 || base < 2)
        return ;
    if (n < 10)
        ft_putchar(n + '0');
    else if (n < 36)
        ft_putchar(n - 10 + 'A');
    else
        ft_putchar(n - 36 + 'a');
}
void        ft_putnbr_base(unsigned int n, unsigned int base)
{
    if (n > base - 1)
    {
        ft_putnbr_base(n / base, base);
        ft_putnbr_base(n % base, base);
    }
    else
        ft_putdigit_base(n, base);
}
