﻿#include <iostream>
#include "array.h"

using namespace std;

void fill_array(Array* arr) {
	int height;
	int size = array_size(arr);
	for (int i = 0; i < size; i++) {
		cout << "write height students(cm): ";
		cin >> height;
		array_set(arr, i, height);
	}
}

int find_average(Array* arr) {
	int average = 0;
	int size = array_size(arr);
	for (int i = 0; i < size; i++) {
		average += array_get(arr, i);
	}
	return average / size;
}

int find_count_students(Array* arr, int average) {
	int count = 0;
	int size = array_size(arr);
	for (int i = 0; i < size; i++) {
		if (array_get(arr, i) > average) count++;
	}
	return count;
}

int main() {
	setlocale(LC_ALL, "rus");
	//Create an array with students
	int size;
	cout << "write size: ";
	cin >> size;
	Array* arr = array_create(size);

	//fill array
	fill_array(arr);

	//search average value
	int average = find_average(arr);

	//search for the number of students whose growth is above average
	cout << "Количество студентов у которых рост выше среднего по классу: " << find_count_students(arr, average) << "\n\n";
}