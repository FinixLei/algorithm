// This program is calculate days between two given dates 

#include <iostream>
using namespace std;

int month2Days[13] = {
    0, 
    31,     // 1
    28,     // 2
    31,     // 3
    30,     // 4
    31,     // 5
    30,     // 6
    31,     // 7
    31,     // 8
    30,     // 9
    31,     // 10
    30,     // 11
    31      // 12
};

int daysFromMonthBeignToYearEnd[13] = {
    0,          // place holder
    365,        // from 01/01 to year end
    365-31,     // from 02/01 to year end
    365-31-28,  // from 03/01 to year end
    365-31-28-31,       // from 04/01 to year end
    365-31-28-31-30,    // from 05/01 to year end
    365-31-28-31-30-31, // from 06/01 to year end
    31+31+30+31+30+31,  // from 07/01 to year end
    31+30+31+30+31,     // from 08/01 to year end
    30+31+30+31,    // from 09/01 to year end
    31+30+31,       // from 10/01 to year end
    30+31,      // from 11/01 to year end
    31          // from 12/01 to year end
};


inline bool isLeapYear(int year) {
    return ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) );
}

bool validDate(int y, int m, int d) {
    if (y < 0 || m <= 0 || d <= 0) return false;
    
    if (isLeapYear(y) && m == 2) {
        if (d > 29) return false;
    }
    else {
        if (month2Days[m] < d) return false;
    }
    return true;
}

int daysToYearEnd(int y, int m, int d) {
    int count = month2Days[m] - d;
    if (m+1 <= 12) count += daysFromMonthBeignToYearEnd[m+1];
    if (m <= 2 && isLeapYear(y)) count ++;
    return count;
}

int DateDiff(int y1, int m1, int d1, int y2, int m2, int d2) 
{
    if (!validDate(y1, m1, d1)) throw "Wrong Date1";
    if (!validDate(y2, m2, d2)) throw "Wrong Date2";
    
    // Suppose date2 should be bigger than date1
    if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1==y2 && m1==m2 && d1>d2)) {
        return -DateDiff(y2, m2, d2, y1, m1, d1);
    }
    
    int daysToY1End = daysToYearEnd(y1, m1, d1);
    int daysToY2End = daysToYearEnd(y2, m2, d2);
    // cout << daysToY1End << endl;
    // cout << daysToY2End << endl;
    
    int leapYearsForY1 = y1/4 - y1/100 + y1/400;
    int leapYearsForY2 = y2/4 - y2/100 + y2/400;
    // cout << "leapYearsForY1=" << leapYearsForY1 << ", leapYearsForY2=" << leapYearsForY2 << endl;
    int daysBetweenYearEnds = (y2-y1) * 365 + leapYearsForY2 - leapYearsForY1;
    
    int diffDays = daysToY1End + daysBetweenYearEnds - daysToY2End;
    return diffDays;
}

int main()
{
    int y1=1982, m1=9, d1=15, y2=2021, m2=11, d2=20;
    int result = DateDiff(y1, m1, d1, y2, m2, d2);
    cout << "From " << y1 << "-" << m1 << "-" << d1 << " to "
         << y2 << "-" << m2 << "-" << d2 << ", there are " << result << " days." << endl;
    return 0;
}