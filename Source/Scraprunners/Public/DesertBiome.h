// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Biome.h"

/**
 * 
 */
class SCRAPRUNNERS_API DesertBiome : public ABiome
{
public:
	DesertBiome();
	virtual ~DesertBiome() = default;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UMaterialInterface*> Materials;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Resolution;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LengthAndWidth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HeightScalar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SizeScalar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TilingScalar;

	virtual FBiomeData GetBiomeData() const override;

	virtual void GenerateTerrainData(TArray<FVector>& OutVertexPositions, TArray<FVector>& OutNormals, TArray<FVector2D>& OutUVs, TArray<int32>& OutIndices) override;
};
