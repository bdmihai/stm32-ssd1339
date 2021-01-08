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
 |  Author: Mihai Baneu                           Last modified: 08.Dec.2020  |
 |                                                                            |
 |___________________________________________________________________________*/

/* 
  Text drawing is based on the :
  u8x8 original code from https://github.com/olikraus/u8g2/
  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.
*/

#include <stdint.h>
#include "ssd1339.h"

ssd1339_hw_control_t hw;

void ssd1339_init(ssd1339_hw_control_t hw_control)
{
    hw = hw_control;
    hw.config_control_out();
    hw.config_data_out();
    hw.dc_cs_wr_high();
    hw.res_high();
    hw.rd_high();
}

void ssd1339_reset_on()
{
    hw.res_low();
}

void ssd1339_reset_off()
{
    hw.res_high();
}

void ssd1339_command(uint8_t command)
{
    hw.dc_cs_wr_low();
    hw.data_wr(command);
    hw.dc_cs_wr_high();
}

void ssd1339_write8(uint8_t data)
{
    hw.cs_wr_low();
    hw.data_wr(data);
    hw.cs_wr_high();
}

void ssd1339_write16(uint16_t data)
{
    hw.cs_wr_low();
    hw.data_wr((data >> 8) & 0xFF);
    hw.cs_wr_high();
    asm ("nop");
    hw.cs_wr_low();
    hw.data_wr(data & 0xFF);
    hw.cs_wr_high();
}

void ssd1339_write(const uint8_t *buffer, int size)
{
    while (size--) {
        hw.cs_wr_low();
        hw.data_wr(*(buffer++));
        hw.cs_wr_high();
    }
}

uint8_t ssd1339_read8()
{
    uint8_t data;
    hw.config_data_in();
    hw.cs_low();
    hw.rd_low();
    data = hw.data_rd();
    hw.rd_high();
    hw.cs_high();
    hw.config_data_out();
    return data;
}

void ssd1339_set_column_address(uint8_t start, uint8_t end)
{
    ssd1339_command(SSD1339_CMD_SET_COLUMN_ADDRESS);
    ssd1339_write8(start);
    ssd1339_write8(end);
}

void ssd1339_set_row_address(uint8_t start, uint8_t end)
{
    ssd1339_command(SSD1339_CMD_SET_ROW_ADDRESS);
    ssd1339_write8(start);
    ssd1339_write8(end);
}

void ssd1339_set_write_ram()
{
    ssd1339_command(SSD1339_CMD_SET_WRITE_RAM);
}

void ssd1339_set_read_ram()
{
    ssd1339_command(SSD1339_CMD_SET_READ_RAM);
}

void ssd1339_set_map_and_color_depth(uint8_t mode)
{
    ssd1339_command(SSD1339_CMD_SET_MAPAND_COLOR_DEPTH);
    ssd1339_write8(mode);
}

void ssd1339_set_display_start_line(uint8_t line)
{
    ssd1339_command(SSD1339_CMD_SET_DISPLAY_START_LINE);
    ssd1339_write8(line);
}

void ssd1339_set_display_offset(uint8_t offset)
{
    ssd1339_command(SSD1339_CMD_SET_DISPLAY_OFFSET);
    ssd1339_write8(offset);
}

void ssd1339_set_display_mode(uint8_t mode)
{
    ssd1339_command(SSD1339_CMD_SET_DISPLAY_MODE | mode);
}

void ssd1339_set_master_configuration(uint8_t config)
{
    ssd1339_command(SSD1339_CMD_SET_MASTER_CONFIGURATION);
    ssd1339_write8(config);
}

void ssd1339_set_sleep_mode(uint8_t mode)
{
    ssd1339_command(SSD1339_CMD_SET_SLEEP_MODE | mode);
}

void ssd1339_set_power_saving_mode(uint8_t mode)
{
    ssd1339_command(SSD1339_CMD_SET_POWER_SAVING_MODE);
    ssd1339_write8(mode);
}

void ssd1339_set_reset_and_precharge(uint8_t reset, uint8_t precharge)
{
    ssd1339_command(SSD1339_CMD_SET_RESET_AND_PRECHARGE);
    ssd1339_write8(reset | (precharge << 4));
}

void ssd1339_set_clockdiv_and_oscilator(uint8_t clockdiv, uint8_t oscilator)
{
    ssd1339_command(SSD1339_CMD_SET_CLOCKDIV_AND_OSCILATOR);
    ssd1339_write8(clockdiv | (oscilator << 4));
}

void ssd1339_set_use_buildin_lut()
{
    ssd1339_command(SSD1339_CMD_SET_USE_BUILTIN_LUT);
}

void ssd1339_set_precharge_voltage(uint8_t a, uint8_t b, uint8_t c)
{
    ssd1339_command(SSD1339_CMD_SET_PRECHARGE_VOLTAGE);
    ssd1339_write8(a);
    ssd1339_write8(b);
    ssd1339_write8(c);
}

void ssd1339_set_vcomh(uint8_t vcomh)
{
    ssd1339_command(SSD1339_CMD_SET_VCOMH);
    ssd1339_write8(vcomh);
}

void ssd1339_set_contrast_curent(uint8_t a, uint8_t b, uint8_t c)
{
    ssd1339_command(SSD1339_CMD_SET_CONTRAST_CURRENT);
    ssd1339_write8(a);
    ssd1339_write8(b);
    ssd1339_write8(c);
}

void ssd1339_set_master_contrast_curent(uint8_t contrast)
{
    ssd1339_command(SSD1339_CMD_SET_MASTER_CONTRAST_CURRENT);
    ssd1339_write8(contrast);
}

void ssd1339_set_mux_ratio(uint8_t ratio)
{
    ssd1339_command(SSD1339_CMD_SET_SET_MUX_RATIO);
    ssd1339_write8(ratio);
}

void ssd1339_draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color)
{
    ssd1339_command(SSD1339_CMD_DRAW_LINE);
    ssd1339_write8(x1);
    ssd1339_write8(y1);
    ssd1339_write8(x2);
    ssd1339_write8(y2);
    ssd1339_write16(color);
}

void ssd1339_draw_rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color, uint16_t fill)
{
    ssd1339_command(SSD1339_CMD_DRAW_RECTANGLE);
    ssd1339_write8(x1);
    ssd1339_write8(y1);
    ssd1339_write8(x2);
    ssd1339_write8(y2);
    ssd1339_write16(color);
    ssd1339_write16(fill);
}

void ssd1339_draw_circle(uint8_t x1, uint8_t y1, uint8_t r, uint16_t color, uint16_t fill)
{
    ssd1339_command(SSD1339_CMD_DRAW_CIRCLE);
    ssd1339_write8(x1);
    ssd1339_write8(y1);
    ssd1339_write8(r);
    ssd1339_write16(color);
    ssd1339_write16(fill);
}

void ssd1339_draw_copy(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t x3, uint16_t y3)
{
    ssd1339_command(SSD1339_CMD_DRAW_COPY);
    ssd1339_write8(x1);
    ssd1339_write8(y1);
    ssd1339_write8(x2);
    ssd1339_write8(y2);
    ssd1339_write8(x3);
    ssd1339_write8(y3);
}

void ssd1339_draw_dim(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    ssd1339_command(SSD1339_CMD_DRAW_DIM);
    ssd1339_write8(x1);
    ssd1339_write8(y1);
    ssd1339_write8(x2);
    ssd1339_write8(y2);
}

void ssd1339_draw_clear(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    ssd1339_command(SSD1339_CMD_DRAW_CLEAR);
    ssd1339_write8(x1);
    ssd1339_write8(y1);
    ssd1339_write8(x2);
    ssd1339_write8(y2);
}

void ssd1339_set_fill_copy_mode(uint8_t mode)
{
    ssd1339_command(SSD1339_CMD_SET_FILL_COPY_MODE);
    ssd1339_write8(mode);
}

void ssd1339_draw_fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color)
{
    ssd1339_set_column_address(x1, x2-1);
    ssd1339_set_row_address(y1, y2-1);

    ssd1339_set_write_ram();
    for (int i = 0; i < x2-x1; i++) {
        for (int j = 0; j < y2-y1; j++) {
            ssd1339_write16(color);
        }
    }
}

void ssd1339_draw_gradient_hfill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color)
{
    uint16_t masked;

    ssd1339_set_column_address(x1, x2-1);
    ssd1339_set_row_address(y1, y2-1);
    ssd1339_set_write_ram();
    for (int i = 0; i < x2-x1; i++) {
        for (int j = 0; j < y2-y1; j++) {
            masked = 0;
            masked += (((i/4) % 32) << 11);
            masked += (((i/2) % 64) <<  5);
            masked += ((i/4) % 32);
            ssd1339_write16(color & masked);
        }
    }
}

void ssd1339_draw_gradient_vfill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color)
{
    uint16_t masked;

    ssd1339_set_column_address(x1, x2-1);
    ssd1339_set_row_address(y1, y2-1);
    ssd1339_set_write_ram();
    for (int i = 0; i < x2-x1; i++) {
        for (int j = 0; j < y2-y1; j++) {
            masked = 0;
            masked += (((j/4) % 32) << 11);
            masked += (((j/2) % 64) <<  5);
            masked += ((j/4) % 32);
            ssd1339_write16(color & masked);
        }
    }
}

void ssd1339_draw_image(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const uint16_t *img)
{
    ssd1339_set_column_address(x1, x2-1);
    ssd1339_set_row_address(y1, y2-1);
    ssd1339_set_write_ram();
    ssd1339_write((const uint8_t *)img, (x2-x1) * (y2-y1) * 2);
}

static uint8_t get_font_data(const uint8_t *adr)
{
    return (*(const uint8_t *)(adr));
}

static void get_glyph_data(const uint8_t *font, uint8_t th, uint8_t tv, uint8_t encoding, uint8_t *buf, uint8_t tile_offset)
{
    uint8_t first, last;
    uint16_t offset;

    first = get_font_data(font + 0);
    last = get_font_data(font + 1);
    if (first <= encoding && encoding <= last) {
        offset = encoding;
        offset -= first;
        offset *= th * tv;
        offset += tile_offset;
        offset *= 8;
        offset += 4;
        for (uint8_t i = 0; i < 8; i++) {
            buf[i] = get_font_data(font + offset);
            offset++;
        }
    } else {
        for (uint8_t i = 0; i < 8; i++) {
            buf[i] = 0;
        }
    }
}

static void draw_tile(const uint8_t *buffer, uint8_t x, uint8_t y, uint16_t color, uint16_t background)
{
    const uint8_t colormask[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
    ssd1339_set_column_address(x, x + 8 - 1);
    ssd1339_set_row_address(y, y + 8 - 1);
    ssd1339_set_write_ram();
    for (uint8_t i = 0; i < 8; i++) {
        for (uint8_t j = 0; j < 8; j++) {
            ssd1339_write16((buffer[j] & colormask[i]) ? color : background);
        }
    }
}

static void draw_glyph(const uint8_t *font, uint8_t x, uint8_t y, uint8_t th, uint8_t tv, uint16_t color, uint16_t background, uint8_t encoding)
{
    uint8_t buffer[8];
    uint8_t tile = 0;;

    for (uint8_t yy = 0; yy < tv; yy++) {
        for (uint8_t xx = 0; xx < th; xx++) {
            get_glyph_data(font, th, tv, encoding, buffer, tile);
            draw_tile(buffer, xx * 8 + x, (tv-yy-1) * 8 + y, color, background);
            tile++;
        }
    }
}

void ssd1339_draw_char(const uint8_t *font, uint8_t x, uint8_t y, uint16_t color, uint16_t background, const char c)
{
    uint8_t th = get_font_data(font + 2);
    uint8_t tv = get_font_data(font + 3);

    draw_glyph(font, x, y, th, tv, color, background, c);
}

void ssd1339_draw_string(const uint8_t *font, uint8_t x, uint8_t y, uint16_t color, uint16_t background, const char *s)
{
    uint8_t th = get_font_data(font + 2);
    uint8_t tv = get_font_data(font + 3);

    while (*s != 0) {
        draw_glyph(font, x, y, th, tv, color, background, *s);
        x += th * 8;
        s++;
    }
}
