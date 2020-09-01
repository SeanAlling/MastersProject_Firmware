#ifndef _EPAPER_CFAP152152A00154_
#define _EPAPER_CFAP152152A00154_

#include <stdint.h>
#include "BSP_SPI.h"
#include "BSP_GPO.h"
#include "BSP_GPI.h"
//-----------------------------------------------------------------------------
void ePaper_Init(                 
                 SPI_Peripheral const spi,
                 GPO_Peripheral const cs,
                 GPO_Peripheral const dc,
                 GPO_Peripheral const rst,
                 GPI_Peripheral const busy
                );

void Load_Flash_Image_To_Display_RAM( uint16_t width_pixels,
                                      uint16_t height_pixels,
                                      const uint8_t *BW_image,
                                      const uint8_t *red_image
                                    );

void Load_Inverse_Flash_Image_To_Display_RAM( uint16_t width_pixels,
                                              uint16_t height_pixels,
                                              const uint8_t *BW_image,
                                              const uint8_t *red_image
                                            );
void showImage(void);
void ePaper_PowerOff(void);
void delay( const uint32_t delay_ms);


void ePaper_WriteCMD(uint8_t command);
void WriteCMD_StringFlash(const uint8_t *data, uint8_t datalen);
void eWriteCS(uint8_t);
void eWriteReset(uint8_t);
void eWriteByte(uint8_t);
uint8_t eGetReady(void);
void PartialUpdate(void);
void partialUpdateCharacters(const unsigned char holder[] );
void partialUpdate_DrawCharacter(const unsigned char holder[], uint16_t x, uint16_t y );

#define HEIGHT_PIXELS    (300)
#define WIDTH_PIXELS     (400)
#define WIDTH_MONO_BYTES (50)



//=============================================================================
#endif 
