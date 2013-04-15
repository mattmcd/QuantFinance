all: test test_JC test_Phi test_PhiInverse test_PayOff test_Option test_Wrapper test_Random

test_Phi: test_Phi.cpp Phi_JC.cpp
	$(CXX) -std=c++0x -o test_Phi test_Phi.cpp 

test_PhiInverse: test_PhiInverse.cpp PhiInverse_JC.cpp
	$(CXX) -std=c++0x -o test_PhiInverse test_PhiInverse.cpp 

test: test.cpp Normals.cpp Normals.hpp
	$(CXX) -std=c++0x -I. -o test test.cpp Normals.cpp 

test_JC: test.cpp Normals.hpp Phi_JC.cpp PhiInverse_JC.cpp
	$(CXX) -std=c++0x -I. -o test_JC test.cpp Phi_JC.cpp PhiInverse_JC.cpp

test_PayOff: test_PayOff.cpp PayOff.hpp PayOff.cpp
	$(CXX) -std=c++0x -I. -o test_PayOff test_PayOff.cpp PayOff.cpp

test_Option: test_Option.cpp VanillaOption.hpp PayOff.cpp
	$(CXX) -std=c++0x -I. -o test_Option test_Option.cpp PayOff.cpp

test_Wrapper: test_Wrapper.cpp PayOff.cpp
	$(CXX) -std=c++0x -I. -o test_Wrapper test_Wrapper.cpp PayOff.cpp

test_Random: testRandom.cpp
	$(CXX) -std=c++0x -o test_Random testRandom.cpp
