#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

double Euclideano(const pair<double, double> &punto1, const pair<double, double> &punto2)
{
	double dx = punto1.first - punto2.first;
	double dy = punto1.second - punto2.second;
	return pow((dx * dx + dy * dy), 0.5);
}

double closestPairDistance(const vector<pair<double, double>> &puntos)
{
	double minDist = numeric_limits<double>::infinity();

	for (int i = 0; i < puntos.size(); i++)
	{
		for (int j = i + 1; j < puntos.size(); j++)
		{
			double dist = Euclideano(puntos[i], puntos[j]);
			minDist = min(minDist, dist);
		}
	}

	return minDist;
}

int main()
{
	int N;

	while (cin >> N && N != 0)
	{
		vector<pair<double, double>> puntos(N);

		for (int i = 0; i < N; i++)
		{
			cin >> puntos[i].first;
			cin >> puntos[i].second;
		}

		double minDistance = closestPairDistance(puntos);

		if (minDistance < 10000)
		{
			cout << fixed;
			cout.precision(4);
			cout << minDistance << endl;
		}
		else
		{
			cout << "INFINITY" << endl;
		}
	}
	return 0;
}