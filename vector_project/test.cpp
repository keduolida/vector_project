#include "Contain.h" 

vector<float>item;

int endId=1,row_size=0;
string filename = to_string(endId) + ".txt";
string folder = "D:\\test";
string filepath = folder + "\\" + filename;

int main() {
	ifstream ifs(filepath);
	if(!ifs){
		cout<<"文件不存在"<<endl;
		return 0;
	}
	
	//求出有多少页 多少行 
//	string t;
//	while(getline(ifs,t,'\n')){
//		row_size++;
//		if(row_size==5000){
//			row_size=0;
//			ifs.close();
//			endId++;
//			filename = to_string(endId) + ".txt";
//            folder = "D:\\test";
//            filepath = folder + "\\" + filename;
//            ifs.open(filepath);
//            if(!ifs){
//            	cout<<"文件不存在"<<endl;
//            	return 0;
//			}
//		}
//	}
	ifs.close();
	
	row_size=2945;
	endId=384;
	
    int choice,selectId,cur;
    while(1){
    	cout<<"输入索引"<<endl;
    	cin>>choice;
    	if(choice==0)return 0;
    	
    	string s;
    	cout<<"输入key值"<<endl;
    	cin>>s;
    	cout<<"输入300个向量维度"<<endl;
    	for(int i=0;i<300;i++){
    		float tmp;
    		cin>>tmp;
    		//cout<<tmp<<endl;
    		item.push_back(tmp);
		}
    	
    	float angle;
    	if(choice==3){
    		cout<<"输入选择的页数"<<endl;
    		cin>>selectId;
    		cout<<"输入选择的行数"<<endl;
    		cin>>cur;
		}
		if(choice==4){
			cout<<"输入选择的弧度"<<endl;
			cin>>angle;
		}
    	
    	vector<string>isVaild;
    	switch(choice){
    		case 1:
    			row_size=ADD(s,item,endId,row_size);
    			break;
    		case 2:
    			row_size=INSERT(s,item,endId,row_size);
    			break;
    		case 3:
    			UPDATE(s,item,selectId,cur);
    			break;
    		case 4:
    			isVaild=MAKE(item,angle);
    			break;
    		default:
    			break;
		}
		
		//for(auto v:isVaild)cout<<v<<endl;
		
		//更新数据 
		if(row_size==5000){
			row_size=0;
			ifs.close();
			endId++;
			filename = to_string(endId) + ".txt";
            folder = "D:\\test";
            filepath = folder + "\\" + filename;
            ifs.open(filepath);
            if(!ifs){
            	cout<<"文件不存在"<<endl;
            	return 0;
			}
		}
		item.clear();
	}

    return 0;
}

