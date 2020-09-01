#ifndef FM24CL16B_CONFIG_H_
#define FM24CL16B_CONFIG_H_



/*
    This file contains macro definitions for working with the FM24CL16B.
    The definitions defined here should only be included in FM24CL16B.c
*/

/*
    I2C address is 7 bits in the following format 
    MSB                             LSB
    1    0    1    0    A2    A1    A0
    |______________|    |_____________|
         0x10              Page Index

    The 4 MSB are constant, while the low 3 LSB are used to select 
    which page will be written to.
*/
#define I2C_ADRESS (0xA<<3)

/*
    Three bits used or FRAM page index.
    3 bits represents a total of 8 pages
*/
#define FM24CL16B_NUMBER_PAGES (8)
/*
    Each page has 255 entries. In the datasheet this is given as the word address. 
*/
#define FM24CL16B_ENTRIES_PER_PAGE (256)

/*
    Total number of bytes is the number of words per page multiplied by the 
    number of pages. A address above this range is considered to be invalid.
*/
#define FM24CL16B_NUMBER_OF_ENTRIES (FM24CL16B_NUMBER_PAGES * FM24CL16B_ENTRIES_PER_PAGE)

#define FM24CL16B_ADDRESS_MASK (0x0F<<4)

/*
    3 LSB of slave address define the FRAM page index.
*/
#define FM24CL16B_PAGE_MASK (0x03)


#endif // FM24CL16B_CONFIG_H_