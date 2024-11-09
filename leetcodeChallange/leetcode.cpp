class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        vector<int> vec(26, 0);
        for (char a : word)
        {
            vec[a - 'a']++;
        }
        int res = INT_MAX, del = 0;
        std::sort(vec.begin(), vec.end());
        for (int i = 0; i < 26; i++)
        {
            if (vec[i] == 0)
                continue;
            int a = del, j = 25;
            while (j > i && (vec[j] - vec[i]) > k)
            {
                a += vec[j] - vec[i] - k;
                j--;
            }
            res = min(a, res);
            del += vec[i];
        }

        return res;
        // return util(word,k,i,vec,0);
    }

    int util(string word, int k, int index, vector<int> &vec, int prev)
    {
        if (index > 25)
            return word.size();
        if (vec[index] + k >= vec[25])
            return word.size();
        int first = util(word, k, index + 1, vec, prev + vec[index]);
        int a = 0, j = 25;
        int l = vec[j] - (vec[j] - (vec[index] + k));
        while (vec[j] > l)
        {
            a += vec[j] - l;
            vec[j] = l;
        }
        cout << a << endl;
        cout << prev << endl;
        cout << first << endl;
        return min(a + prev + vec[index], first);
    }
};