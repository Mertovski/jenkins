#!/bin/bash
#-------------------------------------------------------------
#     FILE: TOOL_INSTALLATION_1.5.BASH
#     DESCRIPTION: INSTALLATION OF TOOLS FOR ENVIRONMENT
#     VERSION: 1.5
#-------------------------------------------------------------


#Installing C++ compiler and related tools

sudo apt-get update

sudo apt-get install build-essential manpages-dev

#Setting up parameters to 

if ["$1" == '-help']
	then
		echo "Welome to the help page"
		echo "Here is a list of arguements you"
		echo "-all			|	Installs all depencies"
		echo "-postgres 	|	Installs postgres"
		echo "-pgadmin		|	Installs pgadmin"
		echo "-cppunit		|	Installs cppunit"
		echo "-cppcheck		|	Installs ccpcheck"
		echo "-test			|	This runs test. first -all"
		
fi

if ["$1" == '-postgres'] || [ "$1" == '-all' ] 
	then
#installing postgres and additional packages
#PostGIS
#Procedural languages
#client interfaces
sudo apt-get install postgresql postgresql-contrib
apt-cache search postgres
fi

if ["$1" == -pgadmin] || [ "$1" == '-all' ]
	then
#installing PGadmin3 for the lovers
sudo apt-get install pgadmin3
fi

if ["$1" == -cppunit] || [ "$1" == '-all' ]
	then
#Installing Cppunit
apt-get install libcppunit-doc libcppunit-dev
fi

if ["$1" == -cppcheck] || [ "$1" == '-all' ]
	then
#Installing CPPCheck
sudo apt-get install tre-agrep cppcheck
fi

if ["$1" == '-all']
#cloning the repository for code
git clone feature-01 http://github.com/SDEV56/INFPRJ0156.git

if ["$1" == '-test']
mkdr logs

#running cloc
cat logs/cloc_log.txt
cloc --out=logs/cloc_log.txt INFPRJ0156
