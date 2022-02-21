#include "head.h"

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != 'R')
                continue;
            int j = i;  //j用来对R-L中间的多米诺遍历
            while(j + 1 < n && dominoes[j + 1] == '.')  //溢出
                j++;
            if (j + 1 == n) {  //溢出
                for (int k = i + 1; k <= j; k++) {
                    dominoes[k] = 'R';
                }    
                break;
            }
            if (dominoes[j + 1] == 'R') {  //如果是R...R需要替换.并前进到新的R的位置
                for (int k = i + 1; k <= j; k++) {
                    dominoes[k] = 'R';
                }
                i = j;
                continue;
            }
            if (dominoes[j + 1] == 'L') {  //R...L型，进行替换
                int count = (j - i) / 2;  //需要推翻的数量
                for (int k = 1; k <= count; k++) {
                    dominoes[i + k] = 'R';
                    dominoes[j - k + 1] = 'L';
                }
            }
        }
        for (int i = n - 1; i > 0; i--) {
            if (dominoes[i] != 'L')
                continue;
            int j = i;  //j用来对L...L/...L中间的多米诺遍历
            while(j - 1 >= 0 && dominoes[j - 1] == '.')  //溢出
                j--;
            if (j - 1 == -1) {  //溢出
                for (int k = i - 1; k >= j; k--) {
                    dominoes[k] = 'L';
                }    
                break;
            }
            if (dominoes[j - 1] == 'L') {  //如果是L...L需要替换
                for (int k = i - 1; k >= j; k--) {
                    dominoes[k] = 'L';
                }
                i = j;
                continue;
            }
        }
        return dominoes;
    }
};