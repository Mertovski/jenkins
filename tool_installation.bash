#!/bin/bash
#-------------------------------------------------------------
#     FILE: TOOL_INSTALLATION.BASH
#     DESCRIPTION: INSTALLATION OF TOOLS FOR ENVIRONMENT
#     VERSION: 1.0
#-------------------------------------------------------------


#Installing C++ compiler and related tools

sudo apt-get update

sudo apt-get install build-essential manpages-dev



#installing postgres and additional packages
#PostGIS
#Procedural languages
#client interfaces
sudo apt-get install postgresql postgresql-contrib
apt-cache search postgres

##creating a postgres account
#sudo -i -u postgres

#installing PGadmin3 for the lovers
 sudo apt-get install pgadmin3

