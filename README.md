FunCPP - A Fun(ctional) C++11 Library inspired by Ruby
==============================================================

Caution: Under heavy development!

How to compile
----------------
It is recommended to use vagrant to install all dependencies. 
The current gcc version used is *gcc version 4.8.1 (Ubuntu 4.8.1-2ubuntu1~12.04)*

	cd FunCPP
	vagrant up
	vagrant ssh
	mkdir build
	cd build
	cmake -Dtest=ON /vagrant
	make
	./runUnitTests

Example
------------

	funcpp::String a = "hello how are you";
	a.each_char( [](char c) {
	   cout << c << "_";
	} );
