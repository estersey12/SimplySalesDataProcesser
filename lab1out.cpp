//Emmanuelle Esters
//lab1out
//Process sales data

#include <iostream>
#include "graph1.h"

using namespace std;

//Function Prototypes
int getNoMonths();
void getSales(int sales[], int no_months);
int getMax(int sales[], int no_months);
int getMin(int sales[], int no_months);
double getAverage(int sales[], int no_months);
void displayResults(int sales[], int no_months, int max, int min, double avg);

int main()
{
	//Variable Declaration/Initialization
	
	int no_months = 0;
	const int MAX_SALES = 6;
	int sales[MAX_SALES];
	int max = 0;
	int min = 0;
	double total = 0;
	double avg = 0;
	char repeat = 'y';

	//Display Graphics Window
	displayGraphics();

	do
	{
		//Prompt for number of months
		no_months = getNoMonths();

		//Enter sales data
		getSales(sales, no_months);

		//Get max
		max = getMax(sales, no_months);

		//Get min
		min = getMin(sales, no_months);

		//Get average
		avg = getAverage(sales, no_months);

		//Display Results
		displayResults(sales, no_months, max, min, avg);

		//Prompt for repeat
		cout << "Would you like to repeat? (y/n): ";
		cin >> repeat;

	} while ((repeat == 'y') || (repeat == 'Y'));

	return 0;
}

//Function Stubs
int getNoMonths()
{
	//Declare Variables
	int no_months = 0;

	do
	{
		cout << "Enter number of months to process (between 3 aned 6 inclusively): ";
		cin >> no_months;

		if ((no_months < 3) || (no_months > 6))
		{
			cout << "Please enter values between 3 and 6 inclusively!" << endl;
		}

	} while ((no_months < 3) || (no_months > 6));

	return no_months;
}

void getSales(int sales[], int no_months)
{
	//Declare Variables
	int i = 0;

	//Prompt for sales
	for (i = 0; i < no_months; i++)
	{
		cout << "Enter sales for month #" << (i + 1) << ": ";
		cin >> sales[i];
	}
}

int getMax(int sales[], int no_months)
{
	int i = 0;
	int max = 0;

	for (i = 0; i < no_months; i++)
	{
		if (max < sales[i])
		{
			max = sales[i];
		}
	}

	return max;
}

int getMin(int sales[], int no_months)
{
	int i = 0;
	int min = 99999999999999999;

		for (i = 0; i < no_months; i++)
		{

			if (min > sales[i])
			{
				min = sales[i];
			}
		}

	return min;
}

double getAverage(int sales[], int no_months)
{
	int i = 0;
	double total = 0;
	double avg = 0;

	for (i = 0; i < no_months; i++)
	{
		total = total + sales[i];
	}

	avg = total / no_months;

	return avg;
}

void displayResults(int sales[], int no_months, int max, int min, double avg)
{
	//Declare Variables
	int i = 0;
	int height = 1;
	int x = 0;
	int rect = 0;
	int space = 0;
	int y = 275;

	//Display sales image and title
	displayBMP("sales1.bmp", 250, 25);
	gout << setPos(375, 26) << "Sales for " << no_months << " months" << endg;

	//Draw x/y axis 
	drawLine(200, 130, 200, 280, 1);
	drawLine(200, 280, 720, 280, 1);
	gout << setPos(125, 205) << "Monthly" << endg;
	gout << setPos(125, 225) << "Sales" << endg;
	gout << setPos(370, 300) << "Months" << endg;

	//Draw box
	drawLine(200, 345, 420, 345, 1);
	drawLine(420, 345, 420, 445, 1);
	drawLine(420, 445, 200, 445, 1);
	drawLine(200, 445, 200, 345, 1);

	//Sales Stats
	gout << setPos(205, 335) << "Sales Statistics" << endg;
	gout << setPos(205, 380) << "Max Sales: $" << max << endg;
	gout << setPos(205, 400) << "Min Sales: $" << min << endg;
	
	int average = (int)avg;
	gout << setPos(205, 420) << "Avg Sales: $" << average << endg;

	//Display Bars
	for (i = 0; i < no_months; i++)
	{
		//Calculate x
		x = 200 + space;

		height = -((double)sales[i] / max)*100.0;
		rect = drawRect(x, 280, 50, height);

		space += 75;

		//Calculate y
		y = 275 + height;

		switch (i)
		{
		case 0:
			setColor(rect, 255, 0, 0);
			gout << setPos(x, y) << "Jan" << endg;
			break;

		case 1:
			setColor(rect, 0, 255, 0);
			gout << setPos(x, y) << "Feb" << endg;
			break;

		case 2:
			setColor(rect, 0, 0, 255);
			gout << setPos(x, y) << "Mar" << endg;
			break;

		case 3:
			setColor(rect, 255, 255, 0);
			gout << setPos(x, y) << "Apr" << endg;
			break;

		case 4:
			setColor(rect, 255, 0, 255);
			gout << setPos(x, y) << "May" << endg;
			break;

		case 5:
			setColor(rect, 0, 255, 255);
			gout << setPos(x, y) << "June" << endg;
			break;
		}
	}

	
}