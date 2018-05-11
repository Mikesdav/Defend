/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/


#pragma once

#include "CoreMinimal.h"
#include "TappxSetting.generated.h"

/**
 * 
 */
UCLASS(transient, config = Engine)
class UTappxSetting : public UObject
{
	GENERATED_BODY()
	
	// if the android tappx ads enable
    UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "If Is Tappx Android Enable"))
	bool bIsAndroidEnabled;

	// the android tappx appid
	UPROPERTY(Config, EditAnywhere, Category = Android, Meta = (DisplayName = "Tappx Android AppID"))
	FString AndroidAppKey;
    
    // if the ios tappx ads enable
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "If Is Tappx IOS Enable"))
    bool bIsIOSEnabled;
    
	// the ios tappx appid
    UPROPERTY(Config, EditAnywhere, Category = IOS, Meta = (DisplayName = "Tappx IOS AppID"))
    FString IOSAppKey;


#if WITH_EDITOR
	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
