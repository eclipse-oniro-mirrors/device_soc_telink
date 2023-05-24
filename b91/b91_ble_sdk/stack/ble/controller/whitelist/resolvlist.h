/******************************************************************************
 * Copyright (c) 2022 Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *****************************************************************************/
#ifndef LL_RESOLVLIST_H_
#define LL_RESOLVLIST_H_

#include <stack/ble/ble_common.h>

/**
 * @brief      This function is used to initialize resolving list && RPA concerned parameters
 * @param[in]  none
 * @return     Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
void blc_ll_resolvListInit(void);

/**
 * @brief      This function is used to reset resolving list
 * @param[in]  none
 * @return     Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t ll_resolvingList_reset(void);

/**
 * @brief      This function is used to add a device to resolving list
 * @param[in]  peerIdAddrType - device mac address type
 * @param[in]  peerIdAddr - device mac address
 * @param[in]  peer_irk - peer IRK pointer
 * @param[in]  local_irk - local IRK pointer
 * @return     Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t ll_resolvingList_add(u8 peerIdAddrType, u8 *peerIdAddr, u8 *peer_irk, u8 *local_irk);

/**
 * @brief      This function is used to delete a device from resolving list
 * @param[in]  peerIdAddrType - device mac address type
 * @param[in]  peerIdAddr - device mac address
 * @return     Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t ll_resolvingList_delete(u8 peerIdAddrType, u8 *peerIdAddr);

/**
 * @brief      This function is used to enable resolvinglist resolution
 * @param[in]  resolutionEn - 1: enable; 0:disable
 * @return     Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t ll_resolvingList_setAddrResolutionEnable(u8 resolutionEn);

/**
 * @brief      This function is used to get resolving list size
 * @param[out] pointer to size
 * @return     Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t ll_resolvingList_getSize(u8 *Size);

/**
 * @brief	This function is used to get the current peer Resolvable Private
 * 			Address being used for the corresponding peer Public and Random (static) Identity Address.
 * @param[in]	peerIdAddrType - Peer Identity Address Type
 * @param[in]	peerIdAddr - Peer Identity Address
 * @param[out]  peerResolvableAddr - Peer Resolvable Address
 * @return	Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t ll_resolvingList_getPeerResolvableAddr(u8 peerIdAddrType, u8 *peerIdAddr, u8 *peerResolvableAddr);

/**
 * @brief	This function is used to get the current local Resolvable Private
 * 			Address being used for the corresponding peer Identity Address.
 * @param[in]	peerIdAddrType - Peer Identity Address Type
 * @param[in]	peerIdAddr - Peer Identity Address
 * @param[out]  LocalResolvableAddr - Local Resolvable Address
 * @return	Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t ll_resolvingList_getLocalResolvableAddr(u8 peerIdAddrType, u8 *peerIdAddr, u8 *LocalResolvableAddr);

/**
 * @brief	This function is used to enable resolution of Resolvable Private Addresses in the Controller.
 * @param[in]	resolutionEn - Address Resolution Enable/Disable
 * @return	Status - 0x00: command succeeded; 0x01-0xFF: command failed
 */
ble_sts_t ll_resolvingList_setAddrResolutionEnable(u8 resolutionEn);

/*
 * @brief 	This function is used to set the length of time the controller uses a
 * 			Resolvable Private Address before a new resolvable	private address is
 * 			generated and starts being used. This timeout applies to all addresses
 * 			generated by the controller
*  @param[in]	timeout_s - RPA_Timeout: RPA_Timeout measured in seconds Range: 0x0001 to 0x0E10,
                                         Time range: 1 s to 1 hour
 * @return	Status - 0x00: command succeeded; 0x01-0xFF: command failed
 * */
ble_sts_t ll_resolvingList_setResolvablePrivateAddrTimer(u16 timeout_s);

/*
 * @brief 	This function is used to allow the Host to specify the privacy mode to
 * 			be used for a given entry on the resolving list.
 * @param[in]	peerIdAddrType - Peer Identity Address Type
 * @param[in]	peerIdAddr - Peer Identity Address
 * @param[in]	privMode - Privacy_Mode: Network/Device Privacy Mode
 * @return	Status - 0x00: command succeeded; 0x01-0xFF: command failed
 * */
ble_sts_t ll_resolvingList_setPrivcyMode(u8 peerIdAddrType, u8 *peerIdAddr, u8 privMode);

#endif /* LL_RESOLVLIST_H_ */
