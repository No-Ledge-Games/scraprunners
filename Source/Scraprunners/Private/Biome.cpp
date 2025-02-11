// Fill out your copyright notice in the Description page of Project Settings.


#include "Biome.h"
#include "Kismet/KismetMathLibrary.h"


void ABiome::GenerateTerrainData(TArray<FVector>& OutVertexPositions, TArray<FVector>& OutNormals, TArray<FVector2D>& OutUVs, TArray<int32>& OutIndices)
{
	Noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
	Noise.SetSeed(FMath::Rand());
	FBiomeData BiomeData; //this isn't going to work, fix later

	int32 Ceiling = BiomeData.LengthAndWidth * BiomeData.Resolution;

	for (int32 x = 0; x <= Ceiling; x++)
	{
		for (int32 y = 0; y <= Ceiling; y++)
		{
			OutNormals.Add(FVector(0, 0, 1));

			float ZCoord = Noise.GetNoise((float)x, (float)y) * BiomeData.TilingScalar;
			float XCoord = float(x) / BiomeData.Resolution * BiomeData.SizeScalar;
			float YCoord = float(y) / BiomeData.Resolution * BiomeData.SizeScalar;

			OutVertexPositions.Add(FVector(XCoord, YCoord, ZCoord));

			float UVX = (float)x * BiomeData.Resolution * BiomeData.TilingScalar;
			float UVY = (float)y * BiomeData.Resolution * BiomeData.TilingScalar;

			OutUVs.Add(FVector2D(UVX, UVY));

			int32 BottomLeft = x * (Ceiling + 1) + y;
			int32 BottomRight = BottomLeft + 1;
			int32 TopLeft = BottomLeft + Ceiling + 1;
			int32 TopRight = TopLeft + 1;

			if (y < Ceiling && x < Ceiling)
			{
				//1st tri
				OutIndices.Add(BottomLeft);
				OutIndices.Add(BottomRight);
				OutIndices.Add(TopRight);

				//2nd tri
				OutIndices.Add(BottomLeft);
				OutIndices.Add(TopRight);
				OutIndices.Add(TopLeft);
			}
		}
	}
}
