#pragma once
#include<vector>
using namespace std;
class Altset {
public:
    vector<char> gene;
    Altset() = default;
    ~Altset() = default;

    Altset(const char *data, int len);
	Altset& operator = (const Altset &altset);
    Altset& operator = (Altset &&altset);

    void inverse(int index);
    void append(int value);
    bool get(int index) const;
    bool empty() const;
    int count() const;
};
