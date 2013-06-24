#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "memo.h"
#include "ordlist.h"

class Scheduler
{
	public:
		Scheduler();
		void copyConstTest();
		void insertMemo(Memo newMemo);
		void deleteMemo(char *time);
	    void readMemos(char filename[]);
		void writeMemos(char filename[]);	
		void displayMemos();
		void mergeMemos(char filename[]);
		void clearMemos();

	private:
		OrdList<Memo, int> memos;  
};
#endif