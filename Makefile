all: sekuta

sekuta: digit.cpp sekuta.cpp state.cpp
	g++ sekuta.cpp digit.cpp state.cpp -o sekuta
