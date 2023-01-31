#pragma once


#ifdef __APPLE__
#define DllExport(t) extern "C" __attribute__((visibility("default"))) t
#elif __GNUC__
#define DllExport(t) extern "C" __attribute__((visibility("default"))) t
#else
#define DllExport(t) extern "C"  __declspec( dllexport ) t __cdecl
#endif

#include <PxPhysicsAPI.h>
typedef struct {
    float X;
    float Y;
    float Z;
} V3f;

typedef struct {
    double X;
    double Y;
    double Z;
} V3d;

typedef struct {
    double X;
    double Y;
    double Z;
    double W;
} V4d;

typedef struct {
    double W;
    double X;
    double Y;
    double Z;
} Rot3d;

typedef struct {
    Rot3d Rot;
    V3d Trans;
} Euclidean3d;

typedef struct {
    physx::PxFoundation* Foundation;
    physx::PxPhysics* Physics;
    physx::PxCooking* Cooking;
} PxHandle;

typedef struct {
    physx::PxFoundation* Foundation;
    physx::PxPhysics* Physics;
    physx::PxCooking* Cooking;
    physx::PxScene* Scene;
} PxSceneHandle;

DllExport(PxHandle*) pxInit();
DllExport(void) pxDestroy(PxHandle* handle);

DllExport(PxSceneHandle*) pxCreateScene(PxHandle* handle, V3d gravity);
DllExport(void) pxDestroyScene(PxSceneHandle* handle);