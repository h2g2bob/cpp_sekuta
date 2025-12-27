all: sekuta

sekuta: digit.cpp sekuta.cpp
	g++ sekuta.cpp digit.cpp -o sekuta
