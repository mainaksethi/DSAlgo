/**
 * https://algo.monster/liteproblems/751
 * /
 * Asked in Databricks previously
 * 
 * Below problem is good for revision of: 
 * 1. String to integer and vice_versa
 * 2. how to break an integer into base encoding. 
 * 3. 
 * 
 * Problem-Statement:
 * 751. IP to CIDR

    For example, the binary number 00001111 10001000 11111111 01101011 (spaces added for clarity) formatted as an IP address would be 
    "15.136.255.107".
    A CIDR block is a format used to denote a specific set of IP addresses. It is a string consisting of a base IP address, 
    followed by a slash, followed by a prefix length k. The addresses it covers are all the IPs whose first k bits are the same as the 
    base IP address.

    For example, "123.45.67.89/20" is a CIDR block with a prefix length of 20. Any IP address whose binary representation matches 
    01111011 00101101 0100xxxx xxxxxxxx, where x can be either 0 or 1, is in the set covered by the CIDR block.
    You are given a start IP address ip and the number of IP addresses we need to cover n. Your goal is to use as few CIDR blocks as 
    possible to cover all the IP addresses in the inclusive range [ip, ip + n - 1] exactly. No other IP addresses outside of the range 
    should be covered.

    Return the shortest list of CIDR blocks that covers the range of IP addresses. If there are multiple answers, return any of them.
    Example 1:

    Input: ip = "255.0.0.7", n = 10
    Output: ["255.0.0.7/32","255.0.0.8/29","255.0.0.16/32"]
    Explanation:
    The IP addresses that need to be covered are:
    - 255.0.0.7  -> 11111111 00000000 00000000 00000111
    - 255.0.0.8  -> 11111111 00000000 00000000 00001000
    - 255.0.0.9  -> 11111111 00000000 00000000 00001001
    - 255.0.0.10 -> 11111111 00000000 00000000 00001010
    - 255.0.0.11 -> 11111111 00000000 00000000 00001011
    - 255.0.0.12 -> 11111111 00000000 00000000 00001100
    - 255.0.0.13 -> 11111111 00000000 00000000 00001101
    - 255.0.0.14 -> 11111111 00000000 00000000 00001110
    - 255.0.0.15 -> 11111111 00000000 00000000 00001111
    - 255.0.0.16 -> 11111111 00000000 00000000 00010000
    The CIDR block "255.0.0.7/32" covers the first address.
    The CIDR block "255.0.0.8/29" covers the middle 8 addresses (binary format of 11111111 00000000 00000000 00001xxx).
    The CIDR block "255.0.0.16/32" covers the last address.
    Note that while the CIDR block "255.0.0.0/28" does cover all the addresses, it also includes addresses outside of the range, 
    so we cannot use it.
    Example 2:

    Input: ip = "117.145.102.62", n = 8
    Output: ["117.145.102.62/31","117.145.102.64/30","117.145.102.68/31"]


*/


/**
 * Solution: 
 * 1. Find the number of trialing zeros.
 * 2. Try to increase range corresponding to number of trailing zeros and stop if it crosses the threshhold.
 * 3. Push the cidr block and do steps 1 and 2 for remaining numbers.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
using namespace std;
class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        long long val = ipToInteger(ip);
        long long currentVal = val;
        vector<string> ans;
        while(n > 0) {
            int trailingZeros = findTrailingZeros(currentVal);
            int count = 1;
            int bits = 0;
            while(trailingZeros > 0 && count <= n) {
                bits++;
                count = 1 << bits;
                trailingZeros--;
            }
            if (count > n) {
                count = count >> 1;
                bits--;
            }
            ans.push_back(to_cidr(currentVal, 32-bits));
            n = n - count;
            currentVal = currentVal + count;
        }
        return ans;
    }

    int findTrailingZeros(long long val) {
        int count = 0; 
        while((val % 2) == 0 && count <= 8) {
            count++;
            val = val/2; 
        }
        return count;
    }

    string to_cidr(long long val, int count) {
        string s = ip(val);
        s += "/";
        s += ::to_string(count);
        return s;
    }

    string ip(long long val) {
        int count = 0;
        vector<int> v;
        while(count < 4) {
            int rem = val % 256;
            val = val/256;
            v.push_back(rem);
            count++;
        }
        string s = "";
        for (int i = 3; i >= 0; i--) {
            s += ::to_string(v[i]);
            if (i != 0) {
                s += '.';
            }
        }
        return s;
    }

    long long ipToInteger(string ip) {
        long long ans = 0;
        int count = 3;
        for (int i = 0; i < ip.size(); i++) {
            string integer = "";
            while(i < ip.size() && ip[i] != '.') {
                integer += ip[i];
                i++;
            }
            int val = stoi(integer);
            ans += ((long long)pow(256, count)) * val;
            count--;
        }
        return ans;
    }
};