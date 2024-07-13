class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        double ans = 0.0;
        int starting_time = customers[0][0];
        int end = 0, waiting = 0;
        for (auto &row: customers) {
            if (row[0] > starting_time) {
                end = row[0] + row[1];
                waiting = row[1];
                starting_time = end;
            } else {
                end = starting_time + row[1];
                waiting = end - row[0];
                starting_time = end;
            }
            ans += waiting;
        }
        return ans / customers.size();
    }
};
--------------------------------------------------------------------
class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        double ans = 0.0;
        int starting_time = customers[0][0];
        int end = 0, waiting = 0;
        for (auto &row: customers) {
            auto arrival = row[0];
            auto time = row[1];

            if (arrival > starting_time) starting_time = arrival;
            starting_time += time;

            ans += starting_time - arrival;
        }
        return ans / customers.size();
    }
};
--------------------------------------------------------------------
class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        double ans = 0.0;
        int starting_time = customers[0][0];
        int end = 0, waiting = 0;
        for (auto &row: customers) {
            auto arrival = row[0], time = row[1];
            starting_time = max(starting_time, arrival) + time;
            ans += starting_time - arrival;
        }
        return ans / customers.size();
    }
};

