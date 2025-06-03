class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        vector<bool> seen(n, false);        // Already opened boxes
        vector<bool> boxAvailable(n, false);// Boxes we have
        vector<bool> keyAvailable(n, false);// Keys we have
        vector<bool> inQueue(n, false);     // To avoid pushing duplicates in queue

        // Initialize queue with initial boxes
        for (int box : initialBoxes) {
            boxAvailable[box] = true;
            q.push(box);
            inQueue[box] = true;
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int box = q.front();
            q.pop();
            inQueue[box] = false;

            if (seen[box]) continue;

            // If box is open or we have the key
            if (status[box] == 1 || keyAvailable[box]) {
                seen[box] = true;
                totalCandies += candies[box];

                // Collect keys from this box
                for (int key : keys[box]) {
                    if (!keyAvailable[key]) {
                        keyAvailable[key] = true;
                        // If we have the box but haven’t opened it, push to queue
                        if (boxAvailable[key] && !seen[key] && !inQueue[key]) {
                            q.push(key);
                            inQueue[key] = true;
                        }
                    }
                }

                // Collect boxes contained inside
                for (int innerBox : containedBoxes[box]) {
                    if (!boxAvailable[innerBox]) {
                        boxAvailable[innerBox] = true;
                        if (!seen[innerBox] && !inQueue[innerBox]) {
                            q.push(innerBox);
                            inQueue[innerBox] = true;
                        }
                    }
                }
            } 
            // **DO NOT** push the box back here if you can’t open it yet
            // Just ignore it and wait until you get the key
        }

        return totalCandies;
    }
};

//can't open it yet, keep it for later
//basically, we push all the boxes in, if we pop and see that it can't be opened, but at a later point of time, it's available and we get the key, we push it in again and give it another chance