// Copyright Renaissance. All Rights Reserved.


#include "AbilitySystem/CasinoAttributeSet.h"
#include "GameplayEffectExtension.h"

UCasinoAttributeSet::UCasinoAttributeSet()
{
	InitMaxHealth(100.0f);
	InitHealth(100.0f);
}

void UCasinoAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	const FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetMaxHealthAttribute())
	{
		SetMaxHealth(FMath::Max(GetMaxHealth(), 0.0f));
	}
}
