/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/Component/Component.h>

#include <Paper_Kid/Paper_KidBus.h>

namespace Paper_Kid
{
    class Paper_KidSystemComponent
        : public AZ::Component
        , protected Paper_KidRequestBus::Handler
    {
    public:
        AZ_COMPONENT(Paper_KidSystemComponent, "{6C113FD8-0849-4B54-961A-5C4AADDACB33}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        Paper_KidSystemComponent();
        ~Paper_KidSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // Paper_KidRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
