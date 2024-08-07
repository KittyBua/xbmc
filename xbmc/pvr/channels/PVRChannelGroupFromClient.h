/*
 *  Copyright (C) 2012-2023 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "pvr/channels/PVRChannelGroup.h"

struct PVR_CHANNEL_GROUP;

namespace PVR
{

class CPVRChannelGroupFromClient : public CPVRChannelGroup
{
public:
  /*!
   * @brief Create a new channel group instance.
   * @param path The channel group path.
   * @param allChannelsGroup The channel group containing all TV or radio channels.
   */
  CPVRChannelGroupFromClient(const CPVRChannelsPath& path,
                             const std::shared_ptr<const CPVRChannelGroup>& allChannelsGroup);

  /*!
   * @brief Create a new channel group instance from a channel group provided by a PVR client.
   * @param group The channel group provided by the client.
   * @param clientID The id of the client providing the group.
   * @param allChannelsGroup The channel group containing all TV or radio channels.
   */
  CPVRChannelGroupFromClient(const PVR_CHANNEL_GROUP& group,
                             int clientID,
                             const std::shared_ptr<const CPVRChannelGroup>& allChannelsGroup);

  /*!
   * @brief Get the group's origin.
   * @return The origin.
   */
  Origin GetOrigin() const override { return Origin::CLIENT; }

  /*!
   * @brief Return the type of this group.
   */
  int GroupType() const override { return PVR_GROUP_TYPE_CLIENT; }

  /*!
   * @brief Check whether this group could be deleted by the user.
   * @return True if the group could be deleted, false otherwise.
   */
  bool SupportsDelete() const override { return false; }

  /*!
   * @brief Check whether members could be added to this group by the user.
   * @return True if members could be added, false otherwise.
   */
  bool SupportsMemberAdd() const override { return false; }

  /*!
   * @brief Check whether members could be removed from this group by the user.
   * @return True if members could be removed, false otherwise.
   */
  bool SupportsMemberRemove() const override { return false; }

  /*!
   * @brief Check whether this group is owner of the channel instances it contains.
   * @return True if owner, false otherwise.
   */
  bool IsChannelsOwner() const override { return false; }

  /*!
   * @brief Update data with channel group members from the given clients, sync with local data.
   * @param clients The clients to fetch data from. Leave empty to fetch data from all created clients.
   * @return True on success, false otherwise.
   */
  bool UpdateFromClients(const std::vector<std::shared_ptr<CPVRClient>>& clients) override;
};
} // namespace PVR
