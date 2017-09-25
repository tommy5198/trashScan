#include <vector>
#include "env.h"
#include "gen.h"
#include "util.h"

using namespace std;

int main() {
    
    int K = 6;
    vector<Node> nodeMap = GenerateNodeMap();
    double becX = 0, becY = 0;
    int numOfPkt = 0;
    do {
        // collect info
        for(int i=0; i<nodeMap.size(); i++) {
            Node& node = nodeMap[i];
            node.predDis = GetEstimatedDistance(transPwr, GetDis(becX, becY, node.x, node.y));
            if(node.predDis != -1) {
                for(int j=0; i<nodeMap.size(); j++) {
                    if(i == j) continue;
                    Node& nodeHop = nodeMap[i];
                }
            }
        }
        for(int i = 0; i < K; i++) {
            SV[i] = A * (lda[0] * numOfB[i][0] + lda[1] * numOfB[i][1] + lda[2] * numOfB[i][2] - lda[3] * numOfB[i][3]) / (sumOfRec[i] + 1) + B * sumRec[i] / sumTotRec;
            if(SV[i] > maxSV) {
                maxSV = SV[i];
                dir = i;
            }
        }
        if(SV[(dir+K+1)%K] > SV[(dir+K-1)%K])
            dirNxt = (dir+K+1)%K;
        else
            dirNxt = (dir+K-1)%K;

    }

    return 0;
}
