#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <iomanip>

using namespace std;

const int N = 100;
int mx_size = 10 * 1024 * 1024;
int cur = 0, cnt = 1, id = 1, row_size = 0;

int main() {
    ifstream ifs("D:\\glove.42B.300d\\glove.42B.300d.txt");

    if (!ifs) {
        cout << "文件不存在" << endl;
        return 0;
    }

    ifs.seekg(0, ios::end);
    long file_size = ifs.tellg();   
    long mx = file_size / 4;  
    cout << mx << endl;   
    ifs.seekg(0, ios::beg);  

    string filename = to_string(cnt) + ".txt";
    string folder = "D:\\test";
    string filepath = folder + "\\" + filename;
    ofstream ofs(filepath, ios::app);
    if (!ofs.is_open()) {
        cout << "文件不存在" << endl;
        return 0;
    }
    ofs << fixed << setprecision(6);

    string s;
    while(getline(ifs,s)){ 
        //cout<<s<<endl;
        row_size++;
        ofs<<s<<endl;
        
        if(row_size==5000){ //最多8700组数据 
            row_size = 0;
            ofs.close();  
            cnt++;  
            filename = to_string(cnt) + ".txt";
            filepath = folder + "\\" + filename;
            ofs.open(filepath, ios::app); 
            if (!ofs.is_open()) {
                cout << "文件不存在" << endl;
                return 0;
            }
            ofs << fixed << setprecision(6);  
        }
    }

    ifs.close();
    ofs.close();
    return 0;
}

