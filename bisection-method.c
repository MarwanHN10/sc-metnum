#include<stdio.h>
#include<conio.h>
#include<math.h>


#define f(x) x*exp(-x)+1

void main()
{
	 float a, b, x, f0, f1, f2, e, error;
	 int iterasi = 1;
	 int n;
	 /* Inputs */
	 up:
	 printf("\nMasukkan nilai atas:\n");
	 scanf("%f", &a);
	 printf("Masukkan nilai bawah:\n");
	 scanf("%f", &b);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 /* Calculating Functional Value */
	 f0 = f(a);
	 f1 = f(b);
	 /* Checking whether given guesses brackets the root or not. */
	 if( f0 * f1 > 0.0)
	 {
		  printf("Incorrect Initial Guesses.\n");
		  goto up;
	 }
   /* Implementing Bisection Method */
	 printf("\nIterasi\t\ta\t\tb\t\tx\t\tf(x)\t\tf(a)\t\terror\n");
	 do
	 {
		  x = (a + b)/2;
		  f2 = f(x);
		  error=fabs(b-a);
		  printf("%d\t\t%f\t%f\t%f\t%f\t%f\t%f\n",iterasi, a, b, x, f2,f0, error);
		
		  if( f0 * f2 < 0)
		  {
			   b = x;
			   f1 = f2;
		  }
		  else
		  {
			   a = x;
			   f0 = f2;
		  }
		  iterasi = iterasi + 1;
	 }while(fabs(f2)>e);
	 printf("\nAkarnya adalah: %f", x);
	 getch();
}
