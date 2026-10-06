/*
 * AUTO-GENERATED FILE - DO NOT EDIT.
 * Generated from the Excel CAN protocol definition.
 */

#include "can_messages.h"

#include <string.h>

bool MsgSpeedStatus_decode(const uint8_t *data, uint8_t dlc, MsgSpeedStatus_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgSpeedStatus_t *)0) || (dlc < MSGSPEEDSTATUS_CAN_DLC))
    {
        return false;
    }

    /* Decode SpeedActual. */
    msg->SpeedActual = (int32_t)(((int64_t)(((((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8 | ((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 16 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 24) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000))));

    return true;
}

bool MsgSpeedStatus_encode(const MsgSpeedStatus_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgSpeedStatus_t *)0) || (dlc < MSGSPEEDSTATUS_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGSPEEDSTATUS_CAN_DLC);

    /* Encode SpeedActual. */
    data[0] |= (uint8_t)(((((uint64_t)msg->SpeedActual) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->SpeedActual) >> 8) & UINT64_C(0xFF)) << 0);
    data[2] |= (uint8_t)(((((uint64_t)msg->SpeedActual) >> 16) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->SpeedActual) >> 24) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgSpeedStatus_send(const MsgSpeedStatus_t *msg)
{
    uint8_t data[MSGSPEEDSTATUS_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgSpeedStatus_t *)0) ||
        (!(((double)msg->SpeedActual >= -2147483648) && ((double)msg->SpeedActual <= 2147483647))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgSpeedStatus_encode(msg, data, MSGSPEEDSTATUS_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGSPEEDSTATUS_CAN_ID, true, data, MSGSPEEDSTATUS_CAN_DLC);
}

bool MsgSpeedSourceStatus_decode(const uint8_t *data, uint8_t dlc, MsgSpeedSourceStatus_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgSpeedSourceStatus_t *)0) || (dlc < MSGSPEEDSOURCESTATUS_CAN_DLC))
    {
        return false;
    }

    /* Decode SpeedSource. */
    msg->SpeedSource = (SpeedSource_value_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgSpeedSourceStatus_encode(const MsgSpeedSourceStatus_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgSpeedSourceStatus_t *)0) || (dlc < MSGSPEEDSOURCESTATUS_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGSPEEDSOURCESTATUS_CAN_DLC);

    /* Encode SpeedSource. */
    data[0] |= (uint8_t)(((((uint64_t)msg->SpeedSource) >> 0) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgSpeedSourceStatus_send(const MsgSpeedSourceStatus_t *msg)
{
    uint8_t data[MSGSPEEDSOURCESTATUS_CAN_DLC];

    if (!MsgSpeedSourceStatus_encode(msg, data, MSGSPEEDSOURCESTATUS_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGSPEEDSOURCESTATUS_CAN_ID, true, data, MSGSPEEDSOURCESTATUS_CAN_DLC);
}

bool MsgHeightStatus_decode(const uint8_t *data, uint8_t dlc, MsgHeightStatus_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgHeightStatus_t *)0) || (dlc < MSGHEIGHTSTATUS_CAN_DLC))
    {
        return false;
    }

    /* Decode HeightActual. */
    msg->HeightActual = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode HeightActualSensor1. */
    msg->HeightActualSensor1 = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode HeightActualSensor2. */
    msg->HeightActualSensor2 = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgHeightStatus_encode(const MsgHeightStatus_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgHeightStatus_t *)0) || (dlc < MSGHEIGHTSTATUS_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGHEIGHTSTATUS_CAN_DLC);

    /* Encode HeightActual. */
    data[0] |= (uint8_t)(((((uint64_t)msg->HeightActual) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->HeightActual) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode HeightActualSensor1. */
    data[2] |= (uint8_t)(((((uint64_t)msg->HeightActualSensor1) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->HeightActualSensor1) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode HeightActualSensor2. */
    data[4] |= (uint8_t)(((((uint64_t)msg->HeightActualSensor2) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->HeightActualSensor2) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgHeightStatus_send(const MsgHeightStatus_t *msg)
{
    uint8_t data[MSGHEIGHTSTATUS_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgHeightStatus_t *)0) ||
        (!(((double)msg->HeightActual >= 0) && ((double)msg->HeightActual <= 65535))) ||
        (!(((double)msg->HeightActualSensor1 >= 0) && ((double)msg->HeightActualSensor1 <= 65535))) ||
        (!(((double)msg->HeightActualSensor2 >= 0) && ((double)msg->HeightActualSensor2 <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgHeightStatus_encode(msg, data, MSGHEIGHTSTATUS_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGHEIGHTSTATUS_CAN_ID, true, data, MSGHEIGHTSTATUS_CAN_DLC);
}

bool MsgCounterStatus_decode(const uint8_t *data, uint8_t dlc, MsgCounterStatus_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgCounterStatus_t *)0) || (dlc < MSGCOUNTERSTATUS_CAN_DLC))
    {
        return false;
    }

    /* Decode TripTotalPlants. */
    msg->TripTotalPlants = (uint32_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8 | ((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 16 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 24);

    /* Decode TotalPlants. */
    msg->TotalPlants = (uint32_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8 | ((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 16 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 24);

    return true;
}

bool MsgCounterStatus_encode(const MsgCounterStatus_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgCounterStatus_t *)0) || (dlc < MSGCOUNTERSTATUS_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGCOUNTERSTATUS_CAN_DLC);

    /* Encode TripTotalPlants. */
    data[0] |= (uint8_t)(((((uint64_t)msg->TripTotalPlants) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->TripTotalPlants) >> 8) & UINT64_C(0xFF)) << 0);
    data[2] |= (uint8_t)(((((uint64_t)msg->TripTotalPlants) >> 16) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->TripTotalPlants) >> 24) & UINT64_C(0xFF)) << 0);

    /* Encode TotalPlants. */
    data[4] |= (uint8_t)(((((uint64_t)msg->TotalPlants) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->TotalPlants) >> 8) & UINT64_C(0xFF)) << 0);
    data[6] |= (uint8_t)(((((uint64_t)msg->TotalPlants) >> 16) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->TotalPlants) >> 24) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgCounterStatus_send(const MsgCounterStatus_t *msg)
{
    uint8_t data[MSGCOUNTERSTATUS_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgCounterStatus_t *)0) ||
        (!(((double)msg->TripTotalPlants >= 0) && ((double)msg->TripTotalPlants <= 4294967295))) ||
        (!(((double)msg->TotalPlants >= 0) && ((double)msg->TotalPlants <= 4294967295))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgCounterStatus_encode(msg, data, MSGCOUNTERSTATUS_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGCOUNTERSTATUS_CAN_ID, true, data, MSGCOUNTERSTATUS_CAN_DLC);
}

bool MsgMachineStatus_decode(const uint8_t *data, uint8_t dlc, MsgMachineStatus_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgMachineStatus_t *)0) || (dlc < MSGMACHINESTATUS_CAN_DLC))
    {
        return false;
    }

    /* Decode MachineStatus. */
    msg->MachineStatus = (MachineStatus_value_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xF)) << 0);

    return true;
}

bool MsgMachineStatus_encode(const MsgMachineStatus_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgMachineStatus_t *)0) || (dlc < MSGMACHINESTATUS_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGMACHINESTATUS_CAN_DLC);

    /* Encode MachineStatus. */
    data[0] |= (uint8_t)(((((uint64_t)msg->MachineStatus) >> 0) & UINT64_C(0xF)) << 0);

    return true;
}

bool MsgMachineStatus_send(const MsgMachineStatus_t *msg)
{
    uint8_t data[MSGMACHINESTATUS_CAN_DLC];

    if (!MsgMachineStatus_encode(msg, data, MSGMACHINESTATUS_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGMACHINESTATUS_CAN_ID, true, data, MSGMACHINESTATUS_CAN_DLC);
}

bool MsgRaiseLowerStatus_decode(const uint8_t *data, uint8_t dlc, MsgRaiseLowerStatus_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgRaiseLowerStatus_t *)0) || (dlc < MSGRAISELOWERSTATUS_CAN_DLC))
    {
        return false;
    }

    /* Decode RaiseActive. */
    msg->RaiseActive = (bool)(((((uint64_t)data[0]) >> 0) & UINT64_C(0x1)) << 0);

    /* Decode LowerActive. */
    msg->LowerActive = (bool)(((((uint64_t)data[0]) >> 1) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgRaiseLowerStatus_encode(const MsgRaiseLowerStatus_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgRaiseLowerStatus_t *)0) || (dlc < MSGRAISELOWERSTATUS_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGRAISELOWERSTATUS_CAN_DLC);

    /* Encode RaiseActive. */
    data[0] |= (uint8_t)(((((uint64_t)msg->RaiseActive) >> 0) & UINT64_C(0x1)) << 0);

    /* Encode LowerActive. */
    data[0] |= (uint8_t)(((((uint64_t)msg->LowerActive) >> 0) & UINT64_C(0x1)) << 1);

    return true;
}

bool MsgRaiseLowerStatus_send(const MsgRaiseLowerStatus_t *msg)
{
    uint8_t data[MSGRAISELOWERSTATUS_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgRaiseLowerStatus_t *)0) ||
        (!(((double)msg->RaiseActive >= 0) && ((double)msg->RaiseActive <= 1))) ||
        (!(((double)msg->LowerActive >= 0) && ((double)msg->LowerActive <= 1))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgRaiseLowerStatus_encode(msg, data, MSGRAISELOWERSTATUS_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGRAISELOWERSTATUS_CAN_ID, true, data, MSGRAISELOWERSTATUS_CAN_DLC);
}

bool MsgEdgeDetectionStatus_decode(const uint8_t *data, uint8_t dlc, MsgEdgeDetectionStatus_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgEdgeDetectionStatus_t *)0) || (dlc < MSGEDGEDETECTIONSTATUS_CAN_DLC))
    {
        return false;
    }

    /* Decode EdgeDetectionActive. */
    msg->EdgeDetectionActive = (EdgeDetectionActive_value_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0x3)) << 0);

    /* Decode EdgeDetectionStatus. */
    msg->EdgeDetectionStatus = (bool)(((((uint64_t)data[0]) >> 2) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgEdgeDetectionStatus_encode(const MsgEdgeDetectionStatus_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgEdgeDetectionStatus_t *)0) || (dlc < MSGEDGEDETECTIONSTATUS_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGEDGEDETECTIONSTATUS_CAN_DLC);

    /* Encode EdgeDetectionActive. */
    data[0] |= (uint8_t)(((((uint64_t)msg->EdgeDetectionActive) >> 0) & UINT64_C(0x3)) << 0);

    /* Encode EdgeDetectionStatus. */
    data[0] |= (uint8_t)(((((uint64_t)msg->EdgeDetectionStatus) >> 0) & UINT64_C(0x1)) << 2);

    return true;
}

bool MsgEdgeDetectionStatus_send(const MsgEdgeDetectionStatus_t *msg)
{
    uint8_t data[MSGEDGEDETECTIONSTATUS_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgEdgeDetectionStatus_t *)0) ||
        (!(((double)msg->EdgeDetectionStatus >= 0) && ((double)msg->EdgeDetectionStatus <= 1))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgEdgeDetectionStatus_encode(msg, data, MSGEDGEDETECTIONSTATUS_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGEDGEDETECTIONSTATUS_CAN_ID, true, data, MSGEDGEDETECTIONSTATUS_CAN_DLC);
}

bool MsgAutoControlActive_decode(const uint8_t *data, uint8_t dlc, MsgAutoControlActive_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgAutoControlActive_t *)0) || (dlc < MSGAUTOCONTROLACTIVE_CAN_DLC))
    {
        return false;
    }

    /* Decode AutoControlActive. */
    msg->AutoControlActive = (AutoControlActive_value_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0x3)) << 0);

    return true;
}

bool MsgAutoControlActive_encode(const MsgAutoControlActive_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgAutoControlActive_t *)0) || (dlc < MSGAUTOCONTROLACTIVE_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGAUTOCONTROLACTIVE_CAN_DLC);

    /* Encode AutoControlActive. */
    data[0] |= (uint8_t)(((((uint64_t)msg->AutoControlActive) >> 0) & UINT64_C(0x3)) << 0);

    return true;
}

bool MsgAutoControlActive_send(const MsgAutoControlActive_t *msg)
{
    uint8_t data[MSGAUTOCONTROLACTIVE_CAN_DLC];

    if (!MsgAutoControlActive_encode(msg, data, MSGAUTOCONTROLACTIVE_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGAUTOCONTROLACTIVE_CAN_ID, true, data, MSGAUTOCONTROLACTIVE_CAN_DLC);
}

bool MsgPlantWheelSpeed_decode(const uint8_t *data, uint8_t dlc, MsgPlantWheelSpeed_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgPlantWheelSpeed_t *)0) || (dlc < MSGPLANTWHEELSPEED_CAN_DLC))
    {
        return false;
    }

    /* Decode PlantwheelSpeed. */
    msg->PlantwheelSpeed = (float)(((double)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8) * 0.1) + 0);

    return true;
}

bool MsgPlantWheelSpeed_encode(const MsgPlantWheelSpeed_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgPlantWheelSpeed_t *)0) || (dlc < MSGPLANTWHEELSPEED_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGPLANTWHEELSPEED_CAN_DLC);

    /* Encode PlantwheelSpeed. */
    data[0] |= (uint8_t)(((((uint64_t)(((double)msg->PlantwheelSpeed - 0) / 0.1)) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)(((double)msg->PlantwheelSpeed - 0) / 0.1)) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgPlantWheelSpeed_send(const MsgPlantWheelSpeed_t *msg)
{
    uint8_t data[MSGPLANTWHEELSPEED_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgPlantWheelSpeed_t *)0) ||
        (!(((double)msg->PlantwheelSpeed >= 0) && ((double)msg->PlantwheelSpeed <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgPlantWheelSpeed_encode(msg, data, MSGPLANTWHEELSPEED_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGPLANTWHEELSPEED_CAN_ID, true, data, MSGPLANTWHEELSPEED_CAN_DLC);
}

bool MsgSpeedSetpointCommand_decode(const uint8_t *data, uint8_t dlc, MsgSpeedSetpointCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgSpeedSetpointCommand_t *)0) || (dlc < MSGSPEEDSETPOINTCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode SpeedSetpoint. */
    msg->SpeedSetpoint = (int32_t)(((int64_t)(((((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8 | ((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 16 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 24) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000))));

    return true;
}

bool MsgSpeedSetpointCommand_encode(const MsgSpeedSetpointCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgSpeedSetpointCommand_t *)0) || (dlc < MSGSPEEDSETPOINTCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGSPEEDSETPOINTCOMMAND_CAN_DLC);

    /* Encode SpeedSetpoint. */
    data[0] |= (uint8_t)(((((uint64_t)msg->SpeedSetpoint) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->SpeedSetpoint) >> 8) & UINT64_C(0xFF)) << 0);
    data[2] |= (uint8_t)(((((uint64_t)msg->SpeedSetpoint) >> 16) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->SpeedSetpoint) >> 24) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgSpeedSetpointCommand_send(const MsgSpeedSetpointCommand_t *msg)
{
    uint8_t data[MSGSPEEDSETPOINTCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgSpeedSetpointCommand_t *)0) ||
        (!(((double)msg->SpeedSetpoint >= -2147483648) && ((double)msg->SpeedSetpoint <= 2147483647))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgSpeedSetpointCommand_encode(msg, data, MSGSPEEDSETPOINTCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGSPEEDSETPOINTCOMMAND_CAN_ID, true, data, MSGSPEEDSETPOINTCOMMAND_CAN_DLC);
}

bool MsgPlantSpacingCommand_decode(const uint8_t *data, uint8_t dlc, MsgPlantSpacingCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgPlantSpacingCommand_t *)0) || (dlc < MSGPLANTSPACINGCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode PlantSpacingSetpoint. */
    msg->PlantSpacingSetpoint = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgPlantSpacingCommand_encode(const MsgPlantSpacingCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgPlantSpacingCommand_t *)0) || (dlc < MSGPLANTSPACINGCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGPLANTSPACINGCOMMAND_CAN_DLC);

    /* Encode PlantSpacingSetpoint. */
    data[0] |= (uint8_t)(((((uint64_t)msg->PlantSpacingSetpoint) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->PlantSpacingSetpoint) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgPlantSpacingCommand_send(const MsgPlantSpacingCommand_t *msg)
{
    uint8_t data[MSGPLANTSPACINGCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgPlantSpacingCommand_t *)0) ||
        (!(((double)msg->PlantSpacingSetpoint >= 0) && ((double)msg->PlantSpacingSetpoint <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgPlantSpacingCommand_encode(msg, data, MSGPLANTSPACINGCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGPLANTSPACINGCOMMAND_CAN_ID, true, data, MSGPLANTSPACINGCOMMAND_CAN_DLC);
}

bool MsgHeightSetpointCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightSetpointCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgHeightSetpointCommand_t *)0) || (dlc < MSGHEIGHTSETPOINTCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode HeightSetpoint. */
    msg->HeightSetpoint = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgHeightSetpointCommand_encode(const MsgHeightSetpointCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgHeightSetpointCommand_t *)0) || (dlc < MSGHEIGHTSETPOINTCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGHEIGHTSETPOINTCOMMAND_CAN_DLC);

    /* Encode HeightSetpoint. */
    data[0] |= (uint8_t)(((((uint64_t)msg->HeightSetpoint) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->HeightSetpoint) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgHeightSetpointCommand_send(const MsgHeightSetpointCommand_t *msg)
{
    uint8_t data[MSGHEIGHTSETPOINTCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgHeightSetpointCommand_t *)0) ||
        (!(((double)msg->HeightSetpoint >= 0) && ((double)msg->HeightSetpoint <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgHeightSetpointCommand_encode(msg, data, MSGHEIGHTSETPOINTCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGHEIGHTSETPOINTCOMMAND_CAN_ID, true, data, MSGHEIGHTSETPOINTCOMMAND_CAN_DLC);
}

bool MsgHeightDetectCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightDetectCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgHeightDetectCommand_t *)0) || (dlc < MSGHEIGHTDETECTCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode HeightDetect. */
    msg->HeightDetect = (bool)(((((uint64_t)data[0]) >> 0) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgHeightDetectCommand_encode(const MsgHeightDetectCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgHeightDetectCommand_t *)0) || (dlc < MSGHEIGHTDETECTCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGHEIGHTDETECTCOMMAND_CAN_DLC);

    /* Encode HeightDetect. */
    data[0] |= (uint8_t)(((((uint64_t)msg->HeightDetect) >> 0) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgHeightDetectCommand_send(const MsgHeightDetectCommand_t *msg)
{
    uint8_t data[MSGHEIGHTDETECTCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgHeightDetectCommand_t *)0) ||
        (!(((double)msg->HeightDetect >= 0) && ((double)msg->HeightDetect <= 1))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgHeightDetectCommand_encode(msg, data, MSGHEIGHTDETECTCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGHEIGHTDETECTCOMMAND_CAN_ID, true, data, MSGHEIGHTDETECTCOMMAND_CAN_DLC);
}

bool MsgWheelCircumCommand_decode(const uint8_t *data, uint8_t dlc, MsgWheelCircumCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgWheelCircumCommand_t *)0) || (dlc < MSGWHEELCIRCUMCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode WheelCircum. */
    msg->WheelCircum = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgWheelCircumCommand_encode(const MsgWheelCircumCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgWheelCircumCommand_t *)0) || (dlc < MSGWHEELCIRCUMCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGWHEELCIRCUMCOMMAND_CAN_DLC);

    /* Encode WheelCircum. */
    data[0] |= (uint8_t)(((((uint64_t)msg->WheelCircum) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->WheelCircum) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgWheelCircumCommand_send(const MsgWheelCircumCommand_t *msg)
{
    uint8_t data[MSGWHEELCIRCUMCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgWheelCircumCommand_t *)0) ||
        (!(((double)msg->WheelCircum >= 0) && ((double)msg->WheelCircum <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgWheelCircumCommand_encode(msg, data, MSGWHEELCIRCUMCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGWHEELCIRCUMCOMMAND_CAN_ID, true, data, MSGWHEELCIRCUMCOMMAND_CAN_DLC);
}

bool MsgHeightCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgHeightCommand_t *)0) || (dlc < MSGHEIGHTCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode UpButton. */
    msg->UpButton = (bool)(((((uint64_t)data[0]) >> 0) & UINT64_C(0x1)) << 0);

    /* Decode DownButton. */
    msg->DownButton = (bool)(((((uint64_t)data[0]) >> 1) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgHeightCommand_encode(const MsgHeightCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgHeightCommand_t *)0) || (dlc < MSGHEIGHTCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGHEIGHTCOMMAND_CAN_DLC);

    /* Encode UpButton. */
    data[0] |= (uint8_t)(((((uint64_t)msg->UpButton) >> 0) & UINT64_C(0x1)) << 0);

    /* Encode DownButton. */
    data[0] |= (uint8_t)(((((uint64_t)msg->DownButton) >> 0) & UINT64_C(0x1)) << 1);

    return true;
}

bool MsgHeightCommand_send(const MsgHeightCommand_t *msg)
{
    uint8_t data[MSGHEIGHTCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgHeightCommand_t *)0) ||
        (!(((double)msg->UpButton >= 0) && ((double)msg->UpButton <= 1))) ||
        (!(((double)msg->DownButton >= 0) && ((double)msg->DownButton <= 1))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgHeightCommand_encode(msg, data, MSGHEIGHTCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGHEIGHTCOMMAND_CAN_ID, true, data, MSGHEIGHTCOMMAND_CAN_DLC);
}

bool MsgLiftSpeedCommand_decode(const uint8_t *data, uint8_t dlc, MsgLiftSpeedCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgLiftSpeedCommand_t *)0) || (dlc < MSGLIFTSPEEDCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode SpeedRaise. */
    msg->SpeedRaise = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode SpeedLower. */
    msg->SpeedLower = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgLiftSpeedCommand_encode(const MsgLiftSpeedCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgLiftSpeedCommand_t *)0) || (dlc < MSGLIFTSPEEDCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGLIFTSPEEDCOMMAND_CAN_DLC);

    /* Encode SpeedRaise. */
    data[0] |= (uint8_t)(((((uint64_t)msg->SpeedRaise) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->SpeedRaise) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode SpeedLower. */
    data[2] |= (uint8_t)(((((uint64_t)msg->SpeedLower) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->SpeedLower) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgLiftSpeedCommand_send(const MsgLiftSpeedCommand_t *msg)
{
    uint8_t data[MSGLIFTSPEEDCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgLiftSpeedCommand_t *)0) ||
        (!(((double)msg->SpeedRaise >= 0) && ((double)msg->SpeedRaise <= 65535))) ||
        (!(((double)msg->SpeedLower >= 0) && ((double)msg->SpeedLower <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgLiftSpeedCommand_encode(msg, data, MSGLIFTSPEEDCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGLIFTSPEEDCOMMAND_CAN_ID, true, data, MSGLIFTSPEEDCOMMAND_CAN_DLC);
}

bool MsgConfigCommand_decode(const uint8_t *data, uint8_t dlc, MsgConfigCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgConfigCommand_t *)0) || (dlc < MSGCONFIGCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode ResetPlantCounter. */
    msg->ResetPlantCounter = (bool)(((((uint64_t)data[0]) >> 0) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgConfigCommand_encode(const MsgConfigCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgConfigCommand_t *)0) || (dlc < MSGCONFIGCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGCONFIGCOMMAND_CAN_DLC);

    /* Encode ResetPlantCounter. */
    data[0] |= (uint8_t)(((((uint64_t)msg->ResetPlantCounter) >> 0) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgConfigCommand_send(const MsgConfigCommand_t *msg)
{
    uint8_t data[MSGCONFIGCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgConfigCommand_t *)0) ||
        (!(((double)msg->ResetPlantCounter >= 0) && ((double)msg->ResetPlantCounter <= 1))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgConfigCommand_encode(msg, data, MSGCONFIGCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGCONFIGCOMMAND_CAN_ID, true, data, MSGCONFIGCOMMAND_CAN_DLC);
}

bool MsgNrRowsCommand_decode(const uint8_t *data, uint8_t dlc, MsgNrRowsCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgNrRowsCommand_t *)0) || (dlc < MSGNRROWSCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode NrRows. */
    msg->NrRows = (uint8_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgNrRowsCommand_encode(const MsgNrRowsCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgNrRowsCommand_t *)0) || (dlc < MSGNRROWSCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGNRROWSCOMMAND_CAN_DLC);

    /* Encode NrRows. */
    data[0] |= (uint8_t)(((((uint64_t)msg->NrRows) >> 0) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgNrRowsCommand_send(const MsgNrRowsCommand_t *msg)
{
    uint8_t data[MSGNRROWSCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgNrRowsCommand_t *)0) ||
        (!(((double)msg->NrRows >= 0) && ((double)msg->NrRows <= 255))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgNrRowsCommand_encode(msg, data, MSGNRROWSCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGNRROWSCOMMAND_CAN_ID, true, data, MSGNRROWSCOMMAND_CAN_DLC);
}

bool MsgWorkWidthCommand_decode(const uint8_t *data, uint8_t dlc, MsgWorkWidthCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgWorkWidthCommand_t *)0) || (dlc < MSGWORKWIDTHCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode WorkWidth. */
    msg->WorkWidth = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgWorkWidthCommand_encode(const MsgWorkWidthCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgWorkWidthCommand_t *)0) || (dlc < MSGWORKWIDTHCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGWORKWIDTHCOMMAND_CAN_DLC);

    /* Encode WorkWidth. */
    data[0] |= (uint8_t)(((((uint64_t)msg->WorkWidth) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->WorkWidth) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgWorkWidthCommand_send(const MsgWorkWidthCommand_t *msg)
{
    uint8_t data[MSGWORKWIDTHCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgWorkWidthCommand_t *)0) ||
        (!(((double)msg->WorkWidth >= 0) && ((double)msg->WorkWidth <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgWorkWidthCommand_encode(msg, data, MSGWORKWIDTHCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGWORKWIDTHCOMMAND_CAN_ID, true, data, MSGWORKWIDTHCOMMAND_CAN_DLC);
}

bool MsgHeightThresholdCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightThresholdCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgHeightThresholdCommand_t *)0) || (dlc < MSGHEIGHTTHRESHOLDCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode HeightDetectThreshold. */
    msg->HeightDetectThreshold = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgHeightThresholdCommand_encode(const MsgHeightThresholdCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgHeightThresholdCommand_t *)0) || (dlc < MSGHEIGHTTHRESHOLDCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGHEIGHTTHRESHOLDCOMMAND_CAN_DLC);

    /* Encode HeightDetectThreshold. */
    data[0] |= (uint8_t)(((((uint64_t)msg->HeightDetectThreshold) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->HeightDetectThreshold) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgHeightThresholdCommand_send(const MsgHeightThresholdCommand_t *msg)
{
    uint8_t data[MSGHEIGHTTHRESHOLDCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgHeightThresholdCommand_t *)0) ||
        (!(((double)msg->HeightDetectThreshold >= 0) && ((double)msg->HeightDetectThreshold <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgHeightThresholdCommand_encode(msg, data, MSGHEIGHTTHRESHOLDCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGHEIGHTTHRESHOLDCOMMAND_CAN_ID, true, data, MSGHEIGHTTHRESHOLDCOMMAND_CAN_DLC);
}

bool MsgWaterTimeCommand_decode(const uint8_t *data, uint8_t dlc, MsgWaterTimeCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgWaterTimeCommand_t *)0) || (dlc < MSGWATERTIMECOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode WaterTime. */
    msg->WaterTime = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgWaterTimeCommand_encode(const MsgWaterTimeCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgWaterTimeCommand_t *)0) || (dlc < MSGWATERTIMECOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGWATERTIMECOMMAND_CAN_DLC);

    /* Encode WaterTime. */
    data[0] |= (uint8_t)(((((uint64_t)msg->WaterTime) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->WaterTime) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgWaterTimeCommand_send(const MsgWaterTimeCommand_t *msg)
{
    uint8_t data[MSGWATERTIMECOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgWaterTimeCommand_t *)0) ||
        (!(((double)msg->WaterTime >= 0) && ((double)msg->WaterTime <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgWaterTimeCommand_encode(msg, data, MSGWATERTIMECOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGWATERTIMECOMMAND_CAN_ID, true, data, MSGWATERTIMECOMMAND_CAN_DLC);
}

bool MsgWaterOffsetCommand_decode(const uint8_t *data, uint8_t dlc, MsgWaterOffsetCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgWaterOffsetCommand_t *)0) || (dlc < MSGWATEROFFSETCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode WaterOffset. */
    msg->WaterOffset = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WaterOffset2. */
    msg->WaterOffset2 = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgWaterOffsetCommand_encode(const MsgWaterOffsetCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgWaterOffsetCommand_t *)0) || (dlc < MSGWATEROFFSETCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGWATEROFFSETCOMMAND_CAN_DLC);

    /* Encode WaterOffset. */
    data[0] |= (uint8_t)(((((uint64_t)msg->WaterOffset) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->WaterOffset) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WaterOffset2. */
    data[2] |= (uint8_t)(((((uint64_t)msg->WaterOffset2) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->WaterOffset2) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgWaterOffsetCommand_send(const MsgWaterOffsetCommand_t *msg)
{
    uint8_t data[MSGWATEROFFSETCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgWaterOffsetCommand_t *)0) ||
        (!(((double)msg->WaterOffset >= 0) && ((double)msg->WaterOffset <= 65535))) ||
        (!(((double)msg->WaterOffset2 >= 0) && ((double)msg->WaterOffset2 <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgWaterOffsetCommand_encode(msg, data, MSGWATEROFFSETCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGWATEROFFSETCOMMAND_CAN_ID, true, data, MSGWATEROFFSETCOMMAND_CAN_DLC);
}

bool MsgAutoControlCommand_decode(const uint8_t *data, uint8_t dlc, MsgAutoControlCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgAutoControlCommand_t *)0) || (dlc < MSGAUTOCONTROLCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode AutoControl. */
    msg->AutoControl = (bool)(((((uint64_t)data[0]) >> 0) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgAutoControlCommand_encode(const MsgAutoControlCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgAutoControlCommand_t *)0) || (dlc < MSGAUTOCONTROLCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGAUTOCONTROLCOMMAND_CAN_DLC);

    /* Encode AutoControl. */
    data[0] |= (uint8_t)(((((uint64_t)msg->AutoControl) >> 0) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgAutoControlCommand_send(const MsgAutoControlCommand_t *msg)
{
    uint8_t data[MSGAUTOCONTROLCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgAutoControlCommand_t *)0) ||
        (!(((double)msg->AutoControl >= 0) && ((double)msg->AutoControl <= 1))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgAutoControlCommand_encode(msg, data, MSGAUTOCONTROLCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGAUTOCONTROLCOMMAND_CAN_ID, true, data, MSGAUTOCONTROLCOMMAND_CAN_DLC);
}

bool MsgGripIdleCofCommand_decode(const uint8_t *data, uint8_t dlc, MsgGripIdleCofCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgGripIdleCofCommand_t *)0) || (dlc < MSGGRIPIDLECOFCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode GripperIdleCof. */
    msg->GripperIdleCof = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgGripIdleCofCommand_encode(const MsgGripIdleCofCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgGripIdleCofCommand_t *)0) || (dlc < MSGGRIPIDLECOFCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGGRIPIDLECOFCOMMAND_CAN_DLC);

    /* Encode GripperIdleCof. */
    data[0] |= (uint8_t)(((((uint64_t)msg->GripperIdleCof) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->GripperIdleCof) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgGripIdleCofCommand_send(const MsgGripIdleCofCommand_t *msg)
{
    uint8_t data[MSGGRIPIDLECOFCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgGripIdleCofCommand_t *)0) ||
        (!(((double)msg->GripperIdleCof >= 0) && ((double)msg->GripperIdleCof <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgGripIdleCofCommand_encode(msg, data, MSGGRIPIDLECOFCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGGRIPIDLECOFCOMMAND_CAN_ID, true, data, MSGGRIPIDLECOFCOMMAND_CAN_DLC);
}

bool MsgGripIdleOffsetCommand_decode(const uint8_t *data, uint8_t dlc, MsgGripIdleOffsetCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgGripIdleOffsetCommand_t *)0) || (dlc < MSGGRIPIDLEOFFSETCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode GripperIdleOffset. */
    msg->GripperIdleOffset = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode GripperIdleOffset2. */
    msg->GripperIdleOffset2 = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgGripIdleOffsetCommand_encode(const MsgGripIdleOffsetCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgGripIdleOffsetCommand_t *)0) || (dlc < MSGGRIPIDLEOFFSETCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGGRIPIDLEOFFSETCOMMAND_CAN_DLC);

    /* Encode GripperIdleOffset. */
    data[0] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode GripperIdleOffset2. */
    data[2] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset2) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset2) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgGripIdleOffsetCommand_send(const MsgGripIdleOffsetCommand_t *msg)
{
    uint8_t data[MSGGRIPIDLEOFFSETCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgGripIdleOffsetCommand_t *)0) ||
        (!(((double)msg->GripperIdleOffset >= 0) && ((double)msg->GripperIdleOffset <= 65535))) ||
        (!(((double)msg->GripperIdleOffset2 >= 0) && ((double)msg->GripperIdleOffset2 <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgGripIdleOffsetCommand_encode(msg, data, MSGGRIPIDLEOFFSETCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGGRIPIDLEOFFSETCOMMAND_CAN_ID, true, data, MSGGRIPIDLEOFFSETCOMMAND_CAN_DLC);
}

bool MsgBeltOffsetCommand_decode(const uint8_t *data, uint8_t dlc, MsgBeltOffsetCommand_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgBeltOffsetCommand_t *)0) || (dlc < MSGBELTOFFSETCOMMAND_CAN_DLC))
    {
        return false;
    }

    /* Decode BeltOffset. */
    msg->BeltOffset = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgBeltOffsetCommand_encode(const MsgBeltOffsetCommand_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgBeltOffsetCommand_t *)0) || (dlc < MSGBELTOFFSETCOMMAND_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGBELTOFFSETCOMMAND_CAN_DLC);

    /* Encode BeltOffset. */
    data[0] |= (uint8_t)(((((uint64_t)msg->BeltOffset) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->BeltOffset) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgBeltOffsetCommand_send(const MsgBeltOffsetCommand_t *msg)
{
    uint8_t data[MSGBELTOFFSETCOMMAND_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgBeltOffsetCommand_t *)0) ||
        (!(((double)msg->BeltOffset >= 0) && ((double)msg->BeltOffset <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgBeltOffsetCommand_encode(msg, data, MSGBELTOFFSETCOMMAND_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGBELTOFFSETCOMMAND_CAN_ID, true, data, MSGBELTOFFSETCOMMAND_CAN_DLC);
}

bool MsgConfigRequest_decode(const uint8_t *data, uint8_t dlc, MsgConfigRequest_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgConfigRequest_t *)0) || (dlc < MSGCONFIGREQUEST_CAN_DLC))
    {
        return false;
    }

    /* Decode ConfigGroup. */
    msg->ConfigGroup = (ConfigGroup_value_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgConfigRequest_encode(const MsgConfigRequest_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgConfigRequest_t *)0) || (dlc < MSGCONFIGREQUEST_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGCONFIGREQUEST_CAN_DLC);

    /* Encode ConfigGroup. */
    data[0] |= (uint8_t)(((((uint64_t)msg->ConfigGroup) >> 0) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgConfigRequest_send(const MsgConfigRequest_t *msg)
{
    uint8_t data[MSGCONFIGREQUEST_CAN_DLC];

    if (!MsgConfigRequest_encode(msg, data, MSGCONFIGREQUEST_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGCONFIGREQUEST_CAN_ID, true, data, MSGCONFIGREQUEST_CAN_DLC);
}

bool MsgSpeedConfig_decode(const uint8_t *data, uint8_t dlc, MsgSpeedConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgSpeedConfig_t *)0) || (dlc < MSGSPEEDCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode SpeedSetpointCurrent. */
    msg->SpeedSetpointCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode SpeedDefault. */
    msg->SpeedDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode SpeedMin. */
    msg->SpeedMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode SpeedMax. */
    msg->SpeedMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgSpeedConfig_encode(const MsgSpeedConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgSpeedConfig_t *)0) || (dlc < MSGSPEEDCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGSPEEDCONFIG_CAN_DLC);

    /* Encode SpeedSetpointCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->SpeedSetpointCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->SpeedSetpointCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode SpeedDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->SpeedDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->SpeedDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode SpeedMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->SpeedMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->SpeedMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode SpeedMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->SpeedMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->SpeedMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgSpeedConfig_send(const MsgSpeedConfig_t *msg)
{
    uint8_t data[MSGSPEEDCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgSpeedConfig_t *)0) ||
        (!(((double)msg->SpeedSetpointCurrent >= 0) && ((double)msg->SpeedSetpointCurrent <= 65535))) ||
        (!(((double)msg->SpeedDefault >= 0) && ((double)msg->SpeedDefault <= 65535))) ||
        (!(((double)msg->SpeedMin >= 0) && ((double)msg->SpeedMin <= 65535))) ||
        (!(((double)msg->SpeedMax >= 0) && ((double)msg->SpeedMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgSpeedConfig_encode(msg, data, MSGSPEEDCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGSPEEDCONFIG_CAN_ID, true, data, MSGSPEEDCONFIG_CAN_DLC);
}

bool MsgHeightConfig_decode(const uint8_t *data, uint8_t dlc, MsgHeightConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgHeightConfig_t *)0) || (dlc < MSGHEIGHTCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode HeightSetpointCurrent. */
    msg->HeightSetpointCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode HeightDefault. */
    msg->HeightDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode HeightMin. */
    msg->HeightMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode HeightMax. */
    msg->HeightMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgHeightConfig_encode(const MsgHeightConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgHeightConfig_t *)0) || (dlc < MSGHEIGHTCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGHEIGHTCONFIG_CAN_DLC);

    /* Encode HeightSetpointCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->HeightSetpointCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->HeightSetpointCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode HeightDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->HeightDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->HeightDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode HeightMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->HeightMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->HeightMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode HeightMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->HeightMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->HeightMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgHeightConfig_send(const MsgHeightConfig_t *msg)
{
    uint8_t data[MSGHEIGHTCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgHeightConfig_t *)0) ||
        (!(((double)msg->HeightSetpointCurrent >= 0) && ((double)msg->HeightSetpointCurrent <= 65535))) ||
        (!(((double)msg->HeightDefault >= 0) && ((double)msg->HeightDefault <= 65535))) ||
        (!(((double)msg->HeightMin >= 0) && ((double)msg->HeightMin <= 65535))) ||
        (!(((double)msg->HeightMax >= 0) && ((double)msg->HeightMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgHeightConfig_encode(msg, data, MSGHEIGHTCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGHEIGHTCONFIG_CAN_ID, true, data, MSGHEIGHTCONFIG_CAN_DLC);
}

bool MsgPlantSpacingConfig_decode(const uint8_t *data, uint8_t dlc, MsgPlantSpacingConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgPlantSpacingConfig_t *)0) || (dlc < MSGPLANTSPACINGCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode PlantSpacingCurrent. */
    msg->PlantSpacingCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode PlantSpacingDefault. */
    msg->PlantSpacingDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode PlantSpacingMin. */
    msg->PlantSpacingMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode PlantSpacingMax. */
    msg->PlantSpacingMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgPlantSpacingConfig_encode(const MsgPlantSpacingConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgPlantSpacingConfig_t *)0) || (dlc < MSGPLANTSPACINGCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGPLANTSPACINGCONFIG_CAN_DLC);

    /* Encode PlantSpacingCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->PlantSpacingCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->PlantSpacingCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode PlantSpacingDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->PlantSpacingDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->PlantSpacingDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode PlantSpacingMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->PlantSpacingMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->PlantSpacingMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode PlantSpacingMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->PlantSpacingMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->PlantSpacingMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgPlantSpacingConfig_send(const MsgPlantSpacingConfig_t *msg)
{
    uint8_t data[MSGPLANTSPACINGCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgPlantSpacingConfig_t *)0) ||
        (!(((double)msg->PlantSpacingCurrent >= 0) && ((double)msg->PlantSpacingCurrent <= 65535))) ||
        (!(((double)msg->PlantSpacingDefault >= 0) && ((double)msg->PlantSpacingDefault <= 65535))) ||
        (!(((double)msg->PlantSpacingMin >= 0) && ((double)msg->PlantSpacingMin <= 65535))) ||
        (!(((double)msg->PlantSpacingMax >= 0) && ((double)msg->PlantSpacingMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgPlantSpacingConfig_encode(msg, data, MSGPLANTSPACINGCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGPLANTSPACINGCONFIG_CAN_ID, true, data, MSGPLANTSPACINGCONFIG_CAN_DLC);
}

bool MsgWaterTimeConfig_decode(const uint8_t *data, uint8_t dlc, MsgWaterTimeConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgWaterTimeConfig_t *)0) || (dlc < MSGWATERTIMECONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode WaterTimeCurrent. */
    msg->WaterTimeCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WaterTimeDefault. */
    msg->WaterTimeDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WaterTimeMin. */
    msg->WaterTimeMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WaterTimeMax. */
    msg->WaterTimeMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgWaterTimeConfig_encode(const MsgWaterTimeConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgWaterTimeConfig_t *)0) || (dlc < MSGWATERTIMECONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGWATERTIMECONFIG_CAN_DLC);

    /* Encode WaterTimeCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->WaterTimeCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->WaterTimeCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WaterTimeDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->WaterTimeDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->WaterTimeDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WaterTimeMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->WaterTimeMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->WaterTimeMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WaterTimeMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->WaterTimeMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->WaterTimeMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgWaterTimeConfig_send(const MsgWaterTimeConfig_t *msg)
{
    uint8_t data[MSGWATERTIMECONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgWaterTimeConfig_t *)0) ||
        (!(((double)msg->WaterTimeCurrent >= 0) && ((double)msg->WaterTimeCurrent <= 65535))) ||
        (!(((double)msg->WaterTimeDefault >= 0) && ((double)msg->WaterTimeDefault <= 65535))) ||
        (!(((double)msg->WaterTimeMin >= 0) && ((double)msg->WaterTimeMin <= 65535))) ||
        (!(((double)msg->WaterTimeMax >= 0) && ((double)msg->WaterTimeMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgWaterTimeConfig_encode(msg, data, MSGWATERTIMECONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGWATERTIMECONFIG_CAN_ID, true, data, MSGWATERTIMECONFIG_CAN_DLC);
}

bool MsgWheelCircumConfig_decode(const uint8_t *data, uint8_t dlc, MsgWheelCircumConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgWheelCircumConfig_t *)0) || (dlc < MSGWHEELCIRCUMCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode WheelCircumCurrent. */
    msg->WheelCircumCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WheelCircumDefault. */
    msg->WheelCircumDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WheelCircumMin. */
    msg->WheelCircumMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WheelCircumMax. */
    msg->WheelCircumMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgWheelCircumConfig_encode(const MsgWheelCircumConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgWheelCircumConfig_t *)0) || (dlc < MSGWHEELCIRCUMCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGWHEELCIRCUMCONFIG_CAN_DLC);

    /* Encode WheelCircumCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->WheelCircumCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->WheelCircumCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WheelCircumDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->WheelCircumDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->WheelCircumDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WheelCircumMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->WheelCircumMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->WheelCircumMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WheelCircumMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->WheelCircumMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->WheelCircumMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgWheelCircumConfig_send(const MsgWheelCircumConfig_t *msg)
{
    uint8_t data[MSGWHEELCIRCUMCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgWheelCircumConfig_t *)0) ||
        (!(((double)msg->WheelCircumCurrent >= 0) && ((double)msg->WheelCircumCurrent <= 65535))) ||
        (!(((double)msg->WheelCircumDefault >= 0) && ((double)msg->WheelCircumDefault <= 65535))) ||
        (!(((double)msg->WheelCircumMin >= 0) && ((double)msg->WheelCircumMin <= 65535))) ||
        (!(((double)msg->WheelCircumMax >= 0) && ((double)msg->WheelCircumMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgWheelCircumConfig_encode(msg, data, MSGWHEELCIRCUMCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGWHEELCIRCUMCONFIG_CAN_ID, true, data, MSGWHEELCIRCUMCONFIG_CAN_DLC);
}

bool MsgGripperIdleOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgGripperIdleOffsetConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgGripperIdleOffsetConfig_t *)0) || (dlc < MSGGRIPPERIDLEOFFSETCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode GripperIdleOffsetCurrent. */
    msg->GripperIdleOffsetCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode GripperIdleOffsetDefault. */
    msg->GripperIdleOffsetDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode GripperIdleOffsetMin. */
    msg->GripperIdleOffsetMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode GripperIdleOffsetMax. */
    msg->GripperIdleOffsetMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgGripperIdleOffsetConfig_encode(const MsgGripperIdleOffsetConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgGripperIdleOffsetConfig_t *)0) || (dlc < MSGGRIPPERIDLEOFFSETCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGGRIPPERIDLEOFFSETCONFIG_CAN_DLC);

    /* Encode GripperIdleOffsetCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffsetCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffsetCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode GripperIdleOffsetDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffsetDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffsetDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode GripperIdleOffsetMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffsetMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffsetMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode GripperIdleOffsetMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffsetMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffsetMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgGripperIdleOffsetConfig_send(const MsgGripperIdleOffsetConfig_t *msg)
{
    uint8_t data[MSGGRIPPERIDLEOFFSETCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgGripperIdleOffsetConfig_t *)0) ||
        (!(((double)msg->GripperIdleOffsetCurrent >= 0) && ((double)msg->GripperIdleOffsetCurrent <= 65535))) ||
        (!(((double)msg->GripperIdleOffsetDefault >= 0) && ((double)msg->GripperIdleOffsetDefault <= 65535))) ||
        (!(((double)msg->GripperIdleOffsetMin >= 0) && ((double)msg->GripperIdleOffsetMin <= 65535))) ||
        (!(((double)msg->GripperIdleOffsetMax >= 0) && ((double)msg->GripperIdleOffsetMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgGripperIdleOffsetConfig_encode(msg, data, MSGGRIPPERIDLEOFFSETCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGGRIPPERIDLEOFFSETCONFIG_CAN_ID, true, data, MSGGRIPPERIDLEOFFSETCONFIG_CAN_DLC);
}

bool MsgGripperIdleCofConfig_decode(const uint8_t *data, uint8_t dlc, MsgGripperIdleCofConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgGripperIdleCofConfig_t *)0) || (dlc < MSGGRIPPERIDLECOFCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode GripperIdleCofCurrent. */
    msg->GripperIdleCofCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode GripperIdleCofDefault. */
    msg->GripperIdleCofDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode GripperIdleCofMin. */
    msg->GripperIdleCofMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode GripperIdleCofMax. */
    msg->GripperIdleCofMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgGripperIdleCofConfig_encode(const MsgGripperIdleCofConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgGripperIdleCofConfig_t *)0) || (dlc < MSGGRIPPERIDLECOFCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGGRIPPERIDLECOFCONFIG_CAN_DLC);

    /* Encode GripperIdleCofCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->GripperIdleCofCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->GripperIdleCofCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode GripperIdleCofDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->GripperIdleCofDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->GripperIdleCofDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode GripperIdleCofMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->GripperIdleCofMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->GripperIdleCofMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode GripperIdleCofMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->GripperIdleCofMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->GripperIdleCofMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgGripperIdleCofConfig_send(const MsgGripperIdleCofConfig_t *msg)
{
    uint8_t data[MSGGRIPPERIDLECOFCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgGripperIdleCofConfig_t *)0) ||
        (!(((double)msg->GripperIdleCofCurrent >= 0) && ((double)msg->GripperIdleCofCurrent <= 65535))) ||
        (!(((double)msg->GripperIdleCofDefault >= 0) && ((double)msg->GripperIdleCofDefault <= 65535))) ||
        (!(((double)msg->GripperIdleCofMin >= 0) && ((double)msg->GripperIdleCofMin <= 65535))) ||
        (!(((double)msg->GripperIdleCofMax >= 0) && ((double)msg->GripperIdleCofMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgGripperIdleCofConfig_encode(msg, data, MSGGRIPPERIDLECOFCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGGRIPPERIDLECOFCONFIG_CAN_ID, true, data, MSGGRIPPERIDLECOFCONFIG_CAN_DLC);
}

bool MsgBeltOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgBeltOffsetConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgBeltOffsetConfig_t *)0) || (dlc < MSGBELTOFFSETCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode BeltOffsetCurrent. */
    msg->BeltOffsetCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode BeltOffsetDefault. */
    msg->BeltOffsetDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode BeltOffsetMin. */
    msg->BeltOffsetMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode BeltOffsetMax. */
    msg->BeltOffsetMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgBeltOffsetConfig_encode(const MsgBeltOffsetConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgBeltOffsetConfig_t *)0) || (dlc < MSGBELTOFFSETCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGBELTOFFSETCONFIG_CAN_DLC);

    /* Encode BeltOffsetCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->BeltOffsetCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->BeltOffsetCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode BeltOffsetDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->BeltOffsetDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->BeltOffsetDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode BeltOffsetMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->BeltOffsetMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->BeltOffsetMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode BeltOffsetMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->BeltOffsetMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->BeltOffsetMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgBeltOffsetConfig_send(const MsgBeltOffsetConfig_t *msg)
{
    uint8_t data[MSGBELTOFFSETCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgBeltOffsetConfig_t *)0) ||
        (!(((double)msg->BeltOffsetCurrent >= 0) && ((double)msg->BeltOffsetCurrent <= 65535))) ||
        (!(((double)msg->BeltOffsetDefault >= 0) && ((double)msg->BeltOffsetDefault <= 65535))) ||
        (!(((double)msg->BeltOffsetMin >= 0) && ((double)msg->BeltOffsetMin <= 65535))) ||
        (!(((double)msg->BeltOffsetMax >= 0) && ((double)msg->BeltOffsetMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgBeltOffsetConfig_encode(msg, data, MSGBELTOFFSETCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGBELTOFFSETCONFIG_CAN_ID, true, data, MSGBELTOFFSETCONFIG_CAN_DLC);
}

bool MsgGripperIdleOffset2Config_decode(const uint8_t *data, uint8_t dlc, MsgGripperIdleOffset2Config_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgGripperIdleOffset2Config_t *)0) || (dlc < MSGGRIPPERIDLEOFFSET2CONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode GripperIdleOffset2Current. */
    msg->GripperIdleOffset2Current = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode GripperIdleOffset2Default. */
    msg->GripperIdleOffset2Default = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode GripperIdleOffset2Min. */
    msg->GripperIdleOffset2Min = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode GripperIdleOffset2Max. */
    msg->GripperIdleOffset2Max = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgGripperIdleOffset2Config_encode(const MsgGripperIdleOffset2Config_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgGripperIdleOffset2Config_t *)0) || (dlc < MSGGRIPPERIDLEOFFSET2CONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGGRIPPERIDLEOFFSET2CONFIG_CAN_DLC);

    /* Encode GripperIdleOffset2Current. */
    data[0] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset2Current) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset2Current) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode GripperIdleOffset2Default. */
    data[2] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset2Default) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset2Default) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode GripperIdleOffset2Min. */
    data[4] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset2Min) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset2Min) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode GripperIdleOffset2Max. */
    data[6] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset2Max) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->GripperIdleOffset2Max) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgGripperIdleOffset2Config_send(const MsgGripperIdleOffset2Config_t *msg)
{
    uint8_t data[MSGGRIPPERIDLEOFFSET2CONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgGripperIdleOffset2Config_t *)0) ||
        (!(((double)msg->GripperIdleOffset2Current >= 0) && ((double)msg->GripperIdleOffset2Current <= 65535))) ||
        (!(((double)msg->GripperIdleOffset2Default >= 0) && ((double)msg->GripperIdleOffset2Default <= 65535))) ||
        (!(((double)msg->GripperIdleOffset2Min >= 0) && ((double)msg->GripperIdleOffset2Min <= 65535))) ||
        (!(((double)msg->GripperIdleOffset2Max >= 0) && ((double)msg->GripperIdleOffset2Max <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgGripperIdleOffset2Config_encode(msg, data, MSGGRIPPERIDLEOFFSET2CONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGGRIPPERIDLEOFFSET2CONFIG_CAN_ID, true, data, MSGGRIPPERIDLEOFFSET2CONFIG_CAN_DLC);
}

bool MsgHeightDetectConfig_decode(const uint8_t *data, uint8_t dlc, MsgHeightDetectConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgHeightDetectConfig_t *)0) || (dlc < MSGHEIGHTDETECTCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode HeightDetectCurrent. */
    msg->HeightDetectCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode HeightDetectDefault. */
    msg->HeightDetectDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode HeightDetectMin. */
    msg->HeightDetectMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode HeightDetectMax. */
    msg->HeightDetectMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgHeightDetectConfig_encode(const MsgHeightDetectConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgHeightDetectConfig_t *)0) || (dlc < MSGHEIGHTDETECTCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGHEIGHTDETECTCONFIG_CAN_DLC);

    /* Encode HeightDetectCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->HeightDetectCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->HeightDetectCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode HeightDetectDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->HeightDetectDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->HeightDetectDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode HeightDetectMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->HeightDetectMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->HeightDetectMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode HeightDetectMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->HeightDetectMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->HeightDetectMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgHeightDetectConfig_send(const MsgHeightDetectConfig_t *msg)
{
    uint8_t data[MSGHEIGHTDETECTCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgHeightDetectConfig_t *)0) ||
        (!(((double)msg->HeightDetectCurrent >= 0) && ((double)msg->HeightDetectCurrent <= 65535))) ||
        (!(((double)msg->HeightDetectDefault >= 0) && ((double)msg->HeightDetectDefault <= 65535))) ||
        (!(((double)msg->HeightDetectMin >= 0) && ((double)msg->HeightDetectMin <= 65535))) ||
        (!(((double)msg->HeightDetectMax >= 0) && ((double)msg->HeightDetectMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgHeightDetectConfig_encode(msg, data, MSGHEIGHTDETECTCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGHEIGHTDETECTCONFIG_CAN_ID, true, data, MSGHEIGHTDETECTCONFIG_CAN_DLC);
}

bool MsgWaterOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgWaterOffsetConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgWaterOffsetConfig_t *)0) || (dlc < MSGWATEROFFSETCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode WaterOffsetCurrent. */
    msg->WaterOffsetCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WaterOffsetDefault. */
    msg->WaterOffsetDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WaterOffsetMin. */
    msg->WaterOffsetMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WaterOffsetMax. */
    msg->WaterOffsetMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgWaterOffsetConfig_encode(const MsgWaterOffsetConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgWaterOffsetConfig_t *)0) || (dlc < MSGWATEROFFSETCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGWATEROFFSETCONFIG_CAN_DLC);

    /* Encode WaterOffsetCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->WaterOffsetCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->WaterOffsetCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WaterOffsetDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->WaterOffsetDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->WaterOffsetDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WaterOffsetMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->WaterOffsetMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->WaterOffsetMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WaterOffsetMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->WaterOffsetMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->WaterOffsetMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgWaterOffsetConfig_send(const MsgWaterOffsetConfig_t *msg)
{
    uint8_t data[MSGWATEROFFSETCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgWaterOffsetConfig_t *)0) ||
        (!(((double)msg->WaterOffsetCurrent >= 0) && ((double)msg->WaterOffsetCurrent <= 65535))) ||
        (!(((double)msg->WaterOffsetDefault >= 0) && ((double)msg->WaterOffsetDefault <= 65535))) ||
        (!(((double)msg->WaterOffsetMin >= 0) && ((double)msg->WaterOffsetMin <= 65535))) ||
        (!(((double)msg->WaterOffsetMax >= 0) && ((double)msg->WaterOffsetMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgWaterOffsetConfig_encode(msg, data, MSGWATEROFFSETCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGWATEROFFSETCONFIG_CAN_ID, true, data, MSGWATEROFFSETCONFIG_CAN_DLC);
}

bool MsgWaterOffset2Config_decode(const uint8_t *data, uint8_t dlc, MsgWaterOffset2Config_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgWaterOffset2Config_t *)0) || (dlc < MSGWATEROFFSET2CONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode WaterOffset2Current. */
    msg->WaterOffset2Current = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WaterOffset2Default. */
    msg->WaterOffset2Default = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WaterOffset2Min. */
    msg->WaterOffset2Min = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WaterOffset2Max. */
    msg->WaterOffset2Max = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgWaterOffset2Config_encode(const MsgWaterOffset2Config_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgWaterOffset2Config_t *)0) || (dlc < MSGWATEROFFSET2CONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGWATEROFFSET2CONFIG_CAN_DLC);

    /* Encode WaterOffset2Current. */
    data[0] |= (uint8_t)(((((uint64_t)msg->WaterOffset2Current) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->WaterOffset2Current) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WaterOffset2Default. */
    data[2] |= (uint8_t)(((((uint64_t)msg->WaterOffset2Default) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->WaterOffset2Default) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WaterOffset2Min. */
    data[4] |= (uint8_t)(((((uint64_t)msg->WaterOffset2Min) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->WaterOffset2Min) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WaterOffset2Max. */
    data[6] |= (uint8_t)(((((uint64_t)msg->WaterOffset2Max) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->WaterOffset2Max) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgWaterOffset2Config_send(const MsgWaterOffset2Config_t *msg)
{
    uint8_t data[MSGWATEROFFSET2CONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgWaterOffset2Config_t *)0) ||
        (!(((double)msg->WaterOffset2Current >= 0) && ((double)msg->WaterOffset2Current <= 65535))) ||
        (!(((double)msg->WaterOffset2Default >= 0) && ((double)msg->WaterOffset2Default <= 65535))) ||
        (!(((double)msg->WaterOffset2Min >= 0) && ((double)msg->WaterOffset2Min <= 65535))) ||
        (!(((double)msg->WaterOffset2Max >= 0) && ((double)msg->WaterOffset2Max <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgWaterOffset2Config_encode(msg, data, MSGWATEROFFSET2CONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGWATEROFFSET2CONFIG_CAN_ID, true, data, MSGWATEROFFSET2CONFIG_CAN_DLC);
}

bool MsgSpeedRaiseConfig_decode(const uint8_t *data, uint8_t dlc, MsgSpeedRaiseConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgSpeedRaiseConfig_t *)0) || (dlc < MSGSPEEDRAISECONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode SpeedRaiseCurrent. */
    msg->SpeedRaiseCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode SpeedRaiseDefault. */
    msg->SpeedRaiseDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode SpeedRaiseMin. */
    msg->SpeedRaiseMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode SpeedRaiseMax. */
    msg->SpeedRaiseMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgSpeedRaiseConfig_encode(const MsgSpeedRaiseConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgSpeedRaiseConfig_t *)0) || (dlc < MSGSPEEDRAISECONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGSPEEDRAISECONFIG_CAN_DLC);

    /* Encode SpeedRaiseCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->SpeedRaiseCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->SpeedRaiseCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode SpeedRaiseDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->SpeedRaiseDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->SpeedRaiseDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode SpeedRaiseMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->SpeedRaiseMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->SpeedRaiseMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode SpeedRaiseMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->SpeedRaiseMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->SpeedRaiseMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgSpeedRaiseConfig_send(const MsgSpeedRaiseConfig_t *msg)
{
    uint8_t data[MSGSPEEDRAISECONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgSpeedRaiseConfig_t *)0) ||
        (!(((double)msg->SpeedRaiseCurrent >= 0) && ((double)msg->SpeedRaiseCurrent <= 65535))) ||
        (!(((double)msg->SpeedRaiseDefault >= 0) && ((double)msg->SpeedRaiseDefault <= 65535))) ||
        (!(((double)msg->SpeedRaiseMin >= 0) && ((double)msg->SpeedRaiseMin <= 65535))) ||
        (!(((double)msg->SpeedRaiseMax >= 0) && ((double)msg->SpeedRaiseMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgSpeedRaiseConfig_encode(msg, data, MSGSPEEDRAISECONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGSPEEDRAISECONFIG_CAN_ID, true, data, MSGSPEEDRAISECONFIG_CAN_DLC);
}

bool MsgSpeedLowerConfig_decode(const uint8_t *data, uint8_t dlc, MsgSpeedLowerConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgSpeedLowerConfig_t *)0) || (dlc < MSGSPEEDLOWERCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode SpeedLowerCurrent. */
    msg->SpeedLowerCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode SpeedLowerDefault. */
    msg->SpeedLowerDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode SpeedLowerMin. */
    msg->SpeedLowerMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode SpeedLowerMax. */
    msg->SpeedLowerMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgSpeedLowerConfig_encode(const MsgSpeedLowerConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgSpeedLowerConfig_t *)0) || (dlc < MSGSPEEDLOWERCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGSPEEDLOWERCONFIG_CAN_DLC);

    /* Encode SpeedLowerCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->SpeedLowerCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->SpeedLowerCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode SpeedLowerDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->SpeedLowerDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->SpeedLowerDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode SpeedLowerMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->SpeedLowerMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->SpeedLowerMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode SpeedLowerMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->SpeedLowerMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->SpeedLowerMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgSpeedLowerConfig_send(const MsgSpeedLowerConfig_t *msg)
{
    uint8_t data[MSGSPEEDLOWERCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgSpeedLowerConfig_t *)0) ||
        (!(((double)msg->SpeedLowerCurrent >= 0) && ((double)msg->SpeedLowerCurrent <= 65535))) ||
        (!(((double)msg->SpeedLowerDefault >= 0) && ((double)msg->SpeedLowerDefault <= 65535))) ||
        (!(((double)msg->SpeedLowerMin >= 0) && ((double)msg->SpeedLowerMin <= 65535))) ||
        (!(((double)msg->SpeedLowerMax >= 0) && ((double)msg->SpeedLowerMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgSpeedLowerConfig_encode(msg, data, MSGSPEEDLOWERCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGSPEEDLOWERCONFIG_CAN_ID, true, data, MSGSPEEDLOWERCONFIG_CAN_DLC);
}

bool MsgNrRowsConfig_decode(const uint8_t *data, uint8_t dlc, MsgNrRowsConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgNrRowsConfig_t *)0) || (dlc < MSGNRROWSCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode NrRowsCurrent. */
    msg->NrRowsCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode NrRowsDefault. */
    msg->NrRowsDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode NrRowsMin. */
    msg->NrRowsMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode NrRowsMax. */
    msg->NrRowsMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgNrRowsConfig_encode(const MsgNrRowsConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgNrRowsConfig_t *)0) || (dlc < MSGNRROWSCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGNRROWSCONFIG_CAN_DLC);

    /* Encode NrRowsCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->NrRowsCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->NrRowsCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode NrRowsDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->NrRowsDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->NrRowsDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode NrRowsMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->NrRowsMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->NrRowsMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode NrRowsMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->NrRowsMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->NrRowsMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgNrRowsConfig_send(const MsgNrRowsConfig_t *msg)
{
    uint8_t data[MSGNRROWSCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgNrRowsConfig_t *)0) ||
        (!(((double)msg->NrRowsCurrent >= 0) && ((double)msg->NrRowsCurrent <= 65535))) ||
        (!(((double)msg->NrRowsDefault >= 0) && ((double)msg->NrRowsDefault <= 65535))) ||
        (!(((double)msg->NrRowsMin >= 0) && ((double)msg->NrRowsMin <= 65535))) ||
        (!(((double)msg->NrRowsMax >= 0) && ((double)msg->NrRowsMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgNrRowsConfig_encode(msg, data, MSGNRROWSCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGNRROWSCONFIG_CAN_ID, true, data, MSGNRROWSCONFIG_CAN_DLC);
}

bool MsgWheelPositionOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgWheelPositionOffsetConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgWheelPositionOffsetConfig_t *)0) || (dlc < MSGWHEELPOSITIONOFFSETCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode WheelPositionOffsetCurrent. */
    msg->WheelPositionOffsetCurrent = (uint16_t)(((((uint64_t)data[0]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[1]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WheelPositionOffsetDefault. */
    msg->WheelPositionOffsetDefault = (uint16_t)(((((uint64_t)data[2]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[3]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WheelPositionOffsetMin. */
    msg->WheelPositionOffsetMin = (uint16_t)(((((uint64_t)data[4]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[5]) >> 0) & UINT64_C(0xFF)) << 8);

    /* Decode WheelPositionOffsetMax. */
    msg->WheelPositionOffsetMax = (uint16_t)(((((uint64_t)data[6]) >> 0) & UINT64_C(0xFF)) << 0 | ((((uint64_t)data[7]) >> 0) & UINT64_C(0xFF)) << 8);

    return true;
}

bool MsgWheelPositionOffsetConfig_encode(const MsgWheelPositionOffsetConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgWheelPositionOffsetConfig_t *)0) || (dlc < MSGWHEELPOSITIONOFFSETCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGWHEELPOSITIONOFFSETCONFIG_CAN_DLC);

    /* Encode WheelPositionOffsetCurrent. */
    data[0] |= (uint8_t)(((((uint64_t)msg->WheelPositionOffsetCurrent) >> 0) & UINT64_C(0xFF)) << 0);
    data[1] |= (uint8_t)(((((uint64_t)msg->WheelPositionOffsetCurrent) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WheelPositionOffsetDefault. */
    data[2] |= (uint8_t)(((((uint64_t)msg->WheelPositionOffsetDefault) >> 0) & UINT64_C(0xFF)) << 0);
    data[3] |= (uint8_t)(((((uint64_t)msg->WheelPositionOffsetDefault) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WheelPositionOffsetMin. */
    data[4] |= (uint8_t)(((((uint64_t)msg->WheelPositionOffsetMin) >> 0) & UINT64_C(0xFF)) << 0);
    data[5] |= (uint8_t)(((((uint64_t)msg->WheelPositionOffsetMin) >> 8) & UINT64_C(0xFF)) << 0);

    /* Encode WheelPositionOffsetMax. */
    data[6] |= (uint8_t)(((((uint64_t)msg->WheelPositionOffsetMax) >> 0) & UINT64_C(0xFF)) << 0);
    data[7] |= (uint8_t)(((((uint64_t)msg->WheelPositionOffsetMax) >> 8) & UINT64_C(0xFF)) << 0);

    return true;
}

bool MsgWheelPositionOffsetConfig_send(const MsgWheelPositionOffsetConfig_t *msg)
{
    uint8_t data[MSGWHEELPOSITIONOFFSETCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgWheelPositionOffsetConfig_t *)0) ||
        (!(((double)msg->WheelPositionOffsetCurrent >= 0) && ((double)msg->WheelPositionOffsetCurrent <= 65535))) ||
        (!(((double)msg->WheelPositionOffsetDefault >= 0) && ((double)msg->WheelPositionOffsetDefault <= 65535))) ||
        (!(((double)msg->WheelPositionOffsetMin >= 0) && ((double)msg->WheelPositionOffsetMin <= 65535))) ||
        (!(((double)msg->WheelPositionOffsetMax >= 0) && ((double)msg->WheelPositionOffsetMax <= 65535))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgWheelPositionOffsetConfig_encode(msg, data, MSGWHEELPOSITIONOFFSETCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGWHEELPOSITIONOFFSETCONFIG_CAN_ID, true, data, MSGWHEELPOSITIONOFFSETCONFIG_CAN_DLC);
}

bool MsgZAPConfig_decode(const uint8_t *data, uint8_t dlc, MsgZAPConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgZAPConfig_t *)0) || (dlc < MSGZAPCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode UseTandem. */
    msg->UseTandem = (bool)(((((uint64_t)data[0]) >> 0) & UINT64_C(0x1)) << 0);

    /* Decode UseWaterDosage. */
    msg->UseWaterDosage = (bool)(((((uint64_t)data[0]) >> 1) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgZAPConfig_encode(const MsgZAPConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgZAPConfig_t *)0) || (dlc < MSGZAPCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGZAPCONFIG_CAN_DLC);

    /* Encode UseTandem. */
    data[0] |= (uint8_t)(((((uint64_t)msg->UseTandem) >> 0) & UINT64_C(0x1)) << 0);

    /* Encode UseWaterDosage. */
    data[0] |= (uint8_t)(((((uint64_t)msg->UseWaterDosage) >> 0) & UINT64_C(0x1)) << 1);

    return true;
}

bool MsgZAPConfig_send(const MsgZAPConfig_t *msg)
{
    uint8_t data[MSGZAPCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgZAPConfig_t *)0) ||
        (!(((double)msg->UseTandem >= 0) && ((double)msg->UseTandem <= 1))) ||
        (!(((double)msg->UseWaterDosage >= 0) && ((double)msg->UseWaterDosage <= 1))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgZAPConfig_encode(msg, data, MSGZAPCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGZAPCONFIG_CAN_ID, true, data, MSGZAPCONFIG_CAN_DLC);
}

bool MsgSemiautoConfig_decode(const uint8_t *data, uint8_t dlc, MsgSemiautoConfig_t *msg)
{
    if ((data == (const uint8_t *)0) || (msg == (MsgSemiautoConfig_t *)0) || (dlc < MSGSEMIAUTOCONFIG_CAN_DLC))
    {
        return false;
    }

    /* Decode UseGripper. */
    msg->UseGripper = (bool)(((((uint64_t)data[0]) >> 0) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgSemiautoConfig_encode(const MsgSemiautoConfig_t *msg, uint8_t *data, uint8_t dlc)
{
    if ((data == (uint8_t *)0) || (msg == (const MsgSemiautoConfig_t *)0) || (dlc < MSGSEMIAUTOCONFIG_CAN_DLC))
    {
        return false;
    }

    (void)memset(data, 0, MSGSEMIAUTOCONFIG_CAN_DLC);

    /* Encode UseGripper. */
    data[0] |= (uint8_t)(((((uint64_t)msg->UseGripper) >> 0) & UINT64_C(0x1)) << 0);

    return true;
}

bool MsgSemiautoConfig_send(const MsgSemiautoConfig_t *msg)
{
    uint8_t data[MSGSEMIAUTOCONFIG_CAN_DLC];

    /* Reject values outside the physical range defined in the Excel. */
    if ((msg == (const MsgSemiautoConfig_t *)0) ||
        (!(((double)msg->UseGripper >= 0) && ((double)msg->UseGripper <= 1))))
    {
        CanMessages_RejectedCount++;
        return false;
    }

    if (!MsgSemiautoConfig_encode(msg, data, MSGSEMIAUTOCONFIG_CAN_DLC))
    {
        return false;
    }
    return CanMessages_Transmit(MSGSEMIAUTOCONFIG_CAN_ID, true, data, MSGSEMIAUTOCONFIG_CAN_DLC);
}

CanMsgs_t CanMsgs;
uint32_t CanMessages_RejectedCount;

bool CanMessages_Receive(uint32_t id, bool extended, const uint8_t *data, uint8_t dlc)
{
    bool ok = false;

    switch (id)
    {
    case MSGSPEEDSTATUS_CAN_ID:
        if (extended == true)
        {
            ok = MsgSpeedStatus_decode(data, dlc, &CanMsgs.SpeedStatus.Data);
            if (ok)
            {
                CanMsgs.SpeedStatus.Updated = true;
            }
        }
        break;
    case MSGSPEEDSOURCESTATUS_CAN_ID:
        if (extended == true)
        {
            ok = MsgSpeedSourceStatus_decode(data, dlc, &CanMsgs.SpeedSourceStatus.Data);
            if (ok)
            {
                CanMsgs.SpeedSourceStatus.Updated = true;
            }
        }
        break;
    case MSGHEIGHTSTATUS_CAN_ID:
        if (extended == true)
        {
            ok = MsgHeightStatus_decode(data, dlc, &CanMsgs.HeightStatus.Data);
            if (ok)
            {
                CanMsgs.HeightStatus.Updated = true;
            }
        }
        break;
    case MSGCOUNTERSTATUS_CAN_ID:
        if (extended == true)
        {
            ok = MsgCounterStatus_decode(data, dlc, &CanMsgs.CounterStatus.Data);
            if (ok)
            {
                CanMsgs.CounterStatus.Updated = true;
            }
        }
        break;
    case MSGMACHINESTATUS_CAN_ID:
        if (extended == true)
        {
            ok = MsgMachineStatus_decode(data, dlc, &CanMsgs.MachineStatus.Data);
            if (ok)
            {
                CanMsgs.MachineStatus.Updated = true;
            }
        }
        break;
    case MSGRAISELOWERSTATUS_CAN_ID:
        if (extended == true)
        {
            ok = MsgRaiseLowerStatus_decode(data, dlc, &CanMsgs.RaiseLowerStatus.Data);
            if (ok)
            {
                CanMsgs.RaiseLowerStatus.Updated = true;
            }
        }
        break;
    case MSGEDGEDETECTIONSTATUS_CAN_ID:
        if (extended == true)
        {
            ok = MsgEdgeDetectionStatus_decode(data, dlc, &CanMsgs.EdgeDetectionStatus.Data);
            if (ok)
            {
                CanMsgs.EdgeDetectionStatus.Updated = true;
            }
        }
        break;
    case MSGAUTOCONTROLACTIVE_CAN_ID:
        if (extended == true)
        {
            ok = MsgAutoControlActive_decode(data, dlc, &CanMsgs.AutoControlActive.Data);
            if (ok)
            {
                CanMsgs.AutoControlActive.Updated = true;
            }
        }
        break;
    case MSGPLANTWHEELSPEED_CAN_ID:
        if (extended == true)
        {
            ok = MsgPlantWheelSpeed_decode(data, dlc, &CanMsgs.PlantWheelSpeed.Data);
            if (ok)
            {
                CanMsgs.PlantWheelSpeed.Updated = true;
            }
        }
        break;
    case MSGSPEEDSETPOINTCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgSpeedSetpointCommand_decode(data, dlc, &CanMsgs.SpeedSetpointCommand.Data);
            if (ok)
            {
                CanMsgs.SpeedSetpointCommand.Updated = true;
            }
        }
        break;
    case MSGPLANTSPACINGCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgPlantSpacingCommand_decode(data, dlc, &CanMsgs.PlantSpacingCommand.Data);
            if (ok)
            {
                CanMsgs.PlantSpacingCommand.Updated = true;
            }
        }
        break;
    case MSGHEIGHTSETPOINTCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgHeightSetpointCommand_decode(data, dlc, &CanMsgs.HeightSetpointCommand.Data);
            if (ok)
            {
                CanMsgs.HeightSetpointCommand.Updated = true;
            }
        }
        break;
    case MSGHEIGHTDETECTCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgHeightDetectCommand_decode(data, dlc, &CanMsgs.HeightDetectCommand.Data);
            if (ok)
            {
                CanMsgs.HeightDetectCommand.Updated = true;
            }
        }
        break;
    case MSGWHEELCIRCUMCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgWheelCircumCommand_decode(data, dlc, &CanMsgs.WheelCircumCommand.Data);
            if (ok)
            {
                CanMsgs.WheelCircumCommand.Updated = true;
            }
        }
        break;
    case MSGHEIGHTCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgHeightCommand_decode(data, dlc, &CanMsgs.HeightCommand.Data);
            if (ok)
            {
                CanMsgs.HeightCommand.Updated = true;
            }
        }
        break;
    case MSGLIFTSPEEDCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgLiftSpeedCommand_decode(data, dlc, &CanMsgs.LiftSpeedCommand.Data);
            if (ok)
            {
                CanMsgs.LiftSpeedCommand.Updated = true;
            }
        }
        break;
    case MSGCONFIGCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgConfigCommand_decode(data, dlc, &CanMsgs.ConfigCommand.Data);
            if (ok)
            {
                CanMsgs.ConfigCommand.Updated = true;
            }
        }
        break;
    case MSGNRROWSCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgNrRowsCommand_decode(data, dlc, &CanMsgs.NrRowsCommand.Data);
            if (ok)
            {
                CanMsgs.NrRowsCommand.Updated = true;
            }
        }
        break;
    case MSGWORKWIDTHCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgWorkWidthCommand_decode(data, dlc, &CanMsgs.WorkWidthCommand.Data);
            if (ok)
            {
                CanMsgs.WorkWidthCommand.Updated = true;
            }
        }
        break;
    case MSGHEIGHTTHRESHOLDCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgHeightThresholdCommand_decode(data, dlc, &CanMsgs.HeightThresholdCommand.Data);
            if (ok)
            {
                CanMsgs.HeightThresholdCommand.Updated = true;
            }
        }
        break;
    case MSGWATERTIMECOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgWaterTimeCommand_decode(data, dlc, &CanMsgs.WaterTimeCommand.Data);
            if (ok)
            {
                CanMsgs.WaterTimeCommand.Updated = true;
            }
        }
        break;
    case MSGWATEROFFSETCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgWaterOffsetCommand_decode(data, dlc, &CanMsgs.WaterOffsetCommand.Data);
            if (ok)
            {
                CanMsgs.WaterOffsetCommand.Updated = true;
            }
        }
        break;
    case MSGAUTOCONTROLCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgAutoControlCommand_decode(data, dlc, &CanMsgs.AutoControlCommand.Data);
            if (ok)
            {
                CanMsgs.AutoControlCommand.Updated = true;
            }
        }
        break;
    case MSGGRIPIDLECOFCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgGripIdleCofCommand_decode(data, dlc, &CanMsgs.GripIdleCofCommand.Data);
            if (ok)
            {
                CanMsgs.GripIdleCofCommand.Updated = true;
            }
        }
        break;
    case MSGGRIPIDLEOFFSETCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgGripIdleOffsetCommand_decode(data, dlc, &CanMsgs.GripIdleOffsetCommand.Data);
            if (ok)
            {
                CanMsgs.GripIdleOffsetCommand.Updated = true;
            }
        }
        break;
    case MSGBELTOFFSETCOMMAND_CAN_ID:
        if (extended == true)
        {
            ok = MsgBeltOffsetCommand_decode(data, dlc, &CanMsgs.BeltOffsetCommand.Data);
            if (ok)
            {
                CanMsgs.BeltOffsetCommand.Updated = true;
            }
        }
        break;
    case MSGCONFIGREQUEST_CAN_ID:
        if (extended == true)
        {
            ok = MsgConfigRequest_decode(data, dlc, &CanMsgs.ConfigRequest.Data);
            if (ok)
            {
                CanMsgs.ConfigRequest.Updated = true;
            }
        }
        break;
    case MSGSPEEDCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgSpeedConfig_decode(data, dlc, &CanMsgs.SpeedConfig.Data);
            if (ok)
            {
                CanMsgs.SpeedConfig.Updated = true;
            }
        }
        break;
    case MSGHEIGHTCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgHeightConfig_decode(data, dlc, &CanMsgs.HeightConfig.Data);
            if (ok)
            {
                CanMsgs.HeightConfig.Updated = true;
            }
        }
        break;
    case MSGPLANTSPACINGCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgPlantSpacingConfig_decode(data, dlc, &CanMsgs.PlantSpacingConfig.Data);
            if (ok)
            {
                CanMsgs.PlantSpacingConfig.Updated = true;
            }
        }
        break;
    case MSGWATERTIMECONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgWaterTimeConfig_decode(data, dlc, &CanMsgs.WaterTimeConfig.Data);
            if (ok)
            {
                CanMsgs.WaterTimeConfig.Updated = true;
            }
        }
        break;
    case MSGWHEELCIRCUMCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgWheelCircumConfig_decode(data, dlc, &CanMsgs.WheelCircumConfig.Data);
            if (ok)
            {
                CanMsgs.WheelCircumConfig.Updated = true;
            }
        }
        break;
    case MSGGRIPPERIDLEOFFSETCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgGripperIdleOffsetConfig_decode(data, dlc, &CanMsgs.GripperIdleOffsetConfig.Data);
            if (ok)
            {
                CanMsgs.GripperIdleOffsetConfig.Updated = true;
            }
        }
        break;
    case MSGGRIPPERIDLECOFCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgGripperIdleCofConfig_decode(data, dlc, &CanMsgs.GripperIdleCofConfig.Data);
            if (ok)
            {
                CanMsgs.GripperIdleCofConfig.Updated = true;
            }
        }
        break;
    case MSGBELTOFFSETCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgBeltOffsetConfig_decode(data, dlc, &CanMsgs.BeltOffsetConfig.Data);
            if (ok)
            {
                CanMsgs.BeltOffsetConfig.Updated = true;
            }
        }
        break;
    case MSGGRIPPERIDLEOFFSET2CONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgGripperIdleOffset2Config_decode(data, dlc, &CanMsgs.GripperIdleOffset2Config.Data);
            if (ok)
            {
                CanMsgs.GripperIdleOffset2Config.Updated = true;
            }
        }
        break;
    case MSGHEIGHTDETECTCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgHeightDetectConfig_decode(data, dlc, &CanMsgs.HeightDetectConfig.Data);
            if (ok)
            {
                CanMsgs.HeightDetectConfig.Updated = true;
            }
        }
        break;
    case MSGWATEROFFSETCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgWaterOffsetConfig_decode(data, dlc, &CanMsgs.WaterOffsetConfig.Data);
            if (ok)
            {
                CanMsgs.WaterOffsetConfig.Updated = true;
            }
        }
        break;
    case MSGWATEROFFSET2CONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgWaterOffset2Config_decode(data, dlc, &CanMsgs.WaterOffset2Config.Data);
            if (ok)
            {
                CanMsgs.WaterOffset2Config.Updated = true;
            }
        }
        break;
    case MSGSPEEDRAISECONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgSpeedRaiseConfig_decode(data, dlc, &CanMsgs.SpeedRaiseConfig.Data);
            if (ok)
            {
                CanMsgs.SpeedRaiseConfig.Updated = true;
            }
        }
        break;
    case MSGSPEEDLOWERCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgSpeedLowerConfig_decode(data, dlc, &CanMsgs.SpeedLowerConfig.Data);
            if (ok)
            {
                CanMsgs.SpeedLowerConfig.Updated = true;
            }
        }
        break;
    case MSGNRROWSCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgNrRowsConfig_decode(data, dlc, &CanMsgs.NrRowsConfig.Data);
            if (ok)
            {
                CanMsgs.NrRowsConfig.Updated = true;
            }
        }
        break;
    case MSGWHEELPOSITIONOFFSETCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgWheelPositionOffsetConfig_decode(data, dlc, &CanMsgs.WheelPositionOffsetConfig.Data);
            if (ok)
            {
                CanMsgs.WheelPositionOffsetConfig.Updated = true;
            }
        }
        break;
    case MSGZAPCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgZAPConfig_decode(data, dlc, &CanMsgs.ZAPConfig.Data);
            if (ok)
            {
                CanMsgs.ZAPConfig.Updated = true;
            }
        }
        break;
    case MSGSEMIAUTOCONFIG_CAN_ID:
        if (extended == true)
        {
            ok = MsgSemiautoConfig_decode(data, dlc, &CanMsgs.SemiautoConfig.Data);
            if (ok)
            {
                CanMsgs.SemiautoConfig.Updated = true;
            }
        }
        break;
    default:
        break;
    }

    return ok;
}
