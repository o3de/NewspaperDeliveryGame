/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "Paper_KidSystemComponent.h"

namespace Paper_Kid
{
    void Paper_KidSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<Paper_KidSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<Paper_KidSystemComponent>("Paper_Kid", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void Paper_KidSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("Paper_KidService"));
    }

    void Paper_KidSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("Paper_KidService"));
    }

    void Paper_KidSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void Paper_KidSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    Paper_KidSystemComponent::Paper_KidSystemComponent()
    {
        if (Paper_KidInterface::Get() == nullptr)
        {
            Paper_KidInterface::Register(this);
        }
    }

    Paper_KidSystemComponent::~Paper_KidSystemComponent()
    {
        if (Paper_KidInterface::Get() == this)
        {
            Paper_KidInterface::Unregister(this);
        }
    }

    void Paper_KidSystemComponent::Init()
    {
    }

    void Paper_KidSystemComponent::Activate()
    {
        Paper_KidRequestBus::Handler::BusConnect();
    }

    void Paper_KidSystemComponent::Deactivate()
    {
        Paper_KidRequestBus::Handler::BusDisconnect();
    }
}
