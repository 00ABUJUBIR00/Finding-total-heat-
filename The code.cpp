#include<iostream>
#include<cmath>
main(){
    double Ti;
    double Tf;
    double M;char YN;char NY='Y';
    double dT=Tf-Ti; double Q1;double Q2;double Q3;double Q4;double Q5;double Q; 
    const int S=4187;
    const int Lf=333000;
    const int Lv=2256000;
    while(NY=='y'||NY=='Y'){
    std::cout<<"Please input the MASS: "<<std::endl;
    std::cin>> M; 
    std::cout<<"Please input the initial Temperature: "<<std::endl;
    std::cin>> Ti;
    std::cout<<"Please input the final Temperature: "<<std::endl;
    std::cin>> Tf;
    //When TI=0 and TF=100
    if(Ti==0 & Tf==100) { 
        std::cout<<"Is the initial state solid? [Y/N]"<<std::endl;
        std::cin>> YN;

        if(YN=='y' || YN=='Y'){
            Q1=M*Lf;//solid to water
            std::cout<<"Is the final state vapor? [Y/N]"<<std::endl;
            std::cin>> YN;
            if(YN=='y' || YN=='Y'){
                Q2=M*S*(100);//temp change
                Q3=M*Lv;//liquid to vapor
            }
            else{
                Q2=M*S*(100);
                Q3=0;
            }
            
            Q=Q1+Q2+Q3;
            std::cout<<"The total Heat is: "<<Q<<std::endl;
         }
        else{
            Q1=M*S*(100);
            std::cout<<"Is the final state vapor? [Y/N]"<<std::endl;
            std::cin>> YN;
            if(YN=='y' || YN=='Y'){
                Q2=M*Lv;
            }
            else{
                Q2=0;
            }
        Q=Q1+Q2;
        std::cout<<"The total Heat is: "<<Q<<std::endl;
         }        
    } 
    //When TI=0 but TF<100
    else if(Ti==0 & Tf>0 & Tf<100){
        
        std::cout<<"Is the initial state solid? [Y/N]"<<std::endl;
        std::cin>> YN;
        if(YN=='y' || YN=='Y'){
            Q1=M*Lf;
            Q2=M*S*(Tf-0);
            Q=Q1+Q2;
            std::cout<<"The total Heat is: "<<Q<<std::endl;
         }
        else{
            Q1=M*S*(Tf-0);
            std::cout<<"The total Heat is: "<<Q1<<std::endl;
         }
    }
    //when TI=0 and TF>100......................
        else if(Ti==0 & Tf>100){
        
        std::cout<<"Is the initial state solid? [Y/N]"<<std::endl;
        std::cin>> YN;
        if(YN=='y' || YN=='Y'){
            Q1=M*Lf;
            Q2=M*S*(100-Ti);
            Q3=M*Lv;
            Q4=M*S*(Tf-100);
            Q=Q1+Q2+Q3+Q4;
            std::cout<<"The total Heat is: "<<Q<<std::endl;
         }
        else{
            Q1=M*S*(100-Ti);
            Q2=M*Lv;
            Q3=M*S*(Tf-100);
            Q=Q1+Q2+Q3;
            std::cout<<"The total Heat is: "<<Q<<std::endl;
         }
    }
    //when TI<0 and TF>100.......................
        else if(Ti<0 & Tf>100){
            Q1=M*S*(0-Ti);
            Q2=M*Lf;
            Q3=M*S*(100);
            Q4=M*Lv;
            Q5=M*S*(Tf-100);
            Q=Q1+Q3+Q4+Q5;
            std::cout<<"The total Heat is: "<<Q<<std::endl;
    }
    //if TI>TF
        else if(Ti>Tf){
        std::cout<<"Your Final temperature is lower than Initial "<<std::endl;
    }
    //when 100>TI>0 and TF same
        else if(Ti>0 &Ti<100 & Tf>0 & Tf<100){
        Q1=M*S*(Tf-Ti);
        std::cout<<"The total Heat is: "<<Q1<<std::endl;
    }
    //when TI>100
        else if(Ti>100){
        Q1=M*S*(Tf-Ti);
        std::cout<<"The total Heat is: "<<Q1<<std::endl;
    }
    //if TI=100 and TF>100...........................
        else if(Ti==100 & Tf>100){
        std::cout<<"Is the initial state liquid? [Y/N]"<<std::endl;
        if(YN=='y'||YN=='Y'){
            Q1=M*Lv;
            Q2=M*S*(Tf-100);
            Q=Q1+Q2;
            std::cout<<"The total Heat is: "<<Q<<std::endl;
        }
        else{
            Q1=M*S*(Tf-100);
            std::cout<<"The total Heat is: "<<Q1<<std::endl;
        }
    }
    //when 100>TI>0 but TF=100
    else if(Ti<100 & Ti>0 & Tf==100){
        Q1=M*S*(100-Ti);

        std::cout<<"Is the final state vapor?";
        std::cin>> YN;
        if(YN=='y'||YN=='Y'){
            Q2=M*Lv;
        }
        else{
            Q2=0;
        }
        Q=Q1+Q2;
        std::cout<<"The total Heat is: "<<Q<<std::endl;

    } 
    // i<0 and f<0
    else if(Ti<0 & Tf<0 & Ti<Tf){
        Q=M*S*(Tf-Ti);
        std::cout<<"The total Heat is: "<<Q<<std::endl;
    }
    //i<0 f=100
    else if(Ti<0 & Tf==100){
        Q1=M*S*(0-Ti);
        Q2=M*Lf;
        Q3=M*S*(100);
        std::cout<<"Is the final state vapor?";
        std::cin>> YN;
        if(YN=='y'||YN=='Y'){
            Q4=M*Lv;
        }
        else{
            Q4=0;
        }
        Q=Q1+Q2+Q3+Q4;
        std::cout<<"The total Heat is: "<<Q<<std::endl;
    }
    //100>i>0 and f>100
    else if(Ti<100 & Ti>0 & Tf>100){
        Q1=M*S*(100-Ti);
        Q2=M*Lv;
        Q3=M*S*(Tf-100);
        Q=Q1+Q2+Q3;
        std::cout<<"The total Heat is: "<<Q<<std::endl;
    }
    //i<0 and 100>f>0
    else if(Ti<0 & Tf>0 &Tf<100){
        Q1=M*S*(0-Ti);
        Q2=M*Lf;
        Q3=M*S*(Tf-0);
        Q=Q1+Q2+Q3;
        std::cout<<"The total Heat is: "<<Q<<std::endl;
    }

    std::cout<<"Should we continue?";
    }

    std::cout<<"The End!";

return 0;
}
