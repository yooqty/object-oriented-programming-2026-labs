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
		void normalize();
		
		MyTime add(int sec);
		MyTime sub(int sec);
		MyTime add(MyTime time);
		MyTime sub(MyTime time);
		
		int toSeconds() const;
		
		// Comparison operators (to filter flights within an interval)
		bool operator<(const MyTime& other) const;
        bool operator>(const MyTime& other) const;
        bool operator<=(const MyTime& other) const;
        bool operator>=(const MyTime& other) const;
};

#endif // MYTIME_H
