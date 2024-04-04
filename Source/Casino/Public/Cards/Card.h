// Copyright Renaissance. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.generated.h"

UENUM(BlueprintType)
enum ECardClassType
{
	Default,
	Summon,
	Spell
};

USTRUCT(BlueprintType)
struct FCardInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DisplayDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> DisplayImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ECardClassType> ClassType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(EditCondition="ClassType != ECardClassType::Default", EditConditionHides))
	TArray<TSoftClassPtr<AActor>> ActorsToSpawnOnHit;
};

UCLASS()
class CASINO_API ACard : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
