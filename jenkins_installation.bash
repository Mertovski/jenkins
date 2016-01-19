#-------------------------------------------------------------
#     FILE: JENKINS_INSTALLATION.BASH
#     DESCRIPTION: INSTALLATION OF JENKINS
#     VERSION: 1.0
#-------------------------------------------------------------


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