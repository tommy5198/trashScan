#include <cmath>
#include <random>
#include <iostream>
#include <chrono>

double pathLoss = 3.3;
double pwrLoss = 55;
double d0 = 1;
double F = 13;
double k = 1.38064852e-23;
double T0 = 27;
double Bn = 30000; 
double R = 19.2 * 1024;
double f = 20;
double M = 2;
double sigma = 2; // Z-Curve³]¬°2, 4, 6, 8 

double GetPacketSuccessRate(double recPwr)
{
	double noisePwr = 10 * log10((F + 1) * k * T0 * Bn * 1000); // dbm
	double SNR = recPwr - noisePwr;
	double bitErr = exp(-SNR * Bn / R /2)/2;
	return pow(1 - bitErr, 8 * f * M);
}

double GetEstimatedDistance(double transPwr, double dis)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine randGen(seed);
	std::normal_distribution<double> noiseDist(0, sigma);
	double recPwr = transPwr - (pwrLoss + 10 * pathLoss * log10(dis/d0) + noiseDist(randGen));
	return pow(10, (transPwr - recPwr - pwrLoss) / pathLoss / 10) * d0;
}

double GetDis(double ax, double, ay, double bx, double by)
{
    return sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
}
