// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Kismet/BlueprintFunctionLibrary.h"

#include "BoneIndexViewer.generated.h"

USTRUCT(BlueprintType)
struct BONEINDEXVIEWER_API FBoneIndexParams
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 Index{-1};

	UPROPERTY(BlueprintReadWrite)
	FName Name;
};

UCLASS(BlueprintType)
class BONEINDEXVIEWER_API UBoneIndexViewerFunctionLibrary
	: public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static TArray<FBoneIndexParams> GetSkeletonBoneIndices(USkeletalMesh* InSkeletalMesh);

	//	未実装
	UFUNCTION(BlueprintCallable)
	static TArray<FBoneIndexParams> GetMeshBoneIndices(USkeletalMesh* InSkeletalMesh);

	//	未実装
	UFUNCTION(BlueprintCallable)
	static TArray<FBoneIndexParams> GetCompactPoseBoneIndices(USkeletalMesh* InSkeletalMesh);
};
