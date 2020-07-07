#include <iostream>
#include <string>
using namespace std;

class VO {
private:
	int ch1, m1, s1, dpoint1, dpoint2;

public:
	VO(string time)
	{
		ch1 = ((int)time[0] - 48) * 10 + ((int)time[1] - 48);
		m1 = ((int)time[3] - 48) * 10 + ((int)time[4] - 48);
		s1 = ((int)time[6] - 48) * 10 + ((int)time[7] - 48);
		dpoint1 = (int)time[2];
		dpoint2 = (int)time[5];
	}

	VO VO::operator-(VO temp)
	{
		VO res("00:00:00");
		if (temp.ch1 > 23 || ch1 > 23 || temp.m1 > 59 || m1 > 59 || temp.s1 > 59 || s1 > 59 || dpoint1!=58 || dpoint2!=58 || temp.dpoint1 != 58 || temp.dpoint2 != 58)
		{
			cout << "Error!" << endl;
			res.ch1 = -1;
			return res;
		}
			res.ch1 = temp.ch1 - ch1;
			res.m1 = temp.m1 - m1;
			res.s1 = temp.s1 - s1;
			if (res.s1 < 0)
			{
				res.s1 = res.s1 + 60;
				res.m1--;
			}
			if (res.m1 < 0)
			{
				res.m1 = res.m1 + 60;
				res.ch1--;
			}
			if (res.ch1 < 0)
			{
				res.ch1 = res.ch1 + 24;
			}
			return res;
	}
	void getVO()
	{
		if (ch1 < 0 || m1 < 0 || s1 < 0)
			//cout << "Error!" << endl;
			exit;
		else
		cout << "Raznica: " << ch1 << ":" << m1 << ":" << s1 << endl;
	}
	friend ostream& operator<<(ostream& out, VO obj1)
	{
		obj1.getVO();
		return out;
	}
};