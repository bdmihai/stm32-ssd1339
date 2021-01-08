/*_____________________________________________________________________________
 │                                                                            |
 │ COPYRIGHT (C) 2020 Mihai Baneu                                             |
 │                                                                            |
 | Permission is hereby  granted,  free of charge,  to any person obtaining a |
 | copy of this software and associated documentation files (the "Software"), |
 | to deal in the Software without restriction,  including without limitation |
 | the rights to  use, copy, modify, merge, publish, distribute,  sublicense, |
 | and/or sell copies  of  the Software, and to permit  persons to  whom  the |
 | Software is furnished to do so, subject to the following conditions:       |
 |                                                                            |
 | The above  copyright notice  and this permission notice  shall be included |
 | in all copies or substantial portions of the Software.                     |
 |                                                                            |
 | THE SOFTWARE IS PROVIDED  "AS IS",  WITHOUT WARRANTY OF ANY KIND,  EXPRESS |
 | OR   IMPLIED,   INCLUDING   BUT   NOT   LIMITED   TO   THE  WARRANTIES  OF |
 | MERCHANTABILITY,  FITNESS FOR  A  PARTICULAR  PURPOSE AND NONINFRINGEMENT. |
 | IN NO  EVENT SHALL  THE AUTHORS  OR  COPYRIGHT  HOLDERS  BE LIABLE FOR ANY |
 | CLAIM, DAMAGES OR OTHER LIABILITY,  WHETHER IN AN ACTION OF CONTRACT, TORT |
 | OR OTHERWISE, ARISING FROM,  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  |
 | THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                 |
 |____________________________________________________________________________|
 |                                                                            |
 |  Author: Mihai Baneu                           Last modified: 24.Nov.2020  |
 |                                                                            |
 |___________________________________________________________________________*/
 
#pragma once

#define SSD1339_CMD_NOP                             0x00
#define SSD1339_CMD_SET_COLUMN_ADDRESS              0x15
#define SSD1339_CMD_SET_ROW_ADDRESS                 0x75
#define SSD1339_CMD_SET_WRITE_RAM                   0x5C
#define SSD1339_CMD_SET_READ_RAM                    0x5D
#define SSD1339_CMD_SET_MAPAND_COLOR_DEPTH          0xA0 
#define SSD1339_CMD_SET_DISPLAY_START_LINE          0xA1
#define SSD1339_CMD_SET_DISPLAY_OFFSET              0xA2
#define SSD1339_CMD_SET_DISPLAY_MODE                0xA4
#define SSD1339_CMD_SET_MASTER_CONFIGURATION        0xAD
#define SSD1339_CMD_SET_SLEEP_MODE                  0xAE
#define SSD1339_CMD_SET_POWER_SAVING_MODE           0xB0
#define SSD1339_CMD_SET_RESET_AND_PRECHARGE         0xB1
#define SSD1339_CMD_SET_CLOCKDIV_AND_OSCILATOR      0xB3
#define SSD1339_CMD_SET_USE_BUILTIN_LUT             0xB9
#define SSD1339_CMD_SET_PRECHARGE_VOLTAGE           0xBB
#define SSD1339_CMD_SET_VCOMH                       0xBE
#define SSD1339_CMD_SET_CONTRAST_CURRENT            0xC1
#define SSD1339_CMD_SET_MASTER_CONTRAST_CURRENT     0xC7
#define SSD1339_CMD_SET_SET_MUX_RATIO               0xCA
#define SSD1339_CMD_DRAW_LINE                       0x83
#define SSD1339_CMD_DRAW_RECTANGLE                  0x84
#define SSD1339_CMD_DRAW_CIRCLE                     0x86
#define SSD1339_CMD_DRAW_COPY                       0x8A
#define SSD1339_CMD_SET_FILL_COPY_MODE              0x92
#define SSD1339_CMD_DRAW_DIM                        0x8C
#define SSD1339_CMD_DRAW_CLEAR                      0x8E

#define SSD1339_MODE_ALL_OFF                        0x00 
#define SSD1339_MODE_ALL_ON                         0x01 /* (All pixels have GS15)           */
#define SSD1339_MODE_RESET_TO_NORMAL_DISPLAY        0x02 /* (POR)                            */ 
#define SSD1339_MODE_INVERSE_DISPLAY                0x03 /* (GS0 -> GS63, GS1 -> GS62, ....) */ 

#define SSD1339_REMAP_MODE_HORIZONTAL               0b00000000  /* A[0]=0, Horizontal address increment (POR)                                        */
#define SSD1339_REMAP_MODE_VERTICAL                 0b00000001  /* A[0]=1, Vertical address increment                                                */
#define SSD1339_REMAP_MODE_0_SEG0                   0b00000000  /* A[1]=0, Column address 0 is mapped to SEG0 (POR)                                  */
#define SSD1339_REMAP_MODE_131_SEG0                 0b00000010  /* A[1]=1, Column address 131 is mapped to SEG0                                      */
#define SSD1339_REMAP_MODE_COLOR_ABC                0b00000000  /* A[2]=0, Color sequence: A # B # C (POR)                                           */
#define SSD1339_REMAP_MODE_COLOR_CBA                0b00000100  /* A[2]=1, Color sequence is swapped: C # B # A                                      */
#define SSD1339_REMAP_MODE_NO_18BIT                 0b00000000  /* A[3]=0, Disable 9/18-bit bus interface (POR)                                      */
#define SSD1339_REMAP_MODE_18BIT                    0b00001000  /* A[3]=1, Enable 9/18-bit bus interface                                             */
#define SSD1339_REMAP_MODE_SCAN_0_N                 0b00000000  /* A[4]=0, Scan from COM 0 to COM [N –1] (POR)                                       */
#define SSD1339_REMAP_MODE_SCAN_N_0                 0b00010000  /* A[4]=1, Scan from COM [N-1] to COM0. Where N is the multiplex ratio.              */
#define SSD1339_REMAP_MODE_NO_ODD_EVEN              0b00000000  /* A[5]=0, Disable COM Split Odd Even (POR)                                          */
#define SSD1339_REMAP_MODE_ODD_EVEN                 0b00100000  /* A[5]=1, Enable COM Split Odd Even                                                 */
#define SSD1339_COLOR_MODE_256                      0b00000000  /* A[7:6] Set Color Depth, 256  color                                                */ 
#define SSD1339_COLOR_MODE_65K                      0b01000000  /* A[7:6] Set Color Depth, 65K  color, (POR)                                         */ 
#define SSD1339_COLOR_MODE_262k                     0b10000000  /* A[7:6] Set Color Depth, 262k color, 8/9/18-bit,16 bit (1st option) MCU interface  */ 
#define SSD1339_COLOR_MODE_262k2                    0b11000000  /* A[7:6] Set Color Depth, 262k color, 16 - bit MCU interface (2nd option)           */ 

#define SSD1339_SLEEP_ON                            0x00
#define SSD1339_SLEEP_OFF                           0x01

#define SSD1339_POWER_SAVING_MODE_OFF               0x00  /* 00000b = Normal */
#define SSD1339_POWER_SAVING_MODE_ON                0x12  /* 10010b = Power Saving */

#define SSD1339_FILLMODE_ENABLE                     0x01
#define SSD1339_FILLMODE_DISABLE                    0x00
#define SSD1339_REVERSECOPY_ENABLE                  0x10
#define SSD1339_REVERSECOPY_DISABLE                 0x00
#define SSD1339_XWRAPCOPY_ENABLE                    0x20
#define SSD1339_XWRAPCOPY_DISABLE                   0x00

// display resolution
#define SSD1339_MAX_COLS                            132
#define SSD1339_MAX_RWOS                            133
#define SSD1339_128_COLS                            128
#define SSD1339_128_RWOS                            128

// standard RGB15 colors
#define SSD1339_RGB(R,G,B)                          ((((uint16_t)B >> 3) << 11) + (((uint16_t)G >> 2) << 5) + ((uint16_t)R >> 3))
#define SSD1339_BLACK                               SSD1339_RGB(0,0,0)
#define SSD1339_WHITE                               SSD1339_RGB(255,255,255)
#define SSD1339_RED	                                SSD1339_RGB(255,0,0)
#define SSD1339_LIME                                SSD1339_RGB(0,255,0)
#define SSD1339_BLUE                                SSD1339_RGB(0,0,255)
#define SSD1339_YELLOW                              SSD1339_RGB(255,255,0)
#define SSD1339_CYAN                                SSD1339_RGB(0,255,255)
#define SSD1339_MAGENTA                             SSD1339_RGB(255,0,255)
#define SSD1339_SILVER                              SSD1339_RGB(192,192,192)
#define SSD1339_GRAY                                SSD1339_RGB(128,128,128)
#define SSD1339_MAROON                              SSD1339_RGB(128,0,0)
#define SSD1339_OLIVE                               SSD1339_RGB(128,128,0)
#define SSD1339_GREEN                               SSD1339_RGB(0,128,0)
#define SSD1339_PURPLE                              SSD1339_RGB(128,0,128)
#define SSD1339_TEAL                                SSD1339_RGB(0,128,128)
#define SSD1339_NAVY                                SSD1339_RGB(0,0,128)

typedef void (*ssd1339_config_func_t)();
typedef void (*ssd1339_set_func_t)();
typedef void (*ssd1339_write_func_t)(const uint8_t );
typedef uint8_t (*ssd1339_read_func_t)();

typedef struct ssd1339_hw_control_t {
    ssd1339_config_func_t config_control_out;
    ssd1339_config_func_t config_data_out;
    ssd1339_config_func_t config_data_in;
    ssd1339_set_func_t cs_high;
    ssd1339_set_func_t cs_low;
    ssd1339_set_func_t res_high;
    ssd1339_set_func_t res_low;
    ssd1339_set_func_t dc_high;
    ssd1339_set_func_t dc_low;
    ssd1339_set_func_t wr_high;
    ssd1339_set_func_t wr_low;
    ssd1339_set_func_t rd_high;
    ssd1339_set_func_t rd_low;
    ssd1339_set_func_t cs_wr_high;
    ssd1339_set_func_t cs_wr_low;
    ssd1339_set_func_t cs_rd_high;
    ssd1339_set_func_t cs_rd_low;
    ssd1339_set_func_t dc_cs_wr_high;
    ssd1339_set_func_t dc_cs_wr_low;
    ssd1339_write_func_t data_wr;
    ssd1339_read_func_t data_rd;
} ssd1339_hw_control_t;

/* basic communication */
void ssd1339_init(ssd1339_hw_control_t hw_control);
void ssd1339_reset_on();
void ssd1339_reset_off();
void ssd1339_command(uint8_t command);
void ssd1339_write8(uint8_t data);
void ssd1339_write16(uint16_t data);
void ssd1339_write(const uint8_t *buffer, int size);
uint8_t ssd1339_read8();

/* simple command that can be processed by the display */
void ssd1339_set_column_address(uint8_t start, uint8_t end);
void ssd1339_set_row_address(uint8_t start, uint8_t end);
void ssd1339_set_write_ram();
void ssd1339_set_read_ram();
void ssd1339_set_map_and_color_depth(uint8_t mode);
void ssd1339_set_display_start_line(uint8_t line);
void ssd1339_set_display_offset(uint8_t offset);
void ssd1339_set_display_mode(uint8_t mode);
void ssd1339_set_master_configuration(uint8_t config);
void ssd1339_set_sleep_mode(uint8_t mode);
void ssd1339_set_power_saving_mode(uint8_t mode);
void ssd1339_set_reset_and_precharge(uint8_t reset, uint8_t precharge);
void ssd1339_set_clockdiv_and_oscilator(uint8_t clockdiv, uint8_t oscilator);
void ssd1339_set_precharge_voltage(uint8_t a, uint8_t b, uint8_t c);
void ssd1339_set_use_buildin_lut();
void ssd1339_set_vcomh(uint8_t vcomh);
void ssd1339_set_contrast_curent(uint8_t a, uint8_t b, uint8_t c);
void ssd1339_set_master_contrast_curent(uint8_t contrast);
void ssd1339_set_mux_ratio(uint8_t ratio);

/* graphic acceleration command */
void ssd1339_draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);
void ssd1339_draw_rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color, uint16_t fill);
void ssd1339_draw_circle(uint8_t x1, uint8_t y1, uint8_t r, uint16_t color, uint16_t fill);
void ssd1339_draw_copy(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t x3, uint16_t y3);
void ssd1339_draw_dim(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void ssd1339_draw_clear(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void ssd1339_set_fill_copy_mode(uint8_t mode);

/* background, image and text (based on u8x8 - u2g2 library) */
void ssd1339_draw_fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);
void ssd1339_draw_gradient_hfill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);
void ssd1339_draw_gradient_vfill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);
void ssd1339_draw_image(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const uint16_t *img);
void ssd1339_draw_char(const uint8_t *font, uint8_t x, uint8_t y, uint16_t color, uint16_t background, const char c);
void ssd1339_draw_string(const uint8_t *font, uint8_t x, uint8_t y, uint16_t color, uint16_t background, const char *s);
