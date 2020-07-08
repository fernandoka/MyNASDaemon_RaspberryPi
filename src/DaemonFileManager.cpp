//============================================================================
// Name        : DaemonFileManager.cpp
// Author      : Fernando Candelario Herrero
// Version     :
//===============================

#include "DaemonFileManager.h"



//===============================
// 		PUBLIC METHODS
//===============================
DaemonFileManager::DaemonFileManager(){
	// TODO Auto-generated constructor stub
	this->setupOk = setup();
}

bool DaemonFileManager::isOk(){
	return this->setupOk;
}


//===============================
// 		PRIVATE METHODS
//===============================
bool DaemonFileManager::setup() {

	if(!dirExists()){
		if(!createFolder()){
		    syslog(LOG_ERR,"fail creating folder %s",strerror(errno));
		    return false;
		}
	}
	return true;
	/*try{
		ifstream ifs(this->fileConfName);

		if(!ifs.good())
			openFileErrors(ifs);
	}
	catch(exception &e) {
		syslog(LOG_ERR,"MyNASDaemon_RaspberryPi >> fail setting up the daemon files, %s", e.what());
	}*/

}



void DaemonFileManager::openFileErrors(ifstream &ifs){
    string s = "fail opening .conf file, ";

    if(ifs.fail())
    	s + "Bit fail active";

    if(ifs.eof())
    	s + ", Bit eof active" ;

    if(ifs.bad())
    	s + ", Bit bad active" ;

    syslog(LOG_ERR,"%s",s.c_str());
}

// Based on...
// https://stackoverflow.com/questions/18100097/portable-way-to-check-if-directory-exists-windows-linux-c
bool DaemonFileManager::dirExists()
{
    struct stat info;

    int statRC = stat( this->folderName, &info );

    return ( statRC ==0 && (info.st_mode & S_IFDIR) );
}


bool DaemonFileManager::createFolder(){

	mode_t mode = S_IRWXU | (S_IRGRP|S_IXGRP) | (S_IROTH|S_IXOTH);
	return !mkdir(this->folderName, mode);
}

