 #include <cstdlib>
 #include <iostream>
 #include <deque>
 #include <algorithm>

 using namespace std;

 char *fa="fill A";
 char *fb="fill B";
 char *ea="empty A";
 char *eb="empty B";
 char *pab="pour A B";
 char *pba="pour B A";
 char *s="success";

 const int filla=0;
 const int fillb=1;
 const int emptya=2;
 const int emptyb=3;
 const int pourab=4;
 const int pourba=5;
 const int success=6;

 typedef char *  pchar;

 pchar def[]={fa,fb,ea,eb,pab,pba,s};

 deque<int>travel;                       //记录已出现状态  为了节省空间 将ca cb压缩为一个int型 ca*10000+cb  

 int minStepNum,ica,icb,cr;

 deque<int> result;

 deque<int> output;

 typedef deque<int>::iterator Iter;


 bool checkResult(int &ca,int &cb)          //检测错误状态 以退出不必要的递归 
{
    if(ca==ica&&cb==icb)                   //都满 
    {
      return false;
    }
   if(ca==0&&cb==0)                       //都空 
    {
       return false;
    }
    
    if(find(travel.begin(),travel.end(),ca*10000+cb)!=travel.end())
    {
       return false;                                                                   
    }
   
    return true;  
}

 void seach(int ca,int cb)
 {
      int tempa,tempb,temp;
      if(cb==cr)
      {
         
         if(result.size()<minStepNum||minStepNum==-1)
         {
             output=result;
             minStepNum=result.size();
         }
         
         return;            
      }
      
      
      
      if(ca!=ica&&cb!=icb)// fa fb
      {
         // fill a
           tempa=ica;//a 满 b 不满 
           tempb=cb;
           temp=tempa*10000+tempb;
           if(checkResult(tempa,tempb))//通过检测
           {
              result.push_back(filla);
               travel.push_back(temp);                                   
               seach(tempa,tempb);
               result.pop_back();
               travel.pop_back();//恢复状态
                                             
           }
           
           //fill b
           tempa=ca;//a 满 b 不满 
           tempb=icb;
           temp=tempa*10000+tempb;
           if(checkResult(tempa,tempb))//通过检测
           {
               result.push_back(fillb);
               travel.push_back(temp);                                   
               seach(tempa,tempb);
               result.pop_back();
               travel.pop_back();//恢复状态
                                             
           }
                                                                                                                  
      }
      
      
      if(ca!=0&&cb!=0)
      {
         
           //empty a
           
           tempa=0;
           tempb=cb;
           temp=tempa*10000+tempb;
           if(checkResult(tempa,tempb))//通过检测
           {
               result.push_back(emptya);
               travel.push_back(temp);                                                  seach(tempa,tempb);
               result.pop_back();
               travel.pop_back();//恢复状态
                                             
           }
           
           //empty b
           tempa=ca;
           tempb=0;
           temp=tempa*10000+tempb;
           if(checkResult(tempa,tempb))//通过检测
           {               result.push_back(emptyb);
               travel.push_back(temp);                                   
               seach(tempa,tempb);
               result.pop_back();
               travel.pop_back();//恢复状态
                                             
           }
                      
      }
      
      if(ca!=0&&cb!=icb)
      {
         // pour a b
         if(ca>icb-cb)
         {
            tempa=ca-(icb-cb);
            tempb=icb;
         }
         else
         {
             tempa=0;
             tempb=ca+cb;
         }
         temp=tempa*10000+tempb;
         if(checkResult(tempa,tempb))//通过检测
         {
               result.push_back(pourab);
               travel.push_back(temp);                                   
               seach(tempa,tempb);
               result.pop_back();
               travel.pop_back();//恢复状态
                                             
         }
      }
      
      if(ca!=ica&&cb!=0)
      {
         // pour b a 
         if(cb>ica-ca)
         {
            tempa=ica;
            tempb=cb-(ica-ca);
         }
         else
         {
             tempa=ca+cb;
             tempb=0;
         }
         temp=tempa*10000+tempb;
         if(checkResult(tempa,tempb))//通过检测
         {
               result.push_back(pourba);
               travel.push_back(temp);                                   
               seach(tempa,tempb);
               result.pop_back();
               travel.pop_back();//恢复状态
                                             
         }                  
      }
 }

 int main(int argc, char *argv[])
 {
     while(cin>>ica>>icb>>cr)
     {
         travel.clear();
         result.clear();
         minStepNum=-1;
         
         seach(0,0);
         output.push_back(success);
         
         for(Iter iter=output.begin();iter!=output.end();++iter)
         {
             cout<<def[*iter]<<endl;      
         }                     
     }
   //  system("PAUSE");
     return EXIT_SUCCESS;
}