Hal_core is a lightweight hal environment.

The installed size is approx 6.8Mib

A hal environment can be used as platform to run realtime applications like:

	motion controllers 
	robots
	cnc-machines 
	parport, ethercat applications
	research and development 
	scientific projects
	   
Hal-core can interact with high end software packages like "qt", "kdl kinematics", "opencascade cad", "ruckig trajectory", etc.
Therefore consider to install these software packages before installing hal-core. 

To install:

		$ sudo apt-get install git

		# Set user permissions to the /opt dir.
		$ sudo chmod 777 /opt

		# If you don't have installed qt, kdl kinematics, opencascade cad, you can consider to do this now.
		# Hal-core is working exstensively with these c++ libraries, but hal-core will work without it.
		$ wget https://github.com/grotius-cnc/Linux-Pro/releases/download/1.0.0/qt-creator.deb
		$ wget https://github.com/grotius-cnc/Linux-Pro/releases/download/1.0.0/kdl-kinematics.deb

		# New wget link with opencascade image support
		$ wget ...

		# Dependencies opencascade
		$ sudo apt-get install doxygen cmake tcllib tklib tcl-dev tk-dev libfreetype-dev libx11-dev libgl1-mesa-dev libfreeimage-dev rapidjson-dev 
		$ sudo apt-get install libxmu-dev libxi-dev libfreeimage3 libfreeimage-dev ffmpeg

		# Install packages
		$ sudo dpkg -i qt-creator.deb kdl-kinematics.deb opencascade.deb

		# Install hal-core
		$ git clone https://github.com/grotius-cnc/hal_core.git /opt/hal-core
		$ sudo chmod +x /opt/hal-core/prepare
		$ sudo /opt/hal-core/./prepare
		$ sudo /opt/hal-core/./make
	
To run hal-core:

	$ /opt/hal-core/./runtest

https://user-images.githubusercontent.com/44880102/129791198-ab705999-23ca-4004-a5f5-f0bd3357b47e.mp4
