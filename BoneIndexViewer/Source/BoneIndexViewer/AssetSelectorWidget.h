// Copyright(c) dokuro.moe All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ContentWidget.h"
#include "PropertyCustomizationHelpers.h"

#include "AssetSelectorWidget.generated.h"

class IPropertyHandle;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnObjectChanged, const FAssetData&, InAssetData);

UCLASS(BlueprintType)
class BONEINDEXVIEWER_API UAssetSelectorWidget
	: public UContentWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TObjectPtr<UClass> AllowedClass;
	
	UPROPERTY(BlueprintAssignable)
	FOnObjectChanged OnObjectChanged;

	UPROPERTY(BlueprintReadOnly)
	FString SelectedAssetPath;

protected:

	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	virtual void OnObjectChangedInternal(const FAssetData& InAssetData);

	FOnSetObject OnSetObject;
	TSharedPtr<SObjectPropertyEntryBox> ObjectPropertyEntryBox;
	TSharedPtr<IPropertyHandle> PropertyHandle;
};
