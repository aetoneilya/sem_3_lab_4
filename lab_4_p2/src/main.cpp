#include <iostream>
#include "Date.hpp"

int main()
{
    Date calendar(2001, Month::DEC, 23, 23, 59, 59);
    Date calendar2(2002, Month::DEC, 3, 23, 59, 59);
    // calendar.addSecond(60);
    // calendar.addMinute(60);
    // calendar.addHour(24);
    // calendar.addDay(31);
    // calendar.addMonth(12);
    // calendar.addYear(1);
    
    DateInterval inter = calendar.getInterval(calendar2);
    calendar = calendar.addInterval(inter);
    std::cout << calendar.formatDate("year: YYYY month: MM(MMM) day: DD hh:mm:ss") << std::endl;

    char a;
    std::cin >> a;
}