#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        // Sort folders lexicographically
        std::sort(folder.begin(), folder.end());

        std::vector<std::string> result;
        std::string currentParent = "";

        for (const std::string& f : folder) {
            // If `f` is not a sub-folder of `currentParent`, add it to the result
            if (currentParent.empty() || f.find(currentParent + '/') != 0) {
                result.push_back(f);
                currentParent = f; // Update the current parent folder
            }
        }

        return result;
    }
};
