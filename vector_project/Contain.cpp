#include "Contain.h"

extern string filename;
extern string folder;
extern string filepath;

float dotProduct(vector<float>a,vector<float>b){
	float ans=0.0;
	for(int i=0;i<a.size();i++){
		ans+=a[i]*b[i];
	}
	return ans;
}

float magnitude(vector<float>a){
	float mag=0.0;
	for(int i=0;i<a.size();i++){
		mag+=a[i]*a[i];
	}
	return sqrt(mag);
}

int ADD(string s, vector<float>& item,int endId,int cur) {
    string filename = to_string(endId) + ".txt";
    string folder = "D:\\test";
    string filepath = folder + "\\" + filename;
    ofstream ofs(filepath,ios::app);
    
    if(!ofs){
    	cout<<"文件不存在"<<endl;
    	ofs.close();
    	return cur;
	}
    
    ofs<<s<<" ";
    for(int i=0;i<item.size();i++){
   	    ofs<<to_string(item[i])<<" ";
    }
    ofs<<endl;
   
    ofs.close();
    return cur+1;
}

int INSERT(string s, vector<float>& item,int endId,int cur) {
    return cur;
}

void UPDATE(string s, vector<float>& item,int selectId,int cur) {
    string filename = to_string(selectId) + ".txt";
    string folder = "D:\\test";
    string filepath = folder + "\\" + filename;
    
    ifstream ifs(filepath);
    if(!ifs){
    	cout<<"文件不存在"<<endl;
    	ifs.close();
    	return;
	}
    
    string t;
    vector<string>tmp;
    while(getline(ifs,t,'\n')){
    	tmp.push_back(t);
	}
	
	if(cur<1||cur>tmp.size()){
		//cout<<cur<<" "<<tmp.size()<<endl;
    	cout<<"数据不合法"<<endl;
        ifs.close();
        return;
	}
    
    string temp=s;
    temp+=' ';
    for(int i=0;i<item.size();i++){
    	temp+=to_string(item[i])+" ";
	}
    
    tmp[cur-1]=temp;
    ifs.close();
    
    ofstream ofs(filepath,ios::trunc);
    if(!ofs){
    	cout<<"文件不存在"<<endl;
    	ofs.close();
    	return;
	}
	
	for(auto v:tmp){
		ofs<<v<<endl;
	}
	ofs.close();
    return;
}

vector<string> MAKE(vector<float>& item,float angle) {
	int st=1;
	string filename = to_string(st) + ".txt";
    string folder = "D:\\test";
    string filepath = folder + "\\" + filename;

    ifstream ifs(filepath);
    
    if(!ifs){
    	cout<<"文件不存在"<<endl;
    	ifs.close();
    	return {};
	}
    
    string t;
    int row_size=0;
    vector<float>tmp;
    vector<string>ans;
    while(getline(ifs,t)){
        stringstream ss(t);
        string str,tz;
        //cout<<t<<endl;
        ss>>tz;
        //cout<<tz<<endl;
        while(ss>>str){
        	tmp.push_back(stof(str));
        	//cout<<str<<endl;
		}
		
		float dot=dotProduct(item,tmp);
		float magA=magnitude(item);
		float magB=magnitude(tmp);
		
		float dt=dot/(magA*magB);
		if(dt<=angle||item==tmp){
			ans.push_back(t);
			//cout<<tz<<endl;
		}
		
		st++;
		filename = to_string(st) + ".txt";
		filepath = folder + "\\" + filename;
		tmp.clear();
	}
	
	ifs.close();
    return ans;
}

