#include <vector>

double maxX = 1000; // m
double maxY = 1000; // m
int numOfNodes = 1000;
int numOfMan = 1;

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
double sigma = 2; // Z-Curve: 2, 4, 6, 8 

struct BeaconPacket {
    int ID;
    double x, y;
    int TTL;
};

struct NodePacket {
    int ID;
    double x, y;
    double dis;
    int TTL;
};

struct FeedBkPacket {
    int ID;
    int numOfRec;
    int Hop;
    double dis;
};

struct Node {
    double x, y;
    double predX, predY;
    double actualDis, predDis;
};


std::vector<Node> nodeMap;

