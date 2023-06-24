class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> good, bad;
        for(auto &a:positive_feedback) good.insert(a);
        for(auto &a:negative_feedback) bad.insert(a);
        unordered_map<int,int> mark(student_id.size());//存储学号对应成绩
        for(int i = 0; i < report.size(); i++)
        {
            stringstream ss;//字符串流（可以实现去空格）
            string a;
            ss << report[i];//将原字符串读入流
            while (ss >> a)//每次自动取出一个单词
            {
                if(good.find(a)!=good.end()) mark[student_id[i]] += 3;
                if(bad.find(a)!=bad.end()) mark[student_id[i]]--;
            }
        }
        sort(student_id.begin(),student_id.end(),[&](int a,int b){//自定义排序
            if (mark[a] < mark[b]) return false;
            else if (mark[a] > mark[b]) return true;
            else return a<b;
        });
        return vector<int>(student_id.begin(), student_id.begin() + k);
    }
};
