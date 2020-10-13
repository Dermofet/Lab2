#include <stdio.h>
#include <math.h>
 
double power(double x, int i)
{
    double stepen = 1;
    for (int k = 1; k <= i; k++)
        stepen = stepen*x;
    return stepen;
}
 
double InternalSum (double x, int i)
{
    int j = 0;
    double sum = 0;
    while (j <= i)
    {
        sum = sum + power(x, i)/(j+1);
        j = j + 1;
    }
    return sum;
}
 
double ExternalElement(double x, int i)
{
    double retsum = InternalSum(x, i);
    if (i%2 != 0)
      	retsum = (-1)*retsum;
    return retsum;
}
 
double accuracy(int E)
{
    double accuracy = 1;
    while (E >= 0)
    {
        accuracy = accuracy / 10;
        E = E - 1;
    }
    return accuracy;
}

 
double check(double x, int E)
{
    double sum = 0;
    double previous = ExternalElement(x, 0);
    double current = ExternalElement(x, 1);
    double accur = accuracy(E);
    int i = 1;
    while (fabs(fabs(current) - fabs(previous)) > accur)
    {
        i++;
   	previous = current;
        current = ExternalElement(x, i);
        sum = sum + current;
    }
    return sum;
}

int main()
{
    int E;
    double x;
    printf("Enter the accuracy\n");
    scanf("%d", &E);
    printf("Enter x\n");
    scanf("%lf", &x);
    if (x >= 1)
    {
        printf("ERROR\nIt is impossible to calculate the sum of a numeric row, because it is divergent.\n");
	       return 1;
    }

    double answer = check(x, E);
    printf("Answer = %lf\n", answer);
}
