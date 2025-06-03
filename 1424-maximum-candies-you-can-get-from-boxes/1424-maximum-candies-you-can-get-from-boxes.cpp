class Solution {
public:
    int maxCandies(vector<int>& statuses, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int totalCandies = 0; // This will hold the running total of candies collected.
        int numBoxes = statuses.size(); // Get the number of boxes.
        vector<bool> hasBox(numBoxes, false); // Tracks if we have a box.
        vector<bool> openedBox(numBoxes, false); // Tracks if we've opened a box.
        queue<int> openableBoxes; // Queue to hold boxes that can be opened.

        // Loop over all initially available boxes and try to open them.
        for (int boxId : initialBoxes) {
            hasBox[boxId] = true; // We have this box.
            // If the box is not locked, collect its candies and consider its contents.
            if (statuses[boxId]) {
                totalCandies += candies[boxId]; // Add candies from the current box.
                openedBox[boxId] = true; // Mark the box as opened.
                openableBoxes.push(boxId); // Add it to the queue of boxes to process.
            }
        }

        // Process boxes while there are openable boxes available.
        while (!openableBoxes.empty()) {
            int currentBoxId = openableBoxes.front();
            openableBoxes.pop();

            // Go through the keys obtained from the current box and try to open corresponding boxes.
            for (int key : keys[currentBoxId]) {
                statuses[key] = 1; // The box that corresponds to the key can now be opened.
                // If we have the box and have not yet opened it, collect candies and open it.
                if (hasBox[key] && !openedBox[key]) {
                    totalCandies += candies[key]; // Add candies from the box we can now open.
                    openedBox[key] = true; // Mark the box as opened.
                    openableBoxes.push(key); // Add it to the queue of boxes to process.
                }
            }

            // Go through all boxes contained within the current box.
            for (int containedBox : containedBoxes[currentBoxId]) {
                hasBox[containedBox] = true; // We have this box.
                // If the box is not locked and we haven't opened it yet, collect candies.
                if (statuses[containedBox] && !openedBox[containedBox]) {
                    totalCandies += candies[containedBox]; // Add candies from the contained box.
                    openedBox[containedBox] = true; // Mark the box as opened.
                    openableBoxes.push(containedBox); // Add it to the queue of boxes to process.
                }
            }
        }

        return totalCandies;
    }
};