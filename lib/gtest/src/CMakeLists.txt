cmake_minimum_required(VERSION 2.8.12.1)

add_gtest_sources(gtest.cc 
	gtest-death-test.cc 
	gtest-filepath.cc 
	gtest-internal-inl.h 
	gtest-port.cc 
	gtest-printers.cc 
	gtest-test-part.cc 
	gtest-typed-test.cc)