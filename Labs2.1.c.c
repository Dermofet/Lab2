#include <stdio.h>
#include <math.h>
 
double power(double x, int i)
{
    double stepen = 1;
    for (int k = 1; k <= i; k++)
        stepen = stepen*x;
    printf("x^i = %lf\n", &stepen);
    return stepen;
}
 
double InternalSum (double x, int i)
{
    double j = 0;
    double sum = 0;
    while (j <= i)
    {
        sum = sum + power(x, i)/(j+1);
        j = j + 1;
    }
    printf("sum = %lf\n", &sum);
    return sum;
}
 
double ExternalElement(double x, int i)
{
    if (i%2 == 0)
    	{printf("InternalSum = %lf\n", InternalSum(x, i));
        return InternalSum(x, i);}
    else
    	{printf("(-1)*InternalSum(x, i) = %lf\n", (-1)*InternalSum(x, i));
        return (-1)*InternalSum(x, i);}
}
 
double accuracy(int E)
{
    double accuracy = 1;
    while (E >= 0)
    {
        accuracy = accuracy/10;
        E = E - 1;
    }
    printf("accuracy = %lf\n", &accuracy);
    return accuracy;
}
 
double check(double x, int E)
{
    double sum = 0;
    double current = ExternalElement(x, 1);
    double previous = ExternalElement(x, 0);
    int i = 1;
    while (fabs(current) - fabs(previous) <= accuracy(E))
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
    scanf("%f", &x);
    double answer = check(x, E);
    printf("%lf", &answer);
}



