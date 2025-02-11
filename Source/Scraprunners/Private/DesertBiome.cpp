// Fill out your copyright notice in the Description page of Project Settings.


#include "DesertBiome.h"

DesertBiome::DesertBiome()
{
}

DesertBiome::~DesertBiome()
{
}

FBiomeData DesertBiome::GetBiomeData() const
{
	FBiomeData BiomeData;
	BiomeData.Resolution = Resolution;
	BiomeData.LengthAndWidth = LengthAndWidth;
	BiomeData.HeightScalar = HeightScalar;
	BiomeData.SizeScalar = SizeScalar;
	BiomeData.TilingScalar = TilingScalar;
	return BiomeData;
}

void DesertBiome::GenerateTerrainData(TArray<FVector>& OutVertexPositions,
	TArray<FVector>& OutNormals,
	TArray<FVector2D>& OutUVs,
	TArray<int32>& OutIndices)
{
	//todo procedural content algorithm
}
