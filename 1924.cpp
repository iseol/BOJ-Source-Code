#include <iostream>
#include <string>

using namespace std;

int month, date;
int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int total_days;

int main() {
	cin >> month >> date;
	
	for (int i = 1; i < month; i++) {
		total_days += days_in_month[i];
	}
	total_days += date;
	
	cout << day[total_days%7] << endl; // 총 일 수를 7로 나눈 나머지에 따라 출력 
}
