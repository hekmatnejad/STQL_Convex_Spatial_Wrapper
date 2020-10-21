//#include <cilantro/spatial/space_region.hpp>
#include <stdlib.h>
#include "cvx_polytope_spatial.h"
#include "cilantro_wrapper.h"

extern "C" {

        SpatialRegion_c  newSpatialRegion2D(float* vert , int size = 4 ) {

                SpatialRegion_c newReg;
                SpatialRegion* sr  = new SpatialRegion(vert, size, dimension::D2);
                newReg.obj = sr;
                std::cout << "new 2D object created\n";
                sr->print_space_region2D();
                sr->set_dim(dimension::D2);
                return newReg;
        }

        SpatialRegion_c newSpatialRegion3D(float* vert , int size = 8 ){

                SpatialRegion_c newReg;
                SpatialRegion* sr  = new SpatialRegion(vert, size, dimension::D3);
                newReg.obj = sr;
                std::cout << "new 3D object created\n";
                sr->print_space_region3D();
                sr->set_dim(dimension::D3);
                return newReg;
        }


        SpatialRegion_c clone_me(const SpatialRegion_c &sr){
                SpatialRegion_c newReg;
                newReg.obj = ((SpatialRegion*)sr.obj)->sr_clone();
                return newReg;
        }

        void release_mem(SpatialRegion_c** sr ){

        }

        void complement_of(const SpatialRegion_c &sr){
                cout << "Complement\n";
                ((SpatialRegion*)sr.obj)->sr_complement();
                if( ((SpatialRegion*)sr.obj)->get_dim() == dimension::D2)
                        ((SpatialRegion*)sr.obj)->print_space_region2D();
                else
                        ((SpatialRegion*)sr.obj)->print_space_region3D();
        }

        void relative_complement_of(const SpatialRegion_c &sr1, const SpatialRegion_c &sr2){
                cout << "Relative Complement\n";
                ((SpatialRegion*)sr1.obj)->sr_relative_complement(( SpatialRegion *)sr2.obj);
                if( ((SpatialRegion*)sr1.obj)->get_dim() == dimension::D2)
                        ((SpatialRegion*)sr1.obj)->print_space_region2D();
                else
                        ((SpatialRegion*)sr1.obj)->print_space_region3D();
        }

        void union_of(const SpatialRegion_c &sr1, const SpatialRegion_c &sr2){
                cout << "union\n";
                ((SpatialRegion*)sr1.obj)->sr_union_with(( SpatialRegion *)sr2.obj);
                if( ((SpatialRegion*)sr1.obj)->get_dim() == dimension::D2)
                        ((SpatialRegion*)sr1.obj)->print_space_region2D();
                else
                        ((SpatialRegion*)sr1.obj)->print_space_region3D();
        }

        void intersection_of(const SpatialRegion_c &sr1, const SpatialRegion_c &sr2){
                cout << "intersection\n";
                ((SpatialRegion*)sr1.obj)->sr_intersection_with((SpatialRegion *)sr2.obj);
                if( ((SpatialRegion*)sr1.obj)->get_dim() == dimension::D2)
                        ((SpatialRegion*)sr1.obj)->print_space_region2D();
                else
                        ((SpatialRegion*)sr1.obj)->print_space_region3D();
        }
}