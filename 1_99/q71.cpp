/**
 * 71. Simplify Path
 * https://leetcode.com/problems/simplify-path
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) {
            return "/";
        }

        // extract names
        std::vector<string_view> pathNames;
        size_t i = path.find_first_of('/', 0);
        size_t j = path.find_first_of('/', i + 1);
        print_line(sep, path);
        while (i != string::npos) {
            string_view name;
            if (j != string::npos) {
                name = {path.data() + i + 1, j - i - 1};
            } else {
                name = {path.data() + i + 1, path.size() - i - 1};
            }
            print_var(i, j, string{name});
            if (name == "..") {
                if (!pathNames.empty()) {  // cannot goback from the root level
                    pathNames.pop_back();  // go back one level
                }
            } else if (name == ".") {
                // ignore
            } else {
                if (!name.empty()) {
                    pathNames.push_back(name);
                }
            }
            i = j;
            j = path.find_first_of('/', i + 1);
        }

        // reconstruct a simplified path
        if (pathNames.empty()) {
            return "/";
        }

        string result{};
        for (int k = 0; k < pathNames.size(); ++k) {
            result += "/";
            result += pathNames[k];
        }

        return result;
    }
};

int main() {
    print_line(Solution().simplifyPath("/home/"));
    print_line(Solution().simplifyPath("/home//foo/"));
    print_line(Solution().simplifyPath("/home//foo/../pic"));
    print_line(Solution().simplifyPath("/home/user/Documents/../Pictures"));
    print_line(Solution().simplifyPath("/../"));
    print_line(Solution().simplifyPath("/.../a/../b/c/../d/./"));
    print_line(Solution().simplifyPath(""));
}