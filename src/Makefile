all: test Phi PhiInverse

Phi: Phi_JC.cpp
	g++ -std=c++0x -o Phi Phi_JC.cpp 

PhiInverse: PhiInverse_JC.cpp
	g++ -std=c++0x -o PhiInverse PhiInverse_JC.cpp 

test: test.cpp Normals.cpp Normals.hpp
	g++ -std=c++0x -I. -o test test.cpp Normals.cpp 
