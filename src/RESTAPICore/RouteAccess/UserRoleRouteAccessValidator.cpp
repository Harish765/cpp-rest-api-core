#include "stdafx.h"
#include "UserRoleRouteAccessValidator.h"

#include "Endpoint/ClaimConstants.h"
#include "Endpoint/EndpointRequestData.h"
#include "RouteAccess/IUserRoleService.h"


namespace systelab { namespace rest_api_core {

	UserRoleRouteAccessValidator::UserRoleRouteAccessValidator(const std::vector<std::string>& allowedRoles,
															   const IUserRoleService& userRoleService)
		:m_allowedRoles(allowedRoles)
		,m_userRoleService(userRoleService)
	{
	}

	UserRoleRouteAccessValidator::~UserRoleRouteAccessValidator() = default;

	bool UserRoleRouteAccessValidator::hasAccess(EndpointRequestData& endpointRequestData) const
	{
		try
		{
			std::string sub = endpointRequestData.getAuthorizationClaims().getClaim(claim::SUBJECT);
			std::vector<std::string> roles = m_userRoleService.getUserRoles(sub);
			for (auto role : roles)
			{
				for (auto allowedRole : m_allowedRoles)
				{
					if (role == allowedRole)
					{
						return true;
					}
				}
			}

			return false;
		}
		catch (std::exception&)
		{
			return false;
		}
	}

}}
