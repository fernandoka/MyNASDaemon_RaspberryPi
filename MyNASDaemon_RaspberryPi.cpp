//============================================================================
// Name        : MyNASDaemon_RaspberryPi.cpp
// Author      : Fernando Candelario Herrero
// Version     :
//============================================================================

#include <iostream>

#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main() {
	
	pid_t pid=fork();
	switch(pid){
		case -1:
			cout << "fork failed "  << endl;
			exit(-1);
		case 0:
			
			for (int i = 0; i < 12; ++i)
				cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	
			break;
		default:
			cout << "!!!Cucu!!!" << endl; // prints !!!Hello World!!!
					
			exit(0);
		}
}
