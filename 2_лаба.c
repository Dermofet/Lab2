//lab0_2//
#include <stdio.h>
#include <stdlib.h>


double accuracy(int E)
{
    double accuracy = 1;
    while (E != 0)
    {
        accuracy = accuracy/10;
        E = E - 1;
    }
    return accuracy;
}


double degree (double x, int i)
{
    double deg_x = 1;
    while (i != -1)
    {
        deg_x = deg_x * x;
        i = i - 1;
    }
    return deg_x;
}


double func1_one_element(double x, int j, int i)
{
    return degree(x, i)/(j + 1);
}


double func1(double x, int j, int i)
{
    double sum1 = 0;
    while (j != i+1 )
    {
        sum1 += func1_one_element(x, j, i);
        j++;
    }
    return sum1;
}


double func2_one_element(double x, int j, int i)
{
    if (i%2 == 0)
       return func1(x, j, i);
    else 
       return (-1)*func1(x, j, i); 
}


double func2(double x, int i, int j, double current, double previous, int E)
{
    double sum2 = 0;
    while (abs(current - previous) > accuracy(E))
    {
        sum2 += func2_one_element(x, j ,i);
        current = func2_one_element(x, j, i);
        previous = current;
        i++;
    }
    return sum2;
}


double main() 
{
    int E;
    double x;
    printf("Enter the accuracy\n");
    scanf("%d", &E);
    printf("Enter x\n");
    scanf("%f", &x);
    int i = 0;
    int j = 0;
    double current, previous;
    current = func2_one_element(x, i, j);
    i++;
    j++;
    double answer = func2(x, i, j, current, previous, E);
    printf("Answer is %lf\n", &answer);
}


