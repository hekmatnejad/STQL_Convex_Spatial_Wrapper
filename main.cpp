#include "cilantro_wrapper/cilantro_wrapper.h"
#include <stdio.h>

void test_2D();

void test_3D();

int main(int argc, char* argv[]){

    printf("STQL Spatial Operations Wrapper\n");

    test_2D();
    
    test_3D();

    return 0;
}

void test_2D(){

    printf("\n< 2D test >\n");
    float crd1[2][2] = {{10,20},{30,40}};
    float crd2[2][2] = {{100,200},{300,400}};

    const SpatialRegion_c & sr1 = newSpatialRegion2D(crd1[0], 4);
    const SpatialRegion_c & sr2 = newSpatialRegion2D(crd2[0], 4);
    printf("2D Spatial Operation Tetst...\n");
    union_of( sr1, sr2 );
    relative_complement_of( sr1, sr2 );    

    const SpatialRegion_c & sr3 = clone_me(sr1);
    printf( "cloned:\n");
    print_spatial_region( sr3 );
    release_mem( sr1 );
    print_spatial_region( sr1 );
    //relative_complement_of( sr1, sr2 );    
    relative_complement_of( sr3, sr2 );    
   
}

void test_3D(){

    printf("\n< 3D test >\n");
    float crd1[8][3] = {{0,0,0},{10,0,0},{0,10,0},{10,10,0},{0,0,30},{10,0,30},{0,10,30},{10,10,30}};
    float crd2[8][3] = {{5,5,5},{15,5,5},{5,15,5},{15,15,5},{5,5,35},{15,5,35},{5,15,35},{15,15,35}};

    const SpatialRegion_c & sr1 = newSpatialRegion3D(crd1[0], 8);
    const SpatialRegion_c & sr2 = newSpatialRegion3D(crd2[0], 8);
    printf("3D Spatial Operation Tetst...\n");
    union_of( sr1, sr2 );
    relative_complement_of( sr1, sr2 );    
}