//#include <cilantro/spatial/space_region.hpp>
#include <stdlib.h>
#include "cvx_polytope_spatial.h"
#include "cilantro_wrapper.h"

extern "C" {

        struct SpatialRegion_stc{
                void* obj;
        };
        //SpatialRegion* newSpatialRegion() {
        //        return new SpatialRegion();
        //}

        SpatialRegion_c* newSpatialRegion(float* vert , int dim) {
                SpatialRegion_c* test;
                test = (typeof(test))malloc(sizeof(*test));
                SpatialRegion* sr  = new SpatialRegion(vert, dim);
                test->obj = sr;
                std::cout << "new object created\n";
                if(dim == dimension::D2)
                        sr->print_space_region2D();
                return test;
        }

        SpatialRegion_c* clone_me(SpatialRegion_c* sr){
                return NULL;//sr->sr_clone();
        }

        void release_mem(SpatialRegion_c** sr ){

        }

        void complement_of(SpatialRegion_c* sr){
                //sr->sr_complement();
        }

        void union_of(SpatialRegion_c* sr1, SpatialRegion_c* sr2){
                //sr1->sr_union_with(sr2);
        }

        void intersection_of(SpatialRegion_c* sr1, SpatialRegion_c* sr2){
                //sr1->sr_intersection_with(sr2);
        }
}