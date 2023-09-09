// Program to determine tomorrows date using pointers

#include <stdio.h>
#include <stdbool.h>

// Define Structs
struct date {
int month;
int day;
int year;
};

// Declare Functions
bool isLeapYear (struct date *);
int numberOfDays (struct date *);
void dateUpdate (struct date *);

int main(void) {

  // Declare constants
  struct date thisDay;

  // Get input
  printf ("Enter today's date (mm dd yyyy): ");
  scanf ("%d %d %d", &thisDay.month, &thisDay.day, &thisDay.year);

  // Calculate nextDay
  dateUpdate (&thisDay);

  // Print output 
  printf ("Tomorrows date is %d/%d/%.2d.\n", thisDay.month, thisDay.day, thisDay.year % 100);
  
  return 0;
}

// Define Functions
bool isLeapYear (struct date *d) {
  bool leapYearFlag;

  if ((d->year % 4 == 0 && d->year % 100 != 0) || d->year % 400 == 0) {
    leapYearFlag = true; // It is a leap year
  }
  else {
    leapYearFlag = false; // It is not a leap year
  }

  return leapYearFlag;
}

int numberOfDays (struct date *d) {
  int days;
  const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if (isLeapYear (d) && d->month == 2) {
    days = 29;
  }
  else {
    days = daysPerMonth[d->month - 1];
  }

  return days;
}

void dateUpdate (struct date *today) {

  if (today->day != numberOfDays (today)) {
    today->day++;
  }
  else if (today->month == 12) { // End of Year
    today->day = 1;
    today->month = 1;
    today->year++;
  }
  else {
    today->day = 1;
    today->month++;
  }
}