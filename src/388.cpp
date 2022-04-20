#include "head.h"

class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        vector<int> level(n + 1);

        while (pos < n) {
            /* 检测当前文件的深度 */
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                pos++;
                depth++;
            }
            /* 统计当前文件名的长度 */   
            int len = 0; 
            bool isFile = false;     
            while (pos < n && input[pos] != '\n') {
                if (input[pos] == '.') {
                    isFile = true;
                }
                len++;
                pos++;
            }
            /* 跳过换行符 */
            pos++;

            if (depth > 1) {  //加上前缀长度
                len += level[depth - 1] + 1;
            }
            if (isFile) {
                ans = max(ans, len);
            } else { //保存当前层级长度
                level[depth] = len;
            }
        }
        return ans;
    }
};