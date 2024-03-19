// Copyright Morph


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for(const FAuraAttributeInfo Info : AttributeInformation)
	{
		if(Info.AttributeTag == AttributeTag)
		{
			if(Info.AttributeTag.MatchesTagExact(AttributeTag))
			{
				return Info;
			}
		}
	}
	if(bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find info for attributeTag [%s] on AttributeInfo [%s]."), *AttributeTag.ToString(), *GetNameSafe(this));
	}

	return FAuraAttributeInfo();
}
