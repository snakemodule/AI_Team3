#pragma once

#include "Engine/DataAsset.h"
#include "FGVisionSensingSettings.generated.h"

namespace gp
{
	struct FVector
	{
	};

	UCLASS()
	class UFGVisionSensingSettings : public UDataAsset
	{
		GENERATED_BODY()
	public:

		FVector MyFVector;

		::FVector OGFVector;

		UPROPERTY(EditAnywhere, Category = Sensing)
		float InnerAngle = 90.0f;

		UPROPERTY(EditAnywhere, Category = Sensing)
		float Angle = 180.0f;

		UPROPERTY(EditAnywhere, Category = Sensing)
		float Distance = 8000.0f;

		UPROPERTY(EditAnywhere, Category = Sensing)
		float DistanceInner = 8000.0f;
	};
}
