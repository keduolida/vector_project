#include "Contain.h" 

vector<float>item;

int endId=1,row_size=0;
string filename = to_string(endId) + ".txt";
string folder = "D:\\test";
string filepath = folder + "\\" + filename;

int main() {
	ifstream ifs(filepath);
	if(!ifs){
		cout<<"�ļ�������"<<endl;
		return 0;
	}
	
	//����ж���ҳ ������ 
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
//            	cout<<"�ļ�������"<<endl;
//            	return 0;
//			}
//		}
//	}
	ifs.close();
	
	row_size=2945;
	endId=384;
	
    int choice,selectId,cur;
    while(1){
    	cout<<"��������"<<endl;
    	cin>>choice;
    	if(choice==0)return 0;
    	
    	string s;
    	cout<<"����keyֵ"<<endl;
    	cin>>s;
    	cout<<"����300������ά��"<<endl;
    	for(int i=0;i<300;i++){
    		float tmp;
    		cin>>tmp;
    		//cout<<tmp<<endl;
    		item.push_back(tmp);
		}
    	
    	float angle;
    	if(choice==3){
    		cout<<"����ѡ���ҳ��"<<endl;
    		cin>>selectId;
    		cout<<"����ѡ�������"<<endl;
    		cin>>cur;
		}
		if(choice==4){
			cout<<"����ѡ��Ļ���"<<endl;
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
		
		//�������� 
		if(row_size==5000){
			row_size=0;
			ifs.close();
			endId++;
			filename = to_string(endId) + ".txt";
            folder = "D:\\test";
            filepath = folder + "\\" + filename;
            ifs.open(filepath);
            if(!ifs){
            	cout<<"�ļ�������"<<endl;
            	return 0;
			}
		}
		item.clear();
	}

    return 0;
}

