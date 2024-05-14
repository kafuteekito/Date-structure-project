#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstdlib> 

using namespace std;

void clear()
{
    cout << "\33[2J\33[1;1H"; 
}

struct Date {
    int day, month, year;

    bool isValidDate() 
    {
        if (day < 1 || day > 31 || month > 12 || month < 1) {
            return false;
        } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            return false;
        } else if (month == 2 && ((day > 28 && year % 4 != 0) || (day > 29 && year % 4 == 0))) {
            return false;
        } else {
            return true;
        }
    }

    friend void printDate(const vector<Date>& dates);

    void newDate(vector<Date>& dates) 
    {
        Date newDate;
        cout << "Enter day: ";
        cin >> newDate.day;
        cout << "Enter month: ";
        cin >> newDate.month;
        cout << "Enter year: ";
        cin >> newDate.year;
        if (newDate.isValidDate()) {
            dates.push_back(newDate);
            cout << "Date added successfully!" << endl;
        } else {
            cout << "Invalid date. Please enter a valid date." << endl;
            newDate.newDate(dates);
        }
    }

    void getDayOfWeek(const vector<Date>& dates) 
    {
        int n, month, year, dayOfWeek;
        cout << "Enter the Index of date you want to know the day of the week: ";
        cin >> n;
        if (n >= 0 && n < dates.size()) {
            month = (dates[n].year % 4 == 0) ? 0 : 1;
            switch (dates[n].month) {
                case 1: month += 0; break;
                case 2: month += 3; break;
                case 3: month += 4; break;
                case 4: month += 0; break;
                case 5: month += 2; break;
                case 6: month += 5; break;
                case 7: month += 0; break;
                case 8: month += 3; break;
                case 9: month += 6; break;
                case 10: month += 1; break;
                case 11: month += 4; break;
                case 12: month += 6; break;
                default: break;
            }
            year = (6 + dates[n].year % 100 + (dates[n].year % 100 / 4)) % 7;
            dayOfWeek = (dates[n].day + month + year) % 7;
            cout << "Day of week for " << dates[n].day << "/" << dates[n].month << "/" << dates[n].year << " is ";
            switch (dayOfWeek) {
                case 0: cout << "Saturday \n"; break;
                case 1: cout << "Sunday \n"; break;
                case 2: cout << "Monday \n"; break;
                case 3: cout << "Tuesday \n"; break;
                case 4: cout << "Wednesday \n"; break;
                case 5: cout << "Thursday \n"; break;
                case 6: cout << "Friday \n"; break;
            }
        } else {
            cout << "Invalid index. Please enter a valid index." << endl;
        }
    }

    int calculateDays(const vector<Date>& dates, int counter)
    {
        int days = 0;
        counter--;
        while (counter != 0)
        {
            if (counter == 2) {
                days += 28;
            } else if (counter == 4 || counter == 6 || counter == 9 || counter == 11) {
                days += 30;
            } else {
                days += 31;
            }
            counter--;
        }
        return days;
    }

    void calculateDifference(const vector<Date>& dates)
    {
        int n1, n2, counter1, counter2;
        long long diffInYears, difference, c1, c2;
        cout << "Enter two indexes of date you want to calculate difference: ";
        cin >> n1 >> n2;
        diffInYears = abs(dates[n1].year - dates[n2].year);
        if (diffInYears > 4) diffInYears += diffInYears / 4;
        counter1 = dates[n1].month;
        counter2 = dates[n2].month;
        c1 = calculateDays(dates, counter1);
        c2 = calculateDays(dates, counter2);
        c1 += dates[n1].day;
        c2 += dates[n2].day;
        if (dates[n1].year > dates[n2].year) {
            difference = c1 - c2 + diffInYears * 365;
        } else {
            difference = c2 - c1 + diffInYears * 365;
        }
        cout << "There is " << difference << " days difference" << endl;
    }
};

bool compareDates(const Date& date1, const Date& date2) {
    if (date1.year != date2.year)
        return date1.year < date2.year;
    if (date1.month != date2.month)
        return date1.month < date2.month;
    return date1.day < date2.day;
}

void printDate(const vector<Date>& dates)
{
    cout << "Dates:" << endl;
    for (const auto& d : dates) {
        switch (d.month) {
            case 1: cout << "January "; break;
            case 2: cout << "February "; break;
            case 3: cout << "March "; break;
            case 4: cout << "April "; break;
            case 5: cout << "May "; break;
            case 6: cout << "June "; break;
            case 7: cout << "July "; break;    
            case 8: cout << "August "; break;
            case 9: cout << "September "; break;
            case 10: cout << "October "; break;
            case 11: cout << "November "; break;
            case 12: cout << "December "; break;
        }
        cout << d.day << ", " << d.year << endl;
    }
}

int main() {
    vector<Date> dates;
    Date date;
    int n = -1;
    while (n != 0) {
        cout << "This is Date structure" << endl;
        cout << "These are some functions:" << endl;
        cout << "1. Add new date." << endl;
        cout << "2. Return the day of the week for a date." << endl;
        cout << "3. Calculate the difference in days between two dates." << endl;
        cout << "4. Print the dates." << endl;
        cout << "0. End the program." << endl;
        cout << "Enter the number of function: ";
        cin >> n;
        if (n == 1) {
            clear();
            date.newDate(dates);
        }
        if (n == 2) {
            clear();
            date.getDayOfWeek(dates);
        }
        if (n == 3) {
            clear();
            date.calculateDifference(dates);
        }
        if (n == 4) {
        clear();
        sort(dates.begin(), dates.end(), compareDates);
        printDate(dates);
    }
    }
    return 0;
}
