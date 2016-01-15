#!/bin/bash
#-------------------------------------------------------------
#     FILE: TOOL_INSTALLATION.BASH
#     DESCRIPTION: INSTALLATION OF TOOLS FOR ENVIRONMENT
#     VERSION: 1.0
#-------------------------------------------------------------


#Installing C++ compiler and related tools

sudo apt-get update

sudo apt-get install build-essential manpages-dev

#Installing Jenkins
wget -q -O - https://jenkins-ci.org/debian/jenkins-ci.org.key | sudo apt-key add -
sudo sh -c 'echo deb http://pkg.jenkins-ci.org/debian binary/ > /etc/apt/sources.list.d/jenkins.list'
sudo apt-get update
sudo apt-get install jenkins

#setup Apache2 to proxy port 80 to 8080
sudo aptitude install apache2
sudo a2enmod proxy
sudo a2enmod proxy_http

#setting up file for Apache2

cat <<EOF >/etc/apache2/sites-available/jenkins.conf
<VirtualHost *:80>
	ServerAdmin webmaster@localhost
	ServerName ci.company.com
	ServerAlias ci
	ProxyRequests Off
	<Proxy *>
		Order deny,allow
		Allow from all
	</Proxy>
	ProxyPreserveHost on
	ProxyPass / http://localhost:8080/ nocanon
	AllowEncodedSlashes NoDecode
</VirtualHost>" >
EOF

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

