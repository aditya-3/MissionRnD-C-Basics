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


//converting date to a number

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

//chekcing for any extra characters except numbers and '-' in date

int check_other_symbols(char *dob)
{
	int i = 0;
	while (dob[i] != '\0')
	{
		if (i != 2 && i != 5)
		{

			if (dob[i] < 48 || dob[i]>57)
				return -1;
		}
		i++;
	}
	return 0;
}

//checking for any leap year

void check_leapYear(int year, int *flag)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				*flag = 1;
		}
		else
			*flag = 1;

	}
}

//checking for valid date or not for date2

int check_date(int month,int day,int flag)
{
	if (month > 0 && month < 13)
	{

		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day > 31)
				return -1;
		}
		else if (month == 2)
		{
			if ((flag == 0 && day > 28) || (flag == 1 && day > 29))
				return -1;
		}
		else {

			if (day > 30)
				return -1;
		}
	}
	else
		return -1;
	return 0;
}

//given function

int isOlder(char *dob1, char *dob2)
{
	int *a[2], i = 0, j = 0, t, sum = 0, dob1flag = 0, dob2flag = 0,day1,day2,mon1,mon2,year1,year2;
	for (i = 0; i<2; i++)
	{
		a[i] = (int *)malloc(3 * sizeof(int));
	}
	//checking the placement of '-'
	if (dob1[2] != '-' || dob2[2] != '-' || dob1[5] != '-' || dob2[5] != '-')
	{

		return -1;
	}
		
	//chekcing for any extra characters except numbers and '-' in date
	t = check_other_symbols(dob1);
	if (t == -1)
		return -1;
	t=check_other_symbols(dob2);
	if (t == -1)
		return -1;
	
	
	convert(dob1, a, 0);     //converting date1 to a number
	day1 = a[0][0]; mon1 = a[0][1]; year1 = a[0][2];
	
	 convert(dob2,a,1);       //converting date2 to a number
	 day2 = a[1][0]; mon2 = a[1][1]; year2 = a[1][2];

	
	 check_leapYear(year1, &dob1flag);      //checking for any leap year for date 1
	
	 check_leapYear(year2, &dob2flag);      //checking for any leap year for date 2
	

	
	 t = check_date(mon1,day1,dob1flag);     /////checking for valid date or not for date1
	 if (t == -1)
		 return -1;
	 t = check_date(mon2, day2, dob2flag);    /////checking for valid date or not for date2
	 if (t == -1)
		 return -1;
	 
	//checking for same date or not
	if (year1 == year2 && mon1 == mon2 && day1 == day2)
	{

		return 0;
	}

	else if (year1 <= year2)
	{
		if (mon1 <= mon2)
		{
			if (day1 <= day2)
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