/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/


#include "TappxSetting.h"
#include "AdCollectionEditor.h"



#if WITH_EDITOR
void UTappxSetting::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
    SaveConfig(CPF_Config, *GetDefaultConfigFilename() );
}
#endif
