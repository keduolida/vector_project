#ifndef CONTAIN_H
#define CONTAIN_H

#include <bits/stdc++.h>

using namespace std;

extern string filename;
extern string folder;
extern string filepath;

float dotProduct(vector<float>a,vector<float>b);
float magnitude(vector<float>a);
int ADD(string s, vector<float>& item,int endId,int cur);
int INSERT(string s, vector<float>& item,int endId,int cur);
void UPDATE(string s, vector<float>& item,int endId,int cur);
vector<string> MAKE(vector<float>& item,float angle);

#endif // CONTAIN_H

