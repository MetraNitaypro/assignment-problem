#pragma once
#include <vector>
#include <iterator>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
/*!
	\brief class rabota
	\author Artem Opryatin
	\version 1.0
	\date december 2020 
	\warning using this class only for studing

*/
class rabota {
private:
	/*!
cost table
*/
	vector<vector<int>> table;
	/*!
result
*/
	vector<vector<int>> result;
	/*!
auxiliary array
*/
	vector<int> used;
	/*!
auxiliary array
*/
	vector<int> buffer;
	/*!
counter
*/
	vector<int> buffer1;
	int r;
	/*!
price
*/
	int prise;
	/*!
size of cost table
*/
	int size;
	/*!
depth-first walk used for the Hungarian algorithm
\param[in] a graph
\param[in] v vertex
\param[out] bool djpisati
*/
	bool dfs(vector<vector<int>> &a, int v);
public:
	/*!
creates a matrix with the size specified in the input parameter
\param[in] size size matrix

*/
	rabota(const unsigned size);
	/*!
	reads a matrix of costs from a file
\param[in] f file name
\param[in] r class rabota

*/
	friend ifstream& operator>>(ifstream& f, rabota & r);
	/*!
		writes the program execution result to a file
\param[in] f file name
\param[in] r class rabota
*/
	friend ofstream& operator<<(ofstream& f, rabota& r);
	/*!
	brute force
*/
	void foo();
	/*!
	greedy algorithm
*/
	void foo1();
	/*!
	Hungarian algorithm
*/
	void Serb();
	void venger(vector<vector<int>>& a,vector<vector<int>>&g,vector<int>& k, vector<int>& v,int i);
};
