class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange){
            ans += numBottles/numExchange;
            numBottles = (numBottles/numExchange) + (numBottles % numExchange);
        }
        return ans;
    }
};
-------------------------------------------------------------------------------------

class Solution {
public:
    int numWaterBottles(int b, int e) {
        return (b*e-1)/(e-1);
    }
};
