#include "cilantro_wrapper/cilantro_wrapper.h"
#include <stdio.h>

void test_2D();

void test_3D();

int main(int argc, char* argv[]){

    printf("STQL Spatial Operations Wrapper\n");
    //test_2D();
    test_3D();
    return 0;
}

void test_2D(){

    printf("\n2D test:\n");
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
    const SpatialRegion_c & sr1 = newSpatialRegion2D(crd1, 2);
    const SpatialRegion_c & sr2 = newSpatialRegion2D(crd2, 2);
    printf("2D Spatial Operation Tetst...\n");
    //intersection_of(sr1, sr2);
    relative_complement_of(sr1,sr2);    
}

void test_3D(){

    printf("\n3D test:\n");
    float crd1[8][3] = {{0,0,0},{10,0,0},{0,10,0},{10,10,0},{0,0,30},{10,0,30},{0,10,30},{10,10,30}};
    float crd2[8][3] = {{5,5,5},{15,5,5},{5,15,5},{15,15,5},{5,5,35},{15,5,35},{5,15,35},{15,15,35}};

    const SpatialRegion_c & sr1 = newSpatialRegion3D(crd1[0], 3);
    const SpatialRegion_c & sr2 = newSpatialRegion3D(crd2[0], 3);
    printf("3D Spatial Operation Tetst...\n");
    //intersection_of(sr1, sr2);
    relative_complement_of(sr1,sr2);    
}