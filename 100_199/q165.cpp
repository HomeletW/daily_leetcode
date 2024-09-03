/*
 * Given two version numbers, version1 and version2, compare them.
 *
 * https://leetcode.com/problems/compare-version-numbers
 */
#include <string>
#include <charconv>
#include <cassert>

#include "my_util.hpp"

using namespace std;

class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		return compareVersion_view(version1, version2);
	}

	int compareVersion_view(string_view version1, string_view version2)
	{
		int v1_int, v2_int;
		int v1_index, v2_index;
		v1_index = parseSubVersion(version1, v1_int);
		v2_index = parseSubVersion(version2, v2_int);

		std::cout << "v1: " << v1_int << ", v2: " << v2_int << "\n";

		if (v1_int < v2_int)
		{
			return -1;
		}
		else if (v1_int > v2_int)
		{
			return 1;
		}
		else
		{
			if (v1_index == version1.size() && v2_index == version2.size())
			{
				return 0;
			}
			else if (v1_index == version1.size())
			{
				return compareVersion_view({}, version2.substr(v2_index + 1));
			}
			else if (v2_index == version2.size())
			{
				return compareVersion_view(version1.substr(v1_index + 1), {});
			}
			else
			{
				return compareVersion_view(version1.substr(v1_index + 1), version2.substr(v2_index + 1));
			}
		}
	}

	size_t parseSubVersion(string_view version, int& result)
	{
		if (version.empty())
		{
			result = 0;
			return 0;
		}

		size_t index = version.find_first_of('.');
		if (index == string_view::npos)
		{
			auto res = std::from_chars(version.begin(), version.end(), result);
			assert(res.ec != std::errc::invalid_argument);
			return version.size();
		}
		else
		{
			auto res = std::from_chars(version.begin(), version.begin() + index, result);
			assert(res.ec != std::errc::invalid_argument);
			return index;
		}
	}
};

int main()
{
	std::cout << std::boolalpha << Solution().compareVersion("123.123.0.1", "123.123.0.2") << "\n";
	std::cout << std::boolalpha << Solution().compareVersion("123.123.0.1", "123.123.0.0") << "\n";
	std::cout << std::boolalpha << Solution().compareVersion("123.123.0.1", "0") << "\n";
	std::cout << std::boolalpha << Solution().compareVersion("123.123.0.1", "0000122.123") << "\n";
}
