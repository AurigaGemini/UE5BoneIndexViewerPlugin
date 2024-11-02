// Copyright(c) dokuro.moe All Rights Reserved.

#include "AssetSelectorWidget.h"
#include "PropertyHandle.h"

//UE_DISABLE_OPTIMIZATION

namespace { namespace Local {

class FPropertyHandle
	: public IPropertyHandle
{
	FString Value;
	FName Name;
	FFieldVariant FieldVariant;
	TSharedPtr<FStrProperty> StrProperty;
public:
	FPropertyHandle()
		: Name("Test")
		, StrProperty(::MakeShareable<FStrProperty>(new FStrProperty(FieldVariant, Name, EObjectFlags::RF_NoFlags)))
	{
		StrProperty->SetMetaData(Name, TEXT(""));
	}
	virtual FPropertyAccess::Result SetValue(const FAssetData& InAssetData, EPropertyValueSetFlags::Type) override {
		Value = InAssetData.GetSoftObjectPath().ToString();
		return FPropertyAccess::Result::Success;
	}
	virtual FPropertyAccess::Result GetValueAsFormattedString(FString& OutValue, EPropertyPortFlags) const override {
		OutValue = Value;
		return FPropertyAccess::Result::Success;
	}
	virtual bool IsValidHandle() const override { return true; }
	virtual bool IsSamePropertyNode(TSharedPtr<IPropertyHandle>) const override { return false; }
	virtual bool IsEditConst() const override { return false; }
	virtual bool IsEditable() const override { return true; }
	virtual const FFieldClass* GetPropertyClass() const override { return nullptr; }
	virtual FProperty* GetProperty() const override { return StrProperty.Get(); }
	virtual FStringView GetPropertyPath() const override { return FStringView(); }
	virtual TSharedPtr<FPropertyPath> CreateFPropertyPath() const override { return TSharedPtr<FPropertyPath>(); }
	virtual int32 GetArrayIndex() const override { return -1; }
	virtual void RequestRebuildChildren() override {}
	virtual FProperty* GetMetaDataProperty() const override { return nullptr; }
	virtual bool HasMetaData(const FName&) const override { return false; }
	virtual const FString& GetMetaData(const FName&) const override {
		static FString s;
		return s;
	}
	virtual bool GetBoolMetaData(const FName&) const override { return false; }
	virtual int32 GetIntMetaData(const FName&) const override { return -1; }
	virtual float GetFloatMetaData(const FName&) const override { return -1.f; }
	virtual double GetDoubleMetaData(const FName&) const override { return -1.; }
	virtual UClass* GetClassMetaData(const FName&) const override { return nullptr; }
	virtual void SetInstanceMetaData(const FName&, const FString&) override {}
	virtual const FString* GetInstanceMetaData(const FName& Key) const override { return nullptr; }
	virtual const TMap<FName, FString>* GetInstanceMetaDataMap() const override { return nullptr; }
	virtual FText GetToolTipText() const override { return FText(); }
	virtual void SetToolTipText(const FText& ToolTip) override {}
	virtual bool HasDocumentation() override { return false; }
	virtual FString GetDocumentationLink() override { return FString(); }
	virtual FString GetDocumentationExcerptName() override { return FString(); }
	virtual uint8* GetValueBaseAddress(uint8*) const override { return nullptr; }
	virtual FPropertyAccess::Result GetValueAsDisplayString(FString&, EPropertyPortFlags) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValueAsFormattedText(FText&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValueAsDisplayText(FText&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValueFromFormattedString(const FString&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual void SetOnPropertyValueChanged(const FSimpleDelegate&) override {}
	virtual void SetOnPropertyValueChangedWithData(const TDelegate<void(const FPropertyChangedEvent&)>&) override {}
	virtual void SetOnChildPropertyValueChanged(const FSimpleDelegate&) override {}
	virtual void SetOnChildPropertyValueChangedWithData(const TDelegate<void(const FPropertyChangedEvent&)>&) override {}
	virtual void SetOnPropertyValuePreChange(const FSimpleDelegate&) override {}
	virtual void SetOnChildPropertyValuePreChange(const FSimpleDelegate&) override {}
	virtual void SetOnPropertyResetToDefault(const FSimpleDelegate&) override {}
	virtual FPropertyAccess::Result GetValue(FString&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(float&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(double&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(bool&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(int8&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(int16&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(int32&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(int64&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(uint8&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(uint16&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(uint32&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(uint64&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(FText&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(FName&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(FVector&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(FVector2D&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(FVector4&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(FQuat&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(FRotator&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(UObject*&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(const UObject*&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(FAssetData&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValueData(void*&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(FProperty*&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetValue(const FProperty*&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const FString&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const float&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const double&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const bool&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const int8&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const int16&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const int32&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const int64&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const uint8&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const uint16&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const uint32&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const uint64&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const FText&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const FName&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const FVector&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const FVector2D&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const FVector4&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const FQuat&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const FRotator&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(UObject* const&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const UObject* const&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const TCHAR*, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(FProperty* const&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetValue(const FProperty* const&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual void NotifyPreChange() override {}
	virtual void NotifyPostChange(EPropertyChangeType::Type) override {}
	virtual void NotifyFinishedChangingProperties() override {}
	virtual FPropertyAccess::Result SetObjectValueFromSelection() override { return FPropertyAccess::Result::Fail; }
	virtual int32 GetNumPerObjectValues() const override { return -1; }
	virtual FPropertyAccess::Result SetPerObjectValues(const TArray<FString>&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetPerObjectValues(TArray<FString>&) const override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result SetPerObjectValue(const int32, const FString&, EPropertyValueSetFlags::Type) override { return FPropertyAccess::Result::Fail; }
	virtual FPropertyAccess::Result GetPerObjectValue(const int32, FString&) const override { return FPropertyAccess::Result::Fail; }
	virtual int32 GetIndexInArray() const override { return -1; }
	virtual TSharedPtr<IPropertyHandle> GetChildHandle(FName, bool) const override { return TSharedPtr<IPropertyHandle>(); }
	virtual TSharedPtr<IPropertyHandle> GetChildHandle(uint32) const override { return TSharedPtr<IPropertyHandle>(); }
	virtual TSharedPtr<IPropertyHandle> GetParentHandle() const override { return TSharedPtr<IPropertyHandle>(); }
	virtual TSharedPtr<IPropertyHandle> GetKeyHandle() const override { return TSharedPtr<IPropertyHandle>(); }
	virtual FPropertyAccess::Result GetNumChildren(uint32&) const override { return FPropertyAccess::Result::Fail; }
	virtual uint32 GetNumOuterObjects() const override { return -1; }
	virtual void GetOuterObjects(TArray<UObject*>&) const override {}
	virtual void GetOuterStructs(TArray<TSharedPtr<FStructOnScope>>&) const override {}
	virtual const UClass* GetOuterBaseClass() const override { return nullptr; }
	virtual void ReplaceOuterObjects(const TArray<UObject*>&) override {}
	virtual void GetOuterPackages(TArray<UPackage*>&) const override {}
	virtual void EnumerateRawData(const EnumerateRawDataFuncRef&) override {}
	virtual void EnumerateConstRawData(const EnumerateConstRawDataFuncRef&) const override {}
	virtual void AccessRawData(TArray<void*>&) override {}
	virtual void AccessRawData(TArray<const void*>&) const override {}
	virtual TSharedPtr<IPropertyHandleArray> AsArray() override { return TSharedPtr<IPropertyHandleArray>(); }
	virtual TSharedPtr<IPropertyHandleSet> AsSet() override { return TSharedPtr<IPropertyHandleSet>(); }
	virtual TSharedPtr<IPropertyHandleMap> AsMap() override { return TSharedPtr<IPropertyHandleMap>(); }
	virtual TSharedPtr<IPropertyHandleOptional> AsOptional() override { return TSharedPtr<IPropertyHandleOptional>(); }
	virtual TSharedPtr<IPropertyHandleStruct> AsStruct() override { return TSharedPtr<IPropertyHandleStruct>(); }
	virtual FText GetPropertyDisplayName() const override { return FText(); }
	virtual void SetPropertyDisplayName(FText) override {}
	virtual void ResetToDefault() override {}
	virtual bool DiffersFromDefault() const override { return false; }
	virtual FText GetResetToDefaultLabel() const override { return FText(); }
	virtual bool GeneratePossibleValues(TArray< TSharedPtr<FString> >&, TArray< FText >&, TArray<bool>&) override { return false; }
	virtual void MarkHiddenByCustomization() override {}
	virtual void MarkResetToDefaultCustomized(bool) override {}
	virtual void ClearResetToDefaultCustomized() override {}
	virtual bool IsFavorite() const override { return false; }
	virtual bool IsCustomized() const override { return false; }
	virtual bool IsResetToDefaultCustomized() const override { return false; }
	virtual FString GeneratePathToProperty() const override { return FString(); }
	virtual TSharedRef<SWidget> CreatePropertyNameWidget(const FText&, const FText&) const override { return SNullWidget::NullWidget; }
	virtual TSharedRef<SWidget> CreatePropertyNameWidget(const FText&, const FText&, bool, bool, bool) const { return SNullWidget::NullWidget; } // deprecated
	virtual TSharedRef<SWidget> CreatePropertyValueWidget(bool) const override { return SNullWidget::NullWidget; }
	virtual TSharedRef<SWidget> CreatePropertyValueWidgetWithCustomization(const IDetailsView*) override { return SNullWidget::NullWidget; }
	virtual TSharedRef<SWidget> CreateDefaultPropertyButtonWidgets() const override { return SNullWidget::NullWidget; }
	virtual void CreateDefaultPropertyCopyPasteActions(FUIAction&, FUIAction&) const override {}
	virtual void AddRestriction(TSharedRef<const FPropertyRestriction>) override {}
	virtual bool IsRestricted(const FString&) const override { return false; }
	virtual bool IsRestricted(const FString&, TArray<FText>&) const override { return false; }
	virtual bool GenerateRestrictionToolTip(const FString&, FText&) const override { return false; }
	virtual bool IsDisabled(const FString&) const override { return false; }
	virtual bool IsDisabled(const FString&, TArray<FText>&) const override { return false; }
	virtual bool IsHidden(const FString&) const override { return false; }
	virtual bool IsHidden(const FString&, TArray<FText>&) const override { return false; }
	virtual void SetIgnoreValidation(bool bInIgnore) override {}
	virtual TArray<TSharedPtr<IPropertyHandle>> AddChildStructure(TSharedRef<FStructOnScope>) override { return TArray<TSharedPtr<IPropertyHandle>>(); }
	virtual TArray<TSharedPtr<IPropertyHandle>> AddChildStructure(TSharedRef<IStructureDataProvider>) override { return TArray<TSharedPtr<IPropertyHandle>>(); }
	virtual bool CanResetToDefault() const override { return false; }
	virtual void ExecuteCustomResetToDefault(const FResetToDefaultOverride&) override {}
	virtual FName GetDefaultCategoryName() const override { return FName(); }
	virtual FText GetDefaultCategoryText() const override { return FText(); }
	virtual bool IsCategoryHandle() const override { return false; }
	virtual bool IsExpanded() const override { return false; }
	virtual void SetExpanded(bool) override {}
	virtual bool GeneratePossibleValues(TArray<FString>&, TArray<FText>&, TArray<bool>&, TArray<FText>*) override { return false; }
};

}}

void UAssetSelectorWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	this->ObjectPropertyEntryBox.Reset();
	this->OnSetObject.Unbind();
	this->PropertyHandle.Reset();
}

TSharedRef<SWidget> UAssetSelectorWidget::RebuildWidget() {
	this->PropertyHandle = ::MakeShared<::Local::FPropertyHandle>();
	this->OnSetObject.BindUObject(this, &UAssetSelectorWidget::OnObjectChangedInternal);
	this->ObjectPropertyEntryBox = SNew(SObjectPropertyEntryBox)
		.PropertyHandle(this->PropertyHandle)
		.AllowedClass(this->AllowedClass)
		.OnObjectChanged(this->OnSetObject);
	return this->ObjectPropertyEntryBox.ToSharedRef();
}

void UAssetSelectorWidget::OnObjectChangedInternal(const FAssetData& InAssetData)
{
	if (!this->OnObjectChanged.IsBound()) { return; }
	this->SelectedAssetPath = InAssetData.PackageName.ToString();
	this->OnObjectChanged.Broadcast(InAssetData);
}

UE_ENABLE_OPTIMIZATION
