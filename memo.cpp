#include"memo.h"

Memo::Memo(){
	memset(time,0,6);//fill 0-value
	memset(title,0,41);//fill 0-value 

}

void Memo::setTitle(const char* title){
	if(title){
		memset(this->title,0,41);//erase old title
		strcpy(this->title,title);//set new title
	}
}

void Memo::setTime(const char* time){
	if(time){
		memset(this->time,0,41);//erase old time
		strcpy(this->time,time);//set new time
	}
}

const char * Memo::getTime(){
	return time;
}

const char * Memo::getTitle(){
	return title;
}

int Memo::getKey(){

	int resultKey = -1;

	if(time){

		//get hour
		char hourStr[3];
		strncpy(hourStr,time,2);//copy 2 chars from time
		hourStr[2] = '\0';/* null character manually added */
		int hour = atoi(hourStr);
		
		//get minute
		char minutesStr[3];
		minutesStr[0] = time[3];
		minutesStr[1] = time[4];
		minutesStr[2] = '\0';
				
		int minutes = atoi(minutesStr);

		resultKey = hour * 100 + minutes;
	}

	return resultKey;
}