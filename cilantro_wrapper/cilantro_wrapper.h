#ifndef __CILANTRO_WRAPPER_H
#define __CILANTRO_WRAPPER_H



#ifdef __cplusplus
extern "C" {
#endif

struct SpatialRegion_stc{
        void* obj;
};
typedef struct SpatialRegion_stc SpatialRegion_c;

//typedef struct SpatialRegion SpatialRegion_c;

SpatialRegion_c newSpatialRegion2D(float* vert , int size);

SpatialRegion_c newSpatialRegion3D(float* vert , int size);

SpatialRegion_c clone_me(const SpatialRegion_c &sr);

void release_mem(const SpatialRegion_c &sr);

void complement_of(const SpatialRegion_c &sr);

void relative_complement_of(const SpatialRegion_c &sr1, const SpatialRegion_c &sr2);

void union_of(const SpatialRegion_c &sr1, const SpatialRegion_c &sr2);

void intersection_of(const SpatialRegion_c &sr1, const SpatialRegion_c &sr2);

double area_of(const SpatialRegion_c &sr);

double volume_of(const SpatialRegion_c &sr);

void print_spatial_region(const SpatialRegion_c &sr);

#ifdef __cplusplus
}
#endif
#endif