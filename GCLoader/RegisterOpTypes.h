﻿#pragma once

enum class RegisterReadType {
    DMAC_ID = 0x400,
    FIO_NODE_0_STATUS = 0x4000,
    FIO_NODE_1_STATUS = 0x4004,
    FIO_NODE_0_INPUT = 0x4120,
    FIO_NODE0_ANALOG1 = 0x4124,
    FIO_NODE0_ANALOG2 = 0x4128,
    FIO_NODE0_ANALOG3 = 0x412C,
    FIO_NODE_1_INPUT = 0x41A0,
    FIO_NODE1_ANALOG1 = 0x41A4,
    FIO_NODE1_ANALOG2 = 0x41A8,
    FIO_NODE1_ANALOG3 = 0x41AC,
    FIO_NODE_0_COINSLOT_1 = 0x4140,
    FIO_NODE_0_COINSLOT_2 = 0x4144,
    FIO_NODE_1_COINSLOT_1 = 0x41C0,
    FIO_NODE_1_COINSLOT_2 = 0x41C4,
    FIO_HUB_PORT_1 = 0x4150,
    FIO_HUB_PORT_2 = 0x4154,
    FIO_HUB_PORT_3 = 0x4158,
    FIO_HUB_PORT_4 = 0x415C,
    FIO_GC_UNKNOWN_1 = 0x41D0,
    FIO_GC_UNKNOWN_2 = 0x41D4,
    FIO_GC_UNKNOWN_3 = 0x41D8,
    FIO_GC_UNKNOWN_4 = 0x41DC,
    FIO_GC_UNKNOWN_5 = 0x4148,
    FIO_GC_UNKNOWN_6 = 0x414C,
    FIO_GC_UNKNOWN_7 = 0x41C8,
    FIO_GC_UNKNOWN_8 = 0x41CC,
};

enum class RegisterWriteType {
    NODE0_RESET = 0x4000,
    NODE1_RESET = 0x4004,
    FIO_NODE0P1_COINCOUNTER = 0x4140,
    FIO_NODE0P2_COINCOUNTER = 0x0000,
    FIO_NODE1P1_COINCOUNTER = 0x41C0,
    FIO_NODE1P2_COINCOUNTER = 0x41F0,
    FIO_NODE0_GPIOBANK1 = 0x4100,
    FIO_NODE0_GPIOBANK2 = 0x4104,
    FIO_NODE0_GPIOBANK3 = 0x4108,
    FIO_NODE0_GPIOBANK4 = 0x410C,
    FIO_NODE1_GPIOBANK1 = 0x4180,
    FIO_NODE1_GPIOBANK2 = 0x4184,
    FIO_NODE1_GPIOBANK3 = 0x4188,
    FIO_NODE1_GPIOBANK4 = 0x418C,
};
