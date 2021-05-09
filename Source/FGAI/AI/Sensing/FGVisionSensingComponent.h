#pragma once

#include "Components/ActorComponent.h"
#include "FGVisionSensingComponent.generated.h"

class AActor;
class UFGVisionSensingTargetComponent;
class UFGVisionSensingSettings;

USTRUCT(BlueprintType)
struct FFGVisionSensingResults
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	AActor* SensedActor = nullptr;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFGVisionSensingDelegate, const FFGVisionSensingResults&, Results);

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class UFGVisionSensingComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UFGVisionSensingComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool IsActorVisible(const AActor* ActorToTest, const FVector& Origin, const FVector& Direction, float DistanceMinimum) const; 

	UPROPERTY(Transient)
	TArray<UFGVisionSensingTargetComponent*> SensedTargets;

	UPROPERTY(Transient)
	TArray<UFGVisionSensingTargetComponent*> SeenTargets;

	float GetVisionInRadians() const;

	UPROPERTY(BlueprintAssignable)
	FFGVisionSensingDelegate OnTargetInCentralVision;
	
	UPROPERTY(BlueprintAssignable)
	FFGVisionSensingDelegate OnTargetSensed;

	UPROPERTY(BlueprintAssignable)
	FFGVisionSensingDelegate OnTargetLost;

	UPROPERTY(EditAnywhere, Category = Sensing)
	UFGVisionSensingSettings* SensingSettings = nullptr;

	UPROPERTY(EditAnywhere, Category = Debug)
	bool bDebugDrawVision = false;
};
