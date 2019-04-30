#include <iostream>
#include <algorithm>
using namespace std;

int findClockAngle(int h, int m)
{
	if(h < 0 || m < 0 || h > 12 || m > 60)
		return -1;
	
	if(h == 12) h=0;
	if(m == 60) m = 0;
	
	// 360 degree/12 hr = 30 and m/2 is the degree it moved based on minute
	int hour_angle = h * 30 + (m/2); 
	// 360 degree / 60 min = 6
	int min_angle = m * 6; 
	
	int angle = abs(hour_angle-min_angle);
	
	return min(360-angle, angle);
}

int main()
{
	cout << "The degree bewteen 9 and 60 is " << findClockAngle(9, 60) << endl;
	cout << "The degree bewteen 6 and 30 is " << findClockAngle(6, 30) << endl;
	cout << "The degree bewteen 3 and 45 is " << findClockAngle(3, 45) << endl;
	cout << "The degree bewteen 2 and 25 is " << findClockAngle(2, 25) << endl;
	return 0;
}