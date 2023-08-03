#include<iostream>
#include<string>
#include <map> 
#include <algorithm> 
#include<sstream>
using namespace std;
int termFrequency(string& str, map<string, unsigned>& msu) {
    /* n = msu.count('a');
     cout << n;*/
    unsigned n = 0, m = 0;
    istringstream is(str);
    string word;

    while (is >> word) {
        istringstream sin(word);
        int int_d;
        double double_d;
        if (sin >> int_d || sin >> double_d)
            break;
        for (int i = 0; word[i] != '\0'; i++) {
            if (word[i] == ',' || word[i] == '.' || word[i] == '"' || isdigit(word[i]))
            {
                word.erase(i, 1);
                i--;
            }
        }
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        n = 0;
        n++;

        map<string, unsigned>::iterator  it;
        it = msu.find(word);
        if (it != msu.end()) {
            n = it->second + 1;
            msu.erase(it);
            m--;
        }
        msu.insert(pair<string, unsigned>(word, n));
        m++;
    }
    return m;
}
void alphabetSortedFrequency(map<string, unsigned>& msu) {
    map<string, unsigned>::iterator  iter;
    for (iter = msu.begin(); iter != msu.end(); iter++)
    {
        cout << iter->first << ":" << iter->second << endl;
    }
}
int main() {
    // 从标准输入获取文本串
    std::string content;
    std::getline(std::cin, content, '\n');
    map<string, unsigned> msu;
    // 要求termFrequency实现分词，去掉标点
    // 获取单词存放在map中，记录词频（出现次数）
    // 最后返回不重复的单词数量  
    //单词大小写， find(),判断数字，不作为单词
    //transform(s.begin(),s.end(),s.begin(),::tolower); 
    //str.lower();mymap.find('a')->second 
    unsigned nWords = termFrequency(content, msu);
    // 按首字母A-Z排序一行一词输出词频
    // 提示: map默认按key值排序
    alphabetSortedFrequency(msu);
    return 0;
}

