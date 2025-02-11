// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BiomeData.generated.h"

/**
 * 
 */
USTRUCT()
struct FBiomeData
{
	GENERATED_BODY()

	TArray<UMaterialInterface*> Materials;
	TArray<FVector> VertexPositions;
	TArray<FVector> Normals; //may be put in QuadTreeNode
	TArray<FVector2D> UVs; //Also may be put in QuadTreeNode
	TArray<int32> Indices;
	int32 Resolution;
	int32 LengthAndWidth;
	float HeightScalar;
	float SizeScalar;
	float TilingScalar;
};