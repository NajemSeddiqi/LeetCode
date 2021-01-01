#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
using namespace std;


vector<int> runningSum(const vector<int>& nums) {
	vector<int> vect;
	int sum = 0;
	for (size_t i = 0; i < nums.size(); i++)
		vect.push_back(sum += nums[i]);
		
	return vect;
	/*for (int i = 1; i < (int)nums.size(); ++i)
		nums[i] += nums[i - 1];

	return nums;*/
}

int maximumWealth(const vector<vector<int>>& accounts) {
	int max = 0;
	for (size_t i = 0; i < accounts.size(); i++) {
		int tempMax = accumulate(accounts[i].begin(), accounts[i].end(), 0);
		if (tempMax > max)
			max = tempMax;
	}
	return max;
	//int maxValue = 0;
	//for (auto account : accounts)
	//	maxValue = max(maxValue, accumulate(account.begin(), account.end(), 0));
	//return maxValue;  
}

vector<bool> kidsWithCandies(const vector<int>& candies, const int extraCandies) {
	int max = *max_element(candies.begin(), candies.end());
	vector<bool> vect(candies.size());
	for (size_t i = 0; i < candies.size(); i++) 
		vect.push_back(candies[i] + extraCandies >= max);
	
	return vect;
}

vector<int> shuffle(const vector<int>& nums, int n) {
	vector<int> vect(nums.size());
	for (size_t i = 0, j = 0; i < nums.size(); i += 2, j++) {
		vect[i] = nums[j];
		vect[i + 1] = nums[n++];
	}
	return vect;
}

string defangIPaddr(string address) {
	string result = "";
	for (size_t i = 0; i < address.length(); i++) {
		if (address[i] == '.') {
			result += '[';
			result += '.';
			result += ']';
			continue;

			/*result.push_back('[');
			result.push_back('.');
			result.push_back(']');  <- less memory*/
		}
		result += address[i];
	}
	return result;
	//ostringstream os;
	//for (auto c : s)
	//	if (c == '.')
	//		os << "[.]";
	//	else
	//		os << c;
	//return os.str();
}

int numIdenticalPairs(const vector<int>& nums) {
	int count[101] = {}, res = 0;
	for (auto c : nums)
		res += count[c]++;
		
	return res;
}

string interpret(string command) {
	string res = "";
	for (size_t i = 0; i < command.length(); i++) {
		if (command[i] == '(' && command[i + 1] == 'a') {
			res.push_back('a');
			res.push_back('l');
			i += 3;
			continue;
		}
		if (command[i] == '(' && command[i + 1] == ')') {
			res.push_back('o');
			i++;
			continue;
		}
		res.push_back(command[i]);
	}
	return res;
}


int numJewelsInStones(string jewels, string stones) {
	int res = 0;
	for (size_t i = 0; i < jewels.length(); i++) 
		for (size_t j = 0; j < stones.length(); j++) 
			if (jewels[i] == stones[j])
				res++;
		
	return res;
}

class ParkingSystem {
public:
	int s, m, b;
	ParkingSystem(int big, int medium, int small) {
		s = small;
		m = medium;
		b = big;
	}

	bool addCar(int carType) {
		if (carType == 3) {
			if (s > 0) {
				--s;
				return true;
			}
			return false;
		}
		if (carType == 2) {
			if (m > 0) {
				--m;
				return true;
			}
			return false;
		}
		if (carType == 1) {
			if (b > 0) {
				--b;
				return true;
			}
			return false;
		}
	}
};

vector<int> smallerNumbersThanCurrent(const vector<int>& nums) {
	vector<int> vect(nums.size());
	for (size_t i = 0; i < nums.size(); i++) {
		int count = 0;
		for (size_t j = 0; j < nums.size(); j++) {
			if (nums[i] > nums[j] && i != j)
				count++;
		}
		vect[i] = count;
	}
	return vect;
}

string restoreString(const string s, const vector<int>& indices) {
	string res = s;
	for (size_t i = 0; i < s.length(); i++) 
		res[indices[i]] = s[i];
	
	return res;
}

int numberOfSteps(int num) {
	int res = 0;
	while (num > 0) {
		if (num % 2 == 0) {
			num >>= 1;
			res++;
		}
		else {
			num--;
			res++;
		}
	}
	return res;
}

int subtractProductAndSum(int n) {
	int sum, product = 1; while(n){
		sum += n % 10;
		product *= n % 10;
		n /= 10;	
	}
	return product - sum;
}

vector<int> decompressRLElist(vector<int>& nums) {
	vector<int> vect;
    for (size_t i=0; i<nums.size(); i+=2)
		vect.insert(vect.end(), nums[i], nums[i+1]);
	 	
	return vect;
	// O(log n)
	//for(size_t i = 0; i < nums.size()-1; i+=2){
		//for(int j = 0; j < nums[i]; j++){
			//vect.push_back(nums[i+1]);
		//}
	//}
}

int countConsistentStrings(string allowed, vector<string>& words) {
	int count = 0;
	for(size_t i = 0; i < allowed.length(); i++) 
		for(size_t j = 0; j < words.size(); j++) 
			words[j].erase(remove(words[j].begin(), words[j].end(), allowed[j]), words[j].end());
		
	
	for(size_t i = 0; i < words.size(); i++) 
		if(words[i] == "") 
			count++;
		
	
	return count;
	
	//int ans = 0;
    //for (auto &word : words)
        //if (word.find_first_not_of(allowed) == string::npos) ans++;
    //return ans;
}

vector<int> createTargetArray(const vector<int>& nums, const vector<int>& index) {
	vector<int> vect;
	for(size_t i = 0; i < nums.size(); i++) 
		vect.insert(vect.begin()+index[i], nums[i]);
	
    return vect;  
}

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
	for(size_t i = 1; i  < word1.size(); i++) {
		word1[0] += word1[i];
	}	
	for(size_t i = 1; i < word2.size(); i++){
		word2[0] += word2[i];	
	}
	return word1[0] == word2[0];     
}

int main(){
	createTargetArray(vector<int>{0,1,2,3,4}, vector<int>{0,1,2,2,1});
}
