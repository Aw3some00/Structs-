#include "time.h"
using namespace chron;
Time::Time(int h,int m,int s){
    /*if(s<0||s>59){
     
     }
     if(m<0||m>59){
     
     }
     if(h<0||h>23){
     
     }
     hours=h;
     minutes=m;
     seconds=s;*/
  /*  m+=s/60;
    s%=60;
    if(s<0){
        m+=1;
        s+=60;
    }
    h+=m/60;
    m%=60;

    if(m<0){
        h+=1;
        m+=60;
    }
    h=h%24;
    
    if(h<0){
        h+=24;
    }*/
    totalSeconds=3600*h+60*m+s;
    normalise();
}


int Time::Gethours() const{
    return totalSeconds/3600;
    
}
int Time::Getminutes() const{
    return (totalSeconds%3600)/60;
    
}
int Time::Getseconds() const{
    return(totalSeconds%3600)%60;
    
}
int Time::TotalSeconds() const{
    return totalSeconds;
}
void Time::normalise(){
    totalSeconds=totalSeconds%(3600*24);
    if(totalSeconds<0){
      totalSeconds=totalSeconds+3600*24;
    }
    
      
}
       

Time&Time::operator+=(int s){
    totalSeconds+=s;
    normalise();
    return *this;
}
   
void Time::AddSeconds(int s){
    totalSeconds+=s;
    normalise();
}


Time Time::operator+(int s) const{
    return Time(Gethours(),Getminutes(),Getseconds()+s);
    
}
/*Time operator+(const Time& t,int s){
    return Time(t.Gethours(),t.Getminutes(),t.Getseconds()+s);
}*/ //вне класса

int operator-(const Time& t1,const Time& t2){
    return t1.TotalSeconds()-t2.TotalSeconds();
    
    
}

std::ostream& operator<<(std::ostream& out,const chron::Time& t){
    out<<t.Gethours()<<":"<<t.Getminutes()<<":"<<t.Getseconds();
    return out;
}
std::istream& operator>>(std::istream& in,chron::Time& t){
    int h,m,s;
    char temp;
    in>>h>>temp;
    in>>m>>temp;
    in>>s>>temp;
    t=Time(h,m,s);
    return in;
    
}













