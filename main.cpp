#include <iostream>
#include "time.h"
int main(){
    chron::Time t(1,2,3);
    std::cout<<t.Gethours()<<"\n";
    std::cout<<t.Getminutes()<<"\n";
    std::cout<<t.Getseconds()<<"\n";
    std::cout<<t;
    
    
    
    
    
    
    
   
    return 0;
}
