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
	

// ������
#if 0
	// 169 ����Ԫ��
	vector<int> nums = { 2,2,3,4,6,2,5,2,2 };
	cout << DSYuanSu::majorityElement(nums) << endl;
	
	// 088 �ϲ�������������
	int m = 3;
	int n = 3;
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> nums2 = { 2, 5, 6 };
	HBYXShuZu::merge(nums1, m, nums2, n);

	// 069 X��ƽ���� 6% 63%
	int x = 2147395600;
	int a = 2147483649;
	cout << a << endl;
	cout << XPFangGen::mySqrt(x) << endl;

	// 067 ���������
	string a = "1110110101", b = "1110111011";
	cout << EJZQiuHe::addBinary(a, b) << endl;

	// 066 ��һ 40% 91%
	vector<int> s = { 9,9,9 };
	vector<int> ans = JiaYi::plusOne(s);
	for (auto c : ans) {
		cout << c << " ";
	}

	// 058 ���һ�����ʵĳ��� 100% 63%
	string s = "moon  ";
	cout << ZHYGChangDu::lengthOfLastWord(s) << endl;

	// 053 �������������ĺ� 69% 69%
	vector<int> s = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << ZDLXZShuZu::maxSubArray(s) << endl;

	// 035 ��������λ�� 71% 35%
	vector<int> s = { 1,3,5,6 };
	int target = 2;
	cout << SSCRWeiZhi::searchInsert(s, target) << endl;

	// 028 ʵ��strStr
	string x = "hello";
	string y = "";
	cout << ImpnstrStr::strStr(x, y) << endl;

	// 027 �Ƴ�Ԫ��
	vector<int> num = { 1,2,3,3,5 };
	int goal = 3;
	cout << YiChuYuanSu::removeElement(num, 3) << endl;

	// 026 ɾ���ظ�Ԫ��
	vector<int> arr = { 0,0,1,1,1,2,2,3,3,4 };
	cout << SCCFYuanSu::removeDuplicates(arr) << endl;

	// 021 �ϲ���������
	ListNode* l1 = new ListNode();
	ListNode* l2 = new ListNode();
	l1->val = 1; l1->next = l2;
	YXLianBiao::mergeTwoLists(l1, l2);

	// 020 ��Ч������
	cout << YouXiaoKuoHao::isValid("{[]}") << endl;

	// 014 �����ǰ׺
	vector<string> str = { "leets", "leetcode", "leet", "leets" };
	cout << str[0].substr(0, 3) << endl;
	cout << GGQianZhui::longestCommonPrefix(str) << endl;

	// 013 ��������ת����
	int x = LuoMa::romanToInt("MCDLXXVI");
	cout << x << endl;

	// 09 �������ж�
	int a = 121;
	int b = 1876336781;
	int c = 123456;
	int d = 12345;
	cout << HuiWenShu::isPalindrome(a) << endl;

	// 007 ������ת* 41% 63%
	int x = 1231234526;
	cout << "Xԭ������ֵΪ��" << '\t' << x << endl;
	cout << "��ת�����ֵΪ��" << ZSFZhuan::reverse(x) << endl;

	// 006 Z���ͱ任* 78% 50%
	string s = "PAY";
	int x = 7;
	cout << ConvertZ::convert(s, x) << endl;

	// 005 ������Ӵ�
	MaxHuiWen s;
	string a = s.longestPalindrome("babad");
	cout << a << endl;

	// 003 ���ظ��Ӵ�
	string s = "pwwkew";
	cout << WCFZiChuan::lengthOfLongestSubstring(s) << endl;

	// 001 �������
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> ans = SumOfTwoNumber::twoSum(nums, target);
	cout << ans[0] << "\t" << ans[1] << endl;

	//�滻�ַ����ո����ָ��
	string myStr = "I am happy";
	cout << Solution2::replaceSpace(myStr) << endl;
	return 0;

	//����data���飬���ڳ��ش���������
	int* data;

	//����������Ĺ�ģ����С����
	int scale[5] = { 1000, 5000, 10000, 15000, 20000 };

	//����ʱ�����ڼ�¼�����������ʱ��
	clock_t start, end;

	//Ϊ���ִ�С�����鸳�����ֵ������¼ð���������ʱ��
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


// 169 ����Ԫ��
class DSYuanSu {
public:
	static int majorityElement(vector<int>& nums) {
		/*sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];*/

		unordered_map<int, int> record;//Ԫ��->Ƶ��
		for (int i = 0; i < nums.size(); ++i)
		{
			// �����е�����Ϊ��ֵ����ֵ��Ӧ��һ�����ִ���
			// ÿ��ѭ�����ҵ���ֵ����Ӧ�ĳ��ִ�����+1

			// ��ͼ��nums[i]��ֵ����++��ֵʱ���Զ�������Թ�ϵ
			// ���һ�γ��֡�2����ʱ���򴴽���[2, 1]���ڶ��γ��֡�2����ʱ����öԱ�Ϊ[2, 2]
			record[nums[i]]++;
			if (record[nums[i]] > nums.size() / 2)return nums[i];
		}
		return -1;
	}
};

// 088 �ϲ�������������
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
		// �Լ���ķ�������������˫ָ�룬��������ˮƽ�������д��̫����ӷ�ף�����Ҳû��ʵ������
		// ����һ��û�뵽�ķ��������Ⱥϲ�������sort(nums1.begin(), nums1.end())ָ���������
		// ����������Ϊ�����Ҫ˼��������ȴ�С&�滻
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

// 069 X��ƽ���� 6% 63%
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

// 067 ���������
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

// 066 ��һ 40% 91%
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

// 058 ���һ�����ʵĳ��� 100% 63%
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

// 053 �������������ĺ� 69% 69%
class ZDLXZShuZu {
public:
	static int maxSubArray(vector<int>& nums) {

		int len = nums.size(), pre = 0, ans = 0;
		for (int i = 1; i < len; ++i) {
			// ���ĳԪ�ص�ǰֵ�����㣬��ǰֵ�ӵ���Ԫ����
			if (nums[i - 1] > 0) {
				nums[i] += nums[i - 1];
			}
		}
		// ����forѭ���Ѿ��޸���vector���飬��ʱ������ÿ��ֵ�����Ӵ����ֵ
		ans = *max_element(nums.begin(), nums.end());
		return ans;
	}
};

// 035 ��������λ�� 71% 35%
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

// 028 ʵ��strStr
class ImpnstrStr {
public:
	static int strStr(string haystack, string needle) {
		// ���㷨ʱ�临�ӶȽϸߣ�����KMP�㷨
		// c����strStr�����ԣ��մ����ء�0��
		if (needle == "") {
			return 0;
		}
		int hlen = haystack.length();
		int nlen = needle.length();
		// ҪѰ�ҵ��Ӵ������������򲻿��ܳ�Ϊ�Ӵ�
		if (nlen > hlen) {
			return -1;
		}
		// ������ң�����
		for (int i = 0; i <= hlen - nlen; ++i) {
			if (haystack.substr(i, nlen) == needle) {
				return i;
			}
		}
		return -1;
	}
};

// 027 �Ƴ�Ԫ��
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

// 026 ɾ���ظ�Ԫ��
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

// 026 �ϲ���������
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
		// ʹ�ô�ͷ��������������
		// ����������ͷ��
		ListNode* head = new ListNode();

		// ���������� last ���
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

		// l1 �� l2 ���ܻ���ʣ����û�кϲ��� 
		// ���ڴ������ while ѭ�����˳��� ��ô���� l1 �� l2 ������һ���Ѿ���������
		if (list1 != nullptr) last->next = list1;
		if (list2 != nullptr) last->next = list2;

		return head->next;
	}
};

// 020 ��Ч������
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

// 014 �����ǰ׺
class GGQianZhui {
public:
	static string longestCommonPrefix(vector<string>& strs)
	{
		if (!strs.size())
		{
			return "";
		}
		//Ԫ��0�ĳ���
		int length = strs[0].size();
		// Ԫ�صĸ���
		int count = strs.size();

		for (int i = 0; i < length; ++i)
		{
			//�ȶ����һ��Ԫ�ص�iλ��Ϊchar c���ٽ���������ͬλ�õ�char
			//����֮���Ƚϣ���ͬ��������ֱͬ�ӷ���i-1���ȵ��Ӵ�
			char c = strs[0][i];

			for (int j = 1; j < count; ++j)
			{
				//���ص����������മλ����char c��һ���˻��ߵ�������
				//�����һ�г������쳣����ֱ�ӷ��ظ��м�һ���Ӵ�
				//�����i�ж�û���⣬i+1�е������ˣ�i��0��������Ӵ�����Ϊi
				if (i == strs[j].size() || strs[j][i] != c)
				{
					//str.substr(a, b)���ص���str��aλ����b��Ԫ�ص��Ӵ�
					return strs[0].substr(0, i);
				}
			}
		}
		return strs[0];
	}
};

// 013 ��������ת����
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

// 009 �������ж�
class HuiWenShu {
public:
	static bool isPalindrome(int x) {
		string str = to_string(x);
		//ע��s.zize()Ҫ������
		int len = str.size();
		for (int i = 0; i < len / 2; i++)
		{
			//ע��str[i]���±�0��ʼ����β��Ԫ��Ӧ�ȼ�һ
			if (str[i] != str[len - 1 - i])
			{
				return false;
			}
		}
		return true;
	}
};

// 007 ������ת* 41% 63%
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

// 006 Z���ͱ任* 78% 50%
class ConvertZ {
public:
	static string convert(string s, int numRows) {
		if (numRows == 1) return s;

		vector<string> rows(min(numRows, int(s.size()))); // ��ֹs�ĳ���С������
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) {// ��ǰ��curRowΪ0��numRows -1ʱ����ͷ��������ת��
				goingDown = !goingDown;
			}
			curRow += goingDown ? 1 : -1;
		}

		string ans;
		for (string row : rows) {// ���ϵ��±�����
			ans += row;
		}

		return ans;
	}
};

// 005 ������Ӵ�
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
			int len1 = expandAroundCenter(s, i, i);//һ��Ԫ��Ϊ����
			int len2 = expandAroundCenter(s, i, i + 1);//����Ԫ��Ϊ����
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
		{// ������left��rightΪ���ĵĻ��Ĵ�����
			L--;
			R++;
		}
		return R - L - 1;
	}

};

// 003 ���ظ��Ӵ�
class WCFZiChuan {
public:
	static int lengthOfLongestSubstring(string s) {
		// ��ϣ���ϣ���¼ÿ���ַ��Ƿ���ֹ�
		unordered_set<char> occ;
		int n = s.size();
		// ��ָ�룬��ʼֵΪ -1���൱���������ַ�������߽����࣬��û�п�ʼ�ƶ�
		int rk = -1, ans = 0;
		// ö����ָ���λ�ã���ʼֵ���Եر�ʾΪ -1
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				// ��ָ�������ƶ�һ���Ƴ�һ���ַ�
				occ.erase(s[i - 1]);
			}
			// occ.count()���ع�ϣ���������е���ͬԪ�ظ���
			while (rk + 1 < n && !occ.count(s[rk + 1])) {
				// ���ϵ��ƶ���ָ��
				occ.insert(s[rk + 1]);
				++rk;
			}
			// �� i �� rk ���ַ���һ�����������ظ��ַ��Ӵ�
			ans = max(ans, rk - i + 1);
		}
		return ans;
	}
};

// 001 ����֮��
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

//�ַ����滻����
class Solution2 {
public:
	static string replaceSpace(string s) {
		int count = 0, len = s.size();
		// ͳ�ƿո�����
		// �˴��õ���C++11�﷨������char c�������ַ���s
		for (char c : s) {
			if (c == ' ') count++;
		}
		// �޸� s ����
		s.resize(len + 2 * count);
		// ��������޸�
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

//ð��������
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