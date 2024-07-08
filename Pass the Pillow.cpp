class Solution {
public:
    int passThePillow(int n, int time) {
        if(n > time) return time+1;
        int start = 1;
        bool add = 1;
        while(time){
            if(add) start++;
            else if(!add) start--;
            if(start == n) add = 0;
            else if(start == 1) add = 1; 
            time--;
        }
        return start;
    }
};
-------------------------------------------------------------
class Solution {
public:
    int passThePillow(int n, int time) {
        if(n > time) return time+1;
        int direction = 1;
        int start = 1;
        while(time){
            start +=direction;
            if(start == 1 || start == n) direction *= -1;
            time--;
        }
        return start;
    }
};
--------------------------------------------------------------
class Solution {
public:
    int passThePillow(int n, int time) {
        if(n > time) return time+1;
        int direction = time / (n-1);
        int position = time % (n-1);

        return (direction & 1) ? n - position : position + 1;
    }
};
