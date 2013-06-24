#ifndef MEMO_H
#define MEMO_H

#include<cstring>
#include<stdlib.h>//atoi

class Memo
{
	public:
		Memo();
		const char * getTime();
		const char * getTitle();
		void setTime(const char *);
		void setTitle(const char *);
		int getKey();
	private:
		char time[6];
		char title[41];
};

#endif
