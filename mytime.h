#ifndef MYTIME_H
#define MYTIME_H

class MyTime
{
	public:
		int hour;
		int min;
		int sec;
		MyTime();
		MyTime(int hour, int min, int sec);
		void info();
		MyTime add(int sec);
		MyTime add(MyTime time);
};

#endif // MYTIME_H
