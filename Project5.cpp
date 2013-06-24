#include "interface.h"
#include "linkedlist.h"


void main ()
{
    /*Interface cmdInterface;  

    while ( !cmdInterface.done() )
    {
       cmdInterface.getCommand();
       cmdInterface.executeCommand();
    }*/
	cout<<"HI baitch";
	LinkedList<char> listA;

	listA.insert('a',-1);
	listA.insert('b',-1);
	listA.insert('c',-1);
	listA.insert('d',-1);
	listA.insert('e',0);
	listA.insert('f',0);

	listA.remove();
	listA.remove();
	listA.remove();
	listA.remove();
	listA.remove();
	listA.remove();

	listA.insert('f',0);
	listA.insert('f',0);
	listA.insert('s',0);
	listA.insert('-',-1);
	listA.insert('-',-1);
	listA.insert('-',-1);
		

	//listA.clear();

	cout<<(bool)listA.empty();

	LinkedList<char> xz = listA;

	cout<<xz.retrieve();
	xz.gotoPrior();
	cout<<xz.retrieve();
	
}
