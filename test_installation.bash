#!/bin/bash
#-------------------------------------------------------------
#     FILE: TEST_INSTALLATION.BASH
#     DESCRIPTION: TOOLS THAT WILL BE USED FOR TESTING IN THE ENVIRONMENT
#     VERSION: 1.0
#-------------------------------------------------------------

#first cloning the repository for code
git clone feature-01 http://github.com/SDEV56/INFPRJ0156.git


#Installing Cppunit
apt-get install libcppunit-doc libcppunit-dev

#installing cloc
sudo apt-get install cloc
echo 'Installation is complete..'
echo 'Running cloc..'


#make directory for test logs
mkdr logs

#running cloc
cat logs/cloc_log.txt
cloc --out=logs/cloc_log.txt INFPRJ0156

#Installing CPPCheck
sudo apt-get install tre-agrep cppcheck
