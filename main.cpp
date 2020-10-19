#include "cilantro_wrapper/cilantro_wrapper.h"
#include <stdio.h>

int main(int argc, char* argv[]){

    printf("Test is running...\n");
    float crd1[4];
    float crd2[4];
    crd1[0] = 10;
    crd1[1] = 20;
    crd1[2] = 30;
    crd1[3] = 40;
    crd2[0] = 100;
    crd2[1] = 200;
    crd2[2] = 300;
    crd2[3] = 400;
    SpatialRegion_c* s1 = newSpatialRegion(crd1, 2);
    SpatialRegion_c* s2 = newSpatialRegion(crd2, 2);
    //intersection_of(s1,s2);
    return 0;
}