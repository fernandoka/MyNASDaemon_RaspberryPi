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


bool DaemonFileManager::writePidAndRefreshTime(int pid, int timeMs){
	bool res = true;

	try{
		ofstream ofs;
		ofs.open(this->confFileName);
		if(!ofs.is_open()){
			syslog(LOG_ERR,"Unable to open .conf file to write pid, stopping daemon");
			res = false;
		}
		if(res)
			ofs << pid << endl << timeMs << endl;

		ofs.close();
	}
	catch(exception &e) {
		syslog(LOG_ERR,"Exception ocurred, fail writting pid in .conf file, %s", e.what());
		res = false;
	}

	return res;
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

		if(!confFileExist()){

			try{ createConfFile();}
			catch(exception &e) {
				syslog(LOG_ERR,"Exception ocurred, fail setting up MyNASDaemon_RaspberryPi .conf file, %s", e.what());
				return false;
			}

		}

	return true;

}// setup()



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
bool DaemonFileManager::dirExists(){
    struct stat info;

    int statRC = stat( this->folderName, &info );

    return ( statRC ==0 && (info.st_mode & S_IFDIR) );
}


bool DaemonFileManager::createFolder(){

	mode_t mode = S_IRWXU | (S_IRGRP|S_IXGRP) | (S_IROTH|S_IXOTH);
	return !mkdir(this->folderName, mode);
}

bool DaemonFileManager::confFileExist(){
    struct stat info;

    int statRC = stat( this->confFileName, &info );

    return ( statRC ==0 && !(info.st_mode & S_IFDIR) );
}

void DaemonFileManager::createConfFile(){
	ofstream ofs(this->confFileName);
	ofs.close();
}


