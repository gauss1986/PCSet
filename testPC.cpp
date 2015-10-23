#include <PCSet.h>
#include "ticktock.h"
#include "getopt.h"

#define PCTYPE "LU"
#define DOF 10
#define ORDER 2

int usage(){
    printf("usage: ");
    return 0;
    }

int main(int argc, char *argv[]){
    // Hard coded values
    string pcType = PCTYPE;
    int dof = DOF;
    int order = ORDER;

    int c;
    // Read the dof, order, Gaussian order and type from input
    while ((c=getopt(argc,(char **)argv, "h:n:o:"))!=-1){
        switch(c) {
            case 'h':
                usage();
                break;
            case 'n':
                dof = strtod(optarg,(char **)NULL);
                break;
            case 'o':
                order = strtod(optarg,(char **)NULL);
                break;
            }
        }
    
    // print the input info to generate PC set
    cout << "Degrees of freedom         " << dof << endl << flush;
    cout << "Order of polynomial chaos  " << order << endl << flush;

    TickTock tt;
    tt.tick();
    PCSet myPCSet("ISP",order,dof,pcType,0.0,1.0);
    tt.tock("Took ");

    return 0;
}
