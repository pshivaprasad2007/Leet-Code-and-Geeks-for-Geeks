class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int totalCount = points.size();
        if (totalCount <= 2) {
            return totalCount;
        }
        auto computeGcd = [](int valA, int valB) {
            while (valB != 0) {
                int remainder = valA % valB;
                valA = valB;
                valB = remainder;
            }
            return valA;
        };
        int maxCollinear = 0;
        for (int i = 0; i < totalCount; ++i) {
            map<pair<int, int>, int> slopeTracker;
            int currentMax = 0;
            for (int j = i + 1; j < totalCount; ++j) {
                int deltaX = points[j][0] - points[i][0];
                int deltaY = points[j][1] - points[i][1];
                if (deltaX == 0) {
                    deltaY = 1;
                } else if (deltaY == 0) {
                    deltaX = 1;
                } else {
                    if (deltaX < 0) {
                        deltaX = -deltaX;
                        deltaY = -deltaY;
                    }
                    int commonDiv = computeGcd(abs(deltaX), abs(deltaY));
                    deltaX /= commonDiv;
                    deltaY /= commonDiv;
                }
                slopeTracker[{deltaX, deltaY}]++;
                currentMax = max(currentMax, slopeTracker[{deltaX, deltaY}]);
            }
            maxCollinear = max(maxCollinear, currentMax + 1);
        }
        return maxCollinear;
    }
    }; 