#pragma once

#include "CoreMinimal.h"
#include "FastNoiseLite.h"
#include "Biome.generated.h"

USTRUCT(BlueprintType)
struct FBiomeData
{
	GENERATED_BODY()

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
};

UCLASS(Abstract, Blueprintable)
class SCRAPRUNNERS_API ABiome : public AActor
{
	GENERATED_BODY()

public:
	FastNoiseLite Noise;
	virtual FBiomeData GetBiomeData() const = 0;

	virtual void GenerateTerrainData(TArray<FVector>& OutVertexPositions, TArray<FVector>& OutNormals, TArray<FVector2D>& OutUVs, TArray<int32>& OutIndices);
};
