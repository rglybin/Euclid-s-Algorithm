// Ruslan Glybin
// 1/29/13
// CSC 335 Computer Algorithms
// Homework #1
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <math.h>

using namespace std;


//Function prototypes
int CIC_alg(int m, int n, int &i);
int E_alg(int m, int n, int &i);

//Main function
void main()
{
	//Arrays

	int mArray[101];
	int nArray[101];
	int iterations[101];
	int averageIterations = 0;
	int results[101];

	  srand(time(0));
   for (int i = 1; i <= 100; i++)
   {

     int m = rand()%(10000-1000+1)+1000;
     int n = rand()%(10000-1000+1)+1000;
	
	 mArray [i] = m;
	 nArray [i] = n;
   }

   int temp_iterations = 0;
   
   for (int i = 1; i <= 100; i++)
   {
	   results[i]= CIC_alg(mArray[i], nArray[i], temp_iterations);
	   iterations[i]=temp_iterations;
	   temp_iterations=0;

   }
   

   int max = iterations[1];
   int max_index = 0;
   int min = iterations[1];
   int min_index = 0;
   for (int i = 1; i <= 100; i++)
   {
	   if (max < iterations[i])
	   {
		   max = iterations[i];
		   max_index = i;
	   }
	   if (min > iterations[i])
	   {
		   min = iterations[i];
		   min_index = i;
	   }

	   averageIterations += iterations[i];
	 
   }
   
	cout<<"running random number generator for 100 pairs.\n"
    <<"Resulting algorithm data is as follows.\n"
    <<endl;

   cout<<"Consecutive Integer Checking:\n"
    <<"----------------------------"
	<<"\nThe most number of iterations is = " << iterations[max_index] << " for GCD"<< "(" << 
	mArray[max_index] << ", " << nArray[max_index] << ") = " << results[max_index]
	<<"\nThe least number of iterations is = " << iterations[min_index] << " for GCD"<< "(" << 
	mArray[min_index] << ", " << nArray[min_index] << ") = " << results[min_index]
    <<"\nThe average number of iterations for all 100 pairs is = " << averageIterations/100
    <<endl;

   for (int i = 1; i <= 100; i++)
   {
	   results[i]=E_alg(mArray[i], nArray[i], temp_iterations);
	   iterations[i]=temp_iterations;
	   temp_iterations=0;

   }
   max = iterations[1];
   max_index = 0;
   min = iterations[1];
   min_index = 0;
   averageIterations = 0;
   for (int i = 1; i <= 100; i++)
   {
	   if (max < iterations[i])
	   {
		   max = iterations[i];
		   max_index = i;
	   }
	   if (min > iterations[i])
	   {
		   min = iterations[i];
		   min_index = i;
	   }

	   averageIterations += iterations[i];
	 
   }

cout<<"\n\nEuclid's:\n"
    <<"--------"
	<<"\nThe most number of iterations is = " << iterations[max_index] << " for GCD"<< "(" << 
	mArray[max_index] << ", " << nArray[max_index] << ") = " << results[max_index]
	<<"\nThe least number of iterations is = " << iterations[min_index] << " for GCD"<< "(" << 
	mArray[min_index] << ", " << nArray[min_index] << ") = " << results[min_index]
    <<"\nThe average number of iterations for all 100 pairs is = " << averageIterations/100
    <<endl;
cin.get();
}

//Consecutive Integer checking algorithm.
int CIC_alg(int m, int n, int &i)
{
	int temp = 0;
	if (m < n)
		temp = m;
	else
		temp = n;
	while (temp >= 1)
	{
		i++;
		if(m % temp == 0 && n % temp == 0)
			return temp;
			temp--;
	}
	return temp;
}

//Euclid's algorithm.
int E_alg(int m, int n, int &i)
{
	   int temp = 0;
	   while (n != 0)
	   {
		   temp = m % n;
		   m = n;
		   n = temp;
		   i++;
	   }
	   return m;
}




   
