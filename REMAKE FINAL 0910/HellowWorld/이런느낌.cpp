////#include "이런느낌.h"
////
////static const char* Week[7] = { "월요일","화요일","수요일","목요일","금요일","토요일","일요일" };
////
////bool Check(int y)
//		{
////    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); ////// 윤년조건
////}
////
////static int DaysInMonthFunc(int y, int m) 
//		{
////    switch (m) {
////    case 1:  return 31;
////    case 2:  return Check(y) ? 29 : 28;
////    case 3:  return 31;
////    case 4:  return 30;
////    case 5:  return 31;
////    case 6:  return 30;
////    case 7:  return 31;
////    case 8:  return 31;
////    case 9:  return 30;
////    case 10: return 31;
////    case 11: return 30;
////    case 12: return 31;
////    default: return 0;
////    } //////잘못한듯 ?날짜떄려바ㅑㄱ자 모르겟네
////	}
////
////int GetTotalDays(int y, int m, int d) 
//		{
////    int days = 0;
////    for (int i = 1; i < y; ++i) days += Check(i) ? 366 : 365;
////    for (int i = 1; i < m; ++i) days += DaysInMonthFunc(y, i);
////    days += (d - 1);
////    return days;
////		}
////
////const char* GetDayOfWeek(int y, int m, int d)  //////날짜ㄱㄱ
//		{
////    int days = GetTotalDays(y, m, d);
////    return Week[days % 7];
////	}

//////나중에 ㄱ ㅈㅈ