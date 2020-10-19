#ifndef __CILANTRO_WRAPPER_H
#define __CILANTRO_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

struct SpatialRegion_stc;
typedef struct SpatialRegion_stc SpatialRegion_c;

//SpatialRegion* newSpatialRegion();

SpatialRegion_c* newSpatialRegion(float* vert , int dim);

SpatialRegion_c* clone_me(SpatialRegion_c* sr);

void release_mem(SpatialRegion_c** sr );

void complement_of(SpatialRegion_c* sr);

void union_of(SpatialRegion_c* sr1, SpatialRegion_c* sr2);

void intersection_of(SpatialRegion_c* sr1, SpatialRegion_c* sr2);

#ifdef __cplusplus
}
#endif
#endif