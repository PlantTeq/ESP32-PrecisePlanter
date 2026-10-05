/*
 * AUTO-GENERATED FILE - DO NOT EDIT.
#define CAN_PROTOCOL_VERSION "V1.06"
#define CAN_PROTOCOL_DATE    "2026-10-05"
#define CAN_PROTOCOL_TIME    "13:53:50"
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
    /* Actuele snelheid */
    int32_t SpeedActual;
} MsgSpeedStatus_t;

bool MsgSpeedStatus_decode(const uint8_t *data, uint8_t dlc, MsgSpeedStatus_t *msg);
bool MsgSpeedStatus_encode(const MsgSpeedStatus_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgSpeedSourceStatus_t
{
    /* Wijze waarop snelheid wordt gemeten */
    SpeedSource_value_t SpeedSource;
} MsgSpeedSourceStatus_t;

bool MsgSpeedSourceStatus_decode(const uint8_t *data, uint8_t dlc, MsgSpeedSourceStatus_t *msg);
bool MsgSpeedSourceStatus_encode(const MsgSpeedSourceStatus_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgHeightStatus_t
{
    /* Actuele hoogte (gebruikt door controller) */
    uint16_t HeightActual;
    /* Actuele hoogte sensor 1 */
    uint16_t HeightActualSensor1;
    /* Actuele hoogte sensor 2 */
    uint16_t HeightActualSensor2;
} MsgHeightStatus_t;

bool MsgHeightStatus_decode(const uint8_t *data, uint8_t dlc, MsgHeightStatus_t *msg);
bool MsgHeightStatus_encode(const MsgHeightStatus_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgCounterStatus_t
{
    /* Telling planten trip */
    uint32_t TripTotalPlants;
    /* Telling planten totaal */
    uint32_t TotalPlants;
} MsgCounterStatus_t;

bool MsgCounterStatus_decode(const uint8_t *data, uint8_t dlc, MsgCounterStatus_t *msg);
bool MsgCounterStatus_encode(const MsgCounterStatus_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgMachineStatus_t
{
    /* 0=off, 1=standby, 2=on, 3=estop, */
    MachineStatus_value_t MachineStatus;
} MsgMachineStatus_t;

bool MsgMachineStatus_decode(const uint8_t *data, uint8_t dlc, MsgMachineStatus_t *msg);
bool MsgMachineStatus_encode(const MsgMachineStatus_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgRaiseLowerStatus_t
{
    /* Handmatig machine liften = actief */
    bool RaiseActive;
    /* Handmatig machine zakken = actief */
    bool LowerActive;
} MsgRaiseLowerStatus_t;

bool MsgRaiseLowerStatus_decode(const uint8_t *data, uint8_t dlc, MsgRaiseLowerStatus_t *msg);
bool MsgRaiseLowerStatus_encode(const MsgRaiseLowerStatus_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgEdgeDetectionStatus_t
{
    /* Is einde rij detectie actief */
    EdgeDetectionActive_value_t EdgeDetectionActive;
    /* Is einde rij gedetecteerd? */
    bool EdgeDetectionStatus;
} MsgEdgeDetectionStatus_t;

bool MsgEdgeDetectionStatus_decode(const uint8_t *data, uint8_t dlc, MsgEdgeDetectionStatus_t *msg);
bool MsgEdgeDetectionStatus_encode(const MsgEdgeDetectionStatus_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgAutoControlActive_t
{
    /* Is AutoControl actief? */
    AutoControlActive_value_t AutoControlActive;
} MsgAutoControlActive_t;

bool MsgAutoControlActive_decode(const uint8_t *data, uint8_t dlc, MsgAutoControlActive_t *msg);
bool MsgAutoControlActive_encode(const MsgAutoControlActive_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgPlantWheelSpeed_t
{
    /* Plantwielsnelheid */
    float PlantwheelSpeed;
} MsgPlantWheelSpeed_t;

bool MsgPlantWheelSpeed_decode(const uint8_t *data, uint8_t dlc, MsgPlantWheelSpeed_t *msg);
bool MsgPlantWheelSpeed_encode(const MsgPlantWheelSpeed_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgSpeedSetpointCommand_t
{
    /* Handmatig snelheid setpoint */
    int32_t SpeedSetpoint;
} MsgSpeedSetpointCommand_t;

bool MsgSpeedSetpointCommand_decode(const uint8_t *data, uint8_t dlc, MsgSpeedSetpointCommand_t *msg);
bool MsgSpeedSetpointCommand_encode(const MsgSpeedSetpointCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgPlantSpacingCommand_t
{
    /* setpoint plantafstand */
    uint16_t PlantSpacingSetpoint;
} MsgPlantSpacingCommand_t;

bool MsgPlantSpacingCommand_decode(const uint8_t *data, uint8_t dlc, MsgPlantSpacingCommand_t *msg);
bool MsgPlantSpacingCommand_encode(const MsgPlantSpacingCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgHeightSetpointCommand_t
{
    /* setpoint hoogte */
    uint16_t HeightSetpoint;
} MsgHeightSetpointCommand_t;

bool MsgHeightSetpointCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightSetpointCommand_t *msg);
bool MsgHeightSetpointCommand_encode(const MsgHeightSetpointCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgHeightDetectCommand_t
{
    /* Einde rij detectie On/off */
    bool HeightDetect;
} MsgHeightDetectCommand_t;

bool MsgHeightDetectCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightDetectCommand_t *msg);
bool MsgHeightDetectCommand_encode(const MsgHeightDetectCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgWheelCircumCommand_t
{
    /* Instelling wielomtrek */
    uint16_t WheelCircum;
} MsgWheelCircumCommand_t;

bool MsgWheelCircumCommand_decode(const uint8_t *data, uint8_t dlc, MsgWheelCircumCommand_t *msg);
bool MsgWheelCircumCommand_encode(const MsgWheelCircumCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgHeightCommand_t
{
    /* knop handmatig machine liften */
    bool UpButton;
    /* knop handmatig machine dalen */
    bool DownButton;
} MsgHeightCommand_t;

bool MsgHeightCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightCommand_t *msg);
bool MsgHeightCommand_encode(const MsgHeightCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgLiftSpeedCommand_t
{
    /* Reactiesnelheid liften */
    uint16_t SpeedRaise;
    /* Reactiesneleheid dalen */
    uint16_t SpeedLower;
} MsgLiftSpeedCommand_t;

bool MsgLiftSpeedCommand_decode(const uint8_t *data, uint8_t dlc, MsgLiftSpeedCommand_t *msg);
bool MsgLiftSpeedCommand_encode(const MsgLiftSpeedCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgConfigCommand_t
{
    /* reset plantenteller */
    bool ResetPlantCounter;
} MsgConfigCommand_t;

bool MsgConfigCommand_decode(const uint8_t *data, uint8_t dlc, MsgConfigCommand_t *msg);
bool MsgConfigCommand_encode(const MsgConfigCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgNrRowsCommand_t
{
    /* Instelling aantal rijen */
    uint8_t NrRows;
} MsgNrRowsCommand_t;

bool MsgNrRowsCommand_decode(const uint8_t *data, uint8_t dlc, MsgNrRowsCommand_t *msg);
bool MsgNrRowsCommand_encode(const MsgNrRowsCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgWorkWidthCommand_t
{
    /* Instelling werkbreedte */
    uint16_t WorkWidth;
} MsgWorkWidthCommand_t;

bool MsgWorkWidthCommand_decode(const uint8_t *data, uint8_t dlc, MsgWorkWidthCommand_t *msg);
bool MsgWorkWidthCommand_encode(const MsgWorkWidthCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgHeightThresholdCommand_t
{
    /* Grenswaarde einde rij detectie */
    uint16_t HeightDetectThreshold;
} MsgHeightThresholdCommand_t;

bool MsgHeightThresholdCommand_decode(const uint8_t *data, uint8_t dlc, MsgHeightThresholdCommand_t *msg);
bool MsgHeightThresholdCommand_encode(const MsgHeightThresholdCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgWaterTimeCommand_t
{
    /* Watergift tijd */
    uint16_t WaterTime;
} MsgWaterTimeCommand_t;

bool MsgWaterTimeCommand_decode(const uint8_t *data, uint8_t dlc, MsgWaterTimeCommand_t *msg);
bool MsgWaterTimeCommand_encode(const MsgWaterTimeCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgWaterOffsetCommand_t
{
    /* Timing water gift */
    uint16_t WaterOffset;
    /* Timing water gift unit 2 */
    uint16_t WaterOffset2;
} MsgWaterOffsetCommand_t;

bool MsgWaterOffsetCommand_decode(const uint8_t *data, uint8_t dlc, MsgWaterOffsetCommand_t *msg);
bool MsgWaterOffsetCommand_encode(const MsgWaterOffsetCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgAutoControlCommand_t
{
    /* Auto Control Gripper On/off */
    bool AutoControl;
} MsgAutoControlCommand_t;

bool MsgAutoControlCommand_decode(const uint8_t *data, uint8_t dlc, MsgAutoControlCommand_t *msg);
bool MsgAutoControlCommand_encode(const MsgAutoControlCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgGripIdleCofCommand_t
{
    /* check */
    uint16_t GripperIdleCof;
} MsgGripIdleCofCommand_t;

bool MsgGripIdleCofCommand_decode(const uint8_t *data, uint8_t dlc, MsgGripIdleCofCommand_t *msg);
bool MsgGripIdleCofCommand_encode(const MsgGripIdleCofCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgGripIdleOffsetCommand_t
{
    /* Gripper timing */
    uint16_t GripperIdleOffset;
    /* Gripper 2 timing */
    uint16_t GripperIdleOffset2;
} MsgGripIdleOffsetCommand_t;

bool MsgGripIdleOffsetCommand_decode(const uint8_t *data, uint8_t dlc, MsgGripIdleOffsetCommand_t *msg);
bool MsgGripIdleOffsetCommand_encode(const MsgGripIdleOffsetCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgBeltOffsetCommand_t
{
    /* Belt ZAP timing */
    uint16_t BeltOffset;
} MsgBeltOffsetCommand_t;

bool MsgBeltOffsetCommand_decode(const uint8_t *data, uint8_t dlc, MsgBeltOffsetCommand_t *msg);
bool MsgBeltOffsetCommand_encode(const MsgBeltOffsetCommand_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgConfigRequest_t
{
    /* Bericht om configuratieparameters op te vragen */
    ConfigGroup_value_t ConfigGroup;
} MsgConfigRequest_t;

bool MsgConfigRequest_decode(const uint8_t *data, uint8_t dlc, MsgConfigRequest_t *msg);
bool MsgConfigRequest_encode(const MsgConfigRequest_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgSpeedConfig_t
{
    uint16_t SpeedSetpointCurrent;
    uint16_t SpeedDefault;
    uint16_t SpeedMin;
    uint16_t SpeedMax;
} MsgSpeedConfig_t;

bool MsgSpeedConfig_decode(const uint8_t *data, uint8_t dlc, MsgSpeedConfig_t *msg);
bool MsgSpeedConfig_encode(const MsgSpeedConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgHeightConfig_t
{
    uint16_t HeightSetpointCurrent;
    uint16_t HeightDefault;
    uint16_t HeightMin;
    uint16_t HeightMax;
} MsgHeightConfig_t;

bool MsgHeightConfig_decode(const uint8_t *data, uint8_t dlc, MsgHeightConfig_t *msg);
bool MsgHeightConfig_encode(const MsgHeightConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgPlantSpacingConfig_t
{
    uint16_t PlantSpacingCurrent;
    uint16_t PlantSpacingDefault;
    uint16_t PlantSpacingMin;
    uint16_t PlantSpacingMax;
} MsgPlantSpacingConfig_t;

bool MsgPlantSpacingConfig_decode(const uint8_t *data, uint8_t dlc, MsgPlantSpacingConfig_t *msg);
bool MsgPlantSpacingConfig_encode(const MsgPlantSpacingConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgWaterTimeConfig_t
{
    uint16_t WaterTimeCurrent;
    uint16_t WaterTimeDefault;
    uint16_t WaterTimeMin;
    uint16_t WaterTimeMax;
} MsgWaterTimeConfig_t;

bool MsgWaterTimeConfig_decode(const uint8_t *data, uint8_t dlc, MsgWaterTimeConfig_t *msg);
bool MsgWaterTimeConfig_encode(const MsgWaterTimeConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgWheelCircumConfig_t
{
    uint16_t WheelCircumCurrent;
    uint16_t WheelCircumDefault;
    uint16_t WheelCircumMin;
    uint16_t WheelCircumMax;
} MsgWheelCircumConfig_t;

bool MsgWheelCircumConfig_decode(const uint8_t *data, uint8_t dlc, MsgWheelCircumConfig_t *msg);
bool MsgWheelCircumConfig_encode(const MsgWheelCircumConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgGripperIdleOffsetConfig_t
{
    uint16_t GripperIdleOffsetCurrent;
    uint16_t GripperIdleOffsetDefault;
    uint16_t GripperIdleOffsetMin;
    uint16_t GripperIdleOffsetMax;
} MsgGripperIdleOffsetConfig_t;

bool MsgGripperIdleOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgGripperIdleOffsetConfig_t *msg);
bool MsgGripperIdleOffsetConfig_encode(const MsgGripperIdleOffsetConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgGripperIdleCofConfig_t
{
    uint16_t GripperIdleCofCurrent;
    uint16_t GripperIdleCofDefault;
    uint16_t GripperIdleCofMin;
    uint16_t GripperIdleCofMax;
} MsgGripperIdleCofConfig_t;

bool MsgGripperIdleCofConfig_decode(const uint8_t *data, uint8_t dlc, MsgGripperIdleCofConfig_t *msg);
bool MsgGripperIdleCofConfig_encode(const MsgGripperIdleCofConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgBeltOffsetConfig_t
{
    uint16_t BeltOffsetCurrent;
    uint16_t BeltOffsetDefault;
    uint16_t BeltOffsetMin;
    uint16_t BeltOffsetMax;
} MsgBeltOffsetConfig_t;

bool MsgBeltOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgBeltOffsetConfig_t *msg);
bool MsgBeltOffsetConfig_encode(const MsgBeltOffsetConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgGripperIdleOffset2Config_t
{
    uint16_t GripperIdleOffset2Current;
    uint16_t GripperIdleOffset2Default;
    uint16_t GripperIdleOffset2Min;
    uint16_t GripperIdleOffset2Max;
} MsgGripperIdleOffset2Config_t;

bool MsgGripperIdleOffset2Config_decode(const uint8_t *data, uint8_t dlc, MsgGripperIdleOffset2Config_t *msg);
bool MsgGripperIdleOffset2Config_encode(const MsgGripperIdleOffset2Config_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgHeightDetectConfig_t
{
    uint16_t HeightDetectCurrent;
    uint16_t HeightDetectDefault;
    uint16_t HeightDetectMin;
    uint16_t HeightDetectMax;
} MsgHeightDetectConfig_t;

bool MsgHeightDetectConfig_decode(const uint8_t *data, uint8_t dlc, MsgHeightDetectConfig_t *msg);
bool MsgHeightDetectConfig_encode(const MsgHeightDetectConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgWaterOffsetConfig_t
{
    uint16_t WaterOffsetCurrent;
    uint16_t WaterOffsetDefault;
    uint16_t WaterOffsetMin;
    uint16_t WaterOffsetMax;
} MsgWaterOffsetConfig_t;

bool MsgWaterOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgWaterOffsetConfig_t *msg);
bool MsgWaterOffsetConfig_encode(const MsgWaterOffsetConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgWaterOffset2Config_t
{
    uint16_t WaterOffset2Current;
    uint16_t WaterOffset2Default;
    uint16_t WaterOffset2Min;
    uint16_t WaterOffset2Max;
} MsgWaterOffset2Config_t;

bool MsgWaterOffset2Config_decode(const uint8_t *data, uint8_t dlc, MsgWaterOffset2Config_t *msg);
bool MsgWaterOffset2Config_encode(const MsgWaterOffset2Config_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgSpeedRaiseConfig_t
{
    uint16_t SpeedRaiseCurrent;
    uint16_t SpeedRaiseDefault;
    uint16_t SpeedRaiseMin;
    uint16_t SpeedRaiseMax;
} MsgSpeedRaiseConfig_t;

bool MsgSpeedRaiseConfig_decode(const uint8_t *data, uint8_t dlc, MsgSpeedRaiseConfig_t *msg);
bool MsgSpeedRaiseConfig_encode(const MsgSpeedRaiseConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgSpeedLowerConfig_t
{
    uint16_t SpeedLowerCurrent;
    uint16_t SpeedLowerDefault;
    uint16_t SpeedLowerMin;
    uint16_t SpeedLowerMax;
} MsgSpeedLowerConfig_t;

bool MsgSpeedLowerConfig_decode(const uint8_t *data, uint8_t dlc, MsgSpeedLowerConfig_t *msg);
bool MsgSpeedLowerConfig_encode(const MsgSpeedLowerConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgNrRowsConfig_t
{
    uint16_t NrRowsCurrent;
    uint16_t NrRowsDefault;
    uint16_t NrRowsMin;
    uint16_t NrRowsMax;
} MsgNrRowsConfig_t;

bool MsgNrRowsConfig_decode(const uint8_t *data, uint8_t dlc, MsgNrRowsConfig_t *msg);
bool MsgNrRowsConfig_encode(const MsgNrRowsConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgWheelPositionOffsetConfig_t
{
    uint16_t WheelPositionOffsetCurrent;
    uint16_t WheelPositionOffsetDefault;
    uint16_t WheelPositionOffsetMin;
    uint16_t WheelPositionOffsetMax;
} MsgWheelPositionOffsetConfig_t;

bool MsgWheelPositionOffsetConfig_decode(const uint8_t *data, uint8_t dlc, MsgWheelPositionOffsetConfig_t *msg);
bool MsgWheelPositionOffsetConfig_encode(const MsgWheelPositionOffsetConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgZAPConfig_t
{
    bool UseTandem;
    bool UseWaterDosage;
} MsgZAPConfig_t;

bool MsgZAPConfig_decode(const uint8_t *data, uint8_t dlc, MsgZAPConfig_t *msg);
bool MsgZAPConfig_encode(const MsgZAPConfig_t *msg, uint8_t *data, uint8_t dlc);

typedef struct MsgSemiautoConfig_t
{
    bool UseGripper;
} MsgSemiautoConfig_t;

bool MsgSemiautoConfig_decode(const uint8_t *data, uint8_t dlc, MsgSemiautoConfig_t *msg);
bool MsgSemiautoConfig_encode(const MsgSemiautoConfig_t *msg, uint8_t *data, uint8_t dlc);

#endif /* CAN_MESSAGES_H */
