#include<stdarg.h>
#include<unistd.h>

int ft_char(char c, int ct)
{
    write(1, &c, 1);
    ct++;
    return(ct);
}

int ft_int(long n, int ct)
{
    if (n < 0)
    {
        write(1, "-", 1);
        ct++;
        n = -n;
    }
    if (n >= 10)
        ct = ft_int(n/10, ct);
    ct = ft_char(n%10 + '0', ct);
    return (ct);
}

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return (i);
}

int ft_str(char *str, int ct)
{
    if (str)
    {
        write(1, str, ft_strlen(str));
        ct += ft_strlen(str);
    }
    else
        ct = ft_str("(null)", ct);
    return (ct);
}

int ft_hex(unsigned int n, int ct)
{
    if (n >= 16)
        ct= ft_hex(n/16, ct);
    n = n%16;
    if (n < 10)
        ct = ft_char(n + '0', ct);
    else
        ct = ft_char(n + 87, ct);
    return (ct);
}

int ft_arg(va_list ap, char c, int ct)
{
    if (c == 'd')
        ct = ft_int(va_arg(ap, int), ct);
    else if (c == 's')
        ct = ft_str(va_arg(ap, char *), ct);
    else if (c == 'x')
        ct = ft_hex(va_arg(ap, unsigned int), ct);
    return (ct);
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    int i = 0;
    int ct = 0;

    va_start(ap, str);
    while(str[i])
    {
        if (str[i] != '%')
        {
            write(1, &str[i], 1);
            ct++;
        }
        else
            ct = ft_arg(ap, str[++i], ct);
        i++;
    }
    va_end(ap);
    return (ct);
}

int main()
{
    int i, j;
    i = ft_printf("hii %d %s %x", 999, "Abu Dhabi", 42);
    j = printf("hii %d %s %x", 999, "Abu Dhabi", 42);
    printf("%d %d", i, j);
}
