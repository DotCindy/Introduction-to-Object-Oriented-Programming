/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 22, 2018
OOP244 - Workshop 9
*/

#ifndef SICT_DATA_H
#define SICT_DATA_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	// max returns the largest item in data
	//
	template <typename T>
	T max(const T* data, int n) {
		T maxData = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++) {
			if (maxData > data[i]) {
				maxData = maxData;
			}
			else {
				maxData = data[i];
			}
		}
		return maxData;
	}

	// min returns the smallest item in data
	//
	template <typename T>
	T min(const T* data, int n) {
		T minData = LARGEST_NUMBER;
		for (int i = 0; i < n; i++) {
			if (minData < data[i]) {
				minData = minData;
			}
			else {
				minData = data[i];
			}
		}
		return minData;
	}

	
	// sum returns the sum of n items in data
	//
	template <typename T>
	T sum(const T* data, int n) {
		T total = 0;
		for (int i = 0; i < n; i++) {
			total += data[i];
		}
		return total;
	}

	// average returns the average of n items in data
	//
	template <typename T>
	double average(const T* data, int n) {
		double total = 0.00;
		for (int i = 0; i < n; i++) {
			total += data[i];
		}
		return total / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		for (int i = 0; i < n; i++) {
			input.ignore(2000, ',');
			input >> data[i];
		}
		return true;
	}

	// display inserts n items of data into std::cout
	//
	template <typename T>
	void display(const char* name, const T* data, int n) {
		std::cout.width(20);
		std::cout << name;
		for (int i = 0; i < n; i++) {
			if (strcmp(name, "ViolentCrime_Rate") == 0 || strcmp(name, "GrandTheftAuto_Rate") == 0) {
				std::cout.setf(std::ios::fixed);
				std::cout.precision(1);
				std::cout.width(15);
				std::cout << data[i];
				std::cout.unsetf(std::ios::fixed);
				std::cout.precision(6);
			}
			else {
				std::cout.width(15);
				std::cout << data[i];
			}
		};
		std::cout << std::endl;

	}

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif
