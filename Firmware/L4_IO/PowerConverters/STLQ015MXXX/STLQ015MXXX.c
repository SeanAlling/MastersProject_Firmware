#include "STLQ015MXXX.h"

#include <stdint.h>

#include "BSP_GPO.h"

#include "MyDebug.h"


uint8_t STLQ015MXXX_Init(STLQ015 * const converter, GPO_Peripheral const gpo)
{
    converter->api = BSP_GPO_Init(gpo);
    converter->gpo = gpo;
    return 0;
}

uint8_t STLQ015MXXX_Enable(STLQ015 const * const converter)
{
    converter->api->Set(converter->gpo);
    return 0;
}

uint8_t STLQ015MXXX_Disable(STLQ015 const * const converter)
{
    converter->api->Clear(converter->gpo);
    return 0;
}
