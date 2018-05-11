/*
* EZ-Mobile-Ads - unreal engine 4 ads plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com> All Rights Reserved.
*/

#include "Tappx.h"
#include "IOSAppDelegate.h"
#include "Misc/ConfigCacheIni.h"
#import <AdsUtil/AdsUtil.h>

void FTappxModule::ShowBanner(enAdsBannerPos pos)
{
    UIViewController* curViewController = (UIViewController*)[IOSAppDelegate GetDelegate].IOSController;

    dispatch_async(dispatch_get_main_queue(), ^{
        [[TappxHelper GetDelegate] ShowBanner:curViewController isBottom:pos==enAdsBannerPos::enAdsBannerPos_Bottom];
    });
}

void FTappxModule::HideBanner()
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [[TappxHelper GetDelegate] HideBanner];
    });
}

void FTappxModule::ShowInterstitialAd()
{
    UIViewController* curViewController = (UIViewController*)[IOSAppDelegate GetDelegate].IOSController;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [[TappxHelper GetDelegate] ShowInterstitialAds:curViewController];
    });
}

bool FTappxModule::IsBannerReady()
{
    NSMutableDictionary *resultDictionary = [NSMutableDictionary dictionaryWithCapacity:1];
    [[TappxHelper GetDelegate] performSelectorOnMainThread:@selector(IsBannerReady:) withObject:resultDictionary waitUntilDone:YES];
    
    NSNumber* number = (NSNumber*)[resultDictionary objectForKey:@"RetValue"];
    bool ret = (bool)[number boolValue];
    
    return ret;
}

bool FTappxModule::IsInterstitalReady()
{
    NSMutableDictionary *resultDictionary = [NSMutableDictionary dictionaryWithCapacity:1];
    [[TappxHelper GetDelegate] performSelectorOnMainThread:@selector(IsInterstitalReady:) withObject:resultDictionary waitUntilDone:YES];
    
    NSNumber* number = (NSNumber*)[resultDictionary objectForKey:@"RetValue"];
    bool ret = (bool)[number boolValue];
    
    return ret;
}



void FTappxModule::StartupModule()
{
    bool isEnable = false;
    
    GConfig->GetBool(TEXT("/Script/AdCollectionEditor.TappxSetting"), TEXT("bIsIOSEnabled"), isEnable, GEngineIni);
    if(isEnable)
    {
        FString appKey;
        GConfig->GetString(TEXT("/Script/AdCollectionEditor.TappxSetting"), TEXT("IOSAppKey"), appKey, GEngineIni);
        
        UIViewController* curViewController = (UIViewController*)[IOSAppDelegate GetDelegate].IOSController;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [[TappxHelper GetDelegate] InitSDK:curViewController AppKey:[NSString stringWithFString:appKey] ];
        });
    }
}

void FTappxModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
    
}
