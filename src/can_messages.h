/*
 * AUTO-GENERATED FILE - DO NOT EDIT.
#define CAN_PROTOCOL_VERSION "V1.12"
#define CAN_PROTOCOL_DATE    "2026-10-05"
#define CAN_PROTOCOL_TIME    "16:53:55"
 * Generated from the Excel CAN protocol definition.
 */

#ifndef CAN_MESSAGES_H
#define CAN_MESSAGES_H

#include <stdbool.h>
#include <stdint.h>

/* CAN message identifiers and DLC values. */
#define MSGSPEEDSTATUS_CAN_ID   ((uint32_t)0x18FF01UL)
#define MSGSPEEDSTATUS_CAN_DLC  ((uint8_t)4U)
#define MSGSPEEDSOURCESTATUS_CAN_ID   ((uint32_t)0x18FF02UL)
#define MSGSPEEDSOURCESTATUS_CAN_DLC  ((uint8_t)1U)
#define MSGHEIGHTSTATUS_CAN_ID   ((uint32_t)0x18FF03UL)
#define MSGHEIGHTSTATUS_CAN_DLC  ((uint8_t)6U)
#define MSGCOUNTERSTATUS_CAN_ID   ((uint32_t)0x18FF04UL)
#define MSGCOUNTERSTATUS_CAN_DLC  ((uint8_t)8U)
#define MSGMACHINESTATUS_CAN_ID   ((uint32_t)0x18FF05UL)
#define MSGMACHINESTATUS_CAN_DLC  ((uint8_t)1U)
#define MSGRAISELOWERSTATUS_CAN_ID   ((uint32_t)0x18FF06UL)
#define MSGRAISELOWERSTATUS_CAN_DLC  ((uint8_t)1U)
#define MSGEDGEDETECTIONSTATUS_CAN_ID   ((uint32_t)0x18FF07UL)
#define MSGEDGEDETECTIONSTATUS_CAN_DLC  ((uint8_t)1U)
#define MSGAUTOCONTROLACTIVE_CAN_ID   ((uint32_t)0x18FF08UL)
#define MSGAUTOCONTROLACTIVE_CAN_DLC  ((uint8_t)1U)
#define MSGPLANTWHEELSPEED_CAN_ID   ((uint32_t)0x18FF09UL)
#define MSGPLANTWHEELSPEED_CAN_DLC  ((uint8_t)2U)
#define MSGSPEEDSETPOINTCOMMAND_CAN_ID   ((uint32_t)0x18FF32UL)
#define MSGSPEEDSETPOINTCOMMAND_CAN_DLC  ((uint8_t)4U)
#define MSGPLANTSPACINGCOMMAND_CAN_ID   ((uint32_t)0x18FF33UL)
#define MSGPLANTSPACINGCOMMAND_CAN_DLC  ((uint8_t)2U)
#define MSGHEIGHTSETPOINTCOMMAND_CAN_ID   ((uint32_t)0x18FF34UL)
#define MSGHEIGHTSETPOINTCOMMAND_CAN_DLC  ((uint8_t)2U)
#define MSGHEIGHTDETECTCOMMAND_CAN_ID   ((uint32_t)0x18FF35UL)
#define MSGHEIGHTDETECTCOMMAND_CAN_DLC  ((uint8_t)1U)
#define MSGWHEELCIRCUMCOMMAND_CAN_ID   ((uint32_t)0x18FF36UL)
#define MSGWHEELCIRCUMCOMMAND_CAN_DLC  ((uint8_t)2U)
#define MSGHEIGHTCOMMAND_CAN_ID   ((uint32_t)0x18FF37UL)
#define MSGHEIGHTCOMMAND_CAN_DLC  ((uint8_t)1U)
#define MSGLIFTSPEEDCOMMAND_CAN_ID   ((uint32_t)0x18FF38UL)
#define MSGLIFTSPEEDCOMMAND_CAN_DLC  ((uint8_t)4U)
#define MSGCONFIGCOMMAND_CAN_ID   ((uint32_t)0x18FF39UL)
#define MSGCONFIGCOMMAND_CAN_DLC  ((uint8_t)1U)
#define MSGNRROWSCOMMAND_CAN_ID   ((uint32_t)0x18FF3AUL)
#define MSGNRROWSCOMMAND_CAN_DLC  ((uint8_t)1U)
#define MSGWORKWIDTHCOMMAND_CAN_ID   ((uint32_t)0x18FF3BUL)
#define MSGWORKWIDTHCOMMAND_CAN_DLC  ((uint8_t)2U)
#define MSGHEIGHTTHRESHOLDCOMMAND_CAN_ID   ((uint32_t)0x18FF3CUL)
#define MSGHEIGHTTHRESHOLDCOMMAND_CAN_DLC  ((uint8_t)2U)
#define MSGWATERTIMECOMMAND_CAN_ID   ((uint32_t)0x18FF3DUL)
#define MSGWATERTIMECOMMAND_CAN_DLC  ((uint8_t)2U)
#define MSGWATEROFFSETCOMMAND_CAN_ID   ((uint32_t)0x18FF3EUL)
#define MSGWATEROFFSETCOMMAND_CAN_DLC  ((uint8_t)4U)
#define MSGAUTOCONTROLCOMMAND_CAN_ID   ((uint32_t)0x18FF3FUL)
#define MSGAUTOCONTROLCOMMAND_CAN_DLC  ((uint8_t)1U)
#define MSGGRIPIDLECOFCOMMAND_CAN_ID   ((uint32_t)0x18FF40UL)
#define MSGGRIPIDLECOFCOMMAND_CAN_DLC  ((uint8_t)2U)
#define MSGGRIPIDLEOFFSETCOMMAND_CAN_ID   ((uint32_t)0x18FF41UL)
#define MSGGRIPIDLEOFFSETCOMMAND_CAN_DLC  ((uint8_t)4U)
#define MSGBELTOFFSETCOMMAND_CAN_ID   ((uint32_t)0x18FF42UL)
#define MSGBELTOFFSETCOMMAND_CAN_DLC  ((uint8_t)2U)
#define MSGCONFIGREQUEST_CAN_ID   ((uint32_t)0x18FF43UL)
#define MSGCONFIGREQUEST_CAN_DLC  ((uint8_t)1U)
#define MSGSPEEDCONFIG_CAN_ID   ((uint32_t)0x18FF65UL)
#define MSGSPEEDCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGHEIGHTCONFIG_CAN_ID   ((uint32_t)0x18FF66UL)
#define MSGHEIGHTCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGPLANTSPACINGCONFIG_CAN_ID   ((uint32_t)0x18FF67UL)
#define MSGPLANTSPACINGCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGWATERTIMECONFIG_CAN_ID   ((uint32_t)0x18FF68UL)
#define MSGWATERTIMECONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGWHEELCIRCUMCONFIG_CAN_ID   ((uint32_t)0x18FF69UL)
#define MSGWHEELCIRCUMCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGGRIPPERIDLEOFFSETCONFIG_CAN_ID   ((uint32_t)0x18FF6AUL)
#define MSGGRIPPERIDLEOFFSETCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGGRIPPERIDLECOFCONFIG_CAN_ID   ((uint32_t)0x18FF6BUL)
#define MSGGRIPPERIDLECOFCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGBELTOFFSETCONFIG_CAN_ID   ((uint32_t)0x18FF6CUL)
#define MSGBELTOFFSETCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGGRIPPERIDLEOFFSET2CONFIG_CAN_ID   ((uint32_t)0x18FF6DUL)
#define MSGGRIPPERIDLEOFFSET2CONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGHEIGHTDETECTCONFIG_CAN_ID   ((uint32_t)0x18FF6EUL)
#define MSGHEIGHTDETECTCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGWATEROFFSETCONFIG_CAN_ID   ((uint32_t)0x18FF6FUL)
#define MSGWATEROFFSETCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGWATEROFFSET2CONFIG_CAN_ID   ((uint32_t)0x18FF70UL)
#define MSGWATEROFFSET2CONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGSPEEDRAISECONFIG_CAN_ID   ((uint32_t)0x18FF71UL)
#define MSGSPEEDRAISECONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGSPEEDLOWERCONFIG_CAN_ID   ((uint32_t)0x18FF72UL)
#define MSGSPEEDLOWERCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGNRROWSCONFIG_CAN_ID   ((uint32_t)0x18FF73UL)
#define MSGNRROWSCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGWHEELPOSITIONOFFSETCONFIG_CAN_ID   ((uint32_t)0x18FF74UL)
#define MSGWHEELPOSITIONOFFSETCONFIG_CAN_DLC  ((uint8_t)8U)
#define MSGZAPCONFIG_CAN_ID   ((uint32_t)0x18FF75UL)
#define MSGZAPCONFIG_CAN_DLC  ((uint8_t)1U)
#define MSGSEMIAUTOCONFIG_CAN_ID   ((uint32_t)0x18FF76UL)
#define MSGSEMIAUTOCONFIG_CAN_DLC  ((uint8_t)1U)

/* Enum values used by the protocol. */

typedef uint8_t SpeedSource_value_t;
#define SPEEDSOURCE_UNKNOWN ((SpeedSource_value_t)0u)
#define SPEEDSOURCE_WHEEL_BASED_SPEED ((SpeedSource_value_t)1u)
#define SPEEDSOURCE_GROUND_BASED_SPEED ((SpeedSource_value_t)2u)
#define SPEEDSOURCE_NAVIGATION_BASED_SPEED ((SpeedSource_value_t)3u)
#define SPEEDSOURCE_BLENDED_SPEED ((SpeedSource_value_t)4u)
#define SPEEDSOURCE_SIMULATED_SPEED ((SpeedSource_value_t)5u)
#define SPEEDSOURCE_MACHINE_SELECTED_SPEED ((SpeedSource_value_t)6u)
#define SPEEDSOURCE_MACHINE_MEASURED_SPEED ((SpeedSource_value_t)7u)
#define SPEEDSOURCE_NO_SOURCE_AVAILABLE ((SpeedSource_value_t)255u)

typedef uint8_t MachineStatus_value_t;
#define MACHINESTATUS_OFF ((MachineStatus_value_t)0u)
#define MACHINESTATUS_ON ((MachineStatus_value_t)1u)
#define MACHINESTATUS_STANDBY ((MachineStatus_value_t)2u)
#define MACHINESTATUS_ESTOP ((MachineStatus_value_t)3u)
#define MACHINESTATUS_ERROR ((MachineStatus_value_t)4u)
#define MACHINESTATUS_UNKNOWN ((MachineStatus_value_t)15u)

typedef uint8_t EdgeDetectionActive_value_t;
#define EDGEDETECTIONACTIVE_OFF___DISABLED___OUTSIDE_THRESHOLD ((EdgeDetectionActive_value_t)0u)
#define EDGEDETECTIONACTIVE_ON___ENABLED___INSIDE_THRESHOLD ((EdgeDetectionActive_value_t)1u)
#define EDGEDETECTIONACTIVE_ERROR ((EdgeDetectionActive_value_t)2u)
#define EDGEDETECTIONACTIVE_UNDEFINED___UNINSTALLED ((EdgeDetectionActive_value_t)3u)

typedef uint8_t AutoControlActive_value_t;
#define AUTOCONTROLACTIVE_OFF___DISABLED___OUTSIDE_THRESHOLD ((AutoControlActive_value_t)0u)
#define AUTOCONTROLACTIVE_ON___ENABLED___INSIDE_THRESHOLD ((AutoControlActive_value_t)1u)
#define AUTOCONTROLACTIVE_ERROR ((AutoControlActive_value_t)2u)
#define AUTOCONTROLACTIVE_UNDEFINED___UNINSTALLED ((AutoControlActive_value_t)3u)

typedef uint8_t ConfigGroup_value_t;
#define CONFIGGROUP_ALL ((ConfigGroup_value_t)0u)
#define CONFIGGROUP_SPEED ((ConfigGroup_value_t)1u)
#define CONFIGGROUP_HEIGHT ((ConfigGroup_value_t)2u)
#define CONFIGGROUP_PLANTSPACING ((ConfigGroup_value_t)3u)
#define CONFIGGROUP_WATERTIME ((ConfigGroup_value_t)4u)
#define CONFIGGROUP_WHEELCIRCUM ((ConfigGroup_value_t)5u)
#define CONFIGGROUP_GRIPPERIDLEOFFSET ((ConfigGroup_value_t)6u)
#define CONFIGGROUP_GRIPPERIDLECOF ((ConfigGroup_value_t)7u)
#define CONFIGGROUP_BELTOFFSET ((ConfigGroup_value_t)8u)
#define CONFIGGROUP_GRIPPERIDLEOFFSET2 ((ConfigGroup_value_t)9u)
#define CONFIGGROUP_HEIGHTDETECT ((ConfigGroup_value_t)10u)
#define CONFIGGROUP_WATEROFFSET ((ConfigGroup_value_t)11u)
#define CONFIGGROUP_WATEROFFSET2 ((ConfigGroup_value_t)12u)
#define CONFIGGROUP_SPEEDRAISE ((ConfigGroup_value_t)13u)
#define CONFIGGROUP_SPEEDLOWER ((ConfigGroup_value_t)14u)
#define CONFIGGROUP_NRROWS ((ConfigGroup_value_t)15u)
#define CONFIGGROUP_WHEELPOSITIONOFFSET ((ConfigGroup_value_t)16u)

/* Decoded application-level message structures. */

typedef struct MsgSpeedStatus_t
{
    /* Actuele snelheid [mm/s] */
    int32_t SpeedActual;
} MsgSpeedStatus_t;

bool MsgSpeedStatus_decode(const uint8_t *data, uint8_t dlc, MsgSpeedStatus_t *msg);
bool MsgSpeedStatus_encode(const MsgSpeedStatus_t *msg, uint8_t *data, uint8_t dlc);
bool MsgSpeedStatus_send(const MsgSpeedStatus_t *msg);

typedef struct MsgSpeedSourceStatus_t
{
    /* Wijze waarop snelheid wordt gemeten */
    SpeedSource_value_t SpeedSource;
} MsgSpeedSourceStatus_t;

bool MsgSpeedSourceStatus_decode(const uint8_t *data, uint8_t dlc, MsgSpeedSourceStatus_t *msg);
bool MsgSpeedSourceStatus_encode(const MsgSpeedSourceStatus_t *msg, uint8_t *data, uint8_t dlc);
bool MsgSpeedSourceStatus_send(const MsgSpeedSourceStatus_t *msg);

typedef struct MsgHeightStatus_t
{
    /* Actuele hoogte (gebruikt door controller) [mm] */
    uint16_t HeightActual;
    /* Actuele hoogte sensor 1 [mm] */
    uint16_t HeightActualSensor1;
    /* Actuele hoogte sensor 2 [mm] */
    uint16_t HeightActualSensor2;
} MsgHeightStatus_t;

bool MsgHeightStatus_decode(const uint8_t *data, uint8_t dlc, MsgHeightStatus_t *msg);
bool MsgHeightStatus_encode(const MsgHeightStatus_t *msg, uint8_t *data, uint8_t dlc);
bool MsgHeightStatus_send(const MsgHeightStatus_t *msg);

typedef struct MsgCounterStatus_t
{
    /* Telling planten trip */
    uint32_t TripTotalPlants;
    /* Telling planten totaal */
    uint32_t TotalPlants;
} MsgCounterStatus_t;

bool MsgCounterStatus_decode(const uint8_t *data, uint8_t dlc, MsgCounterStatus_t *msg);
bool MsgCounterStatus_encode(const MsgCounterStatus_t *msg, uint8_t *data, uint8_t dlc);
bool MsgCounterStatus_send(const MsgCounterStatus_t *msg);

typedef struct MsgMachineStatus_t
{
    /* 0=off, 1=standby, 2=on, 3=estop, */
    MachineStatus_value_t MachineStatus;
} MsgMachineStatus_t;

bool MsgMachineStatus_decode(const uint8_t *data, uint8_t dlc, MsgMachineStatus_t *msg);
bool MsgMachineStatus_encode(const MsgMachineStatus_t *msg, uint8_t *data, uint8_t dlc);
bool MsgMachineStatus_send(const MsgMachineStatus_t *msg);

typedef struct MsgRaiseLowerStatus_t
{
    /* Handmatig machine liften = actief */
    bool RaiseActive;
    /* Handmatig machine zakken = actief */
    bool LowerActive;
} MsgRaiseLowerStatus_t;

bool MsgRaiseLowerStatus_decode(const uint8_t *data, uint8_t dlc, MsgRaiseLowerStatus_t *msg);
bool MsgRaiseLowerStatus_encode(const MsgRaiseLowerStatus_t *msg, uint8_t *data, uint8_t dlc);
bool MsgRaiseLowerStatus_send(const MsgRaiseLowerStatus_t *msg);

typedef struct MsgEdgeDetectionStatus_t
{
    /* Is einde rij detectie actief */
    EdgeDetectionActive_value_t EdgeDetectionActive;
    /* Is einde rij gedetecteerd? */
    bool EdgeDetectionStatus;
} MsgEdgeDetectionStatus_t;

bool MsgEdgeDetectionStatus_decode(const uint8_t *data, uint8_t dlc, MsgEdgeDetectionStatus_t *msg);
bool MsgEdgeDetectionStatus_encode(const MsgEdgeDetectionStatus_t *msg, uint8_t *data, uint8_t dlc);
bool MsgEdgeDetectionStatus_send(const MsgEdgeDetectionStatus_t *msg);

typedef struct MsgAutoControlActive_t
{
    /* Is AutoControl actief? */
    AutoControlActive_value_t AutoControlActive;
} MsgAutoControlActive_t;

bool MsgAutoControlActive_decode(const uint8_t *data, uint8_t dlc, MsgAutoControlActive_t *msg);
bool MsgAutoControlActive_encode(const MsgAutoControlActive_t *msg, uint8_t *data, uint8_t dlc);
bool MsgAutoControlActive_send(const MsgAutoControlActive_t *msg);

typedef struct MsgPlantWheelSpeed_t
{
    /* Plantwielsnelheid [RPM] */
    float PlantwheelSpeed;
} MsgPlantWheelSpeed_t;

bool MsgPlantWheelSpeed_decode(const uint8_t *data, uint8_t dlc, MsgPlantWheelSpeed_t *msg);
bool MsgPlantWheelSpeed_encode(const MsgPlantWheelSpeed_t *msg, uint8_t *data, uint8_t dlc);
bool MsgPlantWheelSpeed_send(const MsgPlantWheelSpeed_t *msg);

typedef struct MsgSpeedSetpointCommand_t
{
    /* Handmatig snelheid setpoint [mm/s] */
    int32_t SpeedSetpoint;
} MsgSpeedSetpointCommand_t;

bool MsgSpeedSetpointCommand_decode(const uint8_t *data, uint8_t dlc, MsgSpeedSetpointCommand_t *msg);
bool MsgSpeedSetpointCommand_encode(const MsgSpeedSetpointCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgSpeedSetpointCommand_send(const MsgSpeedSetpointCommand_t *msg);

typedef struct MsgPlantSpacingCommand_t
{
    /* setpoint plantafstand [mm] */
    uint16_t PlantSpacingSetpoint;
} MsgPlantSpacingCommand_t;

bool MsgPlantSpacingCommand_decode(const uint8_t *data, uint8_t dlc, MsgPlantSpacingCommand_t *msg);
bool MsgPlantSpacingCommand_encode(const MsgPlantSpacingCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgPlantSpacingCommand_send(const MsgPlantSpacingCommand_t *msg);

typedef struct MsgHeightSetpointCommand_t
{
    /* setpoint hoogte [mm] */
    uint16_t HeightSetpoint;
} MsgHeightSetpointCommand_t;

bool MsgHeightSetpointCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightSetpointCommand_t *msg);
bool MsgHeightSetpointCommand_encode(const MsgHeightSetpointCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgHeightSetpointCommand_send(const MsgHeightSetpointCommand_t *msg);

typedef struct MsgHeightDetectCommand_t
{
    /* Einde rij detectie On/off */
    bool HeightDetect;
} MsgHeightDetectCommand_t;

bool MsgHeightDetectCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightDetectCommand_t *msg);
bool MsgHeightDetectCommand_encode(const MsgHeightDetectCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgHeightDetectCommand_send(const MsgHeightDetectCommand_t *msg);

typedef struct MsgWheelCircumCommand_t
{
    /* Instelling wielomtrek [mm] */
    uint16_t WheelCircum;
} MsgWheelCircumCommand_t;

bool MsgWheelCircumCommand_decode(const uint8_t *data, uint8_t dlc, MsgWheelCircumCommand_t *msg);
bool MsgWheelCircumCommand_encode(const MsgWheelCircumCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgWheelCircumCommand_send(const MsgWheelCircumCommand_t *msg);

typedef struct MsgHeightCommand_t
{
    /* knop handmatig machine liften */
    bool UpButton;
    /* knop handmatig machine dalen */
    bool DownButton;
} MsgHeightCommand_t;

bool MsgHeightCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightCommand_t *msg);
bool MsgHeightCommand_encode(const MsgHeightCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgHeightCommand_send(const MsgHeightCommand_t *msg);

typedef struct MsgLiftSpeedCommand_t
{
    /* Reactiesnelheid liften */
    uint16_t SpeedRaise;
    /* Reactiesneleheid dalen */
    uint16_t SpeedLower;
} MsgLiftSpeedCommand_t;

bool MsgLiftSpeedCommand_decode(const uint8_t *data, uint8_t dlc, MsgLiftSpeedCommand_t *msg);
bool MsgLiftSpeedCommand_encode(const MsgLiftSpeedCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgLiftSpeedCommand_send(const MsgLiftSpeedCommand_t *msg);

typedef struct MsgConfigCommand_t
{
    /* reset plantenteller */
    bool ResetPlantCounter;
} MsgConfigCommand_t;

bool MsgConfigCommand_decode(const uint8_t *data, uint8_t dlc, MsgConfigCommand_t *msg);
bool MsgConfigCommand_encode(const MsgConfigCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgConfigCommand_send(const MsgConfigCommand_t *msg);

typedef struct MsgNrRowsCommand_t
{
    /* Instelling aantal rijen */
    uint8_t NrRows;
} MsgNrRowsCommand_t;

bool MsgNrRowsCommand_decode(const uint8_t *data, uint8_t dlc, MsgNrRowsCommand_t *msg);
bool MsgNrRowsCommand_encode(const MsgNrRowsCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgNrRowsCommand_send(const MsgNrRowsCommand_t *msg);

typedef struct MsgWorkWidthCommand_t
{
    /* Instelling werkbreedte [mm] */
    uint16_t WorkWidth;
} MsgWorkWidthCommand_t;

bool MsgWorkWidthCommand_decode(const uint8_t *data, uint8_t dlc, MsgWorkWidthCommand_t *msg);
bool MsgWorkWidthCommand_encode(const MsgWorkWidthCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgWorkWidthCommand_send(const MsgWorkWidthCommand_t *msg);

typedef struct MsgHeightThresholdCommand_t
{
    /* Grenswaarde einde rij detectie [mm] */
    uint16_t HeightDetectThreshold;
} MsgHeightThresholdCommand_t;

bool MsgHeightThresholdCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightThresholdCommand_t *msg);
bool MsgHeightThresholdCommand_encode(const MsgHeightThresholdCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgHeightThresholdCommand_send(const MsgHeightThresholdCommand_t *msg);

typedef struct MsgWaterTimeCommand_t
{
    /* Watergift tijd [ms] */
    uint16_t WaterTime;
} MsgWaterTimeCommand_t;

bool MsgWaterTimeCommand_decode(const uint8_t *data, uint8_t dlc, MsgWaterTimeCommand_t *msg);
bool MsgWaterTimeCommand_encode(const MsgWaterTimeCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgWaterTimeCommand_send(const MsgWaterTimeCommand_t *msg);

typedef struct MsgWaterOffsetCommand_t
{
    /* Timing water gift [ms] */
    uint16_t WaterOffset;
    /* Timing water gift unit 2 [ms] */
    uint16_t WaterOffset2;
} MsgWaterOffsetCommand_t;

bool MsgWaterOffsetCommand_decode(const uint8_t *data, uint8_t dlc, MsgWaterOffsetCommand_t *msg);
bool MsgWaterOffsetCommand_encode(const MsgWaterOffsetCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgWaterOffsetCommand_send(const MsgWaterOffsetCommand_t *msg);

typedef struct MsgAutoControlCommand_t
{
    /* Auto Control Gripper On/off */
    bool AutoControl;
} MsgAutoControlCommand_t;

bool MsgAutoControlCommand_decode(const uint8_t *data, uint8_t dlc, MsgAutoControlCommand_t *msg);
bool MsgAutoControlCommand_encode(const MsgAutoControlCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgAutoControlCommand_send(const MsgAutoControlCommand_t *msg);

typedef struct MsgGripIdleCofCommand_t
{
    /* check [deg] */
    uint16_t GripperIdleCof;
} MsgGripIdleCofCommand_t;

bool MsgGripIdleCofCommand_decode(const uint8_t *data, uint8_t dlc, MsgGripIdleCofCommand_t *msg);
bool MsgGripIdleCofCommand_encode(const MsgGripIdleCofCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgGripIdleCofCommand_send(const MsgGripIdleCofCommand_t *msg);

typedef struct MsgGripIdleOffsetCommand_t
{
    /* Gripper timing [deg] */
    uint16_t GripperIdleOffset;
    /* Gripper 2 timing [deg] */
    uint16_t GripperIdleOffset2;
} MsgGripIdleOffsetCommand_t;

bool MsgGripIdleOffsetCommand_decode(const uint8_t *data, uint8_t dlc, MsgGripIdleOffsetCommand_t *msg);
bool MsgGripIdleOffsetCommand_encode(const MsgGripIdleOffsetCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgGripIdleOffsetCommand_send(const MsgGripIdleOffsetCommand_t *msg);

typedef struct MsgBeltOffsetCommand_t
{
    /* Belt ZAP timing [ms] */
    uint16_t BeltOffset;
} MsgBeltOffsetCommand_t;

bool MsgBeltOffsetCommand_decode(const uint8_t *data, uint8_t dlc, MsgBeltOffsetCommand_t *msg);
bool MsgBeltOffsetCommand_encode(const MsgBeltOffsetCommand_t *msg, uint8_t *data, uint8_t dlc);
bool MsgBeltOffsetCommand_send(const MsgBeltOffsetCommand_t *msg);

typedef struct MsgConfigRequest_t
{
    /* Bericht om configuratieparameters op te vragen */
    ConfigGroup_value_t ConfigGroup;
} MsgConfigRequest_t;

bool MsgConfigRequest_decode(const uint8_t *data, uint8_t dlc, MsgConfigRequest_t *msg);
bool MsgConfigRequest_encode(const MsgConfigRequest_t *msg, uint8_t *data, uint8_t dlc);
bool MsgConfigRequest_send(const MsgConfigRequest_t *msg);

typedef struct MsgSpeedConfig_t
{
    /* [mm/s] */
    uint16_t SpeedSetpointCurrent;
    /* [mm/s] */
    uint16_t SpeedDefault;
    /* [mm/s] */
    uint16_t SpeedMin;
    /* [mm/s] */
    uint16_t SpeedMax;
} MsgSpeedConfig_t;

bool MsgSpeedConfig_decode(const uint8_t *data, uint8_t dlc, MsgSpeedConfig_t *msg);
bool MsgSpeedConfig_encode(const MsgSpeedConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgSpeedConfig_send(const MsgSpeedConfig_t *msg);

typedef struct MsgHeightConfig_t
{
    /* [mm] */
    uint16_t HeightSetpointCurrent;
    /* [mm] */
    uint16_t HeightDefault;
    /* [mm] */
    uint16_t HeightMin;
    /* [mm] */
    uint16_t HeightMax;
} MsgHeightConfig_t;

bool MsgHeightConfig_decode(const uint8_t *data, uint8_t dlc, MsgHeightConfig_t *msg);
bool MsgHeightConfig_encode(const MsgHeightConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgHeightConfig_send(const MsgHeightConfig_t *msg);

typedef struct MsgPlantSpacingConfig_t
{
    /* [mm] */
    uint16_t PlantSpacingCurrent;
    /* [mm] */
    uint16_t PlantSpacingDefault;
    /* [mm] */
    uint16_t PlantSpacingMin;
    /* [mm] */
    uint16_t PlantSpacingMax;
} MsgPlantSpacingConfig_t;

bool MsgPlantSpacingConfig_decode(const uint8_t *data, uint8_t dlc, MsgPlantSpacingConfig_t *msg);
bool MsgPlantSpacingConfig_encode(const MsgPlantSpacingConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgPlantSpacingConfig_send(const MsgPlantSpacingConfig_t *msg);

typedef struct MsgWaterTimeConfig_t
{
    /* [ms] */
    uint16_t WaterTimeCurrent;
    /* [ms] */
    uint16_t WaterTimeDefault;
    /* [ms] */
    uint16_t WaterTimeMin;
    /* [ms] */
    uint16_t WaterTimeMax;
} MsgWaterTimeConfig_t;

bool MsgWaterTimeConfig_decode(const uint8_t *data, uint8_t dlc, MsgWaterTimeConfig_t *msg);
bool MsgWaterTimeConfig_encode(const MsgWaterTimeConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgWaterTimeConfig_send(const MsgWaterTimeConfig_t *msg);

typedef struct MsgWheelCircumConfig_t
{
    /* [mm] */
    uint16_t WheelCircumCurrent;
    /* [mm] */
    uint16_t WheelCircumDefault;
    /* [mm] */
    uint16_t WheelCircumMin;
    /* [mm] */
    uint16_t WheelCircumMax;
} MsgWheelCircumConfig_t;

bool MsgWheelCircumConfig_decode(const uint8_t *data, uint8_t dlc, MsgWheelCircumConfig_t *msg);
bool MsgWheelCircumConfig_encode(const MsgWheelCircumConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgWheelCircumConfig_send(const MsgWheelCircumConfig_t *msg);

typedef struct MsgGripperIdleOffsetConfig_t
{
    /* [deg] */
    uint16_t GripperIdleOffsetCurrent;
    /* [deg] */
    uint16_t GripperIdleOffsetDefault;
    /* [deg] */
    uint16_t GripperIdleOffsetMin;
    /* [deg] */
    uint16_t GripperIdleOffsetMax;
} MsgGripperIdleOffsetConfig_t;

bool MsgGripperIdleOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgGripperIdleOffsetConfig_t *msg);
bool MsgGripperIdleOffsetConfig_encode(const MsgGripperIdleOffsetConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgGripperIdleOffsetConfig_send(const MsgGripperIdleOffsetConfig_t *msg);

typedef struct MsgGripperIdleCofConfig_t
{
    /* [deg] */
    uint16_t GripperIdleCofCurrent;
    /* [deg] */
    uint16_t GripperIdleCofDefault;
    /* [deg] */
    uint16_t GripperIdleCofMin;
    /* [deg] */
    uint16_t GripperIdleCofMax;
} MsgGripperIdleCofConfig_t;

bool MsgGripperIdleCofConfig_decode(const uint8_t *data, uint8_t dlc, MsgGripperIdleCofConfig_t *msg);
bool MsgGripperIdleCofConfig_encode(const MsgGripperIdleCofConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgGripperIdleCofConfig_send(const MsgGripperIdleCofConfig_t *msg);

typedef struct MsgBeltOffsetConfig_t
{
    /* [ms] */
    uint16_t BeltOffsetCurrent;
    /* [ms] */
    uint16_t BeltOffsetDefault;
    /* [ms] */
    uint16_t BeltOffsetMin;
    /* [ms] */
    uint16_t BeltOffsetMax;
} MsgBeltOffsetConfig_t;

bool MsgBeltOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgBeltOffsetConfig_t *msg);
bool MsgBeltOffsetConfig_encode(const MsgBeltOffsetConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgBeltOffsetConfig_send(const MsgBeltOffsetConfig_t *msg);

typedef struct MsgGripperIdleOffset2Config_t
{
    /* [deg] */
    uint16_t GripperIdleOffset2Current;
    /* [deg] */
    uint16_t GripperIdleOffset2Default;
    /* [deg] */
    uint16_t GripperIdleOffset2Min;
    /* [deg] */
    uint16_t GripperIdleOffset2Max;
} MsgGripperIdleOffset2Config_t;

bool MsgGripperIdleOffset2Config_decode(const uint8_t *data, uint8_t dlc, MsgGripperIdleOffset2Config_t *msg);
bool MsgGripperIdleOffset2Config_encode(const MsgGripperIdleOffset2Config_t *msg, uint8_t *data, uint8_t dlc);
bool MsgGripperIdleOffset2Config_send(const MsgGripperIdleOffset2Config_t *msg);

typedef struct MsgHeightDetectConfig_t
{
    /* [mm] */
    uint16_t HeightDetectCurrent;
    /* [mm] */
    uint16_t HeightDetectDefault;
    /* [mm] */
    uint16_t HeightDetectMin;
    /* [mm] */
    uint16_t HeightDetectMax;
} MsgHeightDetectConfig_t;

bool MsgHeightDetectConfig_decode(const uint8_t *data, uint8_t dlc, MsgHeightDetectConfig_t *msg);
bool MsgHeightDetectConfig_encode(const MsgHeightDetectConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgHeightDetectConfig_send(const MsgHeightDetectConfig_t *msg);

typedef struct MsgWaterOffsetConfig_t
{
    /* [deg] */
    uint16_t WaterOffsetCurrent;
    /* [deg] */
    uint16_t WaterOffsetDefault;
    /* [deg] */
    uint16_t WaterOffsetMin;
    /* [deg] */
    uint16_t WaterOffsetMax;
} MsgWaterOffsetConfig_t;

bool MsgWaterOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgWaterOffsetConfig_t *msg);
bool MsgWaterOffsetConfig_encode(const MsgWaterOffsetConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgWaterOffsetConfig_send(const MsgWaterOffsetConfig_t *msg);

typedef struct MsgWaterOffset2Config_t
{
    /* [deg] */
    uint16_t WaterOffset2Current;
    /* [deg] */
    uint16_t WaterOffset2Default;
    /* [deg] */
    uint16_t WaterOffset2Min;
    /* [deg] */
    uint16_t WaterOffset2Max;
} MsgWaterOffset2Config_t;

bool MsgWaterOffset2Config_decode(const uint8_t *data, uint8_t dlc, MsgWaterOffset2Config_t *msg);
bool MsgWaterOffset2Config_encode(const MsgWaterOffset2Config_t *msg, uint8_t *data, uint8_t dlc);
bool MsgWaterOffset2Config_send(const MsgWaterOffset2Config_t *msg);

typedef struct MsgSpeedRaiseConfig_t
{
    uint16_t SpeedRaiseCurrent;
    uint16_t SpeedRaiseDefault;
    uint16_t SpeedRaiseMin;
    uint16_t SpeedRaiseMax;
} MsgSpeedRaiseConfig_t;

bool MsgSpeedRaiseConfig_decode(const uint8_t *data, uint8_t dlc, MsgSpeedRaiseConfig_t *msg);
bool MsgSpeedRaiseConfig_encode(const MsgSpeedRaiseConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgSpeedRaiseConfig_send(const MsgSpeedRaiseConfig_t *msg);

typedef struct MsgSpeedLowerConfig_t
{
    uint16_t SpeedLowerCurrent;
    uint16_t SpeedLowerDefault;
    uint16_t SpeedLowerMin;
    uint16_t SpeedLowerMax;
} MsgSpeedLowerConfig_t;

bool MsgSpeedLowerConfig_decode(const uint8_t *data, uint8_t dlc, MsgSpeedLowerConfig_t *msg);
bool MsgSpeedLowerConfig_encode(const MsgSpeedLowerConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgSpeedLowerConfig_send(const MsgSpeedLowerConfig_t *msg);

typedef struct MsgNrRowsConfig_t
{
    uint16_t NrRowsCurrent;
    uint16_t NrRowsDefault;
    uint16_t NrRowsMin;
    uint16_t NrRowsMax;
} MsgNrRowsConfig_t;

bool MsgNrRowsConfig_decode(const uint8_t *data, uint8_t dlc, MsgNrRowsConfig_t *msg);
bool MsgNrRowsConfig_encode(const MsgNrRowsConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgNrRowsConfig_send(const MsgNrRowsConfig_t *msg);

typedef struct MsgWheelPositionOffsetConfig_t
{
    uint16_t WheelPositionOffsetCurrent;
    uint16_t WheelPositionOffsetDefault;
    uint16_t WheelPositionOffsetMin;
    uint16_t WheelPositionOffsetMax;
} MsgWheelPositionOffsetConfig_t;

bool MsgWheelPositionOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgWheelPositionOffsetConfig_t *msg);
bool MsgWheelPositionOffsetConfig_encode(const MsgWheelPositionOffsetConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgWheelPositionOffsetConfig_send(const MsgWheelPositionOffsetConfig_t *msg);

typedef struct MsgZAPConfig_t
{
    bool UseTandem;
    bool UseWaterDosage;
} MsgZAPConfig_t;

bool MsgZAPConfig_decode(const uint8_t *data, uint8_t dlc, MsgZAPConfig_t *msg);
bool MsgZAPConfig_encode(const MsgZAPConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgZAPConfig_send(const MsgZAPConfig_t *msg);

typedef struct MsgSemiautoConfig_t
{
    bool UseGripper;
} MsgSemiautoConfig_t;

bool MsgSemiautoConfig_decode(const uint8_t *data, uint8_t dlc, MsgSemiautoConfig_t *msg);
bool MsgSemiautoConfig_encode(const MsgSemiautoConfig_t *msg, uint8_t *data, uint8_t dlc);
bool MsgSemiautoConfig_send(const MsgSemiautoConfig_t *msg);

/*
 * Platform glue: every project implements this single function once.
 * It must transmit one frame and return true when it was accepted.
 */
bool CanMessages_Transmit(uint32_t id, bool extended, const uint8_t *data, uint8_t dlc);

/* Last received value per message. Clear Updated after the value is used. */
typedef struct CanMsgs_t
{
    struct
    {
        MsgSpeedStatus_t Data;
        volatile bool Updated;
    } SpeedStatus;
    struct
    {
        MsgSpeedSourceStatus_t Data;
        volatile bool Updated;
    } SpeedSourceStatus;
    struct
    {
        MsgHeightStatus_t Data;
        volatile bool Updated;
    } HeightStatus;
    struct
    {
        MsgCounterStatus_t Data;
        volatile bool Updated;
    } CounterStatus;
    struct
    {
        MsgMachineStatus_t Data;
        volatile bool Updated;
    } MachineStatus;
    struct
    {
        MsgRaiseLowerStatus_t Data;
        volatile bool Updated;
    } RaiseLowerStatus;
    struct
    {
        MsgEdgeDetectionStatus_t Data;
        volatile bool Updated;
    } EdgeDetectionStatus;
    struct
    {
        MsgAutoControlActive_t Data;
        volatile bool Updated;
    } AutoControlActive;
    struct
    {
        MsgPlantWheelSpeed_t Data;
        volatile bool Updated;
    } PlantWheelSpeed;
    struct
    {
        MsgSpeedSetpointCommand_t Data;
        volatile bool Updated;
    } SpeedSetpointCommand;
    struct
    {
        MsgPlantSpacingCommand_t Data;
        volatile bool Updated;
    } PlantSpacingCommand;
    struct
    {
        MsgHeightSetpointCommand_t Data;
        volatile bool Updated;
    } HeightSetpointCommand;
    struct
    {
        MsgHeightDetectCommand_t Data;
        volatile bool Updated;
    } HeightDetectCommand;
    struct
    {
        MsgWheelCircumCommand_t Data;
        volatile bool Updated;
    } WheelCircumCommand;
    struct
    {
        MsgHeightCommand_t Data;
        volatile bool Updated;
    } HeightCommand;
    struct
    {
        MsgLiftSpeedCommand_t Data;
        volatile bool Updated;
    } LiftSpeedCommand;
    struct
    {
        MsgConfigCommand_t Data;
        volatile bool Updated;
    } ConfigCommand;
    struct
    {
        MsgNrRowsCommand_t Data;
        volatile bool Updated;
    } NrRowsCommand;
    struct
    {
        MsgWorkWidthCommand_t Data;
        volatile bool Updated;
    } WorkWidthCommand;
    struct
    {
        MsgHeightThresholdCommand_t Data;
        volatile bool Updated;
    } HeightThresholdCommand;
    struct
    {
        MsgWaterTimeCommand_t Data;
        volatile bool Updated;
    } WaterTimeCommand;
    struct
    {
        MsgWaterOffsetCommand_t Data;
        volatile bool Updated;
    } WaterOffsetCommand;
    struct
    {
        MsgAutoControlCommand_t Data;
        volatile bool Updated;
    } AutoControlCommand;
    struct
    {
        MsgGripIdleCofCommand_t Data;
        volatile bool Updated;
    } GripIdleCofCommand;
    struct
    {
        MsgGripIdleOffsetCommand_t Data;
        volatile bool Updated;
    } GripIdleOffsetCommand;
    struct
    {
        MsgBeltOffsetCommand_t Data;
        volatile bool Updated;
    } BeltOffsetCommand;
    struct
    {
        MsgConfigRequest_t Data;
        volatile bool Updated;
    } ConfigRequest;
    struct
    {
        MsgSpeedConfig_t Data;
        volatile bool Updated;
    } SpeedConfig;
    struct
    {
        MsgHeightConfig_t Data;
        volatile bool Updated;
    } HeightConfig;
    struct
    {
        MsgPlantSpacingConfig_t Data;
        volatile bool Updated;
    } PlantSpacingConfig;
    struct
    {
        MsgWaterTimeConfig_t Data;
        volatile bool Updated;
    } WaterTimeConfig;
    struct
    {
        MsgWheelCircumConfig_t Data;
        volatile bool Updated;
    } WheelCircumConfig;
    struct
    {
        MsgGripperIdleOffsetConfig_t Data;
        volatile bool Updated;
    } GripperIdleOffsetConfig;
    struct
    {
        MsgGripperIdleCofConfig_t Data;
        volatile bool Updated;
    } GripperIdleCofConfig;
    struct
    {
        MsgBeltOffsetConfig_t Data;
        volatile bool Updated;
    } BeltOffsetConfig;
    struct
    {
        MsgGripperIdleOffset2Config_t Data;
        volatile bool Updated;
    } GripperIdleOffset2Config;
    struct
    {
        MsgHeightDetectConfig_t Data;
        volatile bool Updated;
    } HeightDetectConfig;
    struct
    {
        MsgWaterOffsetConfig_t Data;
        volatile bool Updated;
    } WaterOffsetConfig;
    struct
    {
        MsgWaterOffset2Config_t Data;
        volatile bool Updated;
    } WaterOffset2Config;
    struct
    {
        MsgSpeedRaiseConfig_t Data;
        volatile bool Updated;
    } SpeedRaiseConfig;
    struct
    {
        MsgSpeedLowerConfig_t Data;
        volatile bool Updated;
    } SpeedLowerConfig;
    struct
    {
        MsgNrRowsConfig_t Data;
        volatile bool Updated;
    } NrRowsConfig;
    struct
    {
        MsgWheelPositionOffsetConfig_t Data;
        volatile bool Updated;
    } WheelPositionOffsetConfig;
    struct
    {
        MsgZAPConfig_t Data;
        volatile bool Updated;
    } ZAPConfig;
    struct
    {
        MsgSemiautoConfig_t Data;
        volatile bool Updated;
    } SemiautoConfig;
} CanMsgs_t;

extern CanMsgs_t CanMsgs;

/* Number of _send calls rejected because a value was outside its physical range. */
extern uint32_t CanMessages_RejectedCount;

/*
 * Decodes a received frame into CanMsgs. Returns true when the frame is a known
 * message with a valid length. Only decodes, so it is safe to call from an interrupt.
 */
bool CanMessages_Receive(uint32_t id, bool extended, const uint8_t *data, uint8_t dlc);

#endif /* CAN_MESSAGES_H */
