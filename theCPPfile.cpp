#include <iostream>
#include <fstream>
#include "Complex.h"

int main() {
	ifstream domain("domain.txt");
	ofstream nFile("nFile.txt");
	Complex z0, z;
	int numberOfRows = 500, numberOfColumns = 500, nMax = 5000, row, col, n;
	double realMin, realMax, imagMin, imagMax;
	domain >> realMin; 
	domain >> realMax; 
	domain >> imagMin; 
	domain >> imagMax;
	
	for(row = 0; row < numberOfRows; row++) {
		for (col = 0; col < numberOfColumns; col++) {
			z0.setVals((realMax - realMin) * col / (numberOfColumns - 1) + realMin, (imagMax - imagMin) * row / (numberOfRows - 1) + imagMin);
			z = z0;
			n = 0;
			while (n < nMax && z.getMag() < 2) {
				z = z * z + z0;
				n++;
			}
			nFile << n << " ";
		}
		nFile << endl;
	}
	domain.close();
	nFile.close();
	return 0;
}