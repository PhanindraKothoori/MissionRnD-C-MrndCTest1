/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int leapYears(int year, int month);
int leapYears(int year,int month){
	
	if (month <= 2){
		year--;
	}
	int nonleaps = year/100;
	return (year / 4) + (year / 400) - nonleaps;
}
int between_days(struct node *date1head, struct node *date2head){
	int days[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
	if (date1head && date2head){
		int date1[4] = { 0 }, date2[4] = { 0 };
		struct node *temp = date1head;
		int count = 0;
		while (temp){
			date1[count] = (temp->data) * 10 + (temp->next)->data;
			temp = temp->next->next;
			count++;
		}
		count = 0;
		temp = date2head;
		while (temp){
			date2[count] = (temp->data) * 10 + (temp->next)->data;
			temp = temp->next->next;
			count++;
		}
		if (date1[1] == date2[1] && date1[2] == date2[2] && date1[3] == date2[3]){
			if (date1[0] == date2[0]){
				return 0;
			}
			
		}


		unsigned long int days1 = (date1[2] * 100 + date1[3]) * 365;
		unsigned long int days2 = (date2[2] * 100 + date2[3]) * 365;
		for (int i = 0; i < date1[1] - 1; i++){
			days1 += days[i];
		}
		days1 += leapYears(date1[2] * 100 + date1[3],date1[1]) + date1[0];
		for (int i = 0; i < date2[1] - 1; i++){
			days2 += days[i];
		}
		days2 += leapYears(date2[2] * 100 + date2[3],date2[1]) + date2[0];

		return days2 - days1 - 1;
	}
	else{
		return -1;
	}
}