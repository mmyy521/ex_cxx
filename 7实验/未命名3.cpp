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
    // �ӱ�׼�����ȡ�ı���
    std::string content;
    std::getline(std::cin, content, '\n');
    map<string, unsigned> msu;
    // Ҫ��termFrequencyʵ�ִַʣ�ȥ�����
    // ��ȡ���ʴ����map�У���¼��Ƶ�����ִ�����
    // ��󷵻ز��ظ��ĵ�������  
    //���ʴ�Сд�� find(),�ж����֣�����Ϊ����
    //transform(s.begin(),s.end(),s.begin(),::tolower); 
    //str.lower();mymap.find('a')->second 
    unsigned nWords = termFrequency(content, msu);
    // ������ĸA-Z����һ��һ�������Ƶ
    // ��ʾ: mapĬ�ϰ�keyֵ����
    alphabetSortedFrequency(msu);
    return 0;
}

