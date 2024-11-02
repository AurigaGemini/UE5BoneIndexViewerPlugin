// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoneIndexViewer.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, BoneIndexViewer, "BoneIndexViewer" );

//static
TArray<FBoneIndexParams> UBoneIndexViewerFunctionLibrary::GetSkeletonBoneIndices(USkeletalMesh* InSkeletalMesh)
{
	TArray<FBoneIndexParams> ParamsArray;

	if (!IsValid(InSkeletalMesh)) { return ParamsArray; }

	const FReferenceSkeleton& Skeleton = InSkeletalMesh->GetRefSkeleton();
	const int32 BoneNum = Skeleton.GetNum();
	ParamsArray.Reserve(BoneNum);
	for (int32 BoneIndex = 0; BoneIndex < BoneNum; BoneIndex++)
	{
		const FName BoneName = Skeleton.GetBoneName(BoneIndex);
		FBoneIndexParams Params;
		Params.Index = BoneIndex;
		Params.Name  = BoneName;
		ParamsArray.Add(Params);
	}

	return ParamsArray;
}

//static
TArray<FBoneIndexParams> UBoneIndexViewerFunctionLibrary::GetMeshBoneIndices(USkeletalMesh* InSkeletalMesh)
{
	TArray<FBoneIndexParams> Params;
	//未対応
	return Params;
}

//static
TArray<FBoneIndexParams> UBoneIndexViewerFunctionLibrary::GetCompactPoseBoneIndices(USkeletalMesh* InSkeletalMesh)
{
	TArray<FBoneIndexParams> Params;
	//未対応
	return Params;
}
