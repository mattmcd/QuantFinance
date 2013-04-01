all: test test_JC Phi PhiInverse

Phi: test_Phi.cpp Phi_JC.cpp
	g++ -std=c++0x -o Phi test_Phi.cpp 

PhiInverse: test_PhiInverse.cpp PhiInverse_JC.cpp
	g++ -std=c++0x -o PhiInverse test_PhiInverse.cpp 

test: test.cpp Normals.cpp Normals.hpp
	g++ -std=c++0x -I. -o test test.cpp Normals.cpp 

test_JC: test.cpp Normals.hpp Phi_JC.cpp PhiInverse_JC.cpp
	g++ -std=c++0x -I. -o test_JC test.cpp Phi_JC.cpp PhiInverse_JC.cpp
