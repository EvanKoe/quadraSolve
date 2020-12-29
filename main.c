#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct eq {
    double a;
    double b;
    double c;
    double d;
};

int help(void)
{
    printf("This is a quadratic equation solver.\n");
    printf("USAGE\n\t./solve a b c\n\tax^2 + bx + c = 0\n");
    return (0);
}

int is_nb(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '-') {}
        else if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int is_error(int ac, char **av)
{
    if (ac != 4)
        return (1);
    for (int i = 1; i <= 3; ++i)
        if (is_nb(av[i]) == 0)
            return (1);
    return (0);
}

struct eq get_args(char **av)
{
    struct eq t;

    t.a = atof(av[1]);
    t.b = atof(av[2]);
    t.c = atof(av[3]);

    return (t);
}

void solve(char **av)
{
    struct eq e = get_args(av);
    float r1;
    float r2;

    e.d = e.b * e.b - 4 * e.a * e.c;

    if (e.d > 0) {
        r1 = (-e.b + sqrt(e.d)) / (2 * e.a);
        r2 = (-e.b - sqrt(e.d)) / (2 * e.a);
        printf("2 solutions : %.3f and %.3f\n", r1, r2);
    } else if (e.d == 0) {
        r1 = -e.b / (2 * e.a);
        printf("Only 1 solution : %.3f\n", r1);
    } else {
        printf("2 complex solutions :\n");
        printf("(-%.3f + i * sqrt(%.3f) / %.3f)\n", e.b, e.d, 2 * e.a);
        printf("(-%.3f - i * sqrt(%.3f) / %.3f)\n", e.b, e.d, 2 * e.a);
    }
    return ;
}

int main(int ac, char **av)
{
    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h')
        return (help());
    if (is_error(ac, av) == 1) {
        printf("Stop: argument error. See -h for help.\n");
        return (84);
    } else
        solve(av);
    return (0);
}