/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Paper_Kid
{
    class Paper_KidRequests
    {
    public:
        AZ_RTTI(Paper_KidRequests, "{D01FF8B1-C0F8-4DA5-96F6-A213582C2A55}");
        virtual ~Paper_KidRequests() = default;
        // Put your public methods here
    };

    class Paper_KidBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using Paper_KidRequestBus = AZ::EBus<Paper_KidRequests, Paper_KidBusTraits>;
    using Paper_KidInterface = AZ::Interface<Paper_KidRequests>;

} // namespace Paper_Kid
