#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main ()
{
	//defined variable 
   FILE *fp;
   char c;
   int i;
   int totalnum=0;
   int switchnum=0;
   int count2=0;
   int arr[100];
   int j=0;
   string str;
   string ans[100];
   
   //input file path for file 
   stack<char>s;
   char path[100];
   cout<<"Input the path of file:";
   cin>>path;
   
   //Input keyword library
    string a[35]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
   
   //open file 
    fp = fopen(path,"r");
   
   //Search for keywords and count£¨1 and 2 step£© 
    while((c = fgetc(fp))!=EOF)
    {
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
   	        str+=c;
        }
        else{
	        if(str!=""){
	            for(i=0;i<35;i++){
	  	            if(str==a[i]){
	  		            totalnum++;
	  		            if(i==25){
		   	                switchnum++;
		   	                if(s.empty()){
		   	                    s.push('s');
		   	                }
		                }
		                if(i==2&&s.top()=='{'){
		     	            count2++;
			            }
		            }
	            }
	            str="";
	        }
	        else{
	    	    if((c=='{')&&(!s.empty())){
	                s.push(c);
			        }	
			        if((c=='}')&&(!s.empty())){
				        s.pop();
				        s.pop();
				        arr[j++]=count2;
		   	            count2=0;
			        }   
		       }
        }
      
    }
    
    //Total number of keywords and number of Switch cases
    cout<<"total num: "<<totalnum<<endl;
    cout<<"switch num: "<<switchnum<<endl;
    cout<<"case num: ";
    for(i=0;i<j;i++)
    {
   	    cout<<arr[i]<<" ";
    }
    cout<<endl;
    fclose(fp);
    
    //level3 and 4 find the if and else 
    int len=0;
    fp = fopen("data.txt","r");
   
    while((c = fgetc(fp))!=EOF){
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
   	  	    str+=c;
	    }
	    else
		{
	  	    if(str!=""){
		        if(str=="else"&&c==' '){
		  	        continue;
		        }
		    else{
		  	    ans[len++]=str;
		  	    str="";
		    }
            }
        } 
    }
    
   int count3=0,count4=0;
   stack<string> m;
   for(i=0;i<len;i++){
   	    if(ans[i]=="if"||ans[i]=="elseif"){
   	 	    m.push(ans[i]);
	    }
	    if(ans[i]=="else"&&!m.empty()){
	 	    if(m.top()=="if"){
	 		    count3++;
	 		    m.pop();
		    }
		if(m.top()=="elseif")
		{
			while(m.top()=="if")
			{
				m.pop();
			}
			count4++;
			m.pop();
		}
	 }
	 
   } 
   cout<<"if-else num: "<<count3<<endl;
   cout<<"if-elseif-else num: "<<count4<<endl;
   fclose(fp);
   return 0;
}
