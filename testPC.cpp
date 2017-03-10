#include <PCSet.h>
#include "ticktock.h"
#include "getopt.h"
#include <sstream>
#include <fstream>
#include <iostream>

#define PCTYPE "LU"
#define DOF 30
#define ORDER 2
#define COMPUTE3 true

int main(int argc, char *argv[]){
    // Hard coded values
    string pcType = PCTYPE;
    int dof = DOF;
    int order = ORDER;
    bool comp3 = COMPUTE3;

    int c;
    // Read the dof, order, Gaussian order and type from input
    while ((c=getopt(argc,(char **)argv, "n:o:p:t:"))!=-1){
        switch(c) {
            case 'n':
                dof = strtod(optarg,(char **)NULL);
                break;
            case 'o':
                order = strtod(optarg,(char **)NULL);
                break;
            case 'p':
		        int temp2;
                temp2 = strtod(optarg,(char **)NULL);
                if (temp2 == 1)
		            pcType = "HG";
                if (temp2 == 0)
		            pcType = "LU";
                break;
            case 't':
		        int temp;
                temp = strtod(optarg,(char **)NULL);
                if (temp == 0)
		            comp3 = false;
                break;
            }
        }
    
    // print the input info to generate PC set
    cout << "Polynomial kind            " << pcType << endl << flush;
    cout << "Degrees of freedom         " << dof << endl << flush;
    cout << "Order of polynomial chaos  " << order << endl << flush;
    if (comp3){
        cout << "Pijk is computed" << endl << flush;
    }
    else
        {cout << "Pijk computation is skipped" <<endl << flush;
    }

    TickTock tt;
    tt.tick();
    PCSet myPCSet("ISP",order,dof,pcType,0.0,1.0,comp3);
    tt.tock("Took ");

    return 0;
}
