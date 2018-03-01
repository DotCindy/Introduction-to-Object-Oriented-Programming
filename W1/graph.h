/*
Name:                   Cindy Le
Email:                  cle15@myseneca.ca
Date:                   January 23, 2018
Workshop:               At Home
Description:            Compiling Modules
*/

#ifndef SICT_GRAPH_H
#define SICT_GRAPH_H
#define MAX_NO_OF_SAMPLES 20

namespace sict {
	void printGraph(int samples[], int noOfSamples);
	void printBar(int val, int max);
	void getSamples(int samples[], int noOfSamples);
	int findMax(int samples[], int noOfSamples);
}

#endif
