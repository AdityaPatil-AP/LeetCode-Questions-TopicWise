class RandomizedSet
{
public:
    unordered_map<int, int> mp;
    vector<int> arr;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
        {
            return false;
        }
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (mp.find(val) == mp.end())
        {
            return false;
        }

        int pos = mp[val];
        arr[pos] = arr.back();
        arr.pop_back();
        mp[arr[pos]] = pos;
        mp.erase(val);
        return true;
    }

    int getRandom()
    {
        return arr[rand() % arr.size()];
    }
};
