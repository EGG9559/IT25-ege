
#include <iostream>
#include <ctime>
#include <iomanip>
 
using namespace std;
 
int main()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    int year = timePtr->tm_year + 1900;
    int month = timePtr->tm_mon + 1;
    int day = timePtr->tm_mday;
    int daysInMonth;
while (true) {
if (month == 2) {
 if (year % 4 == 0 &&
  (year % 100 != 0 || year % 400 == 0)) {
 daysInMonth = 29;
} else {
 daysInMonth = 28;
 }
} else if (month == 4 || month == 6
 || month == 9 || month == 11) {
daysInMonth = 30;
 } else {
 daysInMonth = 31;
 }
 cout << setw(24) << left << "Month: " << month << "/" << year << endl;
 cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
  tm firstDay;
 firstDay.tm_year = year - 1900;
  firstDay.tm_mon = month - 1;
 firstDay.tm_mday = 1;
 mktime(&firstDay);
 int firstDayOfWeek = firstDay.tm_wday;
  int currentDay = 1;
 for (int i = 0; i < 6; i++) {
  for (int j = 0; j < 7; j++) {
 if (i == 0 && j < firstDayOfWeek) {
  cout << "    ";
 } else if (currentDay > daysInMonth) {
cout << "    ";
  } else {
 if (currentDay == day) {
cout << setw(2) << left << "[" << currentDay << "]";
 } else {
 cout << setw(4) << left << currentDay;
 }
 currentDay++;
 }
 }
 cout << endl;
 if (currentDay > daysInMonth) {
 break;
 }
}
 cout << "do a thing (n = next month, p = previous month, q = quit): ";
 char command;
 cin >> command;
 cout << endl;
 if (command == 'n') {
 month++;
 if (month > 12) {
 month = 1;
  year++;
 }
 } else if (command == 'p') {
 month--;
  if (month < 1) {
 month = 12;
 year--;
}
} else if (command == 'q') {
  break;
 } else {
 cout << "Invalid. You fucked something up." << endl;
  }
 }
 return 0;
}