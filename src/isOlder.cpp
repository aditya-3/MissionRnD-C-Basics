/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<stdlib.h>
void convert(char *dob,int **a,int k)
{
	int i = 0,j=0,sum=0,t;
	while (dob[i] != '\0')
	{
		if (dob[i] != '-')
		{
			t = dob[i] - 48;
			sum *= 10;
			sum = sum + t;
		}
		else if (dob[i] == '-')
		{
			a[k][j++] = sum;
			sum = 0;
		}
		i++;
	}
	a[k][j] = sum;
}
int isOlder(char *dob1, char *dob2)
{
	int *a[2], i = 0, j = 0, t, sum = 0, dob1flag = 0, dob2flag = 0;
	for (i = 0; i<2; i++)
	{
		a[i] = (int *)malloc(3 * sizeof(int));
	}
	//checking the placement of '-'
	if (dob1[2] != '-' || dob2[2] != '-' || dob1[5] != '-' || dob2[5] != '-')
	{

		return -1;
	}
	i = 0;
	//chekcing for any extra characters except numbers and '-' in date1
	while (dob1[i] != '\0')
	{
		if (i != 2 && i != 5)
		{

			if (dob1[i] < 48 || dob1[i]>57)
				return -1;
		}
		i++;
	}
	i = 0;
	//chekcing for any extra characters except numbers and '-' in date2
	while (dob2[i] != '\0')
	{
		if (i != 2 && i != 5)
		{

			if (dob2[i] < 48 || dob2[i]>57)
				return -1;
		}
		i++;
	}
	i = 0;
	//converting date1 to a number
	/*while (dob1[i] != '\0')
	{
		if (dob1[i] != '-')
		{
			t = dob1[i] - 48;
			sum *= 10;
			sum = sum + t;
		}
		else if (dob1[i] == '-')
		{
			a[0][j++] = sum;
			sum = 0;
		}
		i++;
	}
	a[0][j] = sum;
	j = 0;
	i = 0;
	t = 0;
	sum = 0;*/
	convert(dob1, a, 0);
	//converting date2 to a number
	 convert(dob2,a,1);
	/*while (dob2[i] != '\0')
	{
		if (dob2[i] != '-')
		{
			t = dob2[i] - 48;
			sum *= 10;
			sum = sum + t;
		}
		else if (dob2[i] == '-')
		{
			a[1][j++] = sum;
			sum = 0;
		}
		i++;
	}
	a[1][j] = sum;*/

	//checking for any leap year for date 1
	if (a[0][2] % 4 == 0)
	{
		if (a[0][2] % 100 == 0)
		{
			if (a[0][2] % 400 == 0)
				dob1flag = 1;
		}
		else
			dob1flag = 1;

	}
	//checking for any leap year for date 2
	if (a[1][2] % 4 == 0)
	{
		if (a[1][2] % 100 == 0)
		{
			if (a[1][2] % 400 == 0)
				dob2flag = 1;
		}
		else
			dob2flag = 1;

	}

	/////checking for valid date or not for date1
	if (a[0][1] == 1 || a[0][1] == 3 || a[0][1] == 5 || a[0][1] == 7 || a[0][1] == 8 || a[0][1] == 10 || a[0][1] == 12)
	{

		if (a[0][0] > 31)
			return -1;
	}
	else if (a[0][1] == 2)
	{
		if ((dob1flag == 0 && a[0][0] > 28) || (dob1flag == 1 && a[0][0] > 29))
		{

			return -1;
		}
	}
	else {

		if (a[0][0] > 30)
			return -1;
	}
	///checking for valid date or not for date2
	if (a[1][1] == 1 || a[1][1] == 3 || a[1][1] == 5 || a[1][1] == 7 || a[1][1] == 8 || a[1][1] == 10 || a[1][1] == 12)
	{

		if (a[1][0] > 31)
			return -1;
	}
	else if (a[1][1] == 2)
	{

		if ((dob2flag == 0 && a[1][0] > 28) || (dob2flag == 1 && a[1][0] > 29))
			return -1;

	}
	else {
		if (a[1][0] > 30)
			return -1;
	}
	///checking for same date or not
	if (a[0][2] == a[1][2] && a[0][1] == a[1][1] && a[0][0] == a[1][0])
	{

		return 0;
	}

	else if (a[0][2] <= a[1][2])
	{
		if (a[0][1] <= a[1][1])
		{
			if (a[0][0] <= a[1][0])
			{
				
				return 1;
			}
			else			
				return 2;			
		}
		else
			return 2;
	}
	else
		return 2;


}