/* ------------------------------------------------------------------|
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。。|
------------------------------------------------------------------*/

/*	双指针法
*	
*	执行用时：4 ms, 在所有 C++ 提交中击败了94.91%的用户
*	内存消耗：6.6 MB, 在所有 C++ 提交中击败了77.96%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_map>

using namespace std;

int trap(vector<int>& height) 
{
	int left = 0;
	int right = height.size() - 1;
	int sum = 0;
	int lmax = 0;
	int rmax = 0;

	while (left < right)
	{
		if (height[left] < height[right])
		{
			height[left] >= lmax ? (lmax = height[left]) : (sum += lmax - height[left]);
			left++;
		}
		else
		{
			height[right] >= rmax ? (rmax = height[right]) : (sum += rmax - height[right]);
			right--;
		}
	}
	return sum;
}