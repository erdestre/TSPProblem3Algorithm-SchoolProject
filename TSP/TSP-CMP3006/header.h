#pragma once

#include <chrono>
#include <iostream>
#include <fstream> 
#include <string>  
#include <vector>

const int cityCount = 4663;
using namespace std;
int tourLength = 0;
bool merge = true;
int counter = 0;
vector<double> FinalTourX;
vector<double> FinalTourY;
vector<int> FinalTourPos;

vector<int> GreedyAlgorithm(vector<double> x, vector<double> y, vector<int> pos)
{
	vector<double> GidilmemislerX = x;
	vector<double> GidilmemislerY = y;
	vector<int> GidilmemislerPos = pos;

	int randomCity = rand() % GidilmemislerX.size();
	int nextCityPos = 0; //Sonraki þehir
	int dumbCounter = 0;

	double temp = 0, smallestDistance = -1;

	FinalTourX.push_back(GidilmemislerX[randomCity]);
	FinalTourY.push_back(GidilmemislerY[randomCity]);
	FinalTourPos.push_back(GidilmemislerPos[randomCity]);

	double x1 = GidilmemislerX[randomCity];
	double y1 = GidilmemislerY[randomCity];
	int poss = GidilmemislerPos[randomCity];


	while (!(GidilmemislerX.empty()))
	{
		FinalTourX.push_back(GidilmemislerX[randomCity]);
		FinalTourY.push_back(GidilmemislerY[randomCity]);
		FinalTourPos.push_back(GidilmemislerPos[randomCity]);

		poss = GidilmemislerPos[nextCityPos];

		GidilmemislerX.erase(GidilmemislerX.begin() + randomCity); //Ýlk þehir silindi
		GidilmemislerY.erase(GidilmemislerY.begin() + randomCity);
		GidilmemislerPos.erase(GidilmemislerPos.begin() + randomCity);


		for (int j = 0; j < GidilmemislerX.size(); j++)
		{

			double X2 = GidilmemislerX[j];
			double Y2 = GidilmemislerY[j];


			temp = sqrt(pow((x1 - X2), 2) + pow((y1 - Y2), 2));

			if (smallestDistance > temp || smallestDistance == -1) {
				smallestDistance = temp;
				nextCityPos = j;
			}
		}
		tourLength = tourLength + smallestDistance;

		smallestDistance = -1; //Mevcut þehrin en yakýný bulunduktan sonra mesafeyi yok ediyoruz

		if (GidilmemislerX.size() > 0) {
			randomCity = rand() % GidilmemislerX.size();
			x1 = GidilmemislerX[randomCity];
			y1 = GidilmemislerY[randomCity];
		}

		dumbCounter++;
	}

	temp = sqrt(pow((x[0] - x[poss]), 2) + pow((y[0] - y[poss]), 2));
	tourLength = tourLength + temp; //smallestDistance yazýyordu
	//cout << poss << ". þehir otomatik olarak baþtaki þehirle baðlanýr. Rota uzunluðu " << tourLength << endl;

	return FinalTourX, FinalTourY, FinalTourPos;


}
vector<int> NearestNeighbour(vector<double> x, vector<double> y, vector<int> pos)
{
	vector<double> GidilmemislerX = x;
	vector<double> GidilmemislerY = y;
	vector<int> GidilmemislerPos = pos;

	vector<double> FinalTourX;
	vector<double> FinalTourY;
	vector<int> FinalTourPos;

	int nextCityPos = 0; //Sonraki þehir
	int dumbCounter = 0;

	double temp = 0, smallestDistance = -1;

	FinalTourX.push_back(GidilmemislerX[nextCityPos]);
	FinalTourY.push_back(GidilmemislerY[nextCityPos]);
	FinalTourPos.push_back(GidilmemislerPos[nextCityPos]);

	double x1 = GidilmemislerX[nextCityPos];
	double y1 = GidilmemislerY[nextCityPos];
	int poss = GidilmemislerPos[nextCityPos];


	while (!(GidilmemislerX.empty()))
	{


		if (dumbCounter == 0)
		{
			GidilmemislerX.erase(GidilmemislerX.begin() + nextCityPos); //Ýlk þehir silindi
			GidilmemislerY.erase(GidilmemislerY.begin() + nextCityPos);
			GidilmemislerPos.erase(GidilmemislerPos.begin() + nextCityPos);
		}


		for (int j = 0; j < GidilmemislerX.size(); j++)
		{
			double X2 = GidilmemislerX[j];
			double Y2 = GidilmemislerY[j];


			temp = sqrt(pow((x1 - X2), 2) + pow((y1 - Y2), 2));

			if (smallestDistance > temp || smallestDistance == -1) {
				smallestDistance = temp;
				nextCityPos = j;
			}
		}
		tourLength = tourLength + smallestDistance;

		if (!GidilmemislerPos.empty()) {
			poss = GidilmemislerPos[nextCityPos];
			FinalTourX.push_back(GidilmemislerX[nextCityPos]);
			FinalTourY.push_back(GidilmemislerY[nextCityPos]);
			FinalTourPos.push_back(GidilmemislerPos[nextCityPos]);

			x1 = GidilmemislerX[nextCityPos];
			y1 = GidilmemislerY[nextCityPos];

			GidilmemislerX.erase(GidilmemislerX.begin() + nextCityPos); //Þehir listeden çýkarýlýyor
			GidilmemislerY.erase(GidilmemislerY.begin() + nextCityPos);
			GidilmemislerPos.erase(GidilmemislerPos.begin() + nextCityPos);
		}

		smallestDistance = -1; //Mevcut þehrin en yakýný bulunduktan sonra mesafeyi yok ediyoruz

		dumbCounter++;

	}
	if (merge) {
		temp = sqrt(pow((x[0] - x[poss]), 2) + pow((y[0] - y[poss]), 2));
		tourLength = tourLength + temp;
		//cout << poss << ". þehir otomatik olarak baþtaki þehirle baðlanýr. Rota uzunluðu " << tourLength << endl;
	}

	return FinalTourX, FinalTourY, FinalTourPos;
}

vector<int> DivideConquer(vector<double> x, vector<double> y, vector<int> pos)
{
	vector<double> XLocs = x;
	vector<double> YLocs = y;
	vector<int> Poss = pos;
	vector<double> H1x, H2x, H1y, H2y;
	vector<int> H1p, H2p;
	merge = false;

	bool flag = true;

	if (Poss.size() < 3 && flag == true)
	{
		for (int i = 0; i < Poss.size(); i++)
		{
			H1x.push_back(XLocs[i]);
			H1y.push_back(YLocs[i]);
			H1p.push_back(Poss[i]);
		}

		H1x, H1y, H1p = NearestNeighbour(H1x, H1y, H1p);

	}
	else
	{
		for (int i = 0; i < Poss.size() / 2; i++)
		{
			H1x.push_back(XLocs[i]);
			H1y.push_back(YLocs[i]);
			H1p.push_back(Poss[i]);
		}
		for (int i = Poss.size() / 2; i < Poss.size(); i++)
		{
			H2x.push_back(XLocs[i]);
			H2y.push_back(YLocs[i]);
			H2p.push_back(Poss[i]);
		}
		flag = false;
		H1x, H1y, H1p = DivideConquer(H1x, H1y, H1p);
		H2x, H2y, H2p = DivideConquer(H2x, H2y, H2p);


		double a = sqrt(pow((H1x.front() - H2x.front()), 2) + pow((H1y.front() - H2y.front()), 2));
		double b = sqrt(pow((H1x.front() - H2x.back()), 2) + pow((H1y.front() - H2y.back()), 2));
		double c = sqrt(pow((H1x.back() - H2x.front()), 2) + pow((H1y.back() - H2y.front()), 2));
		double d = sqrt(pow((H1x.back() - H2x.back()), 2) + pow((H1y.back() - H2y.back()), 2));

		a = min(a, b);
		b = min(c, d);
		a = min(a, b);
		tourLength += a;
		if (a = sqrt(pow((H1x.front() - H2x.front()), 2) + pow((H1y.front() - H2y.front()), 2))) {
			for (int i = 0; i < H2x.size(); i++)
			{
				reverse(H1x.begin(), H1x.end());
				reverse(H1x.begin(), H1x.end());
				reverse(H1p.begin(), H1p.end());

				H1x.push_back(H2x[i]);
				H1y.push_back(H2y[i]);
				H1p.push_back(H2p[i]);
			}
		}
		else if (a = sqrt(pow((H1x.front() - H2x.back()), 2) + pow((H1y.front() - H2y.back()), 2))) {
			for (int i = 0; i < H2x.size(); i++)
			{
				reverse(H1x.begin(), H1x.end());
				reverse(H1x.begin(), H1x.end());
				reverse(H1p.begin(), H1p.end());
				reverse(H2x.begin(), H2x.end());
				reverse(H2x.begin(), H2x.end());
				reverse(H2p.begin(), H2p.end());

				H1x.push_back(H2x[i]);
				H1y.push_back(H2y[i]);
				H1p.push_back(H2p[i]);
			}
		}
		else if (a = sqrt(pow((H1x.back() - H2x.front()), 2) + pow((H1y.back() - H2y.front()), 2))) {
			for (int i = 0; i < H2x.size(); i++)
			{
				H1x.push_back(H2x[i]);
				H1y.push_back(H2y[i]);
				H1p.push_back(H2p[i]);
			}
		}
		else if (a = sqrt(pow((H1x.back() - H2x.back()), 2) + pow((H1y.back() - H2y.back()), 2))) {
			for (int i = 0; i < H2x.size(); i++)
			{
				reverse(H2x.begin(), H2x.end());
				reverse(H2x.begin(), H2x.end());
				reverse(H2p.begin(), H2p.end());

				H1x.push_back(H2x[i]);
				H1y.push_back(H2y[i]);
				H1p.push_back(H2p[i]);
			}
		}
	}
	return H1x, H1y, H1p;
}


void toTextFile(vector<int> Path, int algorithm, float timer, int distance) {

	ofstream file;

	if (algorithm == 0)
	{
		file.open("outputnn.txt");
		file << "Nearest Neighbour Algorithm \n";		
	}
	else if (algorithm == 1)
	{
		file.open("outputdc.txt");
		file << "Divide and Conquer Algorithm \n";		
	}
	else
	{
		file.open("outputg.txt");
		file << "Greedy Algorithm \n";		
	}

	file << "Start ---> Finish\n\n";
	for (int i = 1; i < Path.size(); i++)
	{
		file << Path[i - 1];
		file << " -----> ";
		file << Path[i];
		file << "\n";
	}
	file << Path.back();
	file << " -----> ";
	file << Path.front();

	file << "\nTime: ";
	file << timer;
	file << " ms \n";

	file << "Distance: ";
	file << distance;
	file << " KM \n";

	file << "\n \n \n";


	file.close();
}


void arrFormat(string* arr) //We have to take X,Y coordinates
{
	char space = ' ';
	string tempLine;
	double X, Y;
	int spaceLoc;

	vector<double> CitiesVectorX;
	vector<double> CitiesVectorY;
	vector<int> CityPos;

	for (int i = 0; i < cityCount; i++)
	{
		tempLine = arr[i];
		spaceLoc = tempLine.find(space);

		tempLine = tempLine.substr(spaceLoc + 1, tempLine.size());

		spaceLoc = tempLine.find(space);

		X = stod(tempLine.substr(0, spaceLoc - 1));
		Y = stod(tempLine.substr(spaceLoc + 1, tempLine.size()));


		CitiesVectorX.push_back(X);
		CitiesVectorY.push_back(Y);
		CityPos.push_back(i);

	}

	float greedyTimer, nearestNeighborTimer, divideConquerTimer;
	int greedyTourLength, nearestNeighborTourLength, divideConquerTourLength;

	///////////////NearestNeighbor///////////////////////////////////////////////////////////////////////////////////////////
	cout << "Nearest Neighbor Algorithm" << endl;
	auto start = chrono::steady_clock::now();
	FinalTourX, FinalTourY, FinalTourPos = NearestNeighbour(CitiesVectorX, CitiesVectorY, CityPos);
	auto end = chrono::steady_clock::now();


	nearestNeighborTimer = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	nearestNeighborTourLength = tourLength;
	toTextFile(FinalTourPos, 0, nearestNeighborTimer, nearestNeighborTourLength);
	tourLength = 0;

	FinalTourX.clear();
	FinalTourY.clear();
	FinalTourPos.clear();

	///////////////Divide&Conquer///////////////////////////////////////////////////////////////////////////////////////////
	cout << endl << "Divide&Conquer Algorithm" << endl;
	start = chrono::steady_clock::now();
	FinalTourX, FinalTourY, FinalTourPos = DivideConquer(CitiesVectorX, CitiesVectorY, CityPos);
	end = chrono::steady_clock::now();


	divideConquerTimer = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	divideConquerTourLength = tourLength;
	toTextFile(FinalTourPos, 1, divideConquerTimer, divideConquerTourLength);
	tourLength = 0;

	FinalTourX.clear();
	FinalTourY.clear();
	FinalTourPos.clear();

	///////////////Greedy////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << endl << "Greedy Algorithm" << endl;
	start = chrono::steady_clock::now();
	FinalTourX, FinalTourY, FinalTourPos = GreedyAlgorithm(CitiesVectorX, CitiesVectorY, CityPos);
	end = chrono::steady_clock::now();

	greedyTimer = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	greedyTourLength = tourLength;
	toTextFile(FinalTourPos, 2, greedyTimer, greedyTourLength);
	tourLength = 0;


	cout << endl << "Greedy Algorithm" << endl;
	cout << "Tour Length: " << greedyTourLength << endl;
	cout << "Compile Time: " << greedyTimer << endl;

	cout << endl << "Divide&Conquer Algorithm" << endl;
	cout << "Tour Length: " << divideConquerTourLength << endl;
	cout << "Compile Time: " << divideConquerTimer << endl;

	cout << endl << "Nearest Neighbor Algorithm" << endl;
	cout << "Tour Length: " << nearestNeighborTourLength << endl;
	cout << "Compile Time: " << nearestNeighborTimer << endl;



}

void fileOpener() {
	string tempArrayList[cityCount];
	ifstream File;
	string line;
	File.open("ca4663.tsp");
	if (File.fail()) { cerr << "Error opening file !!" << endl; exit(1); }

	int lineCounter = 0;		//Refer as document line
	int takenLineCounter = 0;   //Refer as Array's line/counter
	while (!File.eof()) {
		getline(File, line);
		if (lineCounter >= 7 && lineCounter < 4670)
		{
			tempArrayList[takenLineCounter] = line;
			takenLineCounter++;
		}
		lineCounter++;
	}
	File.close();
	arrFormat(tempArrayList);
}


