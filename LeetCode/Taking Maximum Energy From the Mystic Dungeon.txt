class Solution {
public:
int maximumEnergy(vector<int> &energy, int k) {
    int ans = INT_MIN, n = energy.size();
    for (int i = n - 1; i >= 0; i--) {
        energy[i] += (i + k) < n ? energy[i + k] : 0;
        ans = max(ans, energy[i]);
    }
    return ans;
}
};
