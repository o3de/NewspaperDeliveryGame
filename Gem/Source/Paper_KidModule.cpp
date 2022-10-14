/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "Paper_KidSystemComponent.h"

namespace Paper_Kid
{
    class Paper_KidModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(Paper_KidModule, "{D1D68BE7-89A4-4BEB-B16D-A78C32C9C1BC}", AZ::Module);
        AZ_CLASS_ALLOCATOR(Paper_KidModule, AZ::SystemAllocator, 0);

        Paper_KidModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                Paper_KidSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<Paper_KidSystemComponent>(),
            };
        }
    };
}// namespace Paper_Kid

AZ_DECLARE_MODULE_CLASS(Gem_Paper_Kid, Paper_Kid::Paper_KidModule)
