#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <list>
#include <string>
using namespace std;


int main()
{
	

// 主程序
#if 0
	// 169 多数元素
	vector<int> nums = { 2,2,3,4,6,2,5,2,2 };
	cout << DSYuanSu::majorityElement(nums) << endl;
	
	// 088 合并两个有序数组
	int m = 3;
	int n = 3;
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> nums2 = { 2, 5, 6 };
	HBYXShuZu::merge(nums1, m, nums2, n);

	// 069 X的平方根 6% 63%
	int x = 2147395600;
	int a = 2147483649;
	cout << a << endl;
	cout << XPFangGen::mySqrt(x) << endl;

	// 067 二进制求和
	string a = "1110110101", b = "1110111011";
	cout << EJZQiuHe::addBinary(a, b) << endl;

	// 066 加一 40% 91%
	vector<int> s = { 9,9,9 };
	vector<int> ans = JiaYi::plusOne(s);
	for (auto c : ans) {
		cout << c << " ";
	}

	// 058 最后一个单词的长度 100% 63%
	string s = "moon  ";
	cout << ZHYGChangDu::lengthOfLastWord(s) << endl;

	// 053 最大连续子数组的和 69% 69%
	vector<int> s = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << ZDLXZShuZu::maxSubArray(s) << endl;

	// 035 搜索插入位置 71% 35%
	vector<int> s = { 1,3,5,6 };
	int target = 2;
	cout << SSCRWeiZhi::searchInsert(s, target) << endl;

	// 028 实现strStr
	string x = "hello";
	string y = "";
	cout << ImpnstrStr::strStr(x, y) << endl;

	// 027 移除元素
	vector<int> num = { 1,2,3,3,5 };
	int goal = 3;
	cout << YiChuYuanSu::removeElement(num, 3) << endl;

	// 026 删除重复元素
	vector<int> arr = { 0,0,1,1,1,2,2,3,3,4 };
	cout << SCCFYuanSu::removeDuplicates(arr) << endl;

	// 021 合并有序链表
	ListNode* l1 = new ListNode();
	ListNode* l2 = new ListNode();
	l1->val = 1; l1->next = l2;
	YXLianBiao::mergeTwoLists(l1, l2);

	// 020 有效的括号
	cout << YouXiaoKuoHao::isValid("{[]}") << endl;

	// 014 最长公共前缀
	vector<string> str = { "leets", "leetcode", "leet", "leets" };
	cout << str[0].substr(0, 3) << endl;
	cout << GGQianZhui::longestCommonPrefix(str) << endl;

	// 013 罗马数字转整数
	int x = LuoMa::romanToInt("MCDLXXVI");
	cout << x << endl;

	// 09 回文数判断
	int a = 121;
	int b = 1876336781;
	int c = 123456;
	int d = 12345;
	cout << HuiWenShu::isPalindrome(a) << endl;

	// 007 整数反转* 41% 63%
	int x = 1231234526;
	cout << "X原本的数值为：" << '\t' << x << endl;
	cout << "倒转后的数值为：" << ZSFZhuan::reverse(x) << endl;

	// 006 Z字型变换* 78% 50%
	string s = "PAY";
	int x = 7;
	cout << ConvertZ::convert(s, x) << endl;

	// 005 最长回文子串
	MaxHuiWen s;
	string a = s.longestPalindrome("babad");
	cout << a << endl;

	// 003 无重复子串
	string s = "pwwkew";
	cout << WCFZiChuan::lengthOfLongestSubstring(s) << endl;

	// 001 两数相加
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> ans = SumOfTwoNumber::twoSum(nums, target);
	cout << ans[0] << "\t" << ans[1] << endl;

	//替换字符串空格相关指令
	string myStr = "I am happy";
	cout << Solution2::replaceSpace(myStr) << endl;
	return 0;

	//声明data数组，用于承载待排序数据
	int* data;

	//待排序数组的规模，由小至大
	int scale[5] = { 1000, 5000, 10000, 15000, 20000 };

	//声明时钟用于记录排序操作所用时间
	clock_t start, end;

	//为五种大小的数组赋予随机值，并记录冒泡排序操作时间
	for (int i = 0; i < 5; i++)
	{
		data = new int[scale[i]];
		for (int j = 0; j < scale[i]; j++)
		{
			data[j] = (int)rand();
		}
		start = clock();
		myBubbleSort(data, scale[i]);
		end = clock();
		cout << scale[i] << "\t" << end - start << endl;
		/* @result
		1000    3
		5000    56
		10000   272
		15000   631
		20000   1094*/
#endif
}


// 169 多数元素
class DSYuanSu {
public:
	static int majorityElement(vector<int>& nums) {
		/*sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];*/

		unordered_map<int, int> record;//元素->频率
		for (int i = 0; i < nums.size(); ++i)
		{
			// 数组中的数字为键值，键值对应着一个出现次数
			// 每次循环均找到键值所对应的出现次数并+1

			// 对图的nums[i]键值进行++赋值时，自动创建配对关系
			// 如第一次出现“2”的时候，则创建对[2, 1]，第二次出现“2”的时候则该对变为[2, 2]
			record[nums[i]]++;
			if (record[nums[i]] > nums.size() / 2)return nums[i];
		}
		return -1;
	}
};

// 088 合并两个有序数组
class HBYXShuZu {
public:
	static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
#if 0
		if (m == 0) {
			nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
			nums1.pop_back();
			for (int c : nums1) {
				cout << c << " ";
			}
			return;
		}

		int i = 0;
		int j = 0;
		vector<int>::iterator it = nums1.begin();
	outloop:
		for (; j < n; j++) {
			while (nums2[j] < nums1[m - 1]) {
				for (; ; ++i) {
					if (nums1[i] == nums2[j]
						|| (nums1[i] < nums2[j] && nums1[i + 1] > nums2[j])) {
						nums1.insert(it + i, nums2[j]);
						nums1.pop_back();
						++i;
						++j;
						goto outloop;
					}
				}
			}
			break;
		}

		if (i < m + n) {
			nums1.insert(nums1.begin() + i + j + 1, nums2.begin() + j, nums2.end());
			nums1.erase(nums1.begin() + m + n, nums1.end());

		}
		for (int c : nums1) {
			cout << c << " ";
		}
		return;
#endif
		// 自己想的方法类似于正向双指针，但是由于水平问题代码写的太过于臃肿，最终也没能实现需求
		// 还有一种没想到的方法，即先合并再利用sort(nums1.begin(), nums1.end())指令进行排序
		// 下述方法较为巧妙，主要思想是逆向比大小&替换
		int i = nums1.size() - 1;
		m--;
		n--;
		while (n >= 0) {
			while (m >= 0 && nums1[m] > nums2[n]) {
				swap(nums1[i--], nums1[m--]);
			}
			swap(nums1[i--], nums2[n--]);
		}
	}
};

// 069 X的平方根 6% 63%
class XPFangGen {
public:
	static int mySqrt(int x) {
		int i = 0;
		unsigned long i2 = 0;
		while (size_t(i * i) <= x) {
			i += 1;
		}
		if (i * i == x)
		{
			return i;
		}
		else return i - 1;
	}
};

// 067 二进制求和
class EJZQiuHe {
public:
	static string addBinary(string a, string b) {
		string ans;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int n = max(a.size(), b.size()), carry = 0;
		for (size_t i = 0; i < n; ++i) {
			carry += i < a.size() ? (a.at(i) == '1') : 0;
			carry += i < b.size() ? (b.at(i) == '1') : 0;
			ans.push_back((carry % 2) ? '1' : '0');
			carry /= 2;
		}

		if (carry) {
			ans.push_back('1');
		}
		reverse(ans.begin(), ans.end());

		return ans;
	}
};

// 066 加一 40% 91%
class JiaYi {
public:
	static vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		for (int i = len - 1; i >= 0; --i) {
			if (digits[i] != 9) {
				digits[i] ++;
				return digits;
			}
			else digits[i] = 0;
		}
		if (digits[0] == 0) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

// 058 最后一个单词的长度 100% 63%
class ZHYGChangDu {
public:
	static int lengthOfLastWord(string s) {
		int len = s.length();
		int tail = 0;
		for (int i = len - 1; i > 0; --i) {
			if (s[i] != ' ') {
				tail = i;
				break;
				//goto outloop;
			}
		}

		//outloop:
		for (int i = tail - 1; i >= 0; --i) {
			if (s[i] == ' ') {
				return tail - i;
			}
		}
		return tail + 1;
	}
};

// 053 最大连续子数组的和 69% 69%
class ZDLXZShuZu {
public:
	static int maxSubArray(vector<int>& nums) {

		int len = nums.size(), pre = 0, ans = 0;
		for (int i = 1; i < len; ++i) {
			// 如果某元素的前值大于零，则将前值加到该元素上
			if (nums[i - 1] > 0) {
				nums[i] += nums[i - 1];
			}
		}
		// 上述for循环已经修改了vector数组，此时的数组每个值都是子串相加值
		ans = *max_element(nums.begin(), nums.end());
		return ans;
	}
};

// 035 搜索插入位置 71% 35%
class SSCRWeiZhi {
public:
	static int searchInsert(vector<int>& nums, int target) {
		int len = nums.size();
		int front = 0, end = len - 1, mid = 0;
		if (target < nums[0]) return 0;
		else if (target > nums[len - 1]) return len;

		else
			while (end - front != 1)
			{
				mid = (front + end) / 2;
				if (nums[mid] > target)
				{
					end = mid;
				}
				else if (nums[mid] < target)
				{
					front = mid;
				}
				else return mid;
			}

		if (nums[front] == target) return front;
		else return end;
		/*else if (nums[end] == target) return end;
		else return front + 1;*/
	}
};

// 028 实现strStr
class ImpnstrStr {
public:
	static int strStr(string haystack, string needle) {
		// 该算法时间复杂度较高，不如KMP算法
		// c语言strStr的特性，空串返回“0”
		if (needle == "") {
			return 0;
		}
		int hlen = haystack.length();
		int nlen = needle.length();
		// 要寻找的子串长度若更大，则不可能成为子串
		if (nlen > hlen) {
			return -1;
		}
		// 整块查找，暴力
		for (int i = 0; i <= hlen - nlen; ++i) {
			if (haystack.substr(i, nlen) == needle) {
				return i;
			}
		}
		return -1;
	}
};

// 027 移除元素
class YiChuYuanSu {
public:
	static int removeElement(vector<int>& nums, int val) {
		int len = nums.size();
		for (int i = len - 1; i >= 0; --i)
		{
			if (nums[i] == val)
			{
				nums.erase(nums.begin() + i);
			}
		}
		/*for (int i : nums)
		{
			cout << i << endl;
		}*/
		return nums.size();
	}
};

// 026 删除重复元素
class SCCFYuanSu {
public:
	static int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		vector <int>::iterator Iter;
		for (int i = len - 1; i >= 0; --i)
		{
			if (i == 0)
			{
				for (Iter = nums.begin(); Iter != nums.end(); Iter++)
				{
					cout << " " << *Iter;
				}
				cout << endl;
				return nums.size();
			}
			if (nums[i] == nums[i - 1])
			{
				nums.erase(nums.begin() + i);
			}
		}
		return nums.size();
	}
};

// 026 合并有序链表
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class YXLianBiao {
public:
	static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		// 使用带头结点的链表解决问题
		// 待输出链表的头部
		ListNode* head = new ListNode();

		// 待输出链表的 last 结点
		ListNode* last = head;
		while (list1 != nullptr && list2 != nullptr) {
			if (list1->val > list2->val) {
				last->next = list2;
				list2 = list2->next;
			}
			else {
				last->next = list1;
				list1 = list1->next;
			}
			last = last->next;
		}

		// l1 或 l2 可能还有剩余结点没有合并， 
		// 由于从上面的 while 循环中退出， 那么链表 l1 和 l2 至少有一个已经遍历结束
		if (list1 != nullptr) last->next = list1;
		if (list2 != nullptr) last->next = list2;

		return head->next;
	}
};

// 020 有效的括号
class YouXiaoKuoHao {
public:
	static bool isValid(string s) {
		int len = s.length();
		for (int j = 0; j < len / 2; j++) {
			for (int i = 0; i < s.length() - 1; i++) {
				if ((s[i] == '(' && s[i + 1] == ')') ||
					(s[i] == '[' && s[i + 1] == ']') ||
					(s[i] == '{' && s[i + 1] == '}')) {
					s.erase(i, 2);
					break;
				}
			}
		}
		if (s == "") {
			return 1;
		}
		else return 0;
	}
};

// 014 最长公共前缀
class GGQianZhui {
public:
	static string longestCommonPrefix(vector<string>& strs)
	{
		if (!strs.size())
		{
			return "";
		}
		//元素0的长度
		int length = strs[0].size();
		// 元素的个数
		int count = strs.size();

		for (int i = 0; i < length; ++i)
		{
			//先定义第一个元素的i位置为char c，再将其他的相同位置的char
			//都与之作比较，相同继续，不同直接返回i-1长度的子串
			char c = strs[0][i];

			for (int j = 1; j < count; ++j)
			{
				//返回的条件：其余串位置与char c不一样了或者到长度了
				//如果有一列出现了异常，则直接返回该列减一的子串
				//如果至i列都没问题，i+1列到长度了（i从0起）则最大子串长度为i
				if (i == strs[j].size() || strs[j][i] != c)
				{
					//str.substr(a, b)返回的是str从a位置数b个元素的子串
					return strs[0].substr(0, i);
				}
			}
		}
		return strs[0];
	}
};

// 013 罗马数字转整数
class LuoMa {
public:
	static int romanToInt(string s) {
		int num = 0;
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (s[i] == 'M')
			{
				num += 1000;
			}

			else if (s[i] == 'D')
			{
				num += 500;
			}

			else if (s[i] == 'C')
			{
				if (s[i + 1] == 'D')
				{
					num += 400;
					if (i + 2 == len)
					{
						return num;
					}
					i += 1;
				}
				else if (s[i + 1] == 'M')
				{
					num += 900;
					if (i + 2 == len)
					{
						return num;
					}
					i += 1;
				}
				else
					num += 100;
			}

			else if (s[i] == 'L')
			{
				num += 50;

			}

			else if (s[i] == 'X')
			{
				if (s[i + 1] == 'L')
				{
					num += 40;
					if (i + 2 == len)
					{
						return num;
					}
					i += 1;
				}
				else if (s[i + 1] == 'C')
				{
					num += 90;
					if (i + 2 == len)
					{
						return num;
					}
					i += 1;
				}
				else
					num += 10;
			}

			else if (s[i] == 'V')
			{
				num += 5;
			}

			else if (s[i] == 'I')
			{
				if (s[i + 1] == 'V')
				{
					num += 4;
					if (i + 2 == len)
					{
						return num;
					}
					i += 1;
				}
				else if (s[i + 1] == 'X')
				{
					num += 9;
					if (i + 2 == len)
					{
						return num;
					}
					i += 1;
				}
				else
					num += 1;
			}
		}
		return num;
	}
};

// 009 回文数判断
class HuiWenShu {
public:
	static bool isPalindrome(int x) {
		string str = to_string(x);
		//注意s.zize()要加括号
		int len = str.size();
		for (int i = 0; i < len / 2; i++)
		{
			//注意str[i]从下标0开始，故尾部元素应先减一
			if (str[i] != str[len - 1 - i])
			{
				return false;
			}
		}
		return true;
	}
};

// 007 整数反转* 41% 63%
class ZSFZhuan {
public:
	static int reverse(int x) {
		int rev = 0;
		while (x != 0)
		{
			int pop = x % 10;
			x /= 10;
			if ((rev > INT_MAX / 10) || (rev == INT_MAX / 10 && pop > 7))
			{
				return 0;
			}
			else if ((rev < INT_MIN / 10) || rev == INT_MIN / 10 && pop < -8)
			{
				return 0;
			}

			rev = rev * 10 + pop;
		}
		return rev;
	}
};

// 006 Z字型变换* 78% 50%
class ConvertZ {
public:
	static string convert(string s, int numRows) {
		if (numRows == 1) return s;

		vector<string> rows(min(numRows, int(s.size()))); // 防止s的长度小于行数
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) {// 当前行curRow为0或numRows -1时，箭头发生反向转折
				goingDown = !goingDown;
			}
			curRow += goingDown ? 1 : -1;
		}

		string ans;
		for (string row : rows) {// 从上到下遍历行
			ans += row;
		}

		return ans;
	}
};

// 005 最长回文子串
class MaxHuiWen {
public:
	string longestPalindrome(string s)
	{
		if (s.length() < 1)
		{
			return "";
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int len1 = expandAroundCenter(s, i, i);//一个元素为中心
			int len2 = expandAroundCenter(s, i, i + 1);//两个元素为中心
			int len = max(len1, len2);
			if (len > end - start)
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	int expandAroundCenter(string s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{// 计算以left和right为中心的回文串长度
			L--;
			R++;
		}
		return R - L - 1;
	}

};

// 003 无重复子串
class WCFZiChuan {
public:
	static int lengthOfLongestSubstring(string s) {
		// 哈希集合，记录每个字符是否出现过
		unordered_set<char> occ;
		int n = s.size();
		// 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
		int rk = -1, ans = 0;
		// 枚举左指针的位置，初始值隐性地表示为 -1
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				// 左指针向右移动一格，移除一个字符
				occ.erase(s[i - 1]);
			}
			// occ.count()返回哈希集合中已有的相同元素个数
			while (rk + 1 < n && !occ.count(s[rk + 1])) {
				// 不断地移动右指针
				occ.insert(s[rk + 1]);
				++rk;
			}
			// 第 i 到 rk 个字符是一个极长的无重复字符子串
			ans = max(ans, rk - i + 1);
		}
		return ans;
	}
};

// 001 两数之和
class SumOfTwoNumber {
public:
	static vector<int> twoSum(vector<int>& nums, int target)
	{
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (nums[i] + nums[j] == target) {
					return { i, j };
				}
			}
		}
		return {};
	}
};

//字符串替换函数
class Solution2 {
public:
	static string replaceSpace(string s) {
		int count = 0, len = s.size();
		// 统计空格数量
		// 此处用到了C++11语法，利用char c来遍历字符串s
		for (char c : s) {
			if (c == ' ') count++;
		}
		// 修改 s 长度
		s.resize(len + 2 * count);
		// 倒序遍历修改
		for (int i = len - 1, j = s.size() - 1; i < j; i--, j--) {
			if (s[i] != ' ')
				s[j] = s[i];
			else {
				s[j - 2] = '%';
				s[j - 1] = '2';
				s[j] = '0';
				j -= 2;
			}
		}
		return s;
	}
};

//冒泡排序函数
void myBubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			int temp;
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	return;
}